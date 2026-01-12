class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();  
        unordered_map<int, int> lost_mp;  
        vector<int> notLost;  
        vector<int> lostOnce;    

        for(int i = 0; i < n; i++)
        {
            int loser = matches[i][1]; 
            lost_mp[loser] = lost_mp[loser] + 1;  
        }

        for(int i = 0; i < matches.size(); i++)
        {
            int winner = matches[i][0];  
            int loser = matches[i][1];    


            if(lost_mp.find(winner) == lost_mp.end())
            {
                notLost.push_back(winner);  
                lost_mp[winner] = 2;  //  Not Take More In Next Time    
            }

            if(lost_mp[loser] == 1)
                lostOnce.push_back(loser);  
        }


       
        sort(begin(notLost), end(notLost));    
        sort(begin(lostOnce), end(lostOnce));        

        return {notLost, lostOnce};  
    }
};