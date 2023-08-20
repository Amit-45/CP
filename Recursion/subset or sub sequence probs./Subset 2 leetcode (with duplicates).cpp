class Solution {
public:
    
    void backTrack(vector<int>&nums,int idx,vector<vector<int>>&ans,vector<int>curr,set<vector<int>>&hash,int n)
    {
        if(idx==n)
        {
            if(hash.find(curr)==hash.end())
            {
                hash.insert(curr);
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back(nums[idx]);
        backTrack(nums,idx+1,ans,curr,hash,n);
        curr.pop_back();
        backTrack(nums,idx+1,ans,curr,hash,n);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        set<vector<int>>hash;
        backTrack(nums,0,ans,curr,hash,n);
        return ans;
    }
};
