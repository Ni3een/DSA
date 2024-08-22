class Solution {
public:
    vector<int> nextsmallest(vector<int> &heights,int n){
        stack<int> st;
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            res[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> previoussmallest(vector<int> &heights,int n){
        stack<int> st;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            res[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> PSE=previoussmallest(heights,n);
        vector<int> NSE=nextsmallest(heights,n);
        int area;
        int maxvalue=INT_MIN;
        for(int i=0;i<n;i++){
            area=heights[i]*(NSE[i]-PSE[i]-1);
            maxvalue=max(maxvalue,area);
        }
        return maxvalue;
    }
};