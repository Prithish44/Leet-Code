class Solution {
public:
    long long maxArrayValue(vector<int>& nums) 
    {
        int n = nums.size();   


        long long currMax = nums[n - 1];   


        long long maximum = currMax;   


        for(int i = n - 2; i >= 0; i--)  
        {
            if(currMax >= nums[i])  
                currMax = currMax + nums[i];    
            else  
                currMax = nums[i];  
            maximum = max(maximum, currMax);   
        }  


        return maximum;    
    }
};