class Solution {
public:
    bool f(vector<int> &position,int m,int distance){
        int force=position[0];
        int cntball=1;
        for(int i=0;i<position.size();i++){
            if(position[i]-force>=distance){
                cntball++;
                force=position[i];
                if(cntball>= m) return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int left=1;
        int right=position[position.size()-1]-position[0];
        while(left<=right){
            int mid=(left+right)/2;
            if(f(position,m,mid)==true){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
            return right;
        
    }
};