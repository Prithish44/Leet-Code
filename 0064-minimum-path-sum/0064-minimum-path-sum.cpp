class Solution {
public:  
    int m; 
    int n;   
    int t[201][201];  
    int solve(vector<vector<int>> &grid, int i, int j)  
    {
        if(i == m - 1 && j == n - 1)    
            return grid[i][j];    
        
        if(i >= m || j >= n)  
            return 1e9;       
        
        if(t[i][j] != -1)   
            return t[i][j];  
        
        int right = grid[i][j] + solve(grid, i, j + 1); 
        int down = grid[i][j] + solve(grid, i + 1, j);  


        return t[i][j] = min(right, down);   
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        m = grid.size();  
        n = grid[0].size();  

        memset(t, -1, sizeof(t));  


        return solve(grid, 0, 0); 
    }
};