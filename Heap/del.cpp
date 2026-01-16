// MIN HEAP : DELETE USING decreaseKey + extractMin
// -----------------------------------------------
// Idea:
// To delete a node at index i:
// 1) Decrease its value to -infinity
// 2) Heapify UP so it reaches root
// 3) Call extractMin to remove it

class MinHeap {
public:
    vector<int> heap;

    // HEAPIFY UP (RECURSIVE)
    void heapifyUp(int i) {

        // Base case: reached root
        if (i == 0)
            return;

        int parent = (i - 1) / 2;

        // If parent is greater, swap and recurse
        if (heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            heapifyUp(parent);
        }
    }

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

        // If violated, swap and recurse
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // INSERT ELEMENT
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // DECREASE KEY
    // ------------
    // Decrease value at index i to newVal
    // Then heapify UP to restore min heap
    void decreaseKey(int i, int newVal) {

        // Assign new smaller value
        heap[i] = newVal;

        // Fix heap upward
        heapifyUp(i);
    }

    // EXTRACT MIN
    // -----------
    // Removes root (minimum element)
    int extractMin() {

        if (heap.empty())
            return -1;

        int minVal = heap[0];

        // Replace root with last element
        heap[0] = heap.back();
        heap.pop_back();

        // Fix heap downward
        if (!heap.empty())
            heapifyDown(0);

        return minVal;
    }

    // DELETE NODE AT INDEX i
    // ----------------------
    // Uses decreaseKey + extractMin
    void deleteAtIndex(int i) {

        // Step 1: Decrease key to -infinity
        decreaseKey(i, INT_MIN);

        // Step 2: Remove root
        extractMin();
    }
};
