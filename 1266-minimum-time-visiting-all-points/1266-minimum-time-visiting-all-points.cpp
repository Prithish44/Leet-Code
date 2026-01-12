class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();  


        int step = 0;


        for(int i = 0; i < n - 1; i++)
        {

            //  We Have To Reach Point n - 1    

            
            int x1 = points[i][0]; 
            int y1 = points[i][1];  


            int x2 = points[i + 1][0];  
            int y2 = points[i + 1][1];


            int dx = abs(x2 - x1);  
            int dy = abs(y2 - y1);  


            step = step + min(dx, dy) + abs(dx - dy);  
        }


        return step;  
          
    }
};