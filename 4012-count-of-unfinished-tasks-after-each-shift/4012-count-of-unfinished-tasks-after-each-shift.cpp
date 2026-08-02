class Solution {
public:   
    int M = 1e9 + 7;   
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) 
    {
       int n = tasks.size();  

       vector<long long> prefix(n, 0);   

       vector<int> result;  

       prefix[0] = tasks[0];  

       for(int i = 0; i < n - 1; i++)  
            prefix[i + 1] = (prefix[i] + tasks[i + 1]);    

        long long curr = 0; 
        
        for(int &shift : shifts)  
        {
            curr = curr + shift;  

            if(curr >= prefix[n - 1])  
            {
                result.push_back(0);   
                curr = 0;   
            }   
            else  
            {
                int cnt = upper_bound(begin(prefix), end(prefix), curr) - begin(prefix);  
                result.push_back(n - cnt);   
            }  
        }   


        return result;   
    }
};