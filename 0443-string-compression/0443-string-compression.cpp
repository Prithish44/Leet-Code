class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n = chars.size();  

        int i = 0; 
        int index = 0;

        while(i < n)
        {
            int count = 0;   


            char ch = chars[i];     


            while(i < n && chars[i] == ch)  
            {
                count = count + 1;  


                i = i + 1; 
            }  

            chars[index] = ch;   


            index = index + 1;    



            if(count > 1)  
            {
                string count_str = to_string(count);    


                for(char &ch : count_str)  
                {
                    chars[index] = ch;    


                    index = index + 1; 
                }
            }   
        }   


        return index;       
    }
};