class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<int> multiples(mx + 1, 0);

        // Count numbers divisible by each divisor
        for (int d = 1; d <= mx; d++) {
            for (int k = d; k <= mx; k += d)
                multiples[d] += freq[k];
        }

        vector<long long> gcdCnt(mx + 1);

        // Inclusion-exclusion
        for (int d = mx; d >= 1; d--) {
            long long c = multiples[d];
            gcdCnt[d] = c * (c - 1) / 2;

            for (int k = d + d; k <= mx; k += d)
                gcdCnt[d] -= gcdCnt[k];
        }

        vector<long long> prefix(mx + 1);
        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + gcdCnt[i];

        vector<int> ans;

        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = (l + r) / 2;
                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }

        return ans;
    }
};