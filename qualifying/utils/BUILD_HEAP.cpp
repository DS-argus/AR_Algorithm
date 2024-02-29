#include <iostream>
#include <algorithm>

using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void maxHeapify(int arr[], int N, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        maxHeapify(arr, N, largest);
    }
}
 
// Function to build a Max-Heap from the given array
void buildMaxHeap(int arr[], int N)
{
    // Index of last non-leaf node
    int startIdx = (N / 2) - 1;
 
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        maxHeapify(arr, N, i);
    }
}

void minHeapify(int arr[], int N, int i)
{
    int smallest = i; // Initialize smallest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root
    if (l < N && arr[l] < arr[smallest])
        smallest = l;

    // If right child is smaller than smallest so far
    if (r < N && arr[r] < arr[smallest])
        smallest = r;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        minHeapify(arr, N, smallest);
    }
}

// Function to build a Min-Heap from the given array
void buildMinHeap(int arr[], int N)
{
    // Index of last non-leaf node
    int startIdx = (N / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        minHeapify(arr, N, i);
    }
}
 
// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int N)
{
    cout << "Array representation of Heap is:\n";
 
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver Code
int main()
{
    // Binary Tree Representation
    // of input array
    //             1
    //           /    \
    //         3        5
    //       /  \     /  \
    //     4      6  13  10
    //    / \    / \
    //   9   8  15 17
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
 
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    buildMaxHeap(arr, N);
    printHeap(arr, N);
   
    // Final Heap:
    //              17
    //            /    \
    //          15      13
    //         /  \     / \
    //        9     6  5   10
    //       / \   / \
    //      4   8 3   1


       // Initial array
    int arr2[] = {5, 3, 17, 10, 84, 19, 6, 22, 9};

    int N2 = sizeof(arr2) / sizeof(arr2[0]);

    buildMinHeap(arr2, N2);

    printHeap(arr2, N2);

    // Final Tree Representation (as a comment)
    //               3
    //           /       \
    //          5        6
    //        /  \      /  \
    //      9   84   19    17
    //     / \   
    //    22  9 

    return 0;
}