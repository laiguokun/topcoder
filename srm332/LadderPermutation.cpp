    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "LadderPermutation.cpp"  
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
    vector<int> ans;
bool ok(int n,int m,int k)
{
        if (n==0) return (m==0);
        if (n<m) return false;
        if (m*k<n) return false;
        return true;
}
void work(int n,int m,int k,int x)
{
        for (int i=1;i<=min(n,k);i++)
        {
                if (ok(n-i,m-1,k))
                {
                        for (int j=i;j>0;j--) ans.push_back(j+x);
                        work(n-i,m-1,k,x+i);
                        break;
                }
        }
}      
      
    class LadderPermutation  
    {  
            public:  
            vector <int> createLadder(int n, int m, int k)  
            {
                ans.clear();
                if (!ok(n,m,k)) return ans;
                if (n<m+k-1) return ans;
                work(n-k,m-1,k,0);
                for (int i=n;i>n-k;i--) ans.push_back(i);
                return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 2; int Arr3[] = {2, 1, 4, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, createLadder(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arr3[] = {1, 3, 2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, createLadder(Arg0, Arg1, Arg2)); }
      	void test_case_2() {  int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arr3[] = {1, 3, 2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, createLadder(Arg0, Arg1, Arg2));}
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 2; int Arr3[] = {2, 1, 4, 3, 6, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, createLadder(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 3; int Arr3[] = {3, 2, 1, 6, 5, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, createLadder(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 4; int Arr3[] = {1, 2, 3, 7, 6, 5, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, createLadder(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            LadderPermutation ___test;
            ___test.run_test(-1);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE
