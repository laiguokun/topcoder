    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "LastMarble.cpp"  
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
    const int num=101;
    double f[num][num][2];
    bool vis[num][num][2];
    int re;
    int max(int a,int b) {if (a>b) return a;else return b;}
    double cc(int a,int b)
    {
        double res=1;
        for (int i=a-b+1;i<=a;i++) res*=(double)i;
        for (int i=1;i<=b;i++) res/=(double)i;
        return res;
    }
    double work(int r,int b,int x)
    {
        if (vis[r][b][x]) return f[r][b][x];
        vis[r][b][x]=true;
        double &res=f[r][b][x];
        if (r+b==re)
        {
                if (x!=0) res=1;
                return res;
        }
        if (r+b>re)
        {
                double t=0;
                if (r>0) t+=(1-work(r-1,b,1))*r/(r+b);
                if (b>0) t+=(1-work(r,b-1,x^1))*b/(r+b);
                res=max(res,t);
        }
        if (r+b>re+1)
        {
                double t=0;
                if (r>1) t+=(1-work(r-2,b,1))*cc(r,2)/cc(r+b,2);
                if (r>0 && b>0) t+=(1-work(r-1,b-1,1))*r*b/cc(r+b,2);
                if (b>1) t+=(1-work(r,b-2,x^1))*cc(b,2)/cc(r+b,2);
                res=max(res,t);
        }
        if (r+b>re+2)
        {
                double t=0;
                if (r>2) t+=(1-work(r-3,b,1))*cc(r,3)/cc(r+b,3);
                if (r>1 && b>0) t+=(1-work(r-2,b-1,1))*cc(r,2)*b/cc(r+b,3);
                if (r>0 && b>1) t+=(1-work(r-1,b-2,1))*r*cc(b,2)/cc(r+b,3);
                if (b>2) t+=(1-work(r,b-3,x^1))*cc(b,3)/cc(r+b,3);
                res=max(res,t);
        }
        return res;
    }
    class LastMarble
    {
            public:
            double winningChance(int red, int blue, int removed)
            {
                memset(vis,false,sizeof(vis));
                memset(f,0,sizeof(f));
                re=removed;
                return work(red,blue,0);
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 0; double Arg3 = 0.5; verify_case(0, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 0; double Arg3 = 0.3333333333333333; verify_case(1, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 0; double Arg3 = 0.6666666666666666; verify_case(2, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 1; double Arg3 = 0; verify_case(3, Arg3, winningChance(Arg0, Arg1, Arg2)); }

// END CUT HERE

    };  
      
    // BEGIN CUT HERE  
    int main()
    {
            LastMarble ___test;
            ___test.run_test(3);
            system("pause");
            return 0;  
    }
    // END CUT HERE
