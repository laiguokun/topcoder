    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "CoolRectangles.cpp"  
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
const int maxint=2000000000;
struct T{int a,b,c;};
T p[200];
int s1[200],s2[200],tot,f1[100000],f2[100000],pre[100000],last[100000],g[100000],c[100000],dist[100000],b[100000],q[2000000];
int maxflow,ans,s,t,l,r,u,d;
bool ma[200][200][2],mark[200][200];
bool cmp(T a,T b){return a.a<b.a;}
void ins(int x,int y,int gg,int cc)
{
        tot++;pre[tot]=last[x];last[x]=tot;b[tot]=y;g[tot]=gg;c[tot]=cc;
        tot++;pre[tot]=last[y];last[y]=tot;b[tot]=x;g[tot]=0;c[tot]=-cc;
}
bool odd(int x){return (x%2);}
bool search()
{
        int h=0,tail=0;
        q[0]=s;
        for (int i=0;i<=t;i++) dist[i]=maxint;
        dist[s]=0;
        while (h<=tail)
        {
                int x=q[h];
                int k=last[x];
                while (k>0)
                {
                        if ((g[k])&&(dist[b[k]]>dist[x]+c[k]))
                        {
                                dist[b[k]]=dist[x]+c[k];
                                f1[b[k]]=k;f2[b[k]]=x;
                                tail++;
                                q[tail]=b[k];
                        }
                        k=pre[k];
                }
                h++;
        }
        return dist[t]<maxint;
}
void work()
{
        int x=t,flow=maxint;
        while (x!=s)
        {
                flow=min(flow,g[f1[x]]);
                x=f2[x];
        }
        x=t;
        while (x!=s)
        {
                g[f1[x]]-=flow;
                if (odd(f1[x])) g[f1[x]+1]+=flow;else g[f1[x]-1]+=flow;
                x=f2[x];
        }
        ans+=dist[t]*flow;
        maxflow+=flow;
}
    bool bfs(int a,int b)
    {
        l=-1;r=-1;u=-1;d=-1;
        int q[20000][2];
        int h=0,t=0;
        q[h][0]=a;q[h][1]=b;
        mark[a][b]=true;
        bool ok=true;
        while (h<=t)
        {
                int x=q[h][0],y=q[h][1];
                //up
                if (!ma[x][y][0])
                {
                        if (!mark[x-1][y])
                        {
                                mark[x-1][y]=true;
                                t++;
                                q[t][0]=x-1;q[t][1]=y;
                        }
                }
                else
                {
                        if (u==-1) u=x;
                        else if (u!=x) ok=false;
                }
                //down
                if (!ma[x+1][y][0])
                {
                        if (!mark[x+1][y])
                        {
                                mark[x+1][y]=true;
                                t++;
                                q[t][0]=x+1;q[t][1]=y;
                        }
                }
                else
                {
                        if (d==-1) d=x+1;
                        else if (d!=(x+1)) ok=false;
                }
                //left
                if (!ma[x][y][1])
                {
                        if (!mark[x][y-1])
                        {
                                mark[x][y-1]=true;
                                t++;
                                q[t][0]=x;q[t][1]=y-1;
                        }
                }
                else
                {
                        if (l==-1) l=y;
                        else if (l!=y) ok=false;
                }
                //right
                if (!ma[x][y+1][1])
                {
                        if (!mark[x][y+1])
                        {
                                mark[x][y+1]=true;
                                t++;
                                q[t][0]=x;q[t][1]=y+1;
                        }
                }
                else
                {
                        if (r==-1) r=y+1;
                        else if (r!=(y+1)) ok=false;
                }
                h++;
        }
        return ok;
    }
    class CoolRectangles  
    {  
            public:  
            int compress(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2)  
            {  
                int n=x1.size(),now,tx,ty;
                for (int i=0;i<n;i++)
                {
                        p[i*2].a=x1[i];p[i*2].b=i;p[i*2].c=1;
                        p[i*2+1].a=x2[i];p[i*2+1].b=i;p[i*2+1].c=2;
                }
                sort(p,p+2*n,cmp);
                now=1;
                for (int i=0;i<2*n;i++)
                {
                        if (i!=0 && p[i].a!=p[i-1].a) now++;
                        if (p[i].c==1) x1[p[i].b]=now; else x2[p[i].b]=now;
                        s1[now]=p[i].a;
                        //printf("%d\n",x1[i]);
                }
                tx=now+1;
                for (int i=0;i<n;i++)
                {
                        p[i*2].a=y1[i];p[i*2].b=i;p[i*2].c=1;
                        p[i*2+1].a=y2[i];p[i*2+1].b=i;p[i*2+1].c=2;
                }
                sort(p,p+2*n,cmp);
                now=1;
                for (int i=0;i<2*n;i++)
                {
                        if (i!=0 && p[i].a!=p[i-1].a) now++;
                        if (p[i].c==1) y1[p[i].b]=now; else y2[p[i].b]=now;
                        s2[now]=p[i].a;
                }
                ty=now+1;
                memset(ma,false,sizeof(ma));
                for (int i=0;i<ty;i++)
                {
                        ma[0][i][0]=true;
                        ma[tx][i][0]=true;
                }
                for (int i=0;i<tx;i++)
                {
                        ma[i][0][1]=true;
                        ma[i][ty][1]=true;
                }
              //  for (int i=0;i<n;i++)
              //  {
              //          printf("%d %d %d %d\n",x1[i],y1[i],x2[i],y2[i]);
               // }
                for (int r=0;r<n;r++)
                {
                        for (int j=y1[r];j<y2[r];j++)
                        {
                                ma[x1[r]][j][0]=true;
                                ma[x2[r]][j][0]=true;
                        }
                        for (int i=x1[r];i<x2[r];i++)
                        {
                                ma[i][y1[r]][1]=true;
                                ma[i][y2[r]][1]=true;
                        }
                }
                memset(mark,false,sizeof(mark));
                int sum=-1;
                for (int i=0;i<tx;i++)
                        for (int j=0;j<ty;j++)
                        {
                                if (i==1 && j==1)
                                        int t=1;
                                if (!mark[i][j] && bfs(i,j))
                                {
                                        sum++;
                                        int area=(s1[d]-s1[u])*(s2[r]-s2[l]);
                                        for (int k=0;k<n;k++)
                                                if (l>=y1[k] && r<=y2[k] && u>=x1[k] && d<=x2[k])
                                                        ins(k,n+sum,1,area);
                                }
                                if (mark[2][2])
                                        int t=1;
                        }
                s=n+sum+1;t=n+sum+2;
                for (int i=0;i<n;i++)   ins(s,i,1,0);
                for (int i=0;i<=sum;i++) ins(n+i,t,1,0);
                maxflow=0;
                while (search()) work();
                if (maxflow<n) return -1; else return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, compress(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, compress(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(2, Arg4, compress(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(3, Arg4, compress(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {0,-1,-2,-3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7,6,5,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(4, Arg4, compress(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {1011,-647,134,-2009,875,819}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {189,-1504,1830,-1383,-319,825}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2530,1930,620,-805,1821,1054}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1419,1224,2476,203,1982,2943}
; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2325650; verify_case(5, Arg4, compress(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
  
    };

    // BEGIN CUT HERE  
    int main()  
    {  
            CoolRectangles ___test;  
            ___test.run_test(1);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE  
