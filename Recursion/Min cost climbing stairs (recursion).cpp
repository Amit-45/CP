class Solution {
public:
    int rec(int level, vector<int>& n) {
        // Pruning
        if (level >= n.size()) {
            return 0;
        }

        // Base case
        if (level == n.size() - 1) {
            return n[level];
        }

        // Choose the current step and continue
        int choice1 = n[level] + rec(level + 1, n);
        int choice2 = n[level] + rec(level + 2, n);

        return min(choice1, choice2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int choice1 = rec(0, cost);
        int choice2 = rec(1, cost); 

        return min(choice1, choice2);
    }
};
