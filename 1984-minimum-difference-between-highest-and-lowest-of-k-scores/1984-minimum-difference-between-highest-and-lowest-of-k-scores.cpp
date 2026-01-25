class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();  


        int minDiff = INT_MAX;  


        sort(begin(nums), end(nums));  

        int i = 0; 

        
        int j = k - 1;  


        for(int i = k - 1; i < n; i++)
        {
            int minElement = nums[i - k + 1];  
            int maxElement = nums[i];  


            minDiff = min(minDiff, maxElement - minElement);    
        }


        return minDiff;     
    }
};