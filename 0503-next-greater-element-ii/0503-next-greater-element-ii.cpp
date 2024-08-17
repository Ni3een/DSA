class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ans;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                int nge= st.empty()?-1:st.top();
                ans.push_back(nge);
            }
            st.push(nums[i%n]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};