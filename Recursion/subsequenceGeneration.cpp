class Solution {

private:
    void generateSubsets(int index, const vector<int>& nums, vector<int>& curr, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(curr);
            return;
        }
        
       
        generateSubsets(index + 1, nums, curr, result); //Not take

        curr.push_back(nums[index]); 
        generateSubsets(index + 1, nums, curr, result); //Take
        curr.pop_back(); // Backtrack
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        generateSubsets(0, nums, curr, result);
        return result;
    }

};




