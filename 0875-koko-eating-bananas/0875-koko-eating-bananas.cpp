class Solution {
public:
    bool canEat(int mid, vector<int> &piles, int h)
    {
        long long time = 0;  

        for(auto &pile : piles)
        {
           
                
            time = time +  pile / mid; 
            
            if(pile % mid != 0)  
                time = time + 1; 
            
        }

        if(time <= h)
            return true;
        
        return false;  
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;    
        int u = *max_element(begin(piles), end(piles));    
        
        int time = 0; 

        while(l <= u)
        {
            int mid = l + (u - l) / 2; 
            
            if(canEat(mid, piles, h))
            {
                u = mid - 1;
                time = mid;   
            }
            else 
                l = mid + 1;
        }

        return time;  
    }
};