class Solution {  
public:  
    vector<int> getnsl(vector<int> &arr, int n) {  
        stack<int> st;  
        vector<int> res(n);  
        for (int i = 0; i < n; i++) {  
            while (!st.empty() && arr[st.top()] >= arr[i]) {  
                st.pop();  
            }  
            // If stack is empty, it means there's no smaller on the left  
            res[i] = st.empty() ? -1 : st.top();  
            st.push(i);  
        }  
        return res;  
    }  
    
    vector<int> getnsr(vector<int> &arr, int n) {  
        stack<int> st;  
        vector<int> res(n);  
        for (int i = n - 1; i >= 0; i--) {  
            while (!st.empty() && arr[st.top()] >= arr[i]) {  
                st.pop();  
            }  
            // If stack is empty, it means there's no smaller on the right  
            res[i] = st.empty() ? n : st.top();  
            st.push(i);  
        }  
        return res;  
    }  
    
    int sumSubarrayMins(vector<int>& arr) {  
        int n = arr.size();  
        vector<int> NSL = getnsl(arr, n);  
        vector<int> NSR = getnsr(arr, n);  
        int m = 1e9 + 7;  
        long long sum = 0;  
        for (int i = 0; i < n; i++) {  
            long long lelement = i - NSL[i];   // Number of subarrays ending at `i` where `arr[i]` is minimum  
            long long rigelement = NSR[i] - i;  // Number of subarrays starting at `i` where `arr[i]` is minimum  
            
            long long totalways = lelement * rigelement;  
            long long totalsum = arr[i] * totalways;  
            sum = (sum + totalsum) % m;  
        }  
        return sum;  
    }  
};  