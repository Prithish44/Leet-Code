class Solution {
public: 
    typedef pair<int, int> P;
    long long continuousSubarrays(vector<int>& nums) 
    {
        int n = nums.size();  

        long long count = 0; 

        priority_queue<P, vector<P>> maxHeap; 
        priority_queue<P, vector<P>, greater<P>> minHeap; 
        
        int i = 0;  
        int j = 0;     

        while(j < n)  
        {
            maxHeap.push({nums[j], j});     
            minHeap.push({nums[j], j});  
            while(abs(maxHeap.top().first - minHeap.top().first) > 2)  
            {   
                i++;   

                while(!maxHeap.empty() && maxHeap.top().second < i)  
                    maxHeap.pop();  
                
                while(!minHeap.empty() && minHeap.top().second < i)  
                    minHeap.pop();  
            }  

            count = count + j - i + 1;  
            j++;  
        }   


        return count;    
    }
};