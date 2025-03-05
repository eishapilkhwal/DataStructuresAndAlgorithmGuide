// 567. Permutation in String

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Freq (26, 0);
        vector<int> s2Freq (26, 0);

        for(auto& s : s1){
            s1Freq[s - 'a']++;
        }

        int windowSize = s1.length();

        int start = 0;
        int end = 0;

        while(end < s2.length()){
            s2Freq[s2[end] - 'a']++;

            if ((end - start + 1) > windowSize){
                s2Freq[s2[start] - 'a']--;
                start++;
            }

            if (s1Freq == s2Freq){
                return true;
            }
            end++;
        }

        return false;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
