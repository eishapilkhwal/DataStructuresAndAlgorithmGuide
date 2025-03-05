// 76. Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        int minWindowSize = INT_MAX;

        for(auto& required : t){
            mp[required]++;
        }

        int start = 0;
        int end = 0;
        int requiredCount = t.length();
        int startPoint;
        while(end < s.length()){
            
            if(mp[s[end]] > 0){
                requiredCount--;
            }
            mp[s[end]]--;

            while(requiredCount == 0){
                int currWindowSize = end - start + 1;
                if (currWindowSize < minWindowSize){
                    minWindowSize = currWindowSize;
                    startPoint = start;
                }

                mp[s[start]]++;
                if (mp[s[start]] > 0){
                    requiredCount++;
                }
                start++;
            }   
            end++;
        }

        return (minWindowSize == INT_MAX) ? "" : s.substr(startPoint, minWindowSize);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
