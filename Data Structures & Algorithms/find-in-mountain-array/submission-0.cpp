/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class MountainArray {
 * public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    // Find peak index
    int findPeak(MountainArray &mountainArr) {
        int low = 0;
        int high = mountainArr.length() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }

    // Binary search in increasing half
    int searchLeft(MountainArray &mountainArr, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);

            if (val == target) {
                return mid;
            }
            else if (val < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }

    // Binary search in decreasing half
    int searchRight(MountainArray &mountainArr, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);

            if (val == target) {
                return mid;
            }
            else if (val > target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int peak = findPeak(mountainArr);

        // Search left side first
        int leftAns = searchLeft(mountainArr, target, 0, peak);

        if (leftAns != -1) {
            return leftAns;
        }

        // Search right side
        return searchRight(mountainArr, target, peak + 1,
                           mountainArr.length() - 1);
    }
};