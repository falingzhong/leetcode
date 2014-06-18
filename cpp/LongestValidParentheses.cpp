/**
*   Basic Ideal: Traverse the characters of s from left to right.
*   Use a stack to record the position of '(' we meet. Another 
*   variable is recording the "last not paired position". When meet
*   the ')', update the result according the size of stack and the 
*   value of the variable. O(n) complexity.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        if(s.length()<2)
            return 0;
        int res=0;
        int lastNotPairedIndex=-1;
        if(s[0]==')')
            lastNotPairedIndex=0;
        else
            stk.push(0);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                stk.push(i);
            }
            else
            {
                if(stk.size()==0)
                {
                    lastNotPairedIndex=i;
                }
                else
                {
                    stk.pop();
                    int tlen;
                    if(stk.size()==0)
                        tlen=i-lastNotPairedIndex;
                    else
                    {
                        int left=stk.top();
                        tlen=i-left;
                    }
                    if(tlen>res)
                        res=tlen;
                }
            }
        }
        return res;
    }
};
