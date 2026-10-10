/*Given a string s and a dictionary of strings wordDict,
 add spaces in s to construct a sentence where each word is a valid dictionary word. 
Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.*/

// Solution :- 

class Solution {
private:
    unordered_map<string, vector<string>> memo;
    unordered_set<string> dict;

    vector<string> dfs(string s) {
        // If result for this substring is already computed, return it
        if (memo.count(s)) {
            return memo[s];
        }
        
        vector<string> result;
        // Base case: if the string is empty, return a list containing an empty string
        if (s.empty()) {
            result.push_back("");
            return result;
        }

        for (int i = 1; i <= s.length(); ++i) {
            string prefix = s.substr(0, i);
            // If the prefix is a valid word in the dictionary
            if (dict.count(prefix)) {
                string suffix = s.substr(i);
                // Recursively find all valid sentence formations for the suffix
                vector<string> subResults = dfs(suffix);
                
                for (const string& sub : subResults) {
                    // Combine the prefix and the valid suffix sentence
                    if (sub.empty()) {
                        result.push_back(prefix);
                    } else {
                        result.push_back(prefix + " " + sub);
                    }
                }
            }
        }

        return memo[s] = result;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict.clear();
        memo.clear();
        for (const string& word : wordDict) {
            dict.insert(word);
        }
        return dfs(s);
    }
};
