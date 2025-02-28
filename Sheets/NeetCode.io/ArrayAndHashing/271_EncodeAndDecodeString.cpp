// 271. Encode And Decode String

class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for(auto &s : strs){
            encodedString += to_string(s.length()) + "#" + s;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> originalString;
        string decodedString;
        int i = 0; 
        while(i < s.length()){
            int j = i;

            while(s[j] != '#'){
                j++;
            }
            int lengthSubStr = stoi(s.substr(i, j - i));
            decodedString = s.substr(j + 1, lengthSubStr);
            originalString.push_back(decodedString);
            i = j + 1 + lengthSubStr;
        }
        return originalString;
    }
};


// Time Complexity : O(n)
// Space Complexity : O(n)
