class Solution {
public:
    int visit[256];
    int lengthOfLongestSubstring(string s) {
        memset(visit,-1,sizeof(visit));
        int res=1;
        int left=0;
        int right=0;
        if(s.length()==0)
            return 0;
        visit[s[0]]=0;
        for(right=1;right<s.length();right++)
        {
            if(visit[s[right]]<0||visit[s[right]]<left)
            {
                visit[s[right]]=right;
                int tmpLength=right-left+1;
                if(tmpLength>res)
                    res=tmpLength;
            }
            else
            {
                left=visit[s[right]]+1;
                visit[s[right]]=right;
            }
        }
        return res;
    }
};

