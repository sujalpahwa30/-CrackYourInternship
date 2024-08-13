class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int, int> p;
        int sum = 0;
        int len = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (arr[i] == 0 && len == 0)
                len = 1;
            if (sum == 0)
                len = i + 1;

            if (p.find(sum) != p.end()) {
                len = max(len, i - p[sum]);
            } else {
                p[sum] = i;
            }
        }
        return len;
    }
};
