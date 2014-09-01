#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int N=words.size();
        vector<string> res;
        int wordCount=0;
        int wordLen=0;
        int spaceLen=0;
        int gap=0;
        int rem=0;
        int lineLen=0;
        for(int i=0;i<N;i++)
        {
            if(wordLen+wordCount+words[i].length()>L){
                spaceLen=L-wordLen;
                int beg=i-wordCount;
                string s=words[beg];
                if(wordCount==1){
                    gap=spaceLen;
                    rem=0;
                    s.append(gap,' ');
                }else{
                    gap=spaceLen/(wordCount-1);
                    rem=spaceLen%(wordCount-1);
                    for(int j=beg+1;j<i;j++)
                    {
                        int appendSpace=gap+(rem>0?1:0);
                        s.append(appendSpace,' ');
                        s.append(words[j]);
                        rem--;
                    }
                }
                res.push_back(s);
                wordCount=1;
                wordLen=words[i].length();
            }else{
                wordCount++;
                wordLen+=words[i].length();
            }
        }
        if(wordCount>0)
        {
            int beg=words.size()-wordCount;
            string s=words[beg];
            wordCount--;
            beg++;
            while(wordCount>0)
            {
                s.append(1,' ');
                s.append(words[beg]);
                wordCount--;
                beg++;
            }
            int left=L-s.length();
            s.append(left,' ');
            res.push_back(s);
        }
        return res;
    }
};

int main(){
    Solution sln;
    string wds[]={"Listen","to","many,","speak","to","a","few."};
    vector<string> words(wds,wds+7);
    vector<string> res=sln.fullJustify(words,6);
    for(int i=0;i<res.size();i++)
    {
        cout<<"\""<<res[i]<<"\""<<endl;
    }
    return 0;
}
