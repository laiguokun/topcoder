#line 5 "DancingParty.cpp"
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
const int maxint=100000000; 
struct T {int a,b;}; 
T g[1000000];
int s,t,tot,pre[1000000],last[1000000],h[10000],vh[10000],n;
void ins(int a,int b,int c) 
{ 
        tot++; 
        pre[tot]=last[a];last[a]=tot; 
        g[tot].a=b;g[tot].b=c; 
        tot++; 
        pre[tot]=last[b];last[b]=tot; 
        g[tot].a=a;g[tot].b=0; 
} 
int dfs(int x,int flow) 
{ 
        if (x==t) 
        return flow; 
        int res=0; 
        int k=last[x]; 
        while (k!=0) 
        { 
                if ((h[x]==h[g[k].a]+1)&&(g[k].b>0)) 
                { 
                        int tmp=dfs(g[k].a,min(flow-res,g[k].b)); 
                        res+=tmp; 
                        g[k].b-=tmp; 
                        if ((k&1)==0) g[k-1].b+=tmp; else g[k+1].b+=tmp; 
                        if (res==flow) return flow; 
                } 
                k=pre[k]; 
        } 
        if (h[s]==t+1) return res;
        vh[h[x]]--;
        if (vh[h[x]]==0) h[s]=t+1; 
        vh[++h[x]]++; 
        return res; 
} 
bool judge(VS& g,int x,int k)
{
        memset(last,0,sizeof(last));
        tot=0;
        s=6*n;t=s+1;
        for (int i=0;i<n;i++)
        {
                ins(s,i,x);
                ins(i,n+i,x);
                ins(i,2*n+i,k);
        }
        for (int i=n;i<2*n;i++)
                for (int j=0;j<n;j++)
                        if (g[i-n][j]=='Y') ins(i,j+3*n,1);
        for (int i=2*n;i<3*n;i++)
                for (int j=0;j<n;j++)
                        if (g[i-2*n][j]=='N') ins(i,j+4*n,1);
        for (int i=5*n;i<6*n;i++)
        {
                ins(i,t,x);
                ins(i-2*n,i,x);
                ins(i-n,i,k);
        }
        memset(vh,0,sizeof(vh));
        memset(h,0,sizeof(h));
        vh[0]=t+1;
        int maxflow=0;
        while (h[s]<t+1) maxflow+=dfs(s,maxint);
        return maxflow==n*x;
}
class DancingParty
{
        public:
        int maxDances(vector <string> likes, int k)
        {
                n=likes.size();
                int h=0,t=n;
                while (h<t)
                {
                        int m=(h+t+1)/2;
                        if (judge(likes,m,k)) h=m;else t=m-1;
                }
                return h;
        }
        

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
