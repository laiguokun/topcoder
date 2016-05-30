// BEGIN CUT HERE

// END CUT HERE
#line 5 "ChipArea.cpp"
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
const double eps=1e-9;
struct T{double x,y;};
T p[25000];
double p1[25000];
bool cmp(T a,T b){return a.x<b.x;}
bool cmp1(T a,T b){return a.y<b.y;}
class ChipArea
{
        public:
        double maxArea(int skip, int n)
        {
                int R=1;
                for(int j = 0; j < skip; j++) R = 111 * R % 323537;
                for(int pt = 0; pt < n; pt++)
                {
                        R = 111*R%323537; p[pt].x = R/323537.0;
                        R = 111*R%323537; p[pt].y = R/323537.0;

                }
                p[n].x=0;p[n++].y=0;
                p[n].x=0;p[n++].y=1;
                p[n].x=1;p[n++].y=0;
                p[n].x=1;p[n++].y=1;
                sort(p,p+n,cmp);
                double ans=0;
                for (int i=0;i<n;i++)
                {
                        double l,u,d;
                        u=0;d=1;
                        l=p[i].x;
                        for (int j=i+1;j<n;j++)
                        {
                                if (fabs(p[j].x-p[i].x)<eps) continue;
                                if ((1-l)*(d-u)<ans) break;
                                if (fabs(p[j].y-p[i].y)<eps) break;
                                ans=max(ans,(p[j].x-l)*(d-u));
                                if (fabs(ans-0.06)<0.01)
                                        int t=1;
                                if (p[j].y>p[i].y) d=min(d,p[j].y);
                                if (p[j].y<p[i].y) u=max(u,p[j].y);
                        }
                        ans=max(ans,(1-l)*(d-u));
                        p1[i]=u;
                }
                for (int i=n-1;i>=0;i--)
                {
                        double r,u,d;
                        u=0;d=1;
                        r=p[i].x;
                        for (int j=i-1;j>=0;j--)
                        {
                                if (fabs(p[j].x-p[i].x)<eps) continue;
                                if (r*(d-u)<ans) break;
                                if (fabs(p[j].y-p[i].y)<eps) break;
                                if (p[j].y>p[i].y) d=min(d,p[j].y);
                                if (p[j].y<p[i].y) u=max(u,p[j].y);
                        }
                        ans=max(ans,r*(d-u));
                }
                sort(p,p+n,cmp1);
                for (int i=0;i<n-1;i++)
                        ans=max(ans,p[i].y-p[i-1].y);
                return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 327; int Arg1 = 3; double Arg2 = 0.6058657896932963; verify_case(0, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; double Arg2 = 0.6885306552897291; verify_case(1, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7995; int Arg1 = 25000; double Arg2 = 0.002543062783060902; verify_case(2, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 3000; double Arg2 = 0.0053171745173182395; verify_case(3, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2657; int Arg1 = 2; double Arg2 = 0.4487007515408176; verify_case(4, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 12321; int Arg1 = 2; double Arg2 = 0.615729203993725; verify_case(5, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 15952; int Arg1 = 2; double Arg2 = 0.8629558001353441; verify_case(6, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 2215; int Arg1 = 3; double Arg2 = 0.8157487800137614; verify_case(7, Arg2, maxArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ChipArea ___test;
        ___test.run_test(0);
        system("pause");
        return 0;
}
// END CUT HERE
