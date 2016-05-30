    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "TheXGame.cpp"  
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
      
      
    class TheXGame  
    {  
            public:  
            int firstMove(string board)  
            {  
                int n=board.length();
                int ans=100,last;
                for (int i=0;i<n;i++)
                {
                        string news=board;
                        for (int j=i;j<n;j++)
                        {
                                last=j;
                                if (j-i+1>=ans) break;
                                if (board[j]=='X')  break;
                                news[j]='X';
                                int now=0,x=0;
                                bool mark=false;
                                while (now<n)
                                {
                                        int t=0;
                                        while ((now<n)&&(news[now]=='X')) now++;
                                        while ((now<n)&&(news[now]=='-'))
                                        {
                                                now++;
                                                t++;
                                                mark=true;
                                        }
                                        x^=t;
                                }
                                if ((x==0)&&(mark)) ans=j-i+1;
                        }
                }
                if (ans==100) return -1;else return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cout << "Test Case #" << Case << "..."; if (Expected == Received) cout << "PASSED" << endl; else { cout << "FAILED" << endl; cout << "\tExpected: \"" << Expected << '\"' << endl; cout << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "X---X-X-"; int Arg1 = 1; verify_case(0, Arg1, firstMove(Arg0)); }
	void test_case_1() { string Arg0 = "---"; int Arg1 = 2; verify_case(1, Arg1, firstMove(Arg0)); }
	void test_case_2() { string Arg0 = "--XXX" ; int Arg1 = -1; verify_case(2, Arg1, firstMove(Arg0)); }
	void test_case_3() { string Arg0 = "--------X-----X----X"; int Arg1 = 3; verify_case(3, Arg1, firstMove(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            freopen("output.txt","w",stdout);
            TheXGame ___test;  
            ___test.run_test(2);  
            return 0;  
    }  
    // END CUT HERE
  
