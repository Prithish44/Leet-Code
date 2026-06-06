class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) 
    {
        int n = nums.size();    


        int Sum = accumulate(begin(nums), end(nums), 0);     


        vector<int> result(n);    


        int curr = 0;          


        for(int i = 0; i < n; i++)  
        {
            int Leftsum = curr;  


            curr = curr + nums[i];    


            int Rightsum = Sum - curr;  
            
     
            result[i] = abs(Leftsum - Rightsum);  
        }    


        return result;          
    }
};