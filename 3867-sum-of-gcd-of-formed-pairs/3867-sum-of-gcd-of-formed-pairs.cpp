class Solution {
public:
    long long gcdSum(vector<int>& nums) 
    {
        int n = nums.size();   
        vector<int> prefixGcd;  

        int maxEl = -1;  

        for(int i = 0; i < n; i++)  
        {
            maxEl = max(maxEl, nums[i]);    
            prefixGcd.push_back(__gcd(maxEl, nums[i]));  
        }  

        sort(begin(prefixGcd), end(prefixGcd));  

        long long result = 0;    

        int i = 0; 
        int j = n - 1;    

        while(i < j)  
        {
            result = result + __gcd(prefixGcd[i], prefixGcd[j]);  
            i = i + 1;  
            j = j - 1;  
        }    


        return result;    
    }
};