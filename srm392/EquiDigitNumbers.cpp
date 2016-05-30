// BEGIN CUT HERE

// END CUT HERE
#line 5 "EquiDigitNumbers.cpp"
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
LL c[20];
bool f[10];
int b[10];
LL r;int len;
void change (string a,LL& r,int& len)
{
        len=a.length();
        r=0;
        for (int i=0;i<len;i++) r=r*10+(LL)a[i]-48LL;
}
bool ok(LL num,int s,int now,int p)
{
        int ins=9;
        while (s!=len)
        {
                if (!f[ins])
                {
                        s+=p;
                        for (int i=0;i<p;i++)
                        {
                                num+=ins*c[now];
                                now--;
                        }
                }
                else
                {
                        for (int i=0;i<b[ins];i++)
                        {
                                num+=ins*c[now];
                                now--;
                        }
                }
                ins--;
        }
        for (int j=ins;j>=0;j--)
        {
                if (f[j] && b[j])
                        for (int k=0;k<b[j];k++)
                        {
                                num+=j*c[now];
                                now--;
                        }
        }
        if (num>=r) return true;else return false;
}
class EquiDigitNumbers
{
        public:
        long long findNext(string n)
        {
                change(n,r,len);
                c[0]=1;
                for (int i=1;i<len;i++) c[i]=c[i-1]*10;
                LL ans=-1;
                for (int p=1;p<=len;p++)
                {
                        if (len % p!=0) continue;
                        if (len/p>10) continue;
                        LL num=0;int s=0;
                        memset(f,false,sizeof(f));
                        memset(b,0,sizeof(b));
                        for (int i=len-1;i>=0;i--)
                        {
                                int last;
                                for (int j=0;j<=9;j++)
                                {
                                        if (!f[j])
                                        {
                                                if (s<len)
                                                {
                                                        f[j]=true;s+=p;b[j]=p-1;
                                                      //  if (j==1 && p==2)
                                                      //          int t=1;
                                                        if (ok(num+j*c[i],s,i-1,p)) {num+=j*c[i];break;}
                                                        f[j]=false;s-=p;b[j]=0;
                                                }
                                        }
                                        else
                                        {
                                                if (b[j]==0) continue;
                                                b[j]--;
                                                if (ok(num+j*c[i],s,i-1,p)) {num+=j*c[i];break;}
                                                b[j]++;
                                        }
                                        last=j;
                                }
                                if (last==9) break;
                        }
                        if (num!=0)
                        {
                                if (ans==-1) ans=num; else ans=min(ans,num);
                        }
                }
                return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "42"; long long Arg1 = 42LL; verify_case(0, Arg1, findNext(Arg0)); }
	void test_case_1() { string Arg0 = "2008"; long long Arg1 = 2013LL; verify_case(1, Arg1, findNext(Arg0)); }
	void test_case_2() { string Arg0 = "987654322"; long long Arg1 = 987778899LL; verify_case(2, Arg1, findNext(Arg0)); }
	void test_case_3() { string Arg0 = "12345678910"; long long Arg1 = 22222222222LL; verify_case(3, Arg1, findNext(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        EquiDigitNumbers ___test;
        ___test.run_test(3);
        system("pause");
        return 0;
}
// END CUT HERE
