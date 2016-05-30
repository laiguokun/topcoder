    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "LittleSquares.cpp"  
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
    const int maxn=50;  
    bool r[50];  
    int f[1<<20];  
    class LittleSquares  
    {  
            public:  
            string winner(vector <string> state)  
            {  
                int n=state.size(),m=state[0].length();
                for (int i=(1<<(2*m))-1;i>=0;i--)
                {
                        memset(r,false,sizeof(r));
                        for (int j=0;j<m-1;j++)
                        {
                                int t1=j*2,t2=t1+1,t3=t2+1,t4=t3+1;
                                if ((i & (1<<t1))==0 && (i & (1<<t2))==0 && (i & (1<<t3))==0 && (i & (1<<t4))==0)
                                        r[f[i+(1<<t1)+(1<<t2)+(1<<t3)+(1<<t4)]]=true;
                        }
                        for (int j=0;j<2*m;j++)
                                if ((i & (1<<j))==0) r[f[i+(1<<j)]]=true;
                        for (int j=0;j<maxn;j++)
                                if (!r[j]) {f[i]=j;break;}
                        int t=1;
                }
                int cnt=0;
                for (int i=0;i<n/2;i++)
                {
                        int now=0;
                        for (int j=0;j<m;j++)
                        {
                                if (state[i*2][j]=='#') now=now+(1<<(j*2));
                                if (state[i*2+1][j]=='#') now=now+(1<<(j*2+1));
                        }
                        cnt^=f[now];
                }
                if (n & 1)
                {
                        int t=0;
                        for (int i=0;i<m;i++) if (state[n-1][i]==',') t++;
                        cnt^=t;
                }
                if (cnt) return "first";else return "second";
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "..",
  ".." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "first"; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { string Arr0[] = { "...#",
  "..##" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "first"; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { string Arr0[] = { "..",
  "..",
  "..",
  ".." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "second"; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { string Arr0[] = { "....",
  "...." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "first"; verify_case(3, Arg1, winner(Arg0)); }
	void test_case_4() { string Arr0[] = { ".##.",
  "#..#",
  "#..#",
  ".##." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "second"; verify_case(4, Arg1, winner(Arg0)); }
	void test_case_5() { string Arr0[] = { "#.......",
  ".....##.",
  ".....##.",
  "........",
  "........",
  "........",
  "........",
  "#......#" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "first"; verify_case(5, Arg1, winner(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            LittleSquares ___test;  
            ___test.run_test(1);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE  
