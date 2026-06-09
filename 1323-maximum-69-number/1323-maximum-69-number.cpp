class Solution {
public:
    int maximum69Number (int num) 
    {
        string numStr = to_string(num);  

        int n = numStr.length();  

        for(int i = 0; i < n; i++)  
        {
            if(numStr[i] == '6')  
            {
                numStr[i] = '9';  
                break;    
            }  
        }  
  
        num = stoi(numStr);    
    

        return num;       
    }
};