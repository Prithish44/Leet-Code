class Solution {
public:  
    vector<int> parent;     
    vector<int> rank;    
    int find(int i)  
    {
        if(i == parent[i])  
            return i;  
        
        return parent[i] = find(parent[i]);  
    }   
    void Union(int x, int y)  
    {
        int x_parent = find(x);  
        int y_parent = find(y);  

        if(x_parent == y_parent)  
            return;  
        
        if(rank[x_parent] > rank[y_parent])    
            parent[y_parent] = x_parent; 
        else if(rank[x_parent] < y_parent)  
            parent[x_parent] = y_parent;   
        else  
        {
            parent[x_parent] = y_parent;  
            rank[y_parent] = rank[y_parent] + 1;   
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {    
        parent.resize(n);   
        rank.resize(n, 0);  
        int count = 0;  

        for(auto &v : connections)     
             count = count + 1;
         
        if(count < n - 1)  
            return -1;   

        for(int i = 0; i < n; i++)    
            parent[i] = i;  
        
        int component = n;   

        for(auto &vec : connections)  
        {
            if(find(vec[0]) != find(vec[1]))   
            {
                Union(vec[0], vec[1]);  
                component = component - 1;  
            }     
        }   


        return component - 1;    
    }
};