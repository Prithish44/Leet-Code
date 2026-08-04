class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) 
    {
        int a = *min_element(begin(nums), end(nums));  
        int b = *max_element(begin(nums), end(nums));  

        unordered_set<int> s(begin(nums), end(nums));     

        vector<int> result;    

        for(int i = a; i <= b; i++)  
        {
            if(s.find(i) == s.end())  
                result.push_back(i);
        }    


        return result;    
    }
};