// 84. Largest Rectangle in Histogram

class Solution {
public:

    vector<int> getNextSmallestElement(vector<int>& heights, int n){
        stack<int> st;
        vector<int> nextSmallestElement(n, n);
        for(int i = n - 1; i >= 0; i--){
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            nextSmallestElement[i] = st.empty() ? n : st.top();
            st.push(i);   
        }
        return nextSmallestElement;
    }

    vector<int> getPrevSmallestElement(vector<int>& heights, int n){
        stack<int> st;
        vector<int> prevSmallestElement(n, -1);
        for(int i = 0; i < n; i++){
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            prevSmallestElement[i] = st.empty() ? -1 : st.top();
            st.push(i);   
        }
        return prevSmallestElement;
    }

    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prevSmallestElement = getPrevSmallestElement(heights, n);
        vector<int> nextSmallestElement = getNextSmallestElement(heights, n); 
            
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int area = heights[i] * (nextSmallestElement[i] - prevSmallestElement[i] - 1);
            maxArea = max(maxArea, area);
        
        }
        
        return maxArea;
    }
};


// Time Complexity : O(n)
// Space Complexity : O(n)
