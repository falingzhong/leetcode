#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int Na=a.length();
        int Nb=b.length();
        int N=max(Na,Nb);
        char* ta=new char[N];
        char* tb=new char[N];
        string res;
        int carry=0;
        memset(ta,'0',N);
        memset(tb,'0',N);
        for(int i=0;i<Na;i++)
        {
            ta[i]=a[Na-i-1];
        }
        for(int i=0;i<Nb;i++)
        {
            tb[i]=b[Nb-i-1];
        }
        
        for(int i=0;i<N;i++)
        {
            int sum=ta[i]-'0'+tb[i]-'0'+carry;
            int val=sum%2;
            carry=sum/2;
            res.insert(0,1,'0'+val);
        }
        if(carry>0)
            res.insert(0,1,'0'+carry);
        return res;
    }
};

int main(){
    Solution sln;
    string s=sln.addBinary("1101","11");
    cout<<s<<endl;
    return 0;
}

