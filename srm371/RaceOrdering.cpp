// BEGIN CUT HERE

// END CUT HERE
#line 5 "RaceOrdering.cpp"
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
const int mode=1000003;
VI g;
LL c[100][100],dp[1<<16];
bool p[100],f[100][100],n;
bool dfs(int n,int x)
{
        g.PB(x);
        p[x]=false;
        for (int i=0;i<n;i++)
                if (p[i] && (f[i][x] || f[x][i])) dfs(n,i);
}
LL work(VI g)
{
        int n=g.size();
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for (int i=0;i<1<<n;i++)
                if (dp[i])
                {
                        for (int j=0;j<n;j++)
                                if ((i & (1<<j))==0)
                                {
                                        bool o=true;
                                        for (int k=0;k<n;k++)
                                                if (((i & (1<<k))==0)&&(f[g[k]][g[j]]))
                                                {
                                                        o=false;
                                                        break;
                                                }
                                        if (o) dp[i|(1<<j)]=(dp[i|(1<<j)]+dp[i])%mode;
                                }
                }
        return dp[(1<<n)-1];
}
class RaceOrdering
{
        public:
        int countOrders(int n, vector <int> first, vector <int> second)
        {
                int m=first.size();
                memset(p,true,sizeof(p));
                memset(f,false,sizeof(f));
                for (int i=0;i<m;i++) f[first[i]][second[i]]=true;
                c[0][0]=1;
                for (int i=1;i<=n;i++)
                {
                        c[i][0]=1;
                        for (int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mode;
                }
                for (int k=0;k<n;k++)
                        for (int i=0;i<n;i++)
                                for (int j=0;j<n;j++)
                                        f[i][j]=f[i][j]||(f[i][k]&&f[k][j]);
                LL ans=1;
                int sum=n;
                for (int i=0;i<n;i++)
                {
                        if (p[i])
                        {
                                g.clear();
                                dfs(n,i);
                                int now=g.size();
                                LL res=work(g);
                                ans=(ans*res*c[sum][now])%mode;
                                sum-=now;
                        }
                }
                return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, countOrders(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(1, Arg3, countOrders(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 3, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, countOrders(Arg0, Arg1, Arg2)); }
      	void test_case_3(){}// { int Arg0 = 30; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 90317; verify_case(3, Arg3, countOrders(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        RaceOrdering ___test;
        ___test.run_test(0);
        system("pause");
        return 0;
}
// END CUT HERE
