class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for (auto& entry : freq) {
            maxHeap.push({entry.second, entry.first});
        }
        string result;
        pair<int, char> prev = {-1, '#'};
        while (!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();
            result += current.second;
            if (prev.first > 0) {
                maxHeap.push(prev);
            }
            current.first--;
            prev = current;
        }
        if (result.length() != s.length()) {
            return "";
        }
        return result;
    }
};