class Solution {
public:
    int minimumPushes(string word) 
    {
        int n = word.length();  

        vector<int> count(26, 0);  

        for(int i = 0; i < n; i++)  
            count[word[i] - 'a']++;  
        
        sort(begin(count), end(count), greater<int>());    

        int result = 0;  

        for(int i = 0; i < 26; i++)  
        {
            int freq = count[i];  
            int press = i / 8 + 1;  

            result = result + freq * press;  
        }   


        return result;     
    }
};