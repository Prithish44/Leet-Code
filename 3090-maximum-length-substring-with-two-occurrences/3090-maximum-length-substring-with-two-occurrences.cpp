class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
        int n = s.length();  

        vector<int> freq(26, 0);  

        int i = 0;  
        int j = 0;    

        int result = 0;  

        while(j < n)  
        {
            char ch = s[j];  
            freq[ch - 'a']++;  

            while(freq[ch - 'a'] > 2)  
            {
                freq[s[i] - 'a']--; 
                i++;  
            }  

            result = max(result, j - i + 1);    
            j++;   
        }   


        return result;     
    }
};