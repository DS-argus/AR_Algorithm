// A C++ program to demonstrate common Binary Heap Operations 
#include<iostream> 
#include<climits> 
using namespace std; 

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

// A class for Min Heap 
class MinHeap 
{ 
	int *harr; // pointer to array of elements in heap 
	int capacity; // maximum possible size of min heap 
	int heap_size; // Current number of elements in min heap 
public: 
	// Constructor: Builds a heap from a given array a[] of given size 
	MinHeap(int cap){ 
        heap_size = 0; 
        capacity = cap; 
        harr = new int[cap]; 
    } ; 

	// A recursive method to heapify a subtree with the root at given index 
    // This method assumes that the subtrees are already heapified 
    void MinHeapify(int i) { 
        int l = left(i); 
        int r = right(i); 
        int smallest = i; 
        if (l < heap_size && harr[l] < harr[i]) smallest = l; 
        if (r < heap_size && harr[r] < harr[smallest]) smallest = r; 
        if (smallest != i) { 
            swap(&harr[i], &harr[smallest]); 
            MinHeapify(smallest); 
        } 
    } 


	int parent(int i) { return (i-1)/2; } 

	// to get index of left child of node at index i 
	int left(int i) { return (2*i + 1); } 

	// to get index of right child of node at index i 
	int right(int i) { return (2*i + 2); } 

	// Method to remove minimum element (or root) from min heap 
    int extractMin() { 
        if (heap_size <= 0) return INT_MAX; 
        
        if (heap_size == 1) { 
            heap_size--; 
            return harr[0]; 
        } 

        // Store the minimum value, and remove it from heap 
        int root = harr[0]; 
        harr[0] = harr[heap_size-1]; 
        heap_size--; 
        MinHeapify(0); 

        return root; 
    } 

	// Decreases value of key at index 'i' to new_val. It is assumed that 
    // new_val is smaller than harr[i]. 
    void decreaseKey(int i, int new_val){ 
        harr[i] = new_val; 
        while (i != 0 && harr[parent(i)] > harr[i]) 
        { 
            swap(&harr[i], &harr[parent(i)]); 
            i = parent(i); 
        } 
    } 

	// Returns the minimum key (key at root) from min heap 
	int getMin() { return harr[0]; } 

	// This function deletes key at index i. It first reduced value to minus 
    // infinite, then calls extractMin() 
    void deleteKey(int i) { 
        decreaseKey(i, INT_MIN); 
        extractMin(); 
    } 

	// Inserts a new key 'k' 
	void insertKey(int k) { 
        if (heap_size == capacity) 
        { 
            cout << "\nOverflow: Could not insertKey\n"; 
            return; 
        } 

        // First insert the new key at the end 
        heap_size++; 
        int i = heap_size - 1; 
        harr[i] = k; 

        // Fix the min heap property if it is violated 
        while (i != 0 && harr[parent(i)] > harr[i]) 
        { 
            swap(&harr[i], &harr[parent(i)]); 
            i = parent(i); 
        } 
    } 

}; 

// A class for Max Heap
class MaxHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of max heap
    int heap_size; // Current number of elements in max heap
public:
    // Constructor: Builds a heap from a given array a[] of given size
    MaxHeap(int cap){
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    };

    // A recursive method to heapify a subtree with the root at given index
    // This method assumes that the subtrees are already heapified
    void MaxHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heap_size && harr[l] > harr[i]) largest = l;
        if (r < heap_size && harr[r] > harr[largest]) largest = r;
        if (largest != i) {
            swap(&harr[i], &harr[largest]);
            MaxHeapify(largest);
        }
    }

    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // Method to remove maximum element (or root) from max heap
    int extractMax() {
        if (heap_size <= 0) return INT_MIN;

        if (heap_size == 1) {
            heap_size--;
            return harr[0];
        }

        // Store the maximum value, and remove it from heap
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        MaxHeapify(0);

        return root;
    }

    // Increases value of key at index 'i' to new_val. It is assumed that
    // new_val is larger than harr[i].
    void increaseKey(int i, int new_val){
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] < harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    // Returns the maximum key (key at root) from max heap
    int getMax() { return harr[0]; }

    // This function deletes key at index i. It first increases value to
    // infinite, then calls extractMax()
    void deleteKey(int i) {
        increaseKey(i, INT_MAX);
        extractMax();
    }

    // Inserts a new key 'k'
    void insertKey(int k) {
        if (heap_size == capacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        // First insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        // Fix the max heap property if it is violated
        while (i != 0 && harr[parent(i)] < harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }
};

// Driver program to test above functions 
int main() 
{ 
	MinHeap h(11); 
	h.insertKey(3); 
	h.insertKey(2); 
	h.deleteKey(1); 
	h.insertKey(15); 
	h.insertKey(5); 
	h.insertKey(4); 
	h.insertKey(45); 
	cout << h.extractMin() << " "; 
	cout << h.getMin() << " "; 
	h.decreaseKey(2, 1); 
	cout << h.getMin() << endl; 

    MaxHeap k(11);
    k.insertKey(3);
    k.insertKey(2);
    k.insertKey(15);
    k.insertKey(5);
    k.insertKey(4);
    k.insertKey(45);
    cout << k.extractMax() << " ";
    cout << k.getMax() << " ";
    k.increaseKey(2, 50);
    cout << k.getMax() << endl;

	return 0; 
} 
