/* Given an array of strings strs, group the anagrams together. You can return the answer in any order.*/

// Solution :-

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        
        for (const std::string& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        
        std::vector<std::vector<std::string>> result;
        result.reserve(mp.size());
        
        for (auto& pair : mp) {
            result.push_back(std::move(pair.second));
        }
        
        return result;
    }
};