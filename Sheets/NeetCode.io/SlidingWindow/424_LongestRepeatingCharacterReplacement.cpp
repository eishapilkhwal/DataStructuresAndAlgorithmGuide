424. Longest Repeating Character Replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0); // Frequency array to store character counts
        int left = 0, maxFreq = 0, maxLength = 0, n = s.length();

        // Expanding the window
        for (int right = 0; right < n; right++) {
            freq[s[right] - 'A']++; 
            maxFreq = max(maxFreq, freq[s[right] - 'A']); 

            // If the remaining characters (excluding the most frequent one) exceed k, shrink the window
            if ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--; 
                left++; 
            }

            maxLength = max(maxLength, right - left + 1); // Update the max length found
        }

        return maxLength;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(26)
