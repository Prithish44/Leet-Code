class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.length();   


        vector<int> mp(3, 0);    


        int i = 0;    


        int j = 0;     


        int result = 0;    


        while(j < n)  
        {
            char ch = s[j];    


            mp[ch - 'a'] = mp[ch - 'a'] + 1;     
            

            while(mp[0] > 0 && mp[1] && mp[2] > 0)  
            {
                result = result + n - j;    
                mp[s[i] - 'a'] = mp[s[i] - 'a'] - 1;  
                
                i = i + 1;   
            }   


            j = j + 1;    
        }     


        return result;    
    }
};