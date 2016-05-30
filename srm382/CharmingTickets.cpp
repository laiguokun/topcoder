// BEGIN CUT HERE

// END CUT HERE
#line 5 "CharmingTickets.cpp"
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
const int mode=999983;
const int maxn=9000;
int cnt[2][maxn+10],aa[maxn+10],bb[maxn+10];

class CharmingTickets
{
        public:
        int count(int K, string good)
        {
                int n=good.size(),k=K;
                VI m;
                m.clear();
                for (int i=0;i<n;i++) m.PB((int)good[i]-48);
                int now=0;
                cnt[now][0]=1;
                int a,b;
                a=k/2;
                if ((k & 1)==1) b=k/2+1;else b=k/2;
                for (int i=0;i<k;i++)
                {
                        int last=now;now^=1;
                        memset(cnt[now],0,sizeof(cnt[now]));
                        for (int j=0;j<=maxn;j++)
                        {
                                if (cnt[last][j])
                                {
                                        for (int t=0;t<n;t++)
                                        {
                                                cnt[now][j+m[t]]=cnt[now][j+m[t]]+cnt[last][j];
                                                if (cnt[now][j+m[t]]>=mode) cnt[now][j+m[t]]-=mode;
                                        }
                                }
                        }
                        if (a==(i+1))
                        {
                                for (int j=0;j<=maxn;j++) aa[j]=cnt[now][j];
                        }
                        if (b==(i+1))
                        {
                                for (int j=0;j<=maxn;j++) bb[j]=cnt[now][j];
                        }
                }
                LL ans=0;
                for (int i=0;i<=maxn;i++)
                        ans=(ans+(LL)cnt[now][i]*(LL)cnt[now][i])%mode;
                ans=(ans*2)%mode;
                LL ra=0,rb=0;
                for (int i=0;i<=maxn;i++)
                {
                        ra=(ra+(LL)aa[i]*(LL)aa[i])%mode;
                        rb=(rb+(LL)bb[i]*(LL)bb[i])%mode;
                }
                if (k==1) ra=1;
                ans=((ans-ra*rb)%mode+mode)%mode;
                return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "0123456789"; int Arg2 = 10; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "21"; int Arg2 = 8; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; string Arg1 = "0987654321"; int Arg2 = 1240; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 137; string Arg1 = "0123456789"; int Arg2 = 630063; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CharmingTickets ___test;
        ___test.run_test(0);
        system("pause");
        return 0;
}
// END CUT HERE
