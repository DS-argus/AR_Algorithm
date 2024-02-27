class MedianFinder {
private:
    priority_queue<int> max_heap; // Max heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min heap for the larger half

public:
    MedianFinder() {
        // Constructor
    }

    void addNum(int num) {
        // To maintain balance, we'll always add elements to the max_heap first
        max_heap.push(num);

        // Move the maximum element from max_heap to min_heap
        min_heap.push(max_heap.top());
        max_heap.pop();

        // If min_heap has more elements, move the minimum element to max_heap
        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            // If the total number of elements is even, return the average of the two middle elements
            return (static_cast<double>(max_heap.top()) + min_heap.top()) / 2.0;
        } else {
            // If the total number of elements is odd, max_heap will have the extra element
            return static_cast<double>(max_heap.top());
        }
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */