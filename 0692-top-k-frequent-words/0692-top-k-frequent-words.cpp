class Solution {
public:
    static bool compare(const pair<int, string> &a, const pair<int, string> &b) {
        if (a.first == b.first) {
            return a.second < b.second; // Lexicographical order
        }
        return a.first > b.first; // Higher frequency first
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto &word : words) {
            mp[word]++;
        }

        vector<pair<int, string>> freqWords;
        for (auto &entry : mp) {
            freqWords.push_back({entry.second, entry.first});
        }

        sort(freqWords.begin(), freqWords.end(), compare);

        vector<string> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(freqWords[i].second);
        }

        return res;
    }
};