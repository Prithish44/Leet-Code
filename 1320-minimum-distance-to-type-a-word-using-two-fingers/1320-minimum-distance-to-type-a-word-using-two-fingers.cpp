class Solution {
public:  
    int t[301][7][7][7][7];  
    pair<int, int> getCoord(char ch)  
    {
        int curr = ch - 'A';  


        return {curr / 6, curr % 6};  
    }  

    int getDistance(int x1, int y1, int x2, int y2)  
    {
        return abs(x1 - x2) + abs(y1 - y2);    
    }
    int solve(string &word, int i, int x1, int y1, int x2, int y2)  
    {
        if(i >= word.length())  
            return 0;    

        if(t[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] != -1)  
            return t[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1];  
        auto [x, y] = getCoord(word[i]);  
        // No Use  

        if(x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1)  
            return t[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = solve(word, i + 1, x, y, x2, y2);  
        
        // F2 Use  

        if(x2 == -1 && y2 == -1)  
        {
            int moveF2 = solve(word, i + 1, x1, y1, x, y);  
            int moveF1 = getDistance(x1, y1, x, y) + solve(word, i + 1, x, y, x2, y2);  

            
            return t[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = min(moveF1, moveF2);    
        }    

        // Both Use   

        int moveF1 = getDistance(x1, y1, x, y) + solve(word, i + 1, x, y, x2, y2);    

        int moveF2 = getDistance(x2, y2, x, y) + solve(word, i + 1, x1, y1, x, y);  


        return t[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = min(moveF1, moveF2);    
    }
    int minimumDistance(string word) {  
        memset(t, -1, sizeof(t));  
        return solve(word, 0, -1, -1, -1, -1);     
    }
};