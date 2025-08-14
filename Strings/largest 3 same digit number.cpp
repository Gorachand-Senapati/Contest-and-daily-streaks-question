//2264
// class Solution {
//     vector<string> sameDigitNumbers = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

//     // Check whether the 'num' string contains the 'sameDigitNumber' string or not.
//     bool contains(string sameDigitNumber, string num) {
//         for (int index = 0; index <= num.size() - 3; ++index) {
//             if (num[index] == sameDigitNumber[0] and 
//                 num[index + 1] == sameDigitNumber[1] and 
//                 num[index + 2] == sameDigitNumber[2]) {
//                 return true;
//             }
//         }
//         return false;
//     }

// public:
//     string largestGoodInteger(string num) {
//         // Iterate on all 'sameDigitNumbers' and check if the string 'num' contains it.
//         for (auto& sameDigitNumber: sameDigitNumbers) {
//             if (contains(sameDigitNumber, num)) {
//                 // Return the current 'sameDigitNumbers'.
//                 return sameDigitNumber;
//             }
//         }
//         // No 3 consecutive same digits are present in the string 'num'.
//         return "";
//     }
// };

class Solution {
public:
    string largestGoodInteger(string num) {
        // Assign 'maxDigit' to the NUL character (smallest ASCII value character)
        char maxDigit = '\0';

        // Iterate on characters of the num string.
        for (int index = 0; index <= num.size() - 3; ++index) {
            // If 3 consecutive characters are the same,
            // store the character in 'maxDigit' if bigger than what it already stores.
            if (num[index] == num[index + 1] && num[index] == num[index + 2]) {
                maxDigit = max(maxDigit, num[index]);
            }
        }

        // If 'maxDigit' is NUL return an empty string, otherwise string of size 3 with 'maxDigit' characters.
        return maxDigit == '\0' ? "" : string(3, maxDigit);
    }
};
// all approach TC= O(n), SC= O(1)