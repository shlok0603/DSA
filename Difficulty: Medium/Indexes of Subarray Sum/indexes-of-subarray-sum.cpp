class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {

        int n = arr.size();

        int left = 0;
        long long sum = 0;

        for(int right = 0; right < n; right++) {

            sum += arr[right];

            while(sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }

            if(sum == target) {
                return {left + 1, right + 1};
            }
        }

        return {-1};
    }
};