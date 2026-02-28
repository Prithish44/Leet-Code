class Solution {
public:
    int concatenatedBinary(int n) {
        long result = 0;    


        int M = 1e9 + 7;  

        for(int num = 1; num <= n; num++)  
        {
            int digit = log2(num) + 1;    


            result = ((result << digit) % M + num) % M;    
        }


        return result;    
    }
};