// MIN HEAPIFY (DOWN) - RECURSIVE
// -----------------------------
// Use when heap property is disturbed at index i
// Example:
// - After deleting root
// - After replacing root with last element
//
// Goal:
// Push element DOWN recursively until min-heap property is restored
////****Used IN ADD ELEMENT***** *////
void heapifyDown(vector<int>& heap, int i) {

    int n = heap.size();

    // Assume current index is smallest
    int smallest = i;

    // Calculate children indices
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

        // Swap parent with smallest child
        swap(heap[i], heap[smallest]);

        // Recursively fix affected subtree
        heapifyDown(heap, smallest);
    }

    // Else heap property is already satisfied → stop recursion
}


// Heapify = compare parent with children → swap with smallest → repeat

// Time: O(log N)
// Space: O(log N) recursion stack
