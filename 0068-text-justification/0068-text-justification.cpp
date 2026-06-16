class Solution {
public:  
    int MAXWIDTH;  
    string findLine(int i, int j, vector<string> &words, int eachSpace, int extraSpace)  
    {
        string line;  

        for(int k = i; k < j; k++)  
        {
            line = line + words[k];    
            
            if(k == j - 1)  
                continue;  
            
            for(int z = 1; z <= eachSpace; z++)  
                line = line + ' ';  
            
            if(extraSpace > 0)  
            {
                line = line + ' ';  
                extraSpace = extraSpace - 1;     
            }
        }     


        while(line.length() < MAXWIDTH)  
            line = line + ' ';    

        return line;     
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth) 
    {
        vector<string> result;  
        int n = words.size();  

        MAXWIDTH = maxWidth;  
        
        int i = 0; 
        

        while(i < n)  
        {  
            int j = i + 1;  
            int lettersCount = words[i].length();  
            int space = 0;

            while(j < n && lettersCount + 1 + space + words[j].length() <= maxWidth)  
            {
                lettersCount = lettersCount + words[j].length();  
                space = space + 1;  
                j = j + 1;  
            }  

            int remainingSpace = maxWidth - lettersCount;  
            
            int eachSpace = space == 0 ? 0 : (remainingSpace / space);  
            int extraSpace = space == 0 ? 0 : (remainingSpace % space);  

            if(j == n)  
            {
                eachSpace = 1;  
                extraSpace = 0;  
            }  

            result.push_back(findLine(i, j, words, eachSpace, extraSpace));  

            i = j;    
        }   


        return result;    
    }
};