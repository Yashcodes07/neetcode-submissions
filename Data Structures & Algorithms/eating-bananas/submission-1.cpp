
class Solution {
public:
    long long fun(vector<int>& piles, int h, int speed) {
        long long  koko = 0;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            koko = koko + piles[i] / speed;

            if (piles[i] % speed) {
                koko++;
            }
            if (koko > h) return koko;
        }

        return koko;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = -1;

        while (low <= high) {
            int guess = low + (high - low) / 2;

            int hour = fun(piles, h, guess);

            if (hour > h) {
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
