class Solution {

void solve(vector<int> &nums, int index, vector<int> &out, vector<int> &ans, int &subsetSum)
    {
        if (index >= nums.size())
        {
            ans.push_back(subsetSum); // Store the subset sum
            return;
        }
        solve(nums, index + 1, out, ans, subsetSum); // Exclude current number
        out.push_back(nums[index]);
        subsetSum += nums[index];
        solve(nums, index + 1, out, ans, subsetSum); // Include current number
        subsetSum -= nums[index];
        out.pop_back(); // Backtrack
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        vector<int> out;
        int subsetSum = 0;
        int index = 0;
        solve(arr, index, out, ans, subsetSum);
        return ans;
    }
};
