class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_set<string> bankSet(begin(bank), end(bank));   
        unordered_set<string> visited;  

        queue<string> que;  
        que.push(startGene);  

        visited.insert(startGene);   

        int level = 0;      

        while(!que.empty())    
        {
            int n = que.size();  

            while(n > 0)    
            {
                string curr = que.front();  
                que.pop();     

                if(curr == endGene)    
                    return level;    

                for(char ch : "ACGT")  
                {
                    for(int i = 0; i < curr.length(); i++)   
                    {
                        string neighbour = curr;   
                        neighbour[i] = ch;   

                        if(visited.find(neighbour) == visited.end() && bankSet.find(neighbour) != bankSet.end())     
                        {   
                            que.push(neighbour);   
                            visited.insert(neighbour);   
                        }
                    }
                }   

                n = n - 1;   
            }   

            level = level + 1;    
        }   


        return -1;   
    }
};