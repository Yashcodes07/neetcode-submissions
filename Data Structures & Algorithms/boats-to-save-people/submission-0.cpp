class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int i = 0;
        int j = n-1;
        int res = 0;
        sort(people.begin(),people.end());
        while(i<=j){
            int sum = people[i]+ people[j];
            if(sum <= limit){
             i++;
             j--;
            }
            else if(sum > limit){
                j--;
            }
            res++;
        }
        return res;
    }
};