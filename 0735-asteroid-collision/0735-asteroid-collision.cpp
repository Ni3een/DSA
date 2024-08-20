class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int &a:asteroids){
            while(!st.empty() && a<0 && st.top()>0){ // collision
        
        int sum=a+st.top();
        if(sum<0){
             st.pop();
        }
        else if(sum>0){
             a=0;
             } // break the loop
        else{ 
            st.pop(); 
            a=0;
        }
            }
        if(a!=0){
        st.push(a);
    }
    }
    int s=st.size();
    vector<int> res(s);
    int i=s-1;
    while(!st.empty()){
        res[i]=st.top();
        st.pop();
        i--;
    }
    return res;
    }
};