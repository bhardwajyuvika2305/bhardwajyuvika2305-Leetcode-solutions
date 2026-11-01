/*Given a string s that contains parentheses and letters, 
remove the minimum number of invalid parentheses to make the input string valid.
Return a list of unique strings that are valid with the minimum number of removals. 
You may return the answer in any order.*/

// Solution :-

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

class Solution {
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int levelSize = q.size();
            unordered_set<string> currentLevelValid;

            for (int i = 0; i < levelSize; ++i) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    currentLevelValid.insert(curr);
                    found = true;
                }

                if (found) continue; // Skip generating next children if we found valid ones at this depth

                // Generate all possible states by removing one parenthesis
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    string nextStr = curr.substr(0, j) + curr.substr(j + 1);
                    if (visited.find(nextStr) == visited.end()) {
                        visited.insert(nextStr);
                        q.push(nextStr);
                    }
                }
            }

            if (found) {
                result.assign(currentLevelValid.begin(), currentLevelValid.end());
                break;
            }
        }

        return result;
    }
};
