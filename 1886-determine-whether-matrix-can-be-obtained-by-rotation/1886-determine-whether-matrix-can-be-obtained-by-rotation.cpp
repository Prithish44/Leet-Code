class Solution {
public:
    int n;  


    void rotate(vector<vector<int>> &mat)    
    {
        for(int i = 0; i < n; i++)  
        {
            for(int j = i; j < n; j++)  
                swap(mat[i][j], mat[j][i]);  
        }  


        for(int i = 0; i < n; i++)  
            reverse(begin(mat[i]), end(mat[i]));      
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();  

        for(int c = 1; c <= 4; c++)  
        {
            bool equal = true;  


            for(int i = 0; i < n; i++)  
            {
                for(int j = 0; j < n; j++)  
                {
                    if(mat[i][j] != target[i][j])  
                    {
                        equal = false;  


                        break;
                    }
                }  


                if(!equal)  
                    break;   
            }


            if(equal)  
                return true;  
            

            rotate(mat);  
        }  


        return false;     
    }
};