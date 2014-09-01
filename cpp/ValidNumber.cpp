#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        int N=strlen(s);
        char c;
        bool number=false;
        bool dot=false;
        bool exp=false;
        bool space=false;
        bool neg=false;
        int i=0;
        while(i<N&&s[i]==' ')
            ++i;
        for(;i<N;i++)
        {
            c=s[i];
            if(c==' '){
                space=true;
            }
            else if(space==true)
            {
                return false;
            }
            else if((c=='e'||c=='E')&&exp==false&&number==true)
            {
                exp=true;
                number=false;
                dot=true;
                neg=false;
            }
            else if(c=='.'&&dot==false)
            {
                dot=true;
                neg=true;
            }
            else if(c>='0'&&c<='9')
            {
                number=true;
            }
            else if((c=='+'||c=='-')&&neg=false&&number==false)
            {
                neg=true;
            }
            else
            {
                return false;
            }
        }
        return number;
    }
};
