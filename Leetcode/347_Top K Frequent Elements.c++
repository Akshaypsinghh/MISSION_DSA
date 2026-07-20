class Solution {
public:
typedef pair<int,int>p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<p,vector<p>,greater<p>>pq;

        for(int num:nums){
            mp[num]++;
        }

        for(auto &it:mp){
            int value = it.first;
            int freq = it.second;

            pq.push({freq,value});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
return result;
    }
};