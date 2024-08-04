class Solution {
public:
    int f(vector<int> &weights,int days,int capacity){
        int day=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]<=capacity){
                load=load+weights[i];
            }
            else{
                day=day+1;
                load=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=accumulate(weights.begin(),weights.end(),0); 
        while(left<=right){
            int mid=(left+right)/2;
            int noofdays=f(weights,days,mid);
            if(noofdays<=days){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
     return left;
    }
};