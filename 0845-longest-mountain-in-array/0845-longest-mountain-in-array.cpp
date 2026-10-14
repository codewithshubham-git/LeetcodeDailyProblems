
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int i = 0;

        while (i < n - 1) {
            // Skip equal elements
            while (i < n - 1 && arr[i] == arr[i + 1]) {
                i++;
            }

            int up = 0, down = 0;

            // Increasing part
            while (i < n - 1 && arr[i] < arr[i + 1]) {
                up++;
                i++;
            }

            // Decreasing part
            while (i < n - 1 && arr[i] > arr[i + 1]) {
                down++;
                i++;
            }

            // A valid mountain needs both parts
            if (up > 0 && down > 0) {
                ans = max(ans, up + down + 1);
            }
        }

        return ans;
    }
};
