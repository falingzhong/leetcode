class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res; 
        map<string,int> words;  //保存L中的string以及相应的重复次数
        map<string,int> curStr; //扫描过程中的统计重复次数
        map<string,int>::iterator itr;
        int len=0;
        int N=0;
        int NLen=0;
        int i,j=0;
        if(L.size()==0)
            return res;
        N=L.size(); 
        len=L[0].length();
        if(len==0)
            return res;
        NLen=N*len;
        for(i=0;i<N;i++)
        {
            words[L[i]]++;
        }

        for(i=0;i+NLen<=S.length();i++)
        {
            curStr.clear();
            for(j=0;j<N;j++)
            {
                string s=S.substr(i+j*len,len);
                if(words.find(s)==words.end())
                    break;
                ++curStr[s];
                if(curStr[s]>words[s])
                    break;
            }
            if(j==N)
                res.push_back(i);
        }
        return res;
    }
};
