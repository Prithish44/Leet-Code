class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n = nums.size();    


        vector<int> result(n, -1);    


        long long window = 0;    


        if(n < 2 * k + 1)    
            return result;         


        int left = 0; 
        int right = 2 * k;     
        int i = k; 

        for(int i = left; i <= right; i++)  
            window = window + nums[i];  
        

        int count = 2 * k + 1;  
        result[i] = window / count;  
        i = i + 1;  
        right = right + 1;  

        
        while(right < n)  
        {
            window = window - nums[left] + nums[right];   
            result[i] = window / count;  
            left = left + 1;  
            right = right + 1;   
            i = i + 1;  
        }  


        return result;    
    }
};