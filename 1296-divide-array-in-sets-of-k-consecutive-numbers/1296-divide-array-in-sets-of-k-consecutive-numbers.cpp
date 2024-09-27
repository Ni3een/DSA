class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k==1) return false;
        map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        while(mp.size()){
            int p=mp.begin()->first;
            for(int i=0;i<k;i++){
                if(mp[p+i]>0){
                    mp[p+i]--;
                if(mp[p+i]==0){
                    mp.erase(p+i);
                }
            }
            else{
            return false;
            }
            }
        }
        return true;
    }
};