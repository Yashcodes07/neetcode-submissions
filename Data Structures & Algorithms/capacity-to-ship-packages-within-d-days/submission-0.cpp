class Solution {
public:
int fun(vector<int>& weights, int capacity) {
    int days = 1;
    int load = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (load + weights[i] <= capacity) {
            load += weights[i];
        }
        else {
            days++;
            load = weights[i];
        }
    }

    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int res = 0;

        while(low<=high){
            int guess = low + (high-low)/2;
            int capacity = fun(weights, guess);
            if(capacity > days ){
                low = guess + 1;
            }
            else{
                res = guess ;
                high = guess -1;
            }
        }
        return res;
    }
};