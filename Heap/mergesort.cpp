class data {
public:
    int val, apos, vpos;

    data(int v, int ap, int vp) {
        val = v;
        apos = ap;
        vpos = vp;
    }
};

struct mycomp {
    bool operator()(const data &d1, const data &d2) {
        return d1.val > d2.val;   // min heap
    }
};

class Solution {
public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {

        vector<int> ans;
        int k = mat.size();

        // Min heap
        priority_queue<data, vector<data>, mycomp> pq;

        // Step 1: push first element of each array
        for (int i = 0; i < k; i++) {
            pq.push(data(mat[i][0], i, 0));
        }

        // Step 2: process heap
        while (!pq.empty()) {

            data d = pq.top();
            pq.pop();

            ans.push_back(d.val);

            int ap = d.apos;
            int vp = d.vpos;

            // Step 3: push next element from same array
            if (vp + 1 < mat[ap].size()) {
                pq.push(data(mat[ap][vp + 1], ap, vp + 1));
            }
        }

        return ans;
    }
};
//2D amtrix