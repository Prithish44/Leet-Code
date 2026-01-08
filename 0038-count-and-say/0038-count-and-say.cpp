class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";  
        

        string say = countAndSay(n - 1);  


        string result = ""; 


        for(int i = 0; i < say.length(); i++)
        {
            char ch = say[i];  
            int count = 1;


            while(i < say.length() - 1 && say[i] == say[i + 1])  //  say.length() - 1 As Compare say[i] == say[i + 1] No Out Of Bound  
            {
                count = count + 1; 
                i = i + 1;  
            }


            result = result + to_string(count) + ch;  //  string(ch, 1);  
        }


        return result;      
    }
};