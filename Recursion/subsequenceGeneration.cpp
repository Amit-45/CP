class Solution {

private:
    void generateSubsets(int index, const vector<int>& nums, vector<int>& curr, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(curr);
            return;
        }
        
       
        generateSubsets(index + 1, nums, curr, result); //Not take

        curr.push_back(nums[index]); //Take
        generateSubsets(index + 1, nums, curr, result); //Takke
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

// --------------------------------------------------------------------

// void printF(int ind, vector<int> &ds, int arr[], int n) {
//     if (ind == n) {
//         for (auto it : ds) {
//             cout << it << " ";
//         }
//         cout << endl;
//         return;
//     }

//     // Pick the particular index into the subsequence
//     ds.push_back(arr[ind]);
//     printF(ind + 1, ds, arr, n);
//     ds.pop_back();

//     // Do not pick, or not take condition, skip this element
//     printF(ind + 1, ds, arr, n);
// }

// int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     int arr[] = {3, 1, 2};
//     int n = 3;
//     vector<int> ds;
//     printF(0, ds, arr, n);

//     return 0;
// }
