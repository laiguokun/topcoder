// BEGIN CUT HERE

// END CUT HERE
#line 5 "AlienLanguage.cpp"
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
const int size=3;
LL matrix[size][size],matrix_[size][size],cnt[size][size];
int mode;
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
class AlienLanguage
{
        public:
        int getNumberOfWords(int P, int Q, int N, int M)
        {
                int n;
                mode=M;
                memset(matrix,0,sizeof(matrix));
                memset(cnt,0,sizeof(cnt));
                matrix[0][0]=P;
                matrix[0][1]=1;
                matrix[1][1]=1;
                cnt[0][0]=P;
                n=N-1;
                while (n>0)
                {
                        if ((n & 1)==1) multiply(cnt,matrix);
                        fz(matrix_,matrix);
                        multiply(matrix,matrix_);
                        n/=2;
                }
                LL a1=(cnt[0][1]+cnt[0][0])% M;
                memset(matrix,0,sizeof(matrix));
                memset(cnt,0,sizeof(cnt));
                matrix[0][0]=P;
                matrix[0][1]=P;
                matrix[1][1]=P;
                matrix[1][2]=1;
                matrix[2][2]=1;
                cnt[0][0]=P;
                cnt[0][1]=P;
                n=N-1;
                while (n>0)
                {
                        if ((n & 1)==1) multiply(cnt,matrix);
                        fz(matrix_,matrix);
                        multiply(matrix,matrix_);
                        n/=2;
                }
                LL a2=(cnt[0][1]+cnt[0][2])%M;
                memset(matrix,0,sizeof(matrix));
                memset(cnt,0,sizeof(cnt));
                matrix[0][0]=Q;
                matrix[0][1]=1;
                matrix[1][1]=1;
                cnt[0][0]=Q;
                n=N-1;
                while (n>0)
                {
                        if ((n & 1)==1) multiply(cnt,matrix);
                        fz(matrix_,matrix);
                        multiply(matrix,matrix_);
                        n/=2;
                }
                LL b1=(cnt[0][0]+cnt[0][1])%M;
                memset(matrix,0,sizeof(matrix));
                memset(cnt,0,sizeof(cnt));
                matrix[0][0]=Q;
                matrix[0][1]=Q;
                matrix[1][1]=Q;
                matrix[1][2]=1;
                matrix[2][2]=1;
                cnt[0][0]=Q;
                cnt[0][1]=Q;
                n=N-1;
                while (n>0)
                {
                        if ((n & 1)==1) multiply(cnt,matrix);
                        fz(matrix_,matrix);
                        multiply(matrix,matrix_);
                        n/=2;
                }
                LL b2=(cnt[0][2]+cnt[0][1])%M;
                LL ans=0;
                ans=(ans+(a1+1)*(b1+1)-1)%M;
                ans=(ans+a2*(b1+1)+(a1+1)*b2)%M;
                ans=(ans+a2*b2)%M;
                return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 9; int Arg4 = 8; verify_case(0, Arg4, getNumberOfWords(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 2; int Arg3 = 1000; int Arg4 = 577; verify_case(1, Arg4, getNumberOfWords(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1000000000; int Arg3 = 1000000000; int Arg4 = 0; verify_case(2, Arg4, getNumberOfWords(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 456; int Arg2 = 789; int Arg3 = 987654321; int Arg4 = 345494202; verify_case(3, Arg4, getNumberOfWords(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        AlienLanguage ___test;
        ___test.run_test(1);
        system("pause");
        return 0;
}
// END CUT HERE
