class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        int H = abs(fx - sx); 
        int V = abs(fy - sy);  

        if(sx == fx && sy == fy && t == 1)  
            return false; 
        
        if(t< max(H, V))   
            return false;    
        

        return true;    
    }
};