class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size() - 1;

        while (high - low + 1 > k) {
            if (abs(arr[low] - x) > abs(arr[high] - x)) {
                low++;   // Remove the left element
            } 
            else {
                high--;  // Remove the right element
            }
        }

        vector<int> res;
        for (int i = low; i <= high; i++) {
            res.push_back(arr[i]);
        }

        return res;
    }
};