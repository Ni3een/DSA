class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<int> suffix(n);
        suffix[n-1]=satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=satisfaction[i]+suffix[i+1];
        }
        // for find index
        int ind=-1;
        for(int i=0;i<n;i++){
            if(suffix[i]>=0){
                ind=i;
                break;
            }
        }
        if(ind==-1) return 0;
        // for multiplying 
        int k=1;
        int maxisum=0;
        for(int i=ind;i<n;i++){
            maxisum=maxisum+(satisfaction[i]*k);
            k++;
        }
        return maxisum;

    }
};