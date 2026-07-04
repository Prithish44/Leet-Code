class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n = nums.size();  

        int count1 = 0;  
        int count2 = 0; 

        int majority1 = NULL;   
        int majority2 = NULL;     

        vector<int> result;  

        for(int i = 0; i < n; i++)  
        {
            if(nums[i] == majority1)  
                count1 = count1 + 1; 
            else if(nums[i] == majority2)  
                count2 = count2 + 1;  
            else if(count1 == 0)  
            {
                majority1 = nums[i];    
                count1 = 1;  
            }  
            else if(count2 == 0)  
            {
                majority2 = nums[i];    
                count2 = 1;  
            }
            else  
            {
                count1 = count1 - 1;  
                count2 = count2 - 1;    
            }
        }     

        int freq1 = 0; 
        int freq2 = 0;  

        for(int i = 0; i < n; i++)  
        {
            if(nums[i] == majority1)  
                freq1 = freq1 + 1; 
            else if(nums[i] == majority2)  
                freq2 = freq2 + 1;  
        }    

        if(freq1 > floor(n / 3))  
            result.push_back(majority1);  
        
        if(freq2 > floor(n / 3))  
            result.push_back(majority2);      

        
        return result;   

    }
};