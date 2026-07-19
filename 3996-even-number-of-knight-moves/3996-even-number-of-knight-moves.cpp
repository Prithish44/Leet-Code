class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) 
    {
        vector<vector<int>> dir = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2}, {-2, -1}, {-1, -2}, {2, -1}, {1, -2}};    

        queue<vector<int>> que;  

        vector<vector<bool>> visited(8, vector<bool> (8, false)); 

        que.push({start[0], start[1], 0});  

        visited[start[0]][start[1]] = true;  

        int count;  

        while(!que.empty())  
        {  
            vector<int> t = que.front(); 
            que.pop();    

            if(t[0] == target[0] && t[1] == target[1])  
            {
                count = t[2];  
                break;    
            } 
            
            for(int i = 0; i < 8; i++)  
            {
                int new_i = t[0] + dir[i][0];  
                int new_j = t[1] + dir[i][1];  

                int new_dis = 1 + t[2];  

                if(new_i >=0 && new_i < 8 && new_j >= 0 && new_j < 8 && !visited[new_i][new_j])    
                {
                    visited[new_i][new_j] = true;
                    que.push({new_i, new_j, new_dis});  
                    
                }
            }
        }  


        return count % 2 == 0;  


        // return (start[0] + start[1]) % 2 == (target[0] + target[1]) % 2;   
        
    }
};