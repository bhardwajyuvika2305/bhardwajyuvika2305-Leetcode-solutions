/* Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
*/

// Solution :-

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0, end = s.size() - 1;

        while (st < end) {
            swap(s[st], s[end]);
            st++;
            end--;
        }
    }
};