class Solution {
public:    
    vector<vector<int>> t;   
    int solve(int l, int r, vector<int> &cumSum)    
    {
        if(l >= r)    
            return 0;  
        
        if(t[l][r] != -1)    
            return t[l][r];   
        
        int score = 0;   
        for(int mid = l; mid < r; mid++)  
        {
            int leftSum = cumSum[mid] - (l - 1 >= 0 ? cumSum[l - 1] : 0);  
            int rightSum = cumSum[r] - cumSum[mid];     

            if(leftSum < rightSum)  
                score = max(score, leftSum + solve(l, mid, cumSum));  
            else if(leftSum > rightSum)  
                score = max(score, rightSum + solve(mid + 1, r, cumSum));  
            else  
                score = max({score, leftSum + solve(l, mid, cumSum), rightSum + solve(mid + 1, r, cumSum)});     
        }      


        return t[l][r] = score;     
    }
    int stoneGameV(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();    

        t.resize(n + 1, vector<int>(n + 1, 0));  

        vector<int> cumSum(n);  

        cumSum[0] = stoneValue[0];    

        for(int i = 1; i < n; i++)  
            cumSum[i] = stoneValue[i] + cumSum[i - 1];    
          

        for(int l = n - 1; l >= 0; l--)  
        {
            for(int r = l + 1; r < n; r++)  
            { 
                int score = 0;   
                for(int mid = l; mid < r; mid++)  
                {
                    int leftSum = cumSum[mid] - (l - 1 >= 0 ? cumSum[l - 1] : 0);  
                    int rightSum = cumSum[r] - cumSum[mid];     

                    if(leftSum < rightSum)  
                        score = max(score, leftSum + t[l][mid]);  
                    else if(leftSum > rightSum)  
                        score = max(score, rightSum + t[mid + 1][r]);  
                    else  
                        score = max({score, leftSum + t[l][mid], rightSum + t[mid + 1][r]});     
                }      

                t[l][r] = score;     
            }     
        }   


        return t[0][n - 1];   
    }
};