class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0,ind;
        vector<int> res;
        vector<int> counter(26,0),window(26,0);
        for(int i=0;i<p.length();i++){
            counter[p[i]-'a']++;
        }
        while(j<s.length()){
            window[s[j]-'a']++;
            if(j-i+1<p.length()){
                j++;
            }
            else if(j-i+1==p.length()){
                if(counter==window){
                    ind=i;
                    res.push_back(ind);
                  
                }
                counter[s[i]-'a']++;
                ++i;
                ++j;
            }
        }
        return res;
    }
};