/*A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, 
or 0 if no such sequence exists.*/

// Solution :- 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Step 1: Insert all words into an unordered_set for O(1) lookup
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // If endWord isn't in wordList, transformation is impossible
        if (st.find(endWord) == st.end()) {
            return 0;
        }
        
        // BFS Queue stores pairs of {current_word, transformation_steps}
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        // Erase beginWord from set if present to prevent revisiting
        st.erase(beginWord);
        
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            // Reached target word
            if (word == endWord) {
                return steps;
            }
            
            // Try changing each character of the current word
            for (int i = 0; i < word.length(); ++i) {
                char originalChar = word[i];
                
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;
                    
                    // If modified word exists in dictionary
                    if (st.find(word) != st.end()) {
                        st.erase(word); // Mark visited by removing from set
                        q.push({word, steps + 1});
                    }
                }
                
                // Restore original character for next position iteration
                word[i] = originalChar;
            }
        }
        
        return 0; // No valid sequence found
    }
};


 
