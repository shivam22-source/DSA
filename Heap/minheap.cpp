// MIN HEAP IMPLEMENTATION (FROM SCRATCH)
// ------------------------------------
// Property:
// Parent value <= child values
//
// Indexing (0-based):
// Parent index  = (i - 1) / 2
// Left child    = 2*i + 1
// Right child   = 2*i + 2

class MinHeap {
public:
    vector<int> heap;

    // HEAPIFY UP (RECURSIVE)
    // ----------------------
    // Used after insertion
    // Fixes heap property from index i to root
    void heapifyUp(int i) {

        // Base case: reached root
        if (i == 0)
            return;

        int parent = (i - 1) / 2;

        // If parent is greater, swap and recurse upward
        if (heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            heapifyUp(parent);
        }
    }

    // HEAPIFY DOWN (RECURSIVE)
    // ------------------------
    // Used after deletion or replacement
    // Fixes heap property from index i downward
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

        // If parent is not smallest, swap and recurse
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // INSERT INTO MIN HEAP
    // --------------------
    // Steps:
    // 1) Insert element at the end
    // 2) Heapify UP recursively
    void insert(int val) {

        // Step 1: Insert at end
        heap.push_back(val);

        // Step 2: Fix heap upward
        heapifyUp(heap.size() - 1);
    }

    // GET MIN ELEMENT
    // ----------------
    // Root always contains minimum element
    int getMin() {

        if (heap.empty())
            return -1;

        return heap[0];
    }

    // REMOVE MIN ELEMENT
    // -------------------
    // Steps:
    // 1) Store root value
    // 2) Replace root with last element
    // 3) Remove last element
    // 4) Heapify DOWN recursively
    int extractMin() {

        if (heap.empty())
            return -1;

        int minVal = heap[0];

        // Move last element to root
        heap[0] = heap.back();
        heap.pop_back();

        // Restore heap property
        if (!heap.empty())
            heapifyDown(0);

        return minVal;
    }

    // CURRENT HEAP SIZE
    int size() {
        return heap.size();
    }

    // CHECK IF HEAP IS EMPTY
    bool isEmpty() {
        return heap.empty();
    }
};
