class Solution {
public:
    int findGCD(vector<int>& nums) 
    {
        int minimum = *min_element(begin(nums), end(nums));    


        int maximum = *max_element(begin(nums), end(nums));    


        int result = __gcd(maximum, minimum);    


        return result;     
    }
};