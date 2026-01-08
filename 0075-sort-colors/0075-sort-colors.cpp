class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();  
        int i = 0; 
        int j = 0; 
        int k = n - 1;

        
        while(j <= k)
        {
            if(nums[j] == 1)
                j = j + 1;
            else if(nums[j] == 2)
            {
                swap(nums[j], nums[k]); 
                k = k - 1;
            }
            else 
            {
                swap(nums[i], nums[j]); 
                 i = i + 1; 
                 j = j +1;
            }
        }
    }
};