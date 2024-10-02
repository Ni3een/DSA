class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> mp={'a','e','i','o','u','A','E','I','O','U'};
        int n=s.length();
        int i=0,j=n/2,cntleft=0,cntright=0;
        while(i<n/2 && j<n){
            if(mp.find(s[i])!=mp.end()) cntleft++;
            if(mp.find(s[j])!=mp.end()) cntright++;
            i++;
            j++;
        }
        if(cntleft==cntright) return true;
        else return false;
    }
};