// 739. Daily Temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0); // Initialize result array with zeros
        stack<int> st; // Stack to store indices of temperatures

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop(); // Remove elements that are smaller or equal to current temperature
            }
            
            if (!st.empty()) {
                result[i] = st.top() - i; // Compute days to wait
            }
            
            st.push(i); // Push the index of the current temperature
        }
        
        return result;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
