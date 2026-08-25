class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) 
    {
        unordered_set<int> st(begin(nums), end(nums));  

        int num = k;  

        while(true)  
        {
            if(st.find(num) == st.end())  
                return num;   
            
            num = num + k;  
        }    


        return num;    
    }
};