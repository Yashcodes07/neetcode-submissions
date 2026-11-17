class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = 0;

        while (low <= high) {
            int guess = (low + high) / 2;

            if (target > nums[high]) {
                res = high + 1;
                break;
            }

            if (target < nums[low]) {
                res = low;
                break;
            }

            if (target == nums[guess]) {
                res = guess;
                break;
            }
            else if (target > nums[guess]) {
                low = guess + 1;
            }
            else {
                res = guess;
                high = guess - 1;
            }
        }

        return res;
    }
};