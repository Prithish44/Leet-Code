class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        unordered_map<int, unordered_set<int>> mp;  

        for(auto &reservedSeat : reservedSeats)    
        {
            int row = reservedSeat[0];  
            int seat = reservedSeat[1];  
            mp[row].insert(seat);   
        }  

        int result = (n - mp.size()) * 2;  

        for(auto &[row, bookedSeat] : mp)  
        {
            auto isAvailable = [&](int seat)  
            {
                return bookedSeat.find(seat) == bookedSeat.end(); 
            };     
            bool GroupA = isAvailable(2) && isAvailable(3) && isAvailable(4) & isAvailable(5); 
            bool GroupB = isAvailable(4) && isAvailable(5) && isAvailable(6) & isAvailable(7); 
            bool GroupC = isAvailable(6) && isAvailable(7) && isAvailable(8) & isAvailable(9);  

            if(GroupA && GroupC)  
                result = result + 2;  
            else if(GroupA || GroupB || GroupC)  
                result = result + 1;  
        }  


        return result;    
    }
};