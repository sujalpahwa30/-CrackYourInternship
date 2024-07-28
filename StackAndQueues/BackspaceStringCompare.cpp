class Solution {
public:
    string build(string S) {
        stack<char> ans;
        for (char c : S) {
            if (c != '#') ans.push(c);
            else if (!ans.empty()) ans.pop();
        }
        string result;
        while (!ans.empty()) {
            result += ans.top();
            ans.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};