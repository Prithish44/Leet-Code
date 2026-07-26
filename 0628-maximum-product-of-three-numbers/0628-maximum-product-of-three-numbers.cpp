class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int n = nums.size();   

        sort(begin(nums), end(nums), greater<int>());  

        int product1 = nums[0] * nums[1] * nums[2];   
        int product2 = nums[0] * nums[n - 1] * nums[n - 2];  

        int product = max(product1, product2);    


        return product;    
    }
};