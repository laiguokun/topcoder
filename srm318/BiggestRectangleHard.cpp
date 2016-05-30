    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "BiggestRectangleHard.cpp"  
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
    #define FOR(i,l,h) for(i=(l);i<=(h);i++)  
    #define FORD(i,h,l) for(i=(h);i>=(l);--i)  
      
    typedef vector<int> VI;  
    typedef vector<string> VS;  
    typedef vector<double> VD;  
    typedef long long LL;  
    typedef pair<int,int> PII;  
    bool f[2][46][46][46][46];
    class BiggestRectangleHard  
    {  
            public:  
            int findArea(vector <int> lengths)  
            {
                int x1,x2,x3,x4;
                memset(f,false,sizeof(f));
                f[0][0][0][0][0]=true;
                int now=0;
                for (int i=0;i<lengths.size();i++)
                {
                        now^=1;
                        memset(f[now],false,sizeof(f[now]));
                        FOR(x1,0,45)
                                FOR(x2,0,45)
                                        FOR(x3,0,45)
                                                FOR(x4,0,45)
                                                {
                                                        if (x1>=lengths[i]) f[now][x1][x2][x3][x4]|=f[now^1][x1-lengths[i]][x2][x3][x4];
                                                        if (x2>=lengths[i]) f[now][x1][x2][x3][x4]|=f[now^1][x1][x2-lengths[i]][x3][x4];
                                                        if (x3>=lengths[i]) f[now][x1][x2][x3][x4]|=f[now^1][x1][x2][x3-lengths[i]][x4];
                                                        if (x4>=lengths[i]) f[now][x1][x2][x3][x4]|=f[now^1][x1][x2][x3][x4-lengths[i]];
                                                        f[now][x1][x2][x3][x4]|=f[now^1][x1][x2][x3][x4];
                                                }
                }
               int ans=-1;
                FOR (x1,1,45)
                        FOR (x2,1,45)
                                if (f[now][x1][x1][x2][x2]) ans=max(ans,x1*x2);
                return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3, 3, 4, 5, 7
    }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, findArea(Arg0)); }
	void test_case_1() { int Arr0[] = {9, 9, 5, 6, 2, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, findArea(Arg0)); }
	void test_case_2() { int Arr0[] = {3, 4, 7, 8, 10, 2, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; verify_case(2, Arg1, findArea(Arg0)); }
	void test_case_3() { int Arr0[] = {9, 2, 7, 9, 4, 9, 7, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 224; verify_case(3, Arg1, findArea(Arg0)); }
	void test_case_4() { int Arr0[] = {9, 9, 10, 7, 7, 8, 7, 5, 8, 6, 9, 7, 7, 10, 9, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 961; verify_case(4, Arg1, findArea(Arg0)); }
	void test_case_5() { int Arr0[] = {2, 6, 4, 10, 2, 8, 1, 8, 2, 1, 4, 8, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 272; verify_case(5, Arg1, findArea(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            BiggestRectangleHard ___test;  
            ___test.run_test(2);  
            system("pause");
              return 0;
    }  
    // END CUT HERE
