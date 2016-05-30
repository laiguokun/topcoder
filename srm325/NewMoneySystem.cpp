    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "NewMoneySystem.cpp"  
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
    map<LL,int> m;
    map<LL,int>::iterator it;
    long long tot,dp[10000][100];
    long long f(long long n,int k)
    {
        if (n==0) return 0;
        if (k==1) return n;
        it=m.find(n);
        int now;
        if (it==m.end())
        {
                tot++;
                m.insert(make_pair(n,tot));
                now=tot;
        }
        else
        {
                if (dp[it->second][k]!=0) return dp[it->second][k];
                now=it->second;
        }
        LL res=n;
        res=min(res,n%2LL+f(n/2LL,k-1));
        res=min(res,n%3LL+f(n/3LL,k-1));
        res=min(res,n%4LL+f(n/4LL,k-1));
        res=min(res,n%5LL+f(n/5LL,k-1));
        dp[now][k]=res;
        return dp[now][k];
    }
    void change(string s,long long& x)
    {
        x=0;
        for (int i=0;i<s.length();i++) x=x*10+(int)s[i]-48;
    }
    class NewMoneySystem
    {
            public:
            long long chooseBanknotes(string N, int K)
            {
                        long long n;
                        change(N,n);
                        return f(n,K);
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1025"; int Arg1 = 6; long long Arg2 = 2LL; verify_case(0, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1005"; int Arg1 = 5; long long Arg2 = 3LL; verify_case(1, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "12000"; int Arg1 = 14; long long Arg2 = 1LL; verify_case(2, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "924323565426323626"; int Arg1 = 1; long long Arg2 = 924323565426323626LL; verify_case(3, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "924323565426323626"; int Arg1 = 50; long long Arg2 = 10LL; verify_case(4, Arg2, chooseBanknotes(Arg0, Arg1)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            NewMoneySystem ___test;  
            ___test.run_test(4);  
            return 0;  
    }  
    // END CUT HERE
