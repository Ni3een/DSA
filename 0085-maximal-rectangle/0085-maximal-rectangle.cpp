class Solution {  
public:  
    vector<int> nextSmallest(vector<int> &v, int m) {  
        stack<int> st;  
        vector<int> res(m);  
        for (int i = m - 1; i >= 0; i--) {  
            while (!st.empty() && v[st.top()] >= v[i]) {  
                st.pop();  
            }  
            res[i] = st.empty() ? m : st.top();  
            st.push(i);  
        }  
        return res;  
    }  

    vector<int> previousSmallest(vector<int> &v, int m) {  
        stack<int> st;  
        vector<int> res(m);  
        for (int i = 0; i < m; i++) {  
            while (!st.empty() && v[st.top()] >= v[i]) {  
                st.pop();  
            }  
            res[i] = st.empty() ? -1 : st.top();  
            st.push(i);  
        }  
        return res;  
    }  

    int maxRectangle(vector<int> &v, int m) {  
        vector<int> PSE = previousSmallest(v, m);  
        vector<int> NSE = nextSmallest(v, m);  
        int maxArea = 0;  

        for (int i = 0; i < m; i++) {  
            int area = v[i] * (NSE[i] - PSE[i] - 1);  
            maxArea = max(maxArea, area);  
        }  
        return maxArea;  
    }  

    int maximalRectangle(vector<vector<char>>& matrix) {  
        if (matrix.empty() || matrix[0].empty()) {  
            return 0;  
        }  

        int n = matrix.size();  
        int m = matrix[0].size();  
        vector<int> v(m, 0);  
        int maxArea = 0;  

        for (int i = 0; i < n; i++) {  
            for (int j = 0; j < m; j++) {  
                if (matrix[i][j] == '0') {  
                    v[j] = 0;  // Reset the height counter  
                } else {  
                    v[j]++;  // Increment the height  
                }  
            }  
            maxArea = max(maxArea, maxRectangle(v, m)); // Calculate max rectangle for the current row  
        }  
        return maxArea;  
    }  
};