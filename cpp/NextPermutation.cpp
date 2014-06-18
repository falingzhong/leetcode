class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()==0||num.size()==1)
            return;
        int N=num.size();
        int t=num[N-1];
        int i=N-2;
        int j=N-1;
        while(i>=0&&num[i]>num[i+1])
        {
            i--;
        }
        if(i>=0)
        {
            for(j=i+1;j<N&&num[j]>=num[i];j++){
            };
            j--;
        }
        int tmp=num[i];
        num[i]=num[j];
        num[j]=tmp;
        j=N-1;
        i++;
        while(i<j)
        {
            int tmp=num[i];
            num[i]=num[j];
            num[j]=tmp;
            i++;
            j--;
        }
    }
};
