class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) 
    {
        int n = s.length();  

        int i = 0;  
        int j = 0;  
        int ones = 0;  

        string result = "";   

        while(j < n)  
        {
            if(s[j] == '1')  
                ones = ones + 1;  
            
            while(ones > k || s[i] == '0')  
            {
                if(s[i] == '1')  
                    ones = ones - 1;  
                
                i = i + 1;    
            }  

            if(ones == k)  
            {
                string temp = s.substr(i, j - i + 1);  

                if(result.empty() || result.length() > j - i + 1 || (result.length() == temp.length() && result > temp))  
                    result = temp;    
            }     
            
            j = j + 1;
        }   


        return result;   
    }
};