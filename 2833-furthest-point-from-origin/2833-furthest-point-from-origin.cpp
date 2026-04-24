class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;    


        int right = 0;     


        int dash = 0;   
        

        for(char &ch : moves)  
        {
            if(ch == 'L')  
                left = left + 1;  
            else if(ch == 'R')  
                right = right + 1;  
            else  
                dash = dash + 1;    
        }     


        return abs(left - right) + dash;    
        
    }
};