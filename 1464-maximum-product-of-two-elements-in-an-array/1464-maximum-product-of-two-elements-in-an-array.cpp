class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = INT_MIN, s_larg = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= largest) {
                s_larg = largest;
                largest = nums[i];
                

            } else {
                if (nums[i] != largest && nums[i] > s_larg) {
                    s_larg = nums[i];
                }
            }
        }

        return (largest-1)*(s_larg-1);
    }
};