class Solution {  
public:  
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {  
        int n = nums.size();  
        deque<int> dq;  
        vector<int> res;  

        for (int i = 0; i < n; i++) {  
            // Remove indices that are out of the current window  
            if (!dq.empty() && dq.front() == i - k) {  
                dq.pop_front();  
            }  
            // Remove indices of smaller elements as they are not useful  
            while (!dq.empty() && nums[dq.back()] < nums[i]) {  
                dq.pop_back();  
            }  
            // Add current index to the deque  
            dq.push_back(i);  
            // If we have filled at least k elements, add the maximum to the result  
            if (i >= k - 1) {  
                res.push_back(nums[dq.front()]);  
            }  
        }  
        return res;  
    }  
};