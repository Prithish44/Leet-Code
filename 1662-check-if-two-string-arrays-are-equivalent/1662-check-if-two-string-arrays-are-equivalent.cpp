class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        int m = word1.size();  
        int n = word2.size();    

        int w1i = 0; 
        int w2i = 0;  
        int i = 0;  
        int j = 0;  

        while(w1i < m && w2i < n)  
        {
            if(word1[w1i][i] != word2[w2i][j])  
                return false;    
            
            i = i + 1;  
            j = j + 1;  

            if(i == word1[w1i].length())  
            {
                i = 0; 
                w1i = w1i + 1;
            }    
            if(j == word2[w2i].length())  
            {
                j = 0; 
                w2i = w2i + 1;  
            }    
        }  
        if(w1i == m && w2i == n)   
            return true;    
        
        
        return false;    
    }
};