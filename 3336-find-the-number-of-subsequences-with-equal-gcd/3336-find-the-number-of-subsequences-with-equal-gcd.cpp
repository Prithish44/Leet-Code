class Solution {
public:     
    int Mod = 1e9 + 7;
    int t[201][201][201];  
    int solve(vector<int> &nums, int i, int first, int second)  
    {
        if(i == nums.size())  
        {
            bool bothNonEmpty = (first != 0 && second != 0);    
            bool gcdMatch = (first == second);    

            return bothNonEmpty && gcdMatch;     
        }  
        
        if(t[i][first][second] != -1)  
            return t[i][first][second];    
        
        int skip = solve(nums, i + 1, first, second);  
        int take1 = solve(nums, i + 1, __gcd(first, nums[i]), second);    
        int take2 = solve(nums, i + 1, first, __gcd(second, nums[i]));  

        return t[i][first][second] = (0LL + take1 + skip + take2) % Mod;  
    }
    int subsequencePairCount(vector<int>& nums) 
    {  
        memset(t, -1, sizeof(t));  


        return solve(nums, 0, 0, 0);  
    }
};