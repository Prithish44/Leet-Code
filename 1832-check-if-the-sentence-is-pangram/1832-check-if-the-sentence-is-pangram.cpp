class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        int n = sentence.length();  

        if(n < 26)  
            return false;  
        
        vector<int> freq(26, 0);  

        for(char &ch : sentence)  
            freq[ch - 'a'] = freq[ch - 'a'] + 1;  
        
        for(int i = 0; i < 26; i++)  
        {
            if(freq[i] <1)  
                return false;  
        }   


        return true;    
    }
};