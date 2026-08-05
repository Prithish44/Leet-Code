class Solution {
public:  
    int takeCharacters(string s, int k) 
    {
        int n = s.length(); 

        vector<int> mp(3, 0);   

        for(char &ch : s)  
            mp[ch - 'a']++;  
        
        int i = 0; 
        int j = 0;   

        int notDeleteWindow = INT_MIN;    

        if(mp[0] < k || mp[1] < k || mp[2] < k)   
            return -1;  
        
        while(j < n)  
        {
            mp[s[j] - 'a']--;  

            while(i <= j && (mp[0] < k || mp[1] < k || mp[2] < k))  
            {
                mp[s[i] - 'a']++;  
                i++;
            }  

            notDeleteWindow = max(notDeleteWindow, j - i + 1);  
            j++;
        }
        

        return n - notDeleteWindow;     
    }
};