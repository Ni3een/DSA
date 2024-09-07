class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        vector<int> prefixno(n+1,0);
        prefixno[0]=0;
        for(int i=1;i<=n;i++){
            if(customers[i-1]=='N'){
                prefixno[i]=prefixno[i-1]+1;
            }
            else{
                prefixno[i]=prefixno[i-1];
            }
        }
        vector<int> suffixyes(n+1,0);
        suffixyes[n]=0;
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                suffixyes[i]=suffixyes[i+1]+1;
            }
            else{
            suffixyes[i]=suffixyes[i+1];
        }
        }
        int penalty=INT_MAX;
        int minhour=INT_MAX;
        for(int i=0;i<=n;i++){
           int currentpenalty=prefixno[i]+suffixyes[i];
           if(currentpenalty < penalty){
            penalty=currentpenalty;
            minhour=i;
           }

        }
        return minhour;
    }

};