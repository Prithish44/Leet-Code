class Solution {
public:
    int minFlips(string s) {
        string s1;  


        string s2;  


        int n = s.length();    


        s = (s + s);   


        for(int i = 0; i < 2*n; i++)  
        {
            s1 += (i % 2 ? '0' : '1');  


            s2 += (i % 2 ? '1' : '0');    
        }    


        int result = INT_MAX;  


        int flip1 = 0;  


        int flip2 = 0;  


        int i = 0;  


        int j = 0;  


        while(j < 2*n)  
        {
            if(s[j] != s1[j])  
                flip1 = flip1 + 1;  
            if(s[j] != s2[j])  
                flip2 = flip2 + 1;  
            if(j - i + 1 > n)  
            {
                if(s[i] != s1[i])  
                    flip1 = flip1 - 1;  
                if(s[i] != s2[i])  
                    flip2 = flip2 - 1;  
                

                i = i + 1;  
            }  
            if(j - i + 1 == n)  
                result = min({result, flip1, flip2});  
            

            j = j + 1; 
        }  
        

        return result;     
    }
};