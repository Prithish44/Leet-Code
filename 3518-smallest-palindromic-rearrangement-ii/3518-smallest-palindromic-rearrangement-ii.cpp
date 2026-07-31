class Solution {
public:    
    long long nCr(int n, int r, int k)    
    {
        long long result = 1;    

        r = min(r, n - r);    

        for(int i = 1; i <= r; i++)   
        {
            result = result * (n - r + i) / i;   
            
            if(k <= result)    
                break;    
        }    


        return result;    
    }
    string smallestPalindrome(string s, int k) 
    {
        int n = s.length();  

        vector<int> count(26, 0);   

        char mid = ' ';    

        if(n % 2 == 1)   
            mid = s[n / 2];    
        
        for(int i = 0; i < n; i++)    
        {
            if(n % 2 == 1 && i == n / 2)   
                continue;  
            
            count[s[i] - 'a'] = count[s[i] - 'a'] + 1;    
        }     

        for(int i = 0; i < 26; i++)  
            count[i] = count[i] / 2;   
        
        string halfResult = "";  
        int half = n / 2;  

        for(int i = 0; i < half; i++)  
        {    
            bool placeCharacter = false;   
            for(int j = 0; j < 26; j++)  
            {
                if(count[j] > 0)   
                {
                    count[j] = count[j] - 1;   

                    long long ways = 1;  
                
                    int letters = 0;  

                    for(int c = 0; c < 26; c++)  
                        letters = letters + count[c];    

                    for(int c = 0; c < 26; c++)  
                    {
                        if(count[c] > 0)   
                        {
                            ways = ways * nCr(letters, count[c], k);   
                            letters = letters - count[c];   
                        }

                        if(k <= ways)   
                            break;      
                    }   

                    if(k <= ways)  
                    {
                        halfResult.push_back(j + 'a');   
                        placeCharacter = true;    
                        break; 
                    }    

                    k = k - ways;  
                    count[j] = count[j] + 1;
                }         
            }   

            if(placeCharacter != true)    
                return "";    
        }      

        string rev = halfResult;   

        reverse(begin(rev), end(rev));  

        if(mid != ' ')  
            halfResult.push_back(mid);  
        
        
        return halfResult+ rev;   
    }
};