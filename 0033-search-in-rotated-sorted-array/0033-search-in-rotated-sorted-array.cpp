class Solution {
public:  
    int findpivot(vector<int> &nums, int n)  
    {
        int l = 0;    

        int r = n - 1;    

        int mid = l + (r - l) / 2;    

        while(l < r)  
        {
            mid = l + (r - l) / 2;   
            
            if(nums[mid] > nums[r])  
                l = mid + 1;  
            else  
                r = mid;    
        }    


        return l;           
    }    
    int binary_search(int l, int r, vector<int> &nums, int target)    
    {
        int idx = -1;     

        while(l <= r)    
        {
            int mid = l + (r - l) / 2;    

            if(nums[mid] == target)    
            {
                idx = mid;    
                break;
            
            }
            else if(nums[mid] < target)  
                l = mid + 1;  
            else  
                r = mid - 1;  
        }   


        return idx;     
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();     

        int pivot_idx = findpivot(nums, n);  
        
        int idx = binary_search(0, pivot_idx - 1, nums, target);  
        
        if(idx != -1)  
            return idx;  
        
        idx = binary_search(pivot_idx, n - 1, nums, target);     

        
        return idx;   
    }
};