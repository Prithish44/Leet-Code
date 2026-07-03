class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int n = customers.size();   


        int currUnsat = 0;    


        for(int i = 0; i < minutes; i++)  
        {
            if(grumpy[i] == 1)  
                currUnsat = currUnsat + customers[i];  
        }  

        int maxUnsat = currUnsat;     


        int i = 0;    


        int j = minutes;    


        while(j < n)  
        {
            currUnsat = currUnsat - customers[i] * grumpy[i] + customers[j] * grumpy[j];     


            maxUnsat = max(maxUnsat, currUnsat);    


            i++;   

            
            j++;   
        }     


        int totalSat = maxUnsat;    


        for(int i = 0; i < n; i++)  
        {
            if(grumpy[i] == 0)  
                totalSat = totalSat + customers[i];    
        }    


        return totalSat;    
    }
};