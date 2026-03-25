class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();  


        int n = grid[0].size();  


        vector<long long> rowSum(m, 0);  


        vector<long long> colSum(n, 0);    


        long long total = 0;  


        for(int i = 0; i < m; i++)  
        {
            for(int j = 0; j < n; j++)  
            {
                total = total + grid[i][j];  


                rowSum[i] = rowSum[i] + grid[i][j];  


                colSum[j] = colSum[j] + grid[i][j];  
            }
        }  


        if(total % 2 != 0)  
            return false;  
        

        long long upper = 0;  


        long left = 0;  



        for(int i = 0; i < m - 1; i++)  
        {
            upper = upper + rowSum[i];  


            if(upper == total - upper)  
                return true;  
        }    


        for(int i = 0; i < n - 1; i++)  
        {
            left = left + colSum[i];  


            if(left == total - left)  
                return true;  
        }  


        return false;    
    }
};