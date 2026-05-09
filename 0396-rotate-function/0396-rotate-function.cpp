class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int n = nums.size();    

        int sum = 0;  

        int F = 0;    

        for(int i = 0; i < n; i++)  
        {
            sum = sum + nums[i];  

            F = F + i * nums[i];     
        }    

        int result = F;    

        for(int k = 0; k <= n - 1; k++)  
        {
            int new_F = F + sum - n * nums[n - k - 1];  

            result = max(result, new_F);    

            F = new_F;      
        }    


        return result;    
    }
};