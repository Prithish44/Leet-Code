class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        int n = costs.size();  

        
        sort(begin(costs), end(costs));    


        int count = 0;    


        for(int &cost : costs)  
        {
            if(cost > coins)  
                return count;  
            else  
            {
                coins = coins - cost;    


                count = count + 1;    
            }
        }     


        return count;     
    }
};