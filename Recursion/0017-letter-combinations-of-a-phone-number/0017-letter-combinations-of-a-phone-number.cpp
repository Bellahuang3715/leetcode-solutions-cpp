/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/

class Solution {
public:
    void backtrack(const string& digits, string& current, int index, const vector<string>& digitToLetters, vector<string>& result)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }
        string letters = digitToLetters[digits[index] - '0'];   // convert char to int
        for (char letter : letters)
        {
            current.push_back(letter);
            backtrack(digits, current, index+1, digitToLetters, result);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) { return {}; }
        vector<string> digitToLetters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;
        backtrack(digits, current, 0, digitToLetters, result);
        return result;
    }
};