// BEGIN CUT HERE

// END CUT HERE
#line 5 "NestedDiamonds.cpp"
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
double l[100];
double m1,m2;
int n;
double sqr(double a) {return a*a;}
bool cmp(double a,double b) {return a>b;}
void work(int x,double a,double b)
{
        double t=sqr(l[x])-a*2;
        if (b==-1)
        {
                double now=t/2.0;
                m1=max(m1,now);
        }
        else
        {
                double now=-t/2.0;
                m2=min(m2,now);
        }
        if (x!=n-1)
        {
                double t1=sqr(l[x])-a-sqr(l[x+1]);
                if (b==-1)
                {
                        double now=t1;
                        m1=max(m1,now);
                }
                else
                {
                        double now=-t1;
                        m2=min(m2,now);
                }
                work(x+1,sqr(l[x])-a,b*-1);
        }
}
class NestedDiamonds
{
        public:
        double minHeight(vector <int> sides)
        {
                n=sides.size();
                for (int i=0;i<n;i++) l[i]=sides[i];
                sort(l,l+n,cmp);
                for (int i=1;i<n;i++) if (l[i]==l[i-1]) return -1;
                m1=0,m2=sqr(l[0]);
                work(0,0,-1);
                if (m1>m2) return -1; else return sqrt(sqr(l[0])-m2)*2.0;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1000000, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.8284271247461903; verify_case(0, Arg1, minHeight(Arg0)); }
	void test_case_1() { int Arr0[] = {10, 5, 2}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.16515138991168; verify_case(1, Arg1, minHeight(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.69041575982343; verify_case(2, Arg1, minHeight(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -1.0; verify_case(3, Arg1, minHeight(Arg0)); }
	void test_case_4() { int Arr0[] = {1,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.656854249492381; verify_case(4, Arg1, minHeight(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        NestedDiamonds ___test;
        ___test.run_test(-1);
        system("pause");
        return 0;
}
// END CUT HERE
