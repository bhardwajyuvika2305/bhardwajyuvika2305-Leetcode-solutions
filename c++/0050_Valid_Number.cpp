/* Given a string s, return whether s is a valid number.
For example, all the following are valid numbers: "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", while the following are not valid numbers: "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53".
Formally, a valid number is defined using one of the following definitions:
An integer number followed by an optional exponent.
A decimal number followed by an optional exponent.
An integer number is defined with an optional sign '-' or '+' followed by digits.
A decimal number is defined with an optional sign '-' or '+' followed by one of the following definitions:
Digits followed by a dot '.'.
Digits followed by a dot '.' followed by digits.
A dot '.' followed by digits.
An exponent is defined with an exponent notation 'e' or 'E' followed by an integer number.
The digits are defined as one or more digits.*/

// Solution :- 

class Solution {
public:
    bool isNumber(std::string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;
        bool seenDigitAfterE = true;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
                if (seenExponent) {
                    seenDigitAfterE = true;
                }
            } 
            else if (c == '+' || c == '-') {
                // A sign is only valid at index 0 or immediately after 'e' / 'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (c == '.') {
                // Dot is invalid if already seen or if inside exponent part
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } 
            else if (c == 'e' || c == 'E') {
                // Exponent is invalid if already seen or if no digit appeared before it
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigitAfterE = false; // Must be followed by at least one digit
            } 
            else {
                return false; // Any other character is invalid
            }
        }

        return seenDigit && seenDigitAfterE;
    }
};