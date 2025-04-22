// 131. Palindrome Partitioning

class Solution {
public:
    void helper(int index, string& s, vector<string>& possibleOutput, vector<vector<string>>& result){
        if (index == s.length()){
            result.push_back(possibleOutput);
            return;
        }

        for(int i = index; i < s.length(); i++){
            if (isPalindrome(s, index, i)){
                possibleOutput.push_back(s.substr(index, i - index + 1));
                helper(i+1, s, possibleOutput, result);
                possibleOutput.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> possibleOutput;

        helper(0, s, possibleOutput, result);
        return result;
    }
};

// Time Complexity : O(n×2^n)
// Space Complexity : O(n×2^n)
