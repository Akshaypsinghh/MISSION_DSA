#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k == n
        if (k == n) return *max_element(nums.begin(), nums.end());

        // Frequency count
        vector<int> count(51, 0); // since nums[i] <= 50
        for (int num : nums) count[num]++;

        // Case 2: k == 1
        if (k == 1) {
            int ans = -1;
            for (int num : nums) {
                if (count[num] == 1) ans = max(ans, num);
            }
            return ans;
        }

        // Case 3: 1 < k < n
        int ans = -1;
        if (count[nums[0]] == 1) ans = max(ans, nums[0]);
        if (count[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);
        return ans;
    }
};
