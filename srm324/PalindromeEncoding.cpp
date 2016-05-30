    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "PalindromeEncoding.cpp"  
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
      
      
    class PalindromeEncoding  
    {  
            public:  
            int getLength(string s)  
            {
                int t,t1;
                for (t=1;t<s.length();t++)
                        if (s[t]!=s[0]) break;
                if ((t==s.length()-1)&&(s[t]==s[0])) return 1;
                bool mark=false;
                for (t1=t;t1<s.length();t1++)
                        if (s[t1]==s[t1-1]) {mark=true;break;}
                if (mark) return t1-(t-1);else return s.length()-(t-1);
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0111001"; int Arg1 = 2; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arg0 = "00001"; int Arg1 = 2; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arg0 = "01010111100110101110000001011000101000010111000111"; int Arg1 = 6; verify_case(2, Arg1, getLength(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            PalindromeEncoding ___test;  
            ___test.run_test(-1);  
            return 0;  
    }  
    // END CUT HERE  
