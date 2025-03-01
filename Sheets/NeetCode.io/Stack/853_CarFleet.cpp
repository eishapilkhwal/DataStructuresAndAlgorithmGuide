// 853. Car Fleet

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int, greater<int>> mp;

        for(int i = 0; i < position.size(); i++){
            mp[position[i]] = speed[i];
        }
        stack<double> st;
        for(auto & m : mp){
            int distance = target - m.first;
            int speed = m.second;

            double time = (double) distance / speed;

            if (st.empty() || st.top() < time){
                st.push(time);
            } 
            
        }
        return st.size();
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)
