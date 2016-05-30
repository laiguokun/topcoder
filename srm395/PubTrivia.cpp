#line 5 "PubTrivia.cpp"
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
const int maxn=600000;
const LL maxint=1000000000000000LL;
LL point[maxn],bouns[maxn],f[maxn],q[maxn][2],p_[maxn];
void change(int n,VI x,LL p[],int g)
{
        int k=0;
        int m=x.size();
        for (int i=1;i<=n;i++)
        {
                p[i]=x[k];
                int s=(k+1)%m;
                x[k]=((x[k]^x[s])+13)%g;
                k=s;
        }
}
class PubTrivia
{
        public:
        long long maximumScore(int N, int tokensNeeded, vector <int> p, vector <int> b)
        {
                int tn=tokensNeeded;
                change(N,p,point,1001);
                change(N,b,bouns,10001);
                for (int i=1;i<=N;i++) {f[i]=-maxint;p_[i]=point[i];point[i]+=point[i-1];}
                if (tn>N) return point[N];
                f[0]=0;
                int h=1,t=1;
                LL mm=0;
                q[h][0]=0;q[h][1]=0;
                for (int i=1;i<=N;i++)
                {
                        if (i>=tn)
                        {
                                f[i]=f[i-tn]+point[i]-point[i-tn]+bouns[i];
                        }
                        f[i]=max(f[i],mm+point[i-1]-p_[i]);
                        mm=max(mm,f[i]-point[i]);
                }
                LL ans=0;
                for (int i=N;i>=N-tn+1;i--) ans=max(ans,f[i]+point[N]-point[i]);
                return ans;
        }
        

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
