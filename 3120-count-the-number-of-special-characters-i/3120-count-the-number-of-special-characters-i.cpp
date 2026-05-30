class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        int freq1[26];  
        int freq2[26];  
        int count = 0;    


        int n = word.length();    


        for(int i = 0; i < n; i++)  
        {
            char ch = word[i];  

            if(islower(ch))  
                freq1[ch - 'a'] = 1;    
            if(isupper(ch))     
                freq2[ch - 'A'] = 1;  
        }     


       for(int i = 0; i < 26; i++)
       {
            if(freq1[i] == 1 & freq2[i] == 1)   
                count = count + 1;     
       }   


       return count;         
    }
};