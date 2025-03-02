// 167. Two Sum II - Input Array Is Sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;

        vector<int> result(2);

        while(start < end){
            if (numbers[start] + numbers[end] == target){
                result[0] = start+1;
                result[1] = end+1;
                return result;
            }

            else if (numbers[start] + numbers[end] > target){
                end--;
            }
            else
                start++;
        }
        return result;
    }
};


// Time Complexity : O(N)
// Space Complexity : O(1)
