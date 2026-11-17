
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());//sort an array 

        int n = nums.size();
        vector<vector<int>> res;//result array 
        int a = 0;
        for ( a = 0; a < n - 3; a++) {

            // Skip duplicate first elements
            if (a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }
            for (int b = a + 1; b < n - 2; b++) {

                // Skip duplicate second elements
                if (b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }

                int c = b + 1;
                int d = n - 1;

                while (c < d) {

                    long long sum = (long long)nums[a] + nums[b]
                                  + nums[c] + nums[d];

                    if (sum == target) {

                        res.push_back({
                            nums[a], nums[b], nums[c], nums[d]
                        });

                        c++;
                        d--;

                        // Skip duplicate third elements
                        while (c < d && nums[c] == nums[c - 1]) {
                            c++;
                        }

                        // Skip duplicate fourth elements
                        while (c < d && nums[d] == nums[d + 1]) {
                            d--;
                        }
                    }
                    else if (sum < target) {
                        c++;
                    }
                    else {
                        d--;
                    }
                }
            }
        }

        return res;
    }
};
