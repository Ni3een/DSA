class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // min heap as a key value pair 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=i+1;j<nums.size();j++){
            if(nums[i]==nums[j]){
                cnt++;
            }
            }
            pq.push({cnt,nums[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};