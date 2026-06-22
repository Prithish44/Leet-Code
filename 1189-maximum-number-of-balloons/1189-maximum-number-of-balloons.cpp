class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        int t[26] = {0};     


        int count = INT_MAX;

        for(char &ch : text)  
            t[ch - 'a'] = t[ch - 'a'] + 1;     
        

        count = min(count, t['a' - 'a']);    


        count = min(count, t['b' - 'a']);    


        count = min(count, t['l' - 'a'] / 2);     


        count = min(count, t['o' - 'a'] / 2);     

        
        count = min(count, t['n' - 'a']);   


        return count;     
    }
};