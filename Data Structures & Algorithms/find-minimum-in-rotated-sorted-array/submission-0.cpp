
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = nums[0];

        while (low <= high) {
            int guess = low + (high - low) / 2;

            if (nums[low] <= nums[guess]) {
                res = min(res, nums[low]);
                low = guess + 1;
            }
            else {
                res = min(res, nums[guess]);
                high = guess - 1;
            }
        }

        return res;
    }
};
