    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "TheSquares.cpp"  
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
    struct T{int b;VS r;};
    struct RE{int x,y,l;string name;};
    const int num=1200*1200/2;
    T f[2][3000];
    RE p[3000];
    int d[3000],n,tot,tot_,last[num],pre[num],b[num],last_[num],pre_[num],b_[num];
    bool g[3000][3000],vis[3000];
    bool ff[3000];
    void find(int x)
    {
        if (d[x]!=-1) return;
        int &res=d[x];
        res=0;
        for (int i=0;i<n;i++)
                if (g[x][i])
                {
                        find(i);
                        res=max(res,d[i]+1);
                }
    }
    bool cmp(VS& a,VS& b)
    {
        if (b.size()==0) return true;
        if (a.size()==0) return false;
        return (a[a.size()-1]<=b[b.size()-1]);
    }
    bool cc(RE a,RE b)
    {
        if (a.l<b.l) return false;
        if (a.l>b.l) return true;
        return (a.name<b.name);
    }
    void ins(int x,int y)
    {
        tot++;
        pre[tot]=last[x];
        last[x]=tot;
        b[tot]=y;
    }
    void ins_(int x,int y)
    {
        tot_++;
        pre_[tot]=last_[x];
        last_[x]=tot;
        b_[tot]=y;
    }
    void prepre(int i)
    {
        if (vis[i]) return ;
        vis[i]=true;
        for (int j=0;j<n;j++)
        {
                if (i==j) continue;
                if (p[i].l>=p[j].l && p[i].x<=p[j].x && p[i].y<=p[j].y && p[i].x+p[i].l>=p[j].x+p[j].l && p[i].y+p[i].l>=p[j].y+p[j].l)
                {
                        if (p[i].x==p[j].x && p[i].x==p[j].x && p[i].l==p[j].l)
                        {
                                if (p[i].name>p[j].name) continue;
                                if (p[i].name==p[j].name && i>j) continue;
                        }
                        prepre(j);
                        g[i][j]=true;
                }
        }
        memset(ff,false,sizeof(ff));
        for (int j=0;j<n;j++)
        {
                if (g[i][j])
                {
                        int k=last_[j];
                        while (k!=0)
                        {
                                ff[b_[k]]=true;
                                k=pre_[k];
                        }
                }
        }
        for (int j=0;j<n;j++)
        {
                if (g[i][j] && !ff[j])
                {
                        ins(i,j);
                        if (p[i].name<=p[j].name) ins_(i,j);
                }
        }
    }
    class TheSquares  
    {  
            public:  
            vector <string> findSequence(vector <string> x, vector <string> y, vector <string> lengths, vector <string> names, int k)  
            {
                n=0;
                string xx,yy,nn,ll;
                xx.clear();yy.clear();nn.clear();ll.clear();
                for (int i=0;i<x.size();i++) xx+=x[i];
                for (int i=0;i<y.size();i++) yy+=y[i];
                for (int i=0;i<lengths.size();i++) ll+=lengths[i];
                for (int i=0;i<names.size();i++) nn+=names[i];
                xx+=' ';yy+=' ';nn+=' ';ll+=' ';
                int a=0;
                for (int j=0;j<xx.length();j++)
                {
                        if (xx[j]==' ') {p[n].x=a;a=0;n++;continue;}
                        a=a*10+(int)xx[j]-48;
                }
                a=0;n=0;
                for (int j=0;j<yy.length();j++)
                {
                        if (yy[j]==' ') {p[n].y=a;a=0;n++;continue;}
                        a=a*10+(int)yy[j]-48;
                }
                a=0;n=0;
                for (int j=0;j<ll.length();j++)
                {
                        if (ll[j]==' ') {p[n].l=a;a=0;n++;continue;}
                        a=a*10+(int)ll[j]-48;
                }
                a=0;n=0;
                string bb;bb.clear();
                for (int j=0;j<nn.length();j++)
                {
                        if (nn[j]==' ')
                                {p[n].name=bb;bb.clear();n++;continue;}
                        bb+=nn[j];
                }
                sort(p,p+n,cc);
                int now=0;
                memset(g,false,sizeof(g));
                memset(ff,false,sizeof(ff));
                for (int i=0;i<n;i++) prepre(i);
                memset(d,-1,sizeof(d));
                for (int i=0;i<n;i++) {find(i);}
                int K=k;
                for (int i=0;i<n;i++)
                {
                        if (d[i]>=(K-1))
                        {
                                bool o=true;
                                for (int j=0;j<n;j++)
                                        if (g[j][i] && p[j].name<=p[i].name)
                                                {o=false;break;}
                                if (o)
                                {
                                        f[now][i].b=1;
                                        f[now][i].r.PB(p[i].name);
                                }
                        }
                }
                for (int i=1;i<K;i++)
                {
                        VS min;min.clear();
                        for (int j=0;j<n;j++)
                                if (f[now][j].b!=0 && cmp(f[now][j].r,min))
                                        min=f[now][j].r;
                        if (min.size()==0) break;
                        int lt=now;now^=1;
                        for (int j=0;j<n;j++)
                        {
                                if (f[now][j].b!=0)
                                {
                                        f[now][j].r.clear();
                                        f[now][j].b=0;
                                }
                        }
                        for (int j=0;j<n;j++)
                        {
                                if (!cmp(f[lt][j].r,min)) continue;
                                k=last[j];
                                while (k!=0)
                                {
                                        if (d[b[k]]>=(K-1)-i && f[now][b[k]].b==0 && g[j][b[k]])
                                        {
                                                f[now][b[k]].r=f[lt][j].r;
                                                f[now][b[k]].r.PB(p[b[k]].name);
                                                f[now][b[k]].b=1;
                                        }
                                        k=pre[k];
                                }
                        }
                }
                VS res;res.clear();
                for (int i=0;i<n;i++)
                        if (f[now][i].r.size()!=0)
                                if (cmp(f[now][i].r,res)) res=f[now][i].r;
                return res;
            }
            

    };  

