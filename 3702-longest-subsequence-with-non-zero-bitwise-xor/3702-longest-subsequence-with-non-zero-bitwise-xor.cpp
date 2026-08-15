class Solution {
public:
    int longestSubsequence(vector<int>& nums) 
    {
        int n = nums.size();  

        int resultXOR = 0;  

        bool allZero = true;  

        for(int i = 0; i < n; i++)  
        {
            if(nums[i] != 0)  
                allZero = false;  
            
            resultXOR = resultXOR ^ nums[i];  
        }    

        if(allZero == true)    
            return 0;    
        

        return resultXOR == 0 ? n - 1 : n;     
    }
};