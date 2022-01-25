 /// qustion link -> https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1#
 /*
 Input:
N = 8
nums = {1,1,2,2,3,3,3,4}
k = 2
Output: {3, 2}
Explanation: Elements 1 and 2 have the
same frequency ie. 2. Therefore, in this
case, the answer includes the element 2
as 2 > 1.
 */
 vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> m;
        vector<int> v;
        priority_queue<pair<int,int>> p;
        for(int i =0; i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            p.push({i.second,i.first});
        }
        if(p.size() == 0){
            return v;
        }
        while(k--){
            v.push_back(p.top().second);
            p.pop();
        }
        return v;
    }
