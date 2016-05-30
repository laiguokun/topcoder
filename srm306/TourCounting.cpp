    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "TourCounting.cpp"  
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
    LL ans[50],matrix[50][50];

    class TourCounting  
    {  
            public:  
            int countTours(vector <string> g, int k, int m)  
            {  
                    int n=g.size();
                    k--;
                    LL res=0;
                    for (int now=0;now<n;now++)
                    {
                        memset(ans,0,sizeof(ans));
                        memset(matrix,0,sizeof(matrix));
                        for (int i=0;i<n;i++)
                        {
                                for (int j=0;j<n;j++)
                                        if (g[i][j]=='Y')
                                        {
                                                matrix[i][j]=1;
                                                if (i==now) ans[j]=1;
                                         }
                        }
                        matrix[now][n]=1;
                        matrix[n][n]=1;
                        int step=k-1;
                        while (step>0)
                        {
                                if ((step%2)==1)
                                {
                                        LL t[50];
                                        memcpy(t,ans,sizeof(ans));
                                        memset(ans,0,sizeof(ans));
                                        for (int i=0;i<=n;i++)
                                                for (int j=0;j<=n;j++)
                                                  ans[i]=((t[j]*matrix[j][i])+ans[i])%m;
                                }
                                LL a[50][50],b[50][50];
                                memcpy(a,matrix,sizeof(matrix));
                                memcpy(b,matrix,sizeof(matrix));
                                memset(matrix,0,sizeof(matrix));
                                for (int i=0;i<=n;i++)
                                        for (int j=0;j<=n;j++)
                                                for (int k=0;k<=n;k++)
                                                        matrix[i][j]=((a[i][k]*b[k][j])+matrix[i][j])%m;
                                step=step/2;
                        }
                        res=(res+ans[n]+ans[now])%m;
                    }
                    return (int)res;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNY",
 "NNYN",
 "YNNN",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 100; int Arg3 = 12; verify_case(0, Arg3, countTours(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"NYNNNNN",
 "NNYNNNN",
 "NNNYNNN",
 "NNNNYNN",
 "NNNNNYN",
 "NNNNNNY",
 "YNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 40; int Arg2 = 13; int Arg3 = 9; verify_case(1, Arg3, countTours(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"NYNY",
 "NNNN",
 "YYNY",
 "NYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; int Arg2 = 1000000000; int Arg3 = 0; verify_case(2, Arg3, countTours(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1500; int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, countTours(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"NYYNYYN",
 "YNYNYNY",
 "NYNYNYN",
 "YYYNYNY",
 "NNYYNNY",
 "NYYYNNY",
 "YYYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 100; int Arg3 = 72; verify_case(4, Arg3, countTours(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"NYYY",
 "YNYY",
 "YYNY",
 "YNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 10000; int Arg3 = 3564; verify_case(5, Arg3, countTours(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            TourCounting ___test;  
            ___test.run_test(-1);  
            return 0;  
    }  
    // END CUT HERE  
