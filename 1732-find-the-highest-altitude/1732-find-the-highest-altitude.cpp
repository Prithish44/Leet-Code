class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int n = gain.size();    


        int maxAlt = 0;    


        int curr = 0;        


        for(int &g : gain)  
        {
            curr = curr + g;     
            

            maxAlt = max(maxAlt, curr);    
        }   


        return maxAlt;    
    }
};