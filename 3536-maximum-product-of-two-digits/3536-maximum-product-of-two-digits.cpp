class Solution {
public:
    int maxProduct(int n) 
    {
        int a = 0;  
        int b = 0;  

        while(n > 0)  
        {
            int rem = n % 10;  

            if(a < rem)  
            {
                b = a; 
                a = rem;     
            }  
            else if(b < rem)  
                b = rem;    
            
            n = n / 10;   
        }   


        return a * b;    
    }
};