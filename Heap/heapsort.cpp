// HEAP SORT USING MIN HEAP
// -----------------------
// Steps:
// 1) Build Min Heap from array
// 2) Repeatedly:
//    - Swap root with last element
//    - Reduce heap size
//    - Heapify DOWN from root
//
// Result:
// Sorted array in DESCENDING order
// (Use Max Heap for ascending order)

class HeapSort {
public:
    vector<int> heap;
    int heapSize;

    // HEAPIFY DOWN (RECURSIVE)
    void heapifyDown(int i) {

        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        // Compare with left child
        if (left < heapSize && heap[left] < heap[smallest])
            smallest = left;

        // Compare with right child
        if (right < heapSize && heap[right] < heap[smallest])
            smallest = right;

        // If violation found
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // BUILD MIN HEAP
    void buildHeap(vector<int>& arr) {

        heap = arr;
        heapSize = heap.size();

        // Start from last non-leaf node
        for (int i = (heapSize / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // HEAP SORT
    void heapSort(vector<int>& arr) {

        // Step 1: Build Heap
        buildHeap(arr);

        // Step 2: Extract elements one by one
        for (int i = heapSize - 1; i > 0; i--) {

            // Move min element to end
            swap(heap[0], heap[i]);

            // Reduce heap size
            heapSize--;

            // Restore heap property
            heapifyDown(0);
        }

        // Copy sorted data back
        arr = heap;
    }
};

// HeapSort = buildHeap → swap root → size-- → heapifyDown

// Build Heap : O(N)
// Heapify    : O(log N)
// Heap Sort  : O(N log N)
// Space      : O(1)
