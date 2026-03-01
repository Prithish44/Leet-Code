class Solution {
public:
    int minPartitions(string n) {
        char maxch = *max_element(begin(n), end(n));    


        return maxch - '0';    
    }
};