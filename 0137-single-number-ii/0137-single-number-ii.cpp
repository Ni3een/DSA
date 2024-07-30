class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int bit=0;bit<=31;bit++){
            int count0=0;
            int count1=0;
            for(int &num:nums){
                if((num&(1<<bit))==0){
                    count0++;
                }
                else{
                    count1++;
                }
            }
            if(count1%3==1){
                res=(res|(1<<bit));
            }
        }
        return res;
    }
};