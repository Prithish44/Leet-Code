class Solution {
public:    
    bool isVowel(char ch)    
    {
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u')    
            return true;   
        

        return false;     
    }
    string reverseVowels(string s) 
    {
        int n = s.length();    


        int i = 0;    


        int j = n - 1;     


        while(i < j)  
        {
            if(!isVowel(s[i]))  
                i = i + 1;    
            else if(!isVowel(s[j]))  
                j = j - 1;   
            else  
            {
                swap(s[i], s[j]);    


                i = i + 1;    


                j = j - 1;
            }
        }    


        return s;    
    }
};