class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return 0;
        string s1=num1.reverse();
        string s2=num2.reverse();
        int len1=s1.length();
        int len2=s2.length();
        int L=(len1+len2)*4;
        int* tmp=new int[4];
        
        int carry=0;
        int i1,i2;
        int multi;
        int rem;

        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                i1=int(s1[i]-'0');
                i2=int(s2[j]-'0');
                multi=i1*i2;
                res[i+j]+=multi;
            }
        }
        
        for(int i=0;i<L;i++)
        {
            multi=res[i]+carry;
            res[i]=multi%10;
            carry=multi/10;
        }
    }
};

