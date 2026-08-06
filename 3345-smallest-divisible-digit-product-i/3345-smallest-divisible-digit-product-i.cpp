class Solution {
public:
    int productofDigit(int num)  
    {
        int p = 1;  

        while(num > 0)  
        {
            int r = num % 10;  
            p = p * r;  
            num = num / 10;   
        }   


        return p;   
    }
    int smallestNumber(int n, int t) 
    {
        while(productofDigit(n) % t != 0)  
            n = n + 1;   
        

        return n;    
    }
};