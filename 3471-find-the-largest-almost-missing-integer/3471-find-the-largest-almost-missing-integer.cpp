class Solution {
public:
    int largestInteger(vector<int>& nums, int k) 
    {
        int n = nums.size();  

        unordered_map<int, int> mp;  

        for(int i = 0; i < n; i++)  
            mp[nums[i]] = mp[nums[i]] + 1;  
        if(k == 1)  
        {
            int ans = -1;   
            for(int i = 0; i < n; i++)  
            {
                if(mp[nums[i]] == 1)    
                    ans = max(ans, nums[i]);   
            }
            
            return ans;   
        }   
        else if(k == n)  
        {
            int ans = -1;  
            for(int i = 0; i < n; i++)  
                ans = max(ans, nums[i]);  
            
            return ans;     

        }
        if(mp[nums[0]] == 1 && mp[nums[n - 1]] == 1)    
            return max(nums[0], nums[n - 1]);  
        else if(mp[nums[0]] == 1)  
            return nums[0];  
        else if(mp[nums[n - 1]] == 1)  
            return nums[n - 1];  
        


        return -1;     
        
    }
};