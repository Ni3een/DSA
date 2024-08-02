class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int ans=INT_MAX;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[left]<=nums[mid] && nums[mid]<=nums[right]){
                ans=min(ans,nums[left]);
                break;
            }
            if(nums[mid]>=nums[left]){ 
                ans=min(ans,nums[left]);
                left=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                right=mid-1;
            }
        }
        return ans;
    }
};
/* 1)phle toh mene check kiya ki mera left sort hai ya right sort hai
2) question mein input dekh k pta chlra hai ki mera left part sort hai jo bhi left part ka smallest element hai ushe ans mein daal do or right part mein check kro
yaani left=mid+1;*/