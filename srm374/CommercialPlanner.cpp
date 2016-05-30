    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "CommercialPlanner.cpp"  
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
    const int maxint=2000000001;
    struct T{LL a,b;};
    T p[100];  
    bool cmp(T a,T b){return a.a<b.a;}  
    class CommercialPlanner  
    {  
            public:  
            int bestMinute(vector <int> starts, vector <int> durations, int ourDuration, int secondsPerDay, int n)
            {  
                LL ans=-1,len=0;
                LL mode=secondsPerDay;
                LL m=starts.size();
                if (m==0) return 0;
                for (int i=0;i<m;i++)
                {
                        p[i].a=starts[i];
                        p[i].b=durations[i];
                }
                sort(p,p+m,cmp);
                for (int i=m;i<m*2;i++) p[i]=p[i-m];
                for (int i=0;i<m-1;i++)
                {
                        LL l=p[i].a+p[i].b,r=p[i+1].a;
                        if ((r-l)>=ourDuration)
                        {
                                LL k=(i+n)%m;int rem;
                                if (n>m) rem=maxint; else rem=((p[k].a-l)%mode+mode)%mode;
                                if (rem>len)
                                {
                                        len=rem;
                                        ans=l;
                                }
                        }
                }
                LL l=p[m-1].a+p[m-1].b,r=p[0].a+mode;
                if ((r-l)>=ourDuration)
                {
                        LL k=(m-1+n)%m;int rem;
                        if (n>m) rem=maxint; else rem=((p[k].a-l)%mode+mode)%mode;
                        if (rem>len)
                        {
                                len=rem;
                                ans=(l+mode)%mode;
                        }
                }
                l=max(mode,l);
                if ((r-l)>=ourDuration)
                {
                        LL k=(m-1+n)%m;int rem;
                        if (n>m) rem=maxint; else rem=((p[k].a-l)%mode+mode)%mode;
                        if (rem>=len)
                        {
                                len=rem;
                                ans=(l+mode)%mode;
                        }
                }
                return ans;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {545027599, 771752846, 924284821, 1571578288, 1340302580, 1131656407, 1694716509, 370612933, 1670018392, 230950875, 1611880014, 411905850}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
 int Arr1[] = {90435511, 95788071, 135859500, 18325822, 75739932, 80544951, 125224613, 1880246, 20399823, 113331402, 57893484, 102523377};
 vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
int Arg2 = 104353209; int Arg3 = 1727956668; int Arg4 = 10; int Arg5 = 11; verify_case(0, Arg5, bestMinute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {30, 5, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12, 6, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 63; int Arg3 = 100; int Arg4 = 4; int Arg5 = 42; verify_case(1, Arg5, bestMinute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {30, 5, 51, 17, 49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12, 6, 10, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 60; int Arg4 = 2; int Arg5 = 20; verify_case(2, Arg5, bestMinute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {30, 5, 51, 17, 49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12, 6, 10, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 64; int Arg3 = 100; int Arg4 = 4; int Arg5 = -1; verify_case(3, Arg5, bestMinute(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()
    {  
            CommercialPlanner ___test;  
            ___test.run_test(0);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE  
