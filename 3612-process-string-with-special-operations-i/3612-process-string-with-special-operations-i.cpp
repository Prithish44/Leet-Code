class Solution {
public:
    string processStr(string s) 
    {
        string result = "";      
        

        for(char &ch : s)  
        {
            if(islower(ch))  
                result = result + ch;     
            else if(ch == '*' && result.length() > 0)  
                result.pop_back();    
            else if(ch == '#')  
                result = result + result;    
            else  
                reverse(begin(result), end(result));  
        }   


        return result;    
    }
};