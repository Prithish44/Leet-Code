class Solution {
public:  
    int n;     
    vector<vector<long long>> t;   
    long long solve(vector<int> &nums, int i, bool flag)  
    {
        if(i >= n)    
            return 0;   
        if(t[i][flag] != -1)    
            return t[i][flag];  
        
        int val = nums[i];     
        
        if(flag != true)  
            val = -val;  
        
        long long take = val + solve(nums, i + 1, !flag);  
        long long skip = solve(nums, i + 1, flag);     


        return t[i][flag] = max(take, skip);   
    }
    long long maxAlternatingSum(vector<int>& nums) 
    {
        n = nums.size();   

        t.resize(n + 1, vector<long long>(2, -1));     

        return solve(nums, 0, true);  
    }
};