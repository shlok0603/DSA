class Solution {
public:
    bool possible(vector<int>& arr, int k, long long limit) {
        int students = 1;
        long long pages = 0;

        for (int x : arr) {
            if (pages + x <= limit) {
                pages += x;
            } else {
                students++;
                pages = x;
                if (students > k)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        if (k > n)
            return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (possible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};