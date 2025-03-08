// 875. Koko Eating Bananas

class Solution {
public:
    bool canEatAll(vector<int>& piles, int h, int mid){
        int actualHours = 0;

        for(int & x: piles){
            actualHours += x/mid;

            if (x%mid != 0){
                actualHours++;
            }
        }
        return actualHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high){
            int mid = (low + high)/2;

            if (canEatAll(piles, h, mid)){
                high = mid;
            }

            else{
                low = mid + 1;
            }
        }
        return high;
    }
};

// Time Complexity : O(nlogm) here n is soze of piles and m is maximum of piles
// Space Complexity : O(1)
