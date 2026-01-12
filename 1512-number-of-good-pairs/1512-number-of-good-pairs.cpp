class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;  
        
        for(int &num : nums)
            mp[num] = mp[num] + 1;  
        
        for(auto it = mp.begin(); it != mp.end();)
        {
            if(it->second == 1)
                it = mp.erase(it);  
            else  
                ++it;  
        }

        int result = 0;  

        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            int n = it->second;  
            result = result + (n*(n - 1)) / 2;  
        }

        return result;  
    }
};