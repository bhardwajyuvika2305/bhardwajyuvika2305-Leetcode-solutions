/*Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.*/

// Solution :-

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert integers to strings
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        
        // Custom sort using the concatenated comparison rule
        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b) {
            return (a + b) > (b + a);
        });
        
        // Edge case: if the highest number is "0", the whole array is zeroes
        if (strNums[0] == "0") {
            return "0";
        }
        
        // Concatenate all sorted string components
        string result = "";
        for (const string& s : strNums) {
            result += s;
        }
        
        return result;
    }
};
