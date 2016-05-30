// BEGIN CUT HERE

// END CUT HERE
#line 5 "StrangeArray.cpp"
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
const int size=2;
const LL mode=1000000007;
LL matrix[size][size],cnt[size][size],p[3000];
void fz(LL a[size][size],LL b[size][size])
{
        for (int i=0;i<size;i++)
                for (int j=0;j<size;j++) a[i][j]=b[i][j];
}
void multiply(LL a[size][size],LL b[size][size])
{
        LL c[size][size];
        fz(c,a);
        for (int i=0;i<size;i++)
                for (int j=0;j<size;j++) a[i][j]=0;
        for (int i=0;i<size;i++)
                for (int j=0;j<size;j++)
                        for (int k=0;k<size;k++)
                        {
                                a[i][j]=(a[i][j]+c[i][k]*b[k][j])%mode;
                        }
}
void change(LL& a,string b)
{
        int len=b.length();
        a=0;
        for (int i=0;i<len;i++) a=a*10+(int)b[i]-48;
}
LL calc(LL a,LL b)
{
        LL res=1;
        while (b>0)
        {
                if (b & 1) res=(res*a)%mode;
                a=(a*a)%mode;
                b/=2;
        }
        return res;
}
class StrangeArray
{
        public:
        int calculateSum(vector <int> A, vector <int> B, string N)
        {
                LL n=A.size(),m=B.size();
                LL s;
                change(s,N);
                LL len=n*m;
                LL Loop=s/len;
                for (LL i=0;i<len;i++) p[i]=calc(A[i%n],B[i%m]+i/m);
                LL ans=0;
                for (LL i=0;i<len;i++)
                {
                        LL t=calc(A[i%n],n);
                        memset(matrix,0,sizeof(matrix));
                        memset(cnt,0,sizeof(cnt));
                        matrix[0][0]=t;
                        matrix[0][1]=1;
                        matrix[1][1]=1;
                        cnt[0][0]=1;
                        LL loop=Loop;
                        while (loop>0)
                        {
                                if (loop & 1) multiply(cnt,matrix);
                                LL matrix_[size][size];
                                fz(matrix_,matrix);
                                multiply(matrix,matrix_);
                                loop/=2;
                        }
                        ans=(ans+p[i]*cnt[0][1])%mode;
                }
                for (LL i=0;i<s%len;i++)
                {
                        LL t=(LL)B[i%m]+(s/len*len+i)/m;
                        ans=(ans+calc(A[i%n],t))%mode;
                }
                return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] =  {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "999999999999999999"; int Arg3 = 17; verify_case(0, Arg3, calculateSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "3"; int Arg3 = 95; verify_case(1, Arg3, calculateSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "5"; int Arg3 = 192; verify_case(2, Arg3, calculateSum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1000000000"; int Arg3 = 607570807; verify_case(3, Arg3, calculateSum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        StrangeArray ___test;
        ___test.run_test(0);
        system("pause");
        return 0;
}
// END CUT HERE
