class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto &it:s){
            mp[it]++;
        }
        int length=0;
        bool odd=0;
        for(auto &it:mp){
        if(it.second%2==0) length+=it.second;
        else{
            length+=it.second-1;
            odd=1;
        }
        }
        return length+odd;
    }
};