#include<iostream>
#include<list>
#include<string>
using namespace std;

class Solution {
public:
    int allArray[10];
    string res;
    
    Solution(){
        getAllArray();
        res="";
    }

    string getPermutation(int n, int k) {
        list<int> nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        getPermutation(nums,k);
        return res;
    }

    void getPermutation(list<int> &nums,int k)
    {
        if(k==1)
        {
            while(nums.size()!=0)
            {
                char c=(char)('0'+nums.front());
                nums.pop_front();
                res.append(1,c);
            }
            return;
        }
        int n=nums.size();
        int idx=(k-1)/allArray[n-1];
        list<int>::iterator itr=nums.begin();
        for(int i=0;i<idx;i++)
            itr++;
        char target='0'+(*itr);
        nums.erase(itr);
        res.append(1,target);
        getPermutation(nums,k-idx*allArray[n-1]);
    }

    void getAllArray()
    {
        allArray[0]=allArray[1]=1;
        for(int i=2;i<10;i++)
        {
            allArray[i]=i*allArray[i-1];
        }
    }

};

int main()
{
    Solution sln;
    string res=sln.getPermutation(4,6);
    cout<<res<<endl;
    return 0;
}
