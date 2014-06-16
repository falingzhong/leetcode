class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a=abs((long long)dividend);
        long long b=abs((long long)divisor);
        int shift=0;
        int mask=-1;
        int contribute=1;
        int res=0;
        while((b<<1)<=a){
            b=b<<1;
            shift++;
            mask=mask<<1;
            contribute=contribute<<1;
        }
        while((a>=b&&a!=0)||((a<b)&&shift>0)){
            //todo
            //
            if((a&mask)<b)
            {
                mask=mask>>1;
                b=b>>1;
                shift--;
                contribute=contribute>>1;
            }
            else
            {
                res=(int)(res|contribute);
                contribute=contribute>>1;
                a=a-b;
                b=b>>1;
                shift--;
                mask=mask>>1;
            }
        }
        return (dividend>>31^divisor>>31)?-res:res;
    }
};

