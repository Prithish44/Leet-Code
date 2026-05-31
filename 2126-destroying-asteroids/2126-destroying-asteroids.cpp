class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        int n = asteroids.size();
        long long Mass;  
        sort(begin(asteroids), end(asteroids));  
        Mass = mass;  
        for(int i = 0; i < n; i++)  
        {
            int m = asteroids[i];
            if(Mass < m)  
                return false;  
            if(Mass >= m)  
                Mass = Mass + m;
        }
        return true; 


    }
};