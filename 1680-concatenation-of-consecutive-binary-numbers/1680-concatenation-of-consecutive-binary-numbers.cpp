class Solution {
public:
    int concatenatedBinary(int n) {
        long result = 0;    


        int M = 1e9 + 7;    


        int digit = 0;    

        
        for(int num = 1; num <= n; num++)  
        {
            if((num & (num - 1)) == 0)  
                digit = digit + 1;  


            result = ((result << digit) % M + num) % M;    
        }


        return result;    
    }
};