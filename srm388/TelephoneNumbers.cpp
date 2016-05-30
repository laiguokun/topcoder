// BEGIN CUT HERE

// END CUT HERE
#line 5 "TelephoneNumbers.cpp"
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
int c[7][7];
bool f[22][1<<20];
inline int clear(int x,int k)
{
      //  int t=1<<(k*2);
      //  if (x==273)
        int t=1<<(k*4);
       // return ((x>>((k+1)*2))<<(k*2))+x%(1<<(k*2));
       return (x/(t<<4)*t+(x&(t-1)));
}
string change(int x)
{
        string res1,res2;
        res1.clear();res2.clear();
        while (x>0)
        {
                int t=x%16;
                if (t<10) res1+=char(t+48);else res1+=char(t-10+(int)'a');
                x/=16;
        }
        int len=res1.length();
        for (int i=6;i>len-1;i--) res2+='0';
        for (int i=len-1;i>=0;i--) res2+=res1[i];
        return res2;
}
class TelephoneNumbers
{
        public:
        string kthNumber(int separation, int k)
        {
                int tot=0;
                for (int i=0;i<7;i++)
                        for (int j=i+1;j<7;j++)
                                c[i][j]=tot++;
                int ans=0;
                if (separation==1) ans=k-1;
                if (separation==2)
                {
                        while (true)
                        {
                                bool ok=true;
                                for (int i=0;i<7;i++)
                                {
                                        int t=clear(ans,i);
                                        if (f[i][t]) ok=false;
                                }
                                if (ok)
                                {
                                        k--;
                                        for (int i=0;i<7;i++)
                                        {
                                                int t=clear(ans,i);
                                                f[i][t]=true;
                                        }
                                }
                                if (k==0)
                                        break;
                                ans++;
                        }
                }
                if (separation==3)
                {
                        while (true)
                        {
                                bool ok=true;
                                for (int i=0;i<7;i++)
                                for (int j=i+1;j<7;j++)
                                {
                                        int t=clear(clear(ans,j),i);
                                        if (f[c[i][j]][t]) {ok=false;break;}
                                }
                                if (ok)
                                {
                                        k--;
                                        for (int i=0;i<7;i++)
                                        for (int j=i+1;j<7;j++)
                                        {
                                                int t=clear(clear(ans,j),i);
                                                f[c[i][j]][t]=true;
                                        }
                                }
                                if (k==0) break;
                                ans++;
                        }
                }
                return change(ans);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 15; string Arg2 = "0000004"; verify_case(0, Arg2, kthNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 17; string Arg2 = "0000101"; verify_case(1, Arg2, kthNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 65536; string Arg2 = "0002023"; verify_case(2, Arg2, kthNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TelephoneNumbers ___test;
        ___test.run_test(1);
        system("pause");
        return 0;
}
// END CUT HERE
