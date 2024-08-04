class Solution {
public:
    bool f(vector<int> &nums,long long int threshold,long long int divisor){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+ceil((double)nums[i]/(double)divisor);
        }
        return sum<=threshold;
    }
    int maximum(vector<int> &nums){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=maximum(nums);
        while(left<=right){
             long long int mid=left+(right-left)/2;
            if(f(nums,threshold,mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};