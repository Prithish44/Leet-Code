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
            if(mass < m)  
                return false;  
            if(mass > 1e5)  
                return true;
            if(mass >= m)  
                mass = mass + m;
        }
        return true; 


    }
};