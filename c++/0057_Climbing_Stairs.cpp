/*You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

// Solution :- 

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1; // ways(1)
        int prev1 = 2; // ways(2)
        int current = 0;

        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};