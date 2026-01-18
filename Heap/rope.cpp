class Solution {
public:
    int minCost(vector<int>& arr) {

        // Min heap using priority_queue
        priority_queue<int, vector<int>, greater<int>> pq;

        // Push all rope lengths into min heap
        for (int x : arr) {
            pq.push(x);
        }

        int cost = 0;

        // Continue until one rope remains
        while (pq.size() > 1) {

            // Take two smallest ropes
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            int sum = first + second;
            cost += sum;

            // Push combined rope back
            pq.push(sum);
        }

        return cost;
    }
};
