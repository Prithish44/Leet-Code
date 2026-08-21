class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        int T = (minutesToTest / minutesToDie) + 1;  

        int pig = 0;  

        while(pow(T, pig) < buckets)  
            pig = pig + 1;  
        

        return pig;     
    }
};