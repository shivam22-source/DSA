class Solution {
public:
    int minLights(vector<int>& lights) {
        vector<int> diff(lights.size()+2,0);
        int n=lights.size();
        for (int i = 0; i < lights.size(); i++) {
            if (lights[i] != 0) {
                int left = max(0, i - lights[i]);
                int right = min(n - 1, i + lights[i]);
                diff[left]++;
                diff[right + 1]--;
            }
        }
        int ans = 0;
        int cov = 0;
        for (int i = 0; i < lights.size(); i++) {
            cov += diff[i];
            if (cov > 0) {
                continue;
            }
            ans++;

            int bulb = min(i + 1, n - 1);

            int left = max(0, bulb-1);
            int right = min(n - 1, bulb+1);
            diff[left]++;
            diff[right + 1]--;
            cov++;
        }
        return ans;
    }
};