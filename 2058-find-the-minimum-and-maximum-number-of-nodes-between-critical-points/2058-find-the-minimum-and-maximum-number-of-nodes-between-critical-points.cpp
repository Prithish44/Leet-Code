/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
       ListNode *prev = head; 
       ListNode* curr = head -> next;  

       int firstCriticalIndex = 0; 
       int prevCriticalIndex = 0;  

       int i = 1;    
       
       int minDist = INT_MAX;  

        while(curr -> next != NULL)  
        {
            if((prev -> val > curr -> val && curr -> val < curr -> next -> val) || (prev -> val < curr -> val && curr -> val > curr -> next -> val))  
            {
                if(firstCriticalIndex == 0)  
                {
                    firstCriticalIndex = i; 
                    prevCriticalIndex = i;
                }  
                else  
                {
                    minDist = min(minDist, i - prevCriticalIndex);  
                    prevCriticalIndex = i;  
                }
            }  

            prev = curr;  
            curr = curr -> next;   

            i = i + 1;  
        }   

        if(minDist == INT_MAX)  
            return {-1, -1};    
        

        return {minDist, prevCriticalIndex - firstCriticalIndex};       
    }
};

