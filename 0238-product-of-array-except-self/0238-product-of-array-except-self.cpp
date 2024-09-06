class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int> prefixpr(n);
        vector<int> suffixpro(n);
        int product=nums[0];
        prefixpr[0]=1;
        for(int i=1;i<n;i++){
             prefixpr[i]=product;
            product=product*nums[i];
        }
        product=nums[n-1];
        suffixpro[n-1]=1;
        for(int i=n-2;i>=0;i--){
              suffixpro[i]=product;
            product=product*nums[i];
        }
        for(int i=0;i<n;i++){
          prefixpr[i]=prefixpr[i]*suffixpro[i];
        }
        return prefixpr;

    }
};