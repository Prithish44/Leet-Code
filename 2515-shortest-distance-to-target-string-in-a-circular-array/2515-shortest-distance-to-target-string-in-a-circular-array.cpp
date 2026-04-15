class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();    


        int result = INT_MAX;    


        for(int i = 0; i < n; i++)
        {
            if(words[i] == target)  
            {
                int StartDist = abs(startIndex - i);    


                int CircleDist = n - StartDist;     


                result = min({result, StartDist, CircleDist});
            }
        }     

        return result == INT_MAX ? -1 : result;          
    }
};