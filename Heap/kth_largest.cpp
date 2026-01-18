// =======================================================
// KTH LARGEST ELEMENT IN AN ARRAY
// =======================================================

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------
// METHOD 1: BRUTE FORCE (SORTING)
// -------------------------------------------------------
// Idea:
// Sort array in descending order
// Return element at index k-1
//
// Time  : O(N log N)
// Space : O(1)

int kthLargest_bruteforce(vector<int>& nums, int k) {

    // Sort array in descending order
    sort(nums.begin(), nums.end(), greater<int>());

    // kth largest element
    return nums[k - 1];
}

// -------------------------------------------------------
// METHOD 2: MAX HEAP
// -------------------------------------------------------
// Idea:
// Build max heap of all elements
// Pop max element k-1 times
// Top element is kth largest
//
// Time  : O(N + k log N)
// Space : O(N)

int kthLargest_maxHeap(vector<int>& nums, int k) {

    // Build max heap
    priority_queue<int> pq;
    for (int x : nums)
        pq.push(x);

    // Remove k-1 largest elements
    while (k > 1) {
        pq.pop();
        k--;
    }

    // Top is kth largest
    return pq.top();
}

// -------------------------------------------------------
// METHOD 3: MIN HEAP (OPTIMAL)
// -------------------------------------------------------
// Idea:
// Maintain min heap of size k
// Push elements
// If size > k → pop smallest
// Root of heap is kth largest
//
// Time  : O(N log K)
// Space : O(K)

int kthLargest_minHeap(vector<int>& nums, int k) {

    // Min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : nums) {

        pq.push(x);

        // Keep heap size equal to k
        if (pq.size() > k)
            pq.pop();
    }

    // Root is kth largest
    return pq.top();
}


// Brute  : sort
// MaxHeap: remove k-1 largest
// MinHeap: keep heap size = k
