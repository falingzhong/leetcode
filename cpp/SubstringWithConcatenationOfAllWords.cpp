class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res; 
        map<string,int> words;  //����L�е�string�Լ���Ӧ���ظ�����
        map<string,int> curStr; //ɨ������е�ͳ���ظ�����
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
