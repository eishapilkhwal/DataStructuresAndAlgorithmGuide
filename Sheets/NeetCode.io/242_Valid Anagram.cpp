// 242. Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> frequency;

        for(int i = 0; i < s.length(); i++){
            int ch = s[i] - 'a';
            frequency[ch]++;
        }

        for(int j = 0; j < t.length(); j++){
            int ch = t[j] - 'a';
            frequency[ch]--;
        }

        for(auto &allZero : frequency){
            if(allZero.second != 0){
                return false;
            }
        }

        return true;
    }
};
