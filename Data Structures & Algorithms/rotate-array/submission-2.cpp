class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());//k->n-1
        reverse(nums.begin(),nums.begin()+k);//0->k
    }
};