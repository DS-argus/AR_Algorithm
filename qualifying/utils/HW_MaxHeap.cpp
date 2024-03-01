#include <iostream>
#include <vector>

using namespace std;

class Heap{
        int *harr;
        int capacity;
        int heap_size;
    public:
        Heap(int capacity): capacity(capacity), heap_size(0) {};

        void insertKey(int k){
            if (heap_size == capacity) {
                cout << "\nOverflow: Could not insertKey\n";
                return;
            }
            heap_size++;
            int i = heap_size - 1;
            harr[i] = k;
        }

        int parent(int i) { return (i-1)/2;}
        int left(int i) {return (2*i+1);}
        int right(int i) {return (2*i+2);}

        void buildMaxHeap() {
            // 실제 heap의 마지막 element index = heap_size-1
            int i = parent(heap_size-1);
            for( ; i >= 0; i--){
                MaxHeapify(i);
            }
        }

        void MaxHeapify(int i) {
            // Go Down
            // i = 4
            // l = 9
            // r = 10
            // heap_size = 10
            int l = left(i);
            int r = right(i);
            int largest_index = i;
            if (l < heap_size && harr[l] > harr[largest_index]) {
                largest_index = l;
            }
            if (r < heap_size && harr[r] > harr[largest_index]) {
                largest_index = r;
            }
            if (largest_index != i) {
                int tmp = harr[i];
                harr[i] = harr[largest_index];
                harr[largest_index] = tmp;
                MaxHeapify(largest_index);
            }
        }

        void buildMinHeap() {
            int i = parent(heap_size-1);
            for(; i>=0; i--) {
                MinHeapify(i);
            }
        }

        void MinHeapify(int i){
            // Go Down
            int l = left(i);
            int r = right(i);
            int smallest_index = i;
            if (l < heap_size && harr[l] < harr[smallest_index]) {
                smallest_index = l;
            }
            if (r < heap_size && harr[r] < harr[smallest_index]) {
                smallest_index = r;
            }
            if (smallest_index != i) {
                int tmp = harr[i];
                harr[i] = harr[smallest_index];
                harr[smallest_index] = tmp;
                MinHeapify(smallest_index);
            }
        }

        void printHeap() {
            for(int i = 0; i < heap_size; i++){
                cout << harr[i] << ' ';
            }
        }

        void heapSort() {
            // 그냥 heap에서 시작해도 됨
            buildMaxHeap();
            int tmp;
            int n = heap_size-1;
            for (; n > 0; n--) {
                tmp = harr[0];
                harr[0] = harr[n];
                heap_size--;
                MaxHeapify(0);
                cout << tmp << " ";
            }
            cout << harr[0] << endl;
        }

        int maxHeapMaximum() {
            // 이미 max heap이어야 함
            if (heap_size < 1) {
                cout << "heap underflow";
                return -1;
            }
            return harr[0];
        }

        int minHeapMinimum() {
            // 이미 min heap이어야 함
            if (heap_size < 1) {
                cout << "heap underflow";
                return -1;
            }
            return harr[0];
        }

        int maxHeapExtractMax() {
            // 이미 max heap이어야 함
            int max = maxHeapMaximum();
            harr[0] = harr[heap_size-1];
            heap_size--;
            MaxHeapify(0);
            return max;
        }

        int minHeapExtractMin() {
            int min = minHeapMinimum();
            harr[0] = harr[heap_size-1];
            heap_size--;
            MinHeapify(0);
            return min;
        }

        void maxHeapIncreaseKey(int index, int key){
            // 이미 max heap이어야 함
            if (key < harr[index]) {
                cout << "new key is smaller than current key ";
                return;
            }
            harr[index] = key;
            int i = index;
            int tmp;
            while (i > 0 && harr[i] > harr[parent(i)]) {
                tmp = harr[parent(i)];
                harr[parent(i)] = harr[i];
                harr[i] = tmp;
                i = parent(i);
            }
        }

        void minHeapDecreaseKey(int index, int key) {
            // 이미 min heap이어야 함
            if (key < harr[index]) {
                cout << "new key is larger than current key ";
                return;
            }
            harr[index] = key;
            int i = index;
            int tmp;
            while(i > 0 && harr[i] < harr[parent(i)]) {
                tmp = harr[parent(i)];
                harr[parent(i)] = harr[i];
                harr[i] = tmp;
                i = parent(i);
            }
        }

        void maxHeapDecreaseKey(int index, int key){
            // 이미 max heap이어야 함
            if (key > harr[index]) {
                cout << "new key is larger than currnt key ";
                return;
            }
            harr[index] = key;
            MaxHeapify(index);
        }

        void minHeapIncreaseKey(int index, int key) {
            // 이미 min heap이어야 함
            if (key < harr[index]) {
                cout << "new key is smaller than current key ";
                return;
            }
            harr[index] = key;
            MinHeapify(index);
        }

        void maxHeapInsert(int k){
            // 이미 max heap이어야 함
            if (heap_size == capacity) {
                cout << "heap overflow";
                return;
            }
            heap_size++;

            // version 1
            // harr[heap_size-1] = -1;
            // maxHeapIncreaseKey(heap_size-1, k);

            // version 2
            int i = heap_size - 1;
            harr[i] = k;
            while (i != 0 && harr[parent(i)] < harr[i]) {
                int tmp = harr[parent(i)];
                harr[parent(i)] = harr[i];
                harr[i] = tmp;
                i = parent(i);
            }
        }

        void minHeapInsert(int k){
            // 이미 min heap이어야 함
            if (heap_size == capacity) {
                cout << "heap overflow";
                return;
            }
            heap_size++;

            // version 1
            // harr[heap_size-1] = 100000000000000;
            // maxHeapDecreaseKey(heap_size-1, k);

            // version 2
            int i = heap_size - 1;
            harr[i] = k;
            while (i != 0 && harr[parent(i)] > harr[i]) {
                int tmp = harr[parent(i)];
                harr[parent(i)] = harr[i];
                harr[i] = tmp;
                i = parent(i);
            }
        }
};

int main(void) {
    // Heap MH(11);

    // MH.insertKey(4);
    // MH.insertKey(1);
    // MH.insertKey(3);
    // MH.insertKey(2);
    // MH.insertKey(16);

    // MH.insertKey(9);
    // MH.insertKey(10);
    // MH.insertKey(14);
    // MH.insertKey(8);
    // MH.insertKey(7);

    // MH.buildMaxHeap();
    // MH.printHeap();
    // cout << endl;
    // MH.maxHeapIncreaseKey(4, 22);
    // // MH.maxHeapDecreaseKey(0, 5);
    // MH.printHeap();
    // cout << endl;
    // MH.maxHeapInsert(15);
    // MH.printHeap();
    // cout << endl;

    Heap a(5);
    a.maxHeapInsert(1);
    a.maxHeapInsert(2);
    a.maxHeapInsert(8);
    a.maxHeapIncreaseKey(2, 16);
    cout << a.maxHeapMaximum() << " ";
    a.maxHeapInsert(50);
    a.maxHeapIncreaseKey(1, 9);
    cout << a.maxHeapMaximum() << " ";
    a.maxHeapInsert(4);

    return 0;
}