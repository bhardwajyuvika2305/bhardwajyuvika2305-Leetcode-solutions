#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;

        // Split string by '/'
        while (getline(ss, token, '/')) {
            // Ignore empty strings (from multiple slashes like "//") and "." (current dir)
            if (token == "" || token == ".") {
                continue;
            }
            // ".." means go up to the parent directory (pop from stack if not empty)
            if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                // Valid directory or file name
                st.push_back(token);
            }
        }

        // Reconstruct the simplified canonical path
        string result = "";
        for (const string& dir : st) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};