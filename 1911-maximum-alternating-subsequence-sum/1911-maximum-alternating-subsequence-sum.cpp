class Solution {
public:  
    long long maxAlternatingSum(vector<int>& nums) 
    {
        int n = nums.size();    

        vector<vector<long long>> t(n + 1, vector<long long>(2, 0));  

        for(int i = 1; i < n + 1 ; i++)  
        {
            //  Even  

            t[i][0] = max(t[i - 1][1] - nums[i - 1], t[i - 1][0]);    

            //  Odd  

            t[i][1] = max(t[i - 1][0] + nums[i - 1], t[i - 1][1]);  
        }    


        return max(t[n][0], t[n][1]);    
    }
};