class Solution {
public:
    string processStr(string s) 
    {
        string result = "";  

        for(char &ch : s)  
        {
            if(islower(ch))  
                result.push_back(ch);  
            else if(ch == '*' && !result.empty())  
                result.pop_back();    
            else if(ch == '#')  
                result = result + result;    
            else  
                reverse(begin(result), end(result));  
        }   


        return result;    
    }
};