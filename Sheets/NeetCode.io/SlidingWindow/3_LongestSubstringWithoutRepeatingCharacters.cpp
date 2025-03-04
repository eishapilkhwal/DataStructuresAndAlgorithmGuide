// 3. Longest Substring Without Repeating Characters
 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int start = 0;
        int end = 0;
        int maxLength = 0;

        while(end < s.length()){
            if (mp.find(s[end]) != mp.end() && mp[s[end]] >= start){
                start = mp[s[end]] + 1;
            }
            mp[s[end]] = end;
            
            int length = end - start + 1;
            maxLength = max(length, maxLength);
            end++;
        }  
        return maxLength;   
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
