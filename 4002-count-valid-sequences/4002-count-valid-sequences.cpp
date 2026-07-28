class Solution {
public:      
    int M = 1e9 + 7;  
    long long findPower(long long a, long long b)     
    {
        if(b == 0)    
            return 1;  
        
        long long half = findPower(a, b / 2) % M;  
        long long result = (half * half) % M;     

        if(b % 2 == 1)  
            result = (result * a) % M;  
        

        return result;   
    }
    long long fact(int n)   
    {
        long long f = 1;  

        for(int i = 1; i <= n; i++)    
            f = (f * i) % M;  
        

        return f;   
    }
    long long Combination(int n, int r)    
    {
        if(r < 0 || r > n)     
            return 0;  
        
        long long a = fact(n);  
        long long b = (fact(r) * fact(n - r)) % M;  
        return (a * findPower(b, M - 2)) % M;  
    }
    int countValidSequences(int n, int k) 
    {
        long long total_sequence = Combination(n - 1, k - 1);    
        long long odd = 0;  
        
        if((n - k) % 2 == 0)   
            odd = Combination((n + k - 2) / 2, k - 1);     
        
        long long ans = (total_sequence - odd + M) % M;         


        return ans;   
    }
};