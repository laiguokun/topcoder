    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "StrawberryFieldsOnFire.cpp"  
    #include <cstdlib>  
    #include <cctype>  
    #include <cstring>  
    #include <cstdio>  
    #include <cmath>  
    #include <algorithm>  
    #include <vector>  
    #include <string>  
    #include <iostream>  
    #include <sstream>  
    #include <map>  
    #include <set>  
    #include <queue>  
    #include <stack>  
    #include <fstream>  
    #include <numeric>  
    #include <iomanip>  
    #include <bitset>  
    #include <list>  
    #include <stdexcept>  
    #include <functional>  
    #include <utility>  
    #include <ctime>  
    using namespace std;  
      
    #define PB push_back  
    #define MP make_pair  
      
    #define REP(i,n) for(i=0;i<(n);++i)  
    #define FOR(i,l,h) for(i=(l);i<=(h);++i)  
    #define FORD(i,h,l) for(i=(h);i>=(l);--i)  
      
    typedef vector<int> VI;  
    typedef vector<string> VS;  
    typedef vector<double> VD;  
    typedef long long LL;  
    typedef pair<int,int> PII;
    struct arr
    {
        LL a,b,c,d;
    };
    bool cmp(arr a,arr b)
    {
        if (a.a<b.a) return true;else return false;
    }
    arr p[10000],s[1000];
    LL shu[10000],g[10000][2];
    int n,mark[10000];LL ww,hh;
    int ordnum(char x) {return ((int)x-48);}
    LL max(LL a,LL b) { if (a>b) return a;else return b;}
    LL min(LL a,LL b) { if (a<b) return a;else return b;}
    LL calc(LL time)
    {
        int tot=0;
        for (int i=0;i<n;i++)
        {
                p[i*2+1].a=max(g[i][0]-time,1);
                p[i*2+1].b=max(g[i][1]-time,1);
                p[i*2+1].c=min(g[i][1]+time+1,hh+1);
                p[i*2+1].d=1;
                p[i*2].a=min(g[i][0]+time+1,ww+1);
                p[i*2].b=p[i*2+1].b;
                p[i*2].c=p[i*2+1].c;
                p[i*2].d=-1;
                s[tot].a=p[i*2+1].b;s[tot].b=i*2+1;s[tot++].c=1;
                s[tot].a=p[i*2+1].c;s[tot].b=i*2+1;s[tot++].c=2;
                s[tot].a=p[i*2].b;s[tot].b=i*2;s[tot++].c=1;
                s[tot].a=p[i*2].c;s[tot].b=i*2;s[tot++].c=2;
        }
        sort(s,s+tot,cmp);
        int now=0;
        if (s[0].c==1) p[s[0].b].b=0;else p[s[0].b].c=0;
        shu[0]=s[0].a;
        for (int i=1;i<tot;i++)
        {
                if (s[i].a!=s[i-1].a)
                {
                        now++;
                        shu[now]=s[i].a;
                }
                if (s[i].c==1) p[s[i].b].b=now;else p[s[i].b].c=now;
        }
        sort(p,p+n*2,cmp);
        LL sum=0,last=0,ans=0;
        memset(mark,0,sizeof(mark));
        for (int i=0;i<n*2;i++)
        {
                if (i!=0) ans+=sum*(p[i].a-last);
                for (int j=p[i].b;j<p[i].c;j++)
                {
                        if ((mark[j]>0)&&(mark[j]+p[i].d==0)) sum-=shu[j+1]-shu[j];
                        if ((mark[j]==0)&&(mark[j]+p[i].d>0)) sum+=shu[j+1]-shu[j];
                        mark[j]+=p[i].d;
                }
                last=p[i].a;
        }
        return ans;            
    }  
    class StrawberryFieldsOnFire  
    {  
            public:  
            int timeLimit(int w, int h, string need, vector <string> fire)  
            {
                hh=h;ww=w;
                memset(g,0,sizeof(g));
                LL num=0;
                for (int i=0;i<need.length();i++)
                        num=num*10+ordnum(need[i]);
                n=fire.size();
                for (int i=0;i<n;i++)
                {
                        int now=0,x=0,y=0;
                        while (fire[i][now]!=' ')
                        {
                                x=x*10+ordnum(fire[i][now]);
                                now++;
                        }
                        now++;
                        for (int j=now;j<fire[i].length();j++) y=y*10+ordnum(fire[i][j]);
                        g[i][0]=x;g[i][1]=y;
                }
                LL head=0,tail=ww*hh;
                while (head<tail)
                {
                        LL mid=(head+tail)/2+1;
                        if (calc(mid)<=(ww*hh)-num) head=mid;else tail=mid-1;
                }
                return head;
            }


    };  
     

