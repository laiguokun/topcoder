#line 5 "PseudoRandomKingdom.cpp"
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
double f[505][2],dp[50][505];
bool tr[50][50];
int n,s,c;
void work(int p,int fa)
{
        for (int i=0;i<n;i++)
                if (tr[p][i] && i!=fa) work(i,p);
        memset(f,0,sizeof(f));
        int now=0;
        f[0][now]=1;
        for (int i=0;i<n;i++)
                if (tr[p][i] && i!=fa)
                {
                        int last=now;now^=1;
                        for (int x=0;x<=s;x++) f[x][now]=0;
                        for (int x=0;x<=s;x++)
                        {
                                if (f[x][last]==0) continue;
                                for (int y=0;y<=s;y++)
                                        for (int j=0;j<=c;j++)
                                        {
                                                if (x+y+j>s) break;
                                                if (y+j>x) f[y+j][now]+=(f[x][last]*dp[i][y]/((double)c+1.0));
                                                else f[x][now]+=(f[x][last]*dp[i][y]/((double)c+1.0));
                                        }
                        }
                }
        for (int i=0;i<=s;i++) dp[p][i]=f[i][now];
}
class PseudoRandomKingdom
{
        public:
        double probabilityOfHappiness(vector <string> g, int cost, int savings)
        {
                n=g.size();
                for (int i=0;i<n;i++)
                {
                        int num=0;
                        for (int j=0;j<g[i].length();j++)
                        {
                                if (g[i][j]==' ') {tr[i][num]=true;num=0;continue;}
                                num=num*10+(int)g[i][j]-48;
                        }
                        tr[i][num]=true;
                }
                c=cost;s=savings;
                work(0,-1);
                double res=0;
                for (int i=0;i<=s;i++)
                        res+=dp[0][i];
                return res;
        }
        

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
