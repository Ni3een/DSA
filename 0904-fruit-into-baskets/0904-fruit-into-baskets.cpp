class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() == 1) return 1;
        if (fruits.size() == 2) return 2; // Return 2 regardless of whether the elements are the same or different
        
        int i = 0, j = 0, maxi = 1;
        unordered_map<int, int> mp;
        
        while (j < fruits.size()) {
            mp[fruits[j]]++;
            if (mp.size() <= 2) {
                maxi = max(maxi, j - i + 1);
                ++j;
            } else {
                while (mp.size() > 2) {
                    mp[fruits[i]]--;
                    if (mp[fruits[i]] == 0) {
                        mp.erase(fruits[i]);
                    }
                    ++i;
                }
                ++j;
            }
        }
        return maxi;
    }
};
