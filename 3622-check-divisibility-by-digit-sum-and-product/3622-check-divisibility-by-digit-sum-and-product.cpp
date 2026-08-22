class Solution {
public:
    bool checkDivisibility(int n) 
    {
        int num = n;  

        int Sum = 0;  
        int Prod = 1;   

        while(num > 0)  
        {  
            int r = num % 10;  
            Sum = Sum + num % 10;  
            Prod = Prod * r;  
            num = num / 10;  
        }  

        int total = Sum + Prod;   

        if(n % total == 0)  
            return true;    
        

        return false;     
    }
};