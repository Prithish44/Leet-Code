class Solution {
public:
    string smallestSubsequence(string s) 
    {
        int n = s.length();  

        string result = "";  

        vector<int> lastIdx(26);  
        vector<bool> visit(26, false);    

        for(int i = 0; i < n; i++)  
        {
            char ch = s[i];  
            lastIdx[ch - 'a'] = i;  
        }    

        for(int i = 0; i < n; i++)  
        {
            char ch = s[i];  

            if(visit[ch - 'a'] == true)  
                continue;  
            
            while(result.length() > 0 && result.back() > ch && lastIdx[result.back() - 'a'] > i)  
            {
                visit[result.back() - 'a'] = false;  
                result.pop_back();  
            }  

            result.push_back(ch);  

            visit[ch - 'a'] = true;   
        }   


        return result;    
    }
};