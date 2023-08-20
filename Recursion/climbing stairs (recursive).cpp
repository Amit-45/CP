class Solution {
public:
    int rec(int level, int n) {
        // Pruning
        if (level > n) {
            return 0;
        }
        // Base case
        if (level == n) {
            return 1;
        }
        // Looping part
        int ans = 0;
        for (int steps = 1; steps <= 2; steps++) {
            // Is valid choice
            if (level + steps <= n) {
                int ways = rec(level + steps, n);
                ans += ways;
            }
        }
        return ans;
    }

    int climbStairs(int n) {
        return rec(0, n);
    }
};
