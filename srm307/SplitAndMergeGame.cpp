    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "SplitAndMergeGame.cpp"  
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
    int f[1<<20],f2[1<<20],f1[1<<20];
    class SplitAndMergeGame  
    {  
            public:  
            int minMoves(vector <int> startState, vector <int> finishState)  
            {  
                for (int i=0;i<=(1<<20);i++) f[i]=0;
                int n1=startState.size(),n2=finishState.size();
                f[0]=0;
                for (int i=0;i<=(1<<n1)-1;i++)
                {
                        int sum=0;
                        for (int j=0;j<n1;j++) if (((1<<j)&i)!=0) sum+=startState[j];
                        f1[i]=sum;
                }
                for (int i=0;i<=(1<<n2)-1;i++)
                {
                        int sum=0;
                        for (int j=0;j<n2;j++) if (((1<<j)&i)!=0) sum+=finishState[j];
                        f2[i]=sum;
                }
                if (f1[(1<<n1)-1]!=f2[(1<<n2)-1]) return -1;
                for (int i=1;i<=(1<<(n1+n2))-1;i++)
                {
                        int k1=i%(1<<n1),k2=i>>n1,k3=f2[k2]-f1[k1];
                        for (int j=0;j<n1;j++)
                        {
                                if ((i&(1<<j))!=0)
                                {
                                        f[i]=max(f[i],f[i-(1<<j)]);
                                }
                        }
                        for (int j=n1;j<n1+n2;j++)
                        {
                                if ((i&(1<<j))!=0)
                                {
                                        f[i]=max(f[i],f[i-(1<<j)]);        
                                }
                        }
                        if (k3==0) f[i]++;
                }
                return n1+n2-(2*f[(1<<(n1+n2))-1]);
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, minMoves(Arg0, Arg1)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            SplitAndMergeGame ___test;  
            ___test.run_test(-1);  
            return 0;  
    }  
    // END CUT HERE
