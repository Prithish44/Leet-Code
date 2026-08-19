class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        unordered_map<int, int> mp;  

        for(auto &reservedSeat : reservedSeats)    
        {
            int row = reservedSeat[0];  
            int seat = reservedSeat[1];  
            mp[row] = mp[row] | (1 << seat);  
        }  

        int result = (n - mp.size()) * 2;  

        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);  
        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);   

        for(auto &[row, bookedSeatMask] : mp)  
        {
            // auto isAvailable = [&](int seat)  
            // {
            //     return bookedSeat.find(seat) == bookedSeat.end(); 
            // };     

            bool GroupA = (bookedSeatMask & maskA) == 0;    
            bool GroupB = (bookedSeatMask & maskB) == 0;    
            bool GroupC = (bookedSeatMask & maskC) == 0;    

            if(GroupA && GroupC)  
                result = result + 2;  
            else if(GroupA || GroupB || GroupC)  
                result = result + 1;  
        }  


        return result;    
    }
};