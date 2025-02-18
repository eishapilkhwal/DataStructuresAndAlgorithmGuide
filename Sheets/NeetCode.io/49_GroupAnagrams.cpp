// 49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagramsFrequency;

        for(int i = 0; i < strs.size(); i++){
            string sortedStr = strs[i];
            sort(begin(sortedStr), end(sortedStr));
            anagramsFrequency[sortedStr].push_back(strs[i]);
        }

        for(auto & anagram : anagramsFrequency){
            result.push_back(anagram.second);
        }

        return result;

    }
};

// Time Complexity : O(NK log K ) 
// Space Complexity : O(NK)
// N is the size of strs vector and K is the length of each string
