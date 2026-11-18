class Solution {
public:
    int fun(vector<int>& nums , int mid){
        int subarrays = 1;
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n ; i++){
            if(sum+nums[i]<=mid){
                sum = sum+nums[i];
            }
            else{
                subarrays++;
                sum = nums[i];
            }
        }
        return subarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int res = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            int required = fun(nums,mid);
            if(required > k){
                low = mid+1;
            }
            else{
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};