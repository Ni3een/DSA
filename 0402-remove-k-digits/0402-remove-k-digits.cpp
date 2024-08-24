class Solution {
public:
    string removeKdigits(string num, int k) {
        string res=""; // as a stack kaam krega   // pop_back()->pop() in stack.. back()->top() in stack
        int n=num.length();
        for(int i=0;i<n;i++){
            while(res.length() >0 && res.back()>num[i] && k>0){
                res.pop_back();
                k--;
            }
            if(res.length()>0 || num[i]!='0'){ // agr age wle 0 hai toh consider mt kro
                res.push_back(num[i]);
            }
        }
            while(res.length()>0 && k>0){ // agr mera res sort hua toh
                res.pop_back();
                k--;
            }
            if(res=="") return "0";
        
        return res;
    }
    
};