class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int> arr;
        for (int i = 0; i < points.size(); i++) {
            int y = points[i][0];
            arr.push_back(y);
        }
        sort(arr.begin(), arr.end());
        int count = 0;
        int i = 0;
        while (i < arr.size()) {
            int start = arr[i];

            count++;
            while (i < arr.size() && arr[i] <= start + w) {
                i++;
            }
        }
        return count;
    }
};