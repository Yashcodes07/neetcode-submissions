class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // 1. Remove indices outside the window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Insert current index
            dq.push_back(i);

            // 4. Store maximum once window size reaches k
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};