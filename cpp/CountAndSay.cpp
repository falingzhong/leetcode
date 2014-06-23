#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        if(n==1)
            return res;
        for(int i=2;i<=n;i++)
        {
            res=readString(res);
            cout<<i<<" "<<res<<endl;
        }
        return res;
    }

    string readString(string is){
        string res="";
        int count=1;
        char c=is[0];
        int L=is.length();
        for(int i=1;i<L;i++)
        {
            if(is[i]!=is[i-1])
            {
                res.append(1,(char)('0'+count));
                res.append(1,c);
                count=1;
                c=is[i];
            }else
            {
                count++;
            }
        }
        res.append(1,(char)('0'+count));
        res.append(1,c);
        return res;
    }
};
int main(){
    Solution sln;
    sln.countAndSay(20);
    return 0;
}
