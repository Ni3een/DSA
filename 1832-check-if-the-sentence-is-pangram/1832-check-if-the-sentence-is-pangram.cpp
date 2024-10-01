class Solution {
public:
    bool checkIfPangram(string sentence) {
          int count=0;
    vector<int> res(26,0);
    for(auto &it:sentence){
        int ch= it-'a';
  
    if(res[ch]==0){
        res[ch]++;
        count++;
    }
    }
    if(count==26) return true;
    return false;
    }
};