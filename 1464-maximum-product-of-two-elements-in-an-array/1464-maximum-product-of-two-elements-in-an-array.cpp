class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();   

        // Initialize both to INT_MIN
        int max1 = INT_MIN;  
        int max2 = INT_MIN;   

        for(int i = 0; i < n; i++)  
        {
            // Use >= instead of > to safely cascade values and handle duplicates
            if(nums[i] >= max1)   
            {
               max2 = max1;   
               max1 = nums[i];    
            }  
            else if(nums[i] >= max2)   
            {
                max2 = nums[i];   
            }
        }   

        int product = (max1 - 1) * (max2 - 1);   
        return product;    
    }
};