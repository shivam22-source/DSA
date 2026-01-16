// BUILD MIN HEAP (FROM ARRAY)
// ---------------------------
// Idea:
// Convert an unsorted array into a Min Heap
//
// Logic:
// - Leaf nodes are already heaps
// - Start heapify from last non-leaf node
// - Heapify DOWN recursively
//
// Last non-leaf index = (n / 2) - 1

class MinHeap {
public:
    vector<int> heap;

    // HEAPIFY DOWN (RECURSIVE)
    void heapifyDown(int i) {

        int n = heap.size();
        int smallest = i;

        int left = 2*i + 1;
        int right = 2*i + 2;

        // Compare with left child
        if (left < n && heap[left] < heap[smallest])
            smallest = left;

        // Compare with right child
        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        // If heap property violated
        if (smallest != i) {
            swap(heap[i], heap[smallest]);

            // Recursively fix affected subtree
            heapifyDown(smallest);
        }
    }

    // BUILD HEAP
    // -----------
    // Converts array into Min Heap in O(N)
    void buildHeap(vector<int>& arr) {

        // Copy array into heap
        heap = arr;

        int n = heap.size();

        // Start from last non-leaf node     // last node =size-1=>i-1->parent=>n-2;
        for (int i = (n / 2) - 1; i >= 0; i--) {

            // Fix heap property downward
            heapifyDown(i);
        }
    }
};
