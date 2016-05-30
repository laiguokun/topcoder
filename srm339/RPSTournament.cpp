    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "RPSTournament.cpp"  
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
    int fa[100000],q[200000],d[200000],last;  
    int find(int x)
    {
        int y=x;
        while (fa[y]!=y) y=fa[y];
        while (x!=y)
        {
                int t=fa[x];
                fa[x]=y;
                x=t;
        }
        return y;
    }
    bool judge(int x,int c,int md)
    {
        int h=0,t=0;
        q[t]=x;d[t]=0;
        while (h<=t)
        {
                if (d[h]==md) break;
                x=q[h];
                int y=x-floor(sqrt((double)c*(double)x));
                if (y<=0) y=1;
                y=find(y);
                if (y==(last+1)) return false;
                fa[y]=y+1;
                t++;q[t]=y;d[t]=d[h]+1;
                t++;q[t]=x;d[t]=d[h]+1;
                h++;
        }
        return true;
    }
    class RPSTournament  
    {  
            public:  
            int greatestSeed(int rounds, int C)  
            {  
                int h=1,t=1<<(rounds);
                last=t;
                while (h<t)
                {
                        int mid=(h+t+1)/2;
                        for (int i=1;i<=last+1;i++) fa[i]=i;
                        fa[mid]=mid+1;
                        if (judge(mid,C,rounds)) h=mid;else t=mid-1;
                }
                return h;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, greatestSeed(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 6; verify_case(1, Arg2, greatestSeed(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 9; verify_case(2, Arg2, greatestSeed(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 3; int Arg2 = 50; verify_case(3, Arg2, greatestSeed(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 180; int Arg2 = 9755; verify_case(4, Arg2, greatestSeed(Arg0, Arg1)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()
    {  
            RPSTournament ___test;  
            ___test.run_test(4);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE  
