class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) 
    {
        int n = s.length();  

        int activeCount = count(begin(s), end(s), '1');  

        vector<int> inactiveBlock;  

        int i = 0;  

        while(i < n)  
        {
            if(s[i] == '0')  
            {
                int start = i;  

                while(i < n && s[i] == '0')  
                    i = i + 1;  
                
                inactiveBlock.push_back(i - start);  
            }    
            else  
                i = i + 1;   
        }     

        int k = inactiveBlock.size();  

        int maxPairSum = 0;  

        for(int i = 1; i < k; i++)     
            maxPairSum = max(maxPairSum, inactiveBlock[i] + inactiveBlock[i - 1]);  
        

        return activeCount + maxPairSum;    

    }
};