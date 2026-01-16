// If problem is with PARENT → use heapifyDown
// If problem is with CHILD  → use heapifyUp


📌 REAL CODE DECISION TABLE
Operation	Disturbed Node	Heapify
insert	child	UP ⬆️
decreaseKey	child	UP ⬆️
extractMin	root	DOWN ⬇️
buildHeap	parents	DOWN ⬇️
replace root	root	DOWN ⬇️

// Add something → heapifyUp
// Remove something → heapifyDown
