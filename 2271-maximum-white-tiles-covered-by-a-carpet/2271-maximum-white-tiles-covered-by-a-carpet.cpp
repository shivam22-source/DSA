class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int r = 0;
        int n = tiles.size();
        int ans = 0;
        sort(tiles.begin(), tiles.end());
        int covered = 0;
        for (int l = 0; l < tiles.size(); l++) {
            if (r < l)
                r = l;
            int carp_end = tiles[l][0] + carpetLen - 1;
            while (r < n && carp_end >= tiles[r][1]) {
                covered += (tiles[r][1] - tiles[r][0] + 1);
                r++;
            }
            int curr = covered;
            // partial cover
            if (r < n && tiles[r][0] <= carp_end) {
                curr += carp_end - tiles[r][0] + 1;
            }
            ans = max(ans, curr);

            if (l < r)
                covered -= (tiles[l][1] - tiles[l][0] + 1);
        }
        return ans;
    }
};