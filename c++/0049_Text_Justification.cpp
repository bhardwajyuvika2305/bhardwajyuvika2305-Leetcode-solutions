/* Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left-justified, and no extra space is inserted between words.*/

// Solution :-

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int i = 0, n = words.size();

        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();

            // Find how many words fit in the current line
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }

            int numWords = j - i;
            std::string line = "";

            // Case 1: Last line or line contains only 1 word (Left-justified)
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                // Pad remaining spaces to the right
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } 
            // Case 2: Fully justified line
            else {
                int totalWordLength = 0;
                for (int k = i; k < j; k++) {
                    totalWordLength += words[k].length();
                }

                int totalSpaces = maxWidth - totalWordLength;
                int spacesPerGaps = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToApply = spacesPerGaps + (k - i < extraSpaces ? 1 : 0);
                        line.append(spacesToApply, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j; // Move to the next set of words
        }

        return result;
    }
};