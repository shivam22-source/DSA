✅ HEAP – 1 PAGE REVISION CHECKLIST
🧠 HEAP BASICS

⬜ Complete Binary Tree

⬜ Stored using array

⬜ Parent index = (i-1)/2

⬜ Left child = 2*i+1

⬜ Right child = 2*i+2

🔼 MIN HEAP vs MAX HEAP

⬜ Min Heap → smallest element at root

⬜ Max Heap → largest element at root

⬜ Only parent–child order, not sorted array

🔁 HEAPIFY RULE (MOST IMPORTANT)
ADD / DECREASE  → heapify UP
REMOVE / REPLACE → heapify DOWN

🔼 HEAPIFY UP

⬜ Used after insert

⬜ Used after decreaseKey

⬜ Problem at child

⬜ Compare with parent

⬜ Move upward

🔽 HEAPIFY DOWN

⬜ Used after extractMin / extractMax

⬜ Used in buildHeap

⬜ Problem at root / parent

⬜ Compare with children

⬜ Move downward

🏗 BUILD HEAP

⬜ Start from (n/2) - 1

⬜ Go till index 0

⬜ Use heapifyDown

⬜ Time complexity = O(N)

❌ DELETE (MIN HEAP)

⬜ Delete always happens at root

⬜ Replace root with last element

⬜ Reduce size

⬜ Heapify DOWN

🗑 DELETE AT ANY INDEX

⬜ Use decreaseKey(i, -∞)

⬜ Heapify UP

⬜ Then extractMin

🔢 HEAP SORT

⬜ Build heap

⬜ Swap root with last

⬜ Reduce heap size

⬜ Heapify DOWN

⬜ Max Heap → ascending

⬜ Min Heap → descending

🧩 TOP-K PATTERN

⬜ Use Min Heap

⬜ Keep heap size = k

⬜ If size > k → pop

⬜ Root = answer

🧩 CLOSEST / KTH PATTERN

⬜ Use Max Heap

⬜ Push (distance, value)

⬜ Pop farthest when size > k

📦 STL PRIORITY_QUEUE

⬜ Default = Max Heap

⬜ Min Heap:

priority_queue<int, vector<int>, greater<int>>

⏱ TIME COMPLEXITY

⬜ Insert → O(log N)

⬜ Delete → O(log N)

⬜ Build Heap → O(N)

⬜ Get Min/Max → O(1)

🎯 INTERVIEW ONE-LINERS

⬜ “Heap is used when we need repeated min/max efficiently”

⬜ “Heapify up fixes insertion issues”

⬜ “Heapify down fixes deletion issues”

✅ FINAL CHECK

If you can:

Explain heapify up vs down in words

Decide min vs max heap quickly

Solve Top-K / Kth / Ropes

👉 HEAP CHAPTER COMPLETED ✅