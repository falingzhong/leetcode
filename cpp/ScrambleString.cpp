class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())
            return false;
        if(s1.length()==1)
            return s1==s2;
        int L=s1.length();
        char* c1=new char[L];
        char* c2=new char[L];
        s1.copy(c1,L,0);
        s2.copy(c2,L,0);
        sort(c1,c1+L);
        sort(c2,c2+L);
        for(int i=0;i<L;i++)
        {
            if(c1[i]!=c2[i])
                return false;
        }

        for(int i=1;i<=L-1;i++)
        {
            string s11=s1.substr(0,i);
            string s12=s1.substr(i,L-i);
            string s21=s2.substr(0,i);
            string s22=s2.substr(i,L-i);
            //cout<<"s11 s12 s12 s22 "<<s11<<" "<<s12<<" "<<s21<<" "<<s22<<endl;
            bool tres=isScramble(s11,s21)&&isScramble(s12,s22);
            if(tres)
                return true;
            string s31=s2.substr(0,L-i);
            string s32=s2.substr(L-i,i);
            //cout<<"s31 s32"<<s31<<" "<<s32<<endl;
            tres=isScramble(s11,s32)&&isScramble(s12,s31);
            if(tres)
                return true;
        }
        return false;
    }
};

