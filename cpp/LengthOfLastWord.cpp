#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int max=0;
        int start=-1;
        int len=strlen(s);
        int res=0;
        
        for(int i=0;i<len;i++)
        {
            if(s[i]==' ')
            {
                start=i;
            }
            else
            {
                res=i-start;
            }
        }
        return res;
    }
};
