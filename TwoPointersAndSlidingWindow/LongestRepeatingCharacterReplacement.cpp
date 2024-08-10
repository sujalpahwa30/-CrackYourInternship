class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        int hash[26] = {0};
        int maxFreq = 0;
        while (r < n) {
            hash[s[r] - 'A']++;
            if (hash[s[r] - 'A'] > maxFreq) {
                maxFreq = hash[s[r] - 'A'];
            }
            if ((r-l+1) - maxFreq > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};