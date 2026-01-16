// INSERT NODE IN MIN HEAP
// ----------------------
// Property:
// Parent value <= child value
//
// Steps:
// 1) Insert new node at the end
// 2) Heapify UP until heap property is restored

class MinHeap {
public:
    vector<int> heap;

    void insert(int val) {

        // Step 1: Insert value at the end of heap
        heap.push_back(val);

        // Step 2: Heapify UP
        int i = heap.size() - 1;

        while (i > 0) {

            // Find parent index
            int parent = (i - 1) / 2;

            // If parent is greater, swap
            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;   // move up
            }
            else {
                // Heap property satisfied
                break;
            }
        }
    }
};

// Insert at end → compare with parent → swap until min heap property holds

// Insert 3 into [5, 7, 9]
// Push → [5, 7, 9, 3]
// Heapify up → [3, 5, 9, 7]

// Time: O(log N)
// Space: O(1)
