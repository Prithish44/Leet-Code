class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();  

        int minDiff = INT_MAX;  

        sort(begin(nums), end(nums));  

        int i = 0; 
        int j = k - 1; 

        while(j < n)
        {
            int minElement = nums[i];  
            int maxElement = nums[j];  

            minDiff = min(minDiff, maxElement - minElement);    

            i = i + 1;  
            j = j + 1; 
        }


        return minDiff;     
    }
};