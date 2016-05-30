// BEGIN CUT HERE

// END CUT HERE
#line 5 "EscapeTheJail.cpp"
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
const int ss[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
double p[230][230];
double f[230];
bool g[230][15][15];
int n,m;
bool ok(int x,int y)
{
        return (x>=0 && x<n && y>=0 && y<m);
}
class EscapeTheJail
{
        public:
        double findExit(vector <string> jail)
        {
                n=jail.size();m=jail[0].size();
                int sx,sy;
                for (int i=0;i<n;i++)
                        for (int j=0;j<m;j++)
                                if (jail[i][j]=='@'){sx=i;sy=j;}
               memset(g,false,sizeof(g));
                g[0][sx][sy]=true;
                for (int i=1;i<=n*m;i++)
                        for (int x=0;x<n;x++)
                                for (int y=0;y<m;y++)
                                {
                                        if (g[i-1][x][y])
                                        {
                                                g[i][x][y]=true;
                                                for (int k=0;k<4;k++)
                                                {
                                                        int nx=ss[k][0]+x,ny=ss[k][1]+y;
                                                        if (ok(nx,ny)&&jail[nx][ny]!='#') g[i][nx][ny]=true;
                                                }
                                        }
                                }
                bool o=false;
                for (int x=0;x<n;x++)
                        for (int y=0;y<m;y++)
                        {
                                if (g[n*m][x][y]==false) jail[x][y]='#';
                                else {if (jail[x][y]=='$') o=true;}
                        }
                if (!o) return -1;
                for (int i=0;i<n;i++)
                        for (int j=0;j<m;j++)
                        {
                                if (jail[i][j]=='$')continue;
                                if (jail[i][j]=='#') continue;
                                int k=i*m+j;
                                int s=0;
                                for (int x1=0;x1<4;x1++)
                                {
                                        int nx=ss[x1][0]+i,ny=ss[x1][1]+j;
                                        if (ok(nx,ny)&&jail[nx][ny]!='#') s++;
                                }
                                for (int x1=0;x1<4;x1++)
                                {
                                        int nx=ss[x1][0]+i,ny=ss[x1][1]+j;
                                        int kk=nx*m+ny;
                                        if (ok(nx,ny)&&jail[nx][ny]!='#')
                                         p[k][kk]=1.0/s;
                                }
                                p[k][n*m]=1;
                                p[k][k]=1;
                        }
                for (int i=0;i<n;i++)
                        for (int j=0;j<m;j++)
                        {
                                if (jail[i][j]=='$') continue;
                                if (jail[i][j]=='#') continue;
                                int k=i*m+j;
                                for (int kk=k+1;kk<n*m;kk++)
                                {
                                        if (p[kk][k]>0)
                                        {
                                                p[kk][kk]-=p[kk][k]*p[k][kk];
                                                if (p[kk][kk]==0) f[kk]=-1;
                                                else
                                                {
                                                        for (int k_=k+1;k_<=n*m;k_++)
                                                        {
                                                                if (k_!=kk) p[kk][k_]=(p[kk][k_]+p[k][k_]*p[kk][k])/p[kk][kk];
                                                        }
                                                        p[kk][kk]=1;
                                                        p[kk][k]=0;
                                                }
                                        }
                                }
                        }
                for (int i=n-1;i>=0;i--)
                        for (int j=m-1;j>=0;j--)
                        {
                                if (jail[i][j]=='$') continue;
                                if (jail[i][j]=='#') continue;
                                int k=i*m+j;
                                for (int kk=k+1;kk<n*m;kk++)
                                {
                                        if (p[k][kk]>0)
                                                f[k]+=p[k][kk]*f[kk];
                                }
                                f[k]+=p[k][n*m];
                        }
                int k=sx*m+sy;
                return f[k];
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"@$"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, findExit(Arg0)); }
	void test_case_1() { string Arr0[] = {"$.#.......", "..$..##.#.", "......#@.#", "..#.$##...", ".###.###.#", "..##..##.#", "#.#...#..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.0; verify_case(1, Arg1, findExit(Arg0)); }
	void test_case_2() { string Arr0[] = {"@..$"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.0; verify_case(2, Arg1, findExit(Arg0)); }
	void test_case_3() { string Arr0[] = {"@#",
 "#$"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -1.0; verify_case(3, Arg1, findExit(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        EscapeTheJail ___test;
        ___test.run_test(1);
        system("pause");
        return 0;
}
// END CUT HERE
