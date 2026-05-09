class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size();  
        int n = grid[0].size();  

        int layers = min(m, n) / 2;    

        for(int layer = 0; layer < layers; layer++)  
        {
            int top = layer; 
            int bottom = m - layer - 1;
            int left = layer; 
            int right = n - layer - 1;    

            vector<int> nums;    

            for(int j = left; j <= right; j++)      
                nums.push_back(grid[top][j]);  
            
            for(int i = top + 1; i <= bottom - 1; i++)  
                nums.push_back(grid[i][right]);  
            
            for(int j = right; j >= left; j--)  
                nums.push_back(grid[bottom][j]);  
            
            for(int i = bottom - 1; i >=  top + 1; i--)  
                nums.push_back(grid[i][left]);  
            
            int len = nums.size();     

            int normalize_k = k % len;                

            int id = 0;  

            rotate(begin(nums), begin(nums) + normalize_k, end(nums));    

            for(int j = left; j <= right; j++)      
                grid[top][j] = nums[id++];  
            
            for(int i = top + 1; i <= bottom - 1; i++)  
                grid[i][right] = nums[id++];  
            
            for(int j = right; j >= left; j--)  
                grid[bottom][j] = nums[id++];  
            
            for(int i = bottom - 1; i >=  top + 1; i--)  
                grid[i][left] = nums[id++];  
        }       

        
        return grid;     
    }
};