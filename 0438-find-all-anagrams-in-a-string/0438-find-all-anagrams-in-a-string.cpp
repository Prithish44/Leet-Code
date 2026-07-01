class Solution {
public:  
    bool allZero(vector<int> &counter)  
    {  
        for(int i = 0; i < 26; i++)  
        {
            if(counter[i] != 0)  
                return false;  
        }  


        return true;    
    }
    vector<int> findAnagrams(string s, string p) 
    {
        int n = s.length();  

        vector<int> counter(26, 0);  

        vector<int> result;    

        for(int i = 0; i < p.length(); i++)  
            counter[p[i] - 'a']++;    
        
        int i = 0; 
        int j = 0;  
        int k = p.length();  

        while(j < n)  
        {
            char ch = s[j];  
            counter[ch - 'a']--;  
            
            if(j - i + 1 == k)  
            {
                if(allZero(counter))     
                    result.push_back(i);  
                counter[s[i] - 'a']++;  
                i++;  
            }   

            j++;
        }   


        return result;  
    }
};