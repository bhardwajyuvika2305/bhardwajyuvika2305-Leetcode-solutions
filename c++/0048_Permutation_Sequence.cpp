/* The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence. */

// Solution :-

#include <string>
#include <vector>

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        // Precompute (n-1)! and fill numbers array [1, 2, ..., n]
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        // Convert k to 0-based indexing
        k = k - 1;
        string result = "";
        
        while (true) {
            // Pick digit at index k / fact
            int idx = k / fact;
            result += to_string(numbers[idx]);
            numbers.erase(numbers.begin() + idx);
            
            if (numbers.empty()) {
                break;
            }
            
            // Update k and new factorial block size
            k = k % fact;
            fact = fact / numbers.size();
        }
        
        return result;
    }
};