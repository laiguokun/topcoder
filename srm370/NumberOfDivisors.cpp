// BEGIN CUT HERE

// END CUT HERE
#line 5 "NumberOfDivisors.cpp"
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
const long long maxint=1000000000000000000LL;
const int maxn=500;
bool p[501];
LL tot,s[500],f[2][60000],q[10000];
void pre()
{
        memset(p,true,sizeof(p));
        tot=0;
        for (int i=2;i<=maxn;i++)
        {
                if (p[i]) s[tot++]=i;
                int x=i;
                while (x<=maxn)
                {
                        p[x]=false;
                        x+=i;
                }
        }
}
class NumberOfDivisors
{
        public:
        long long smallestNumber(int k)
        {
                pre();
                if (k==1) return 1;
                int t=0;
                for (int i=1;i<=(int)(sqrt((double)k));i++)
                {
                        if (k%i==0)
                        {
                                q[t++]=i;
                                if (i*i!=k) q[t++]=k/i;
                        }
                }
                int now=0;
                for (int j=0;j<t;j++) f[now][q[j]]=maxint;
                f[now][1]=1;
                double ss=1;
                LL ans=maxint;
                for (int i=0;i<tot;i++)
                {
                        ss*=s[i];
                        if (ss>1e+18) break;
                        int last=now;now^=1;
                        for (int j=0;j<t;j++) f[now][q[j]]=maxint;
                        double ds=s[i];
                        LL ls=s[i];
                        int c=2;
                        while (ds<1e+18)
                        {
                                for (int j=0;j<t;j++)
                                {
                                        if ((k%(q[j]*c))==0)
                                        {
                                                if (ds*(double)f[last][q[j]]<1e+18)
                                                        f[now][q[j]*c]=min(f[now][q[j]*c],f[last][q[j]]*ls);
                                        }
                                }
                                ds=ds*s[i];
                                ls=ls*s[i];
                                c++;
                        }
                        ans=min(ans,f[now][k]);
                }
                if (ans==maxint) return -1; return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 1LL; verify_case(0, Arg1, smallestNumber(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 2LL; verify_case(1, Arg1, smallestNumber(Arg0)); }
	void test_case_2() { int Arg0 = 6; long long Arg1 = 12LL; verify_case(2, Arg1, smallestNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        NumberOfDivisors ___test;
        ___test.run_test(2);
        system("pause");
        return 0;
}
// END CUT HERE
