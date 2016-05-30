    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "RPSChamps.cpp"  
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
    const double eps=1e-15;
    double dp[1000],c[550][550],ci[550];
    double f(int n)
    {
        if (n==1) return 0;
        if (dp[n]!=0) return dp[n];
        double s1=0,s2=0;
        for (int i=1;i<n;i++)
        {
                double k=ci[n]*c[n][i]*3;
                s1=s1+k*(f(i)+f(n-i)+1);
                s2=s2+k;
        }
        s1+=(1-s2);
        dp[n]=s1/(s2);
        return dp[n];
    }
    class RPSChamps  
    {  
            public:  
            double numberOfMoves(int N)
            {
                ci[0]=1;
                for (int i=1;i<=N;i++) ci[i]=ci[i-1]/3;
                c[0][0]=1;
                for (int i=1;i<=N;i++)
                {
                        c[i][0]=1;
                        for (int j=1;j<=i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
                }
                return f(N);
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; double Arg1 = 0.0; verify_case(0, Arg1, numberOfMoves(Arg0)); }
	void test_case_1() { int Arg0 = 2; double Arg1 = 1.5; verify_case(1, Arg1, numberOfMoves(Arg0)); }
	void test_case_2() { int Arg0 = 3; double Arg1 = 3.0; verify_case(2, Arg1, numberOfMoves(Arg0)); }
	void test_case_3() { int Arg0 = 10; double Arg1 = 35.59012622220019; verify_case(3, Arg1, numberOfMoves(Arg0)); }
	void test_case_4() { int Arg0 = 200; double Arg1 = 5.509733035960696E34; verify_case(4, Arg1, numberOfMoves(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            RPSChamps ___test;  
            ___test.run_test(4);
            system("pause");
            return 0;  
    }
    // END CUT HERE  
