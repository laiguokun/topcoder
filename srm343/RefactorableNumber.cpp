    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "RefactorableNumber.cpp"  
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
    int tot,p[3000000],h,q[3000000][3];
    LL s[1000000];
    bool f[3000000];
    void ss()
    {
        memset(f,true,sizeof(f));
        for (int i=2;i<=h;i++)
        {
                if (f[i])
                {
                        tot++;
                        s[tot]=i;
                }
                int x=i;
                while (x<=h)
                {
                        f[x]=false;
                        x+=i;
                }
        }
    }
    void bfs()
    {
        int head=0,t=0;
        q[t][0]=0;q[t][1]=1;q[t][2]=1;
        while (head<=t)
        {
                int  now=q[head][0];
                LL x=q[head][1];
                int k=q[head][2];
                p[x]=k;
                for (int i=now+1;i<=tot;i++)
                {
                        if (x*s[i]>h) break;
                        LL tt=s[i];
                        int sum=2;
                        while (x*tt<=h)
                        {
                                t++;
                                q[t][0]=i;q[t][1]=x*tt;q[t][2]=k*sum;
                                tt=tt*s[i];
                                sum++;
                        }
                }
                head++;
        }
    }
    class RefactorableNumber
    {
            public:
            int count(int low, int high)
            {
                    h=high;
                    ss();
                    bfs();
                    int ans=0;
                    for (int i=low;i<=high;i++)
                        if ((i%p[i])==0)
                                ans++;
                    return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 100; int Arg2 = 12; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 25; int Arg1 = 35; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 289383; int Arg1 = 930885; int Arg2 = 315; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            RefactorableNumber ___test;  
            ___test.run_test(0);
            system("pause");
            return 0;  
    }  
    // END CUT HERE
