    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "FairTournament.cpp"  
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
    const int num=100;
    int f[2][10000][num];  
    void jia(int a[num],int b[num])
    {
        a[0]=max(a[0],b[0]);
        for (int i=1;i<=a[0];i++)
        {
                a[i]=a[i]+b[i];
                if (a[i]>=10)
                {
                        a[i]-=10;
                        a[i+1]++;
                }
        }
        if (a[a[0]+1]>0) a[0]++;
    }
    class FairTournament  
    {  
            public:  
            string countPermutations(int n, int k)  
            {
                int now=0;
                f[now][0][0]=1;f[now][0][1]=1;
                for (int i=1;i<=n;i++)
                {
                        int last=now;now^=1;
                        memset(f[now],0,sizeof(f[now]));
                        for (int j=0;j<1<<(2*k+1);j++)
                        {
                                for (int t=i+k-1;t>=max(i-k,1);t--)
                                {
                                        if ((j&(1<<(i+k-(t+1))))==0)
                                        {
                                                int z=j+(1<<(i+k-(t+1)));
                                                z=(z*2)%(1<<(2*k+1));
                                                jia(f[now][z],f[last][j]);
                                        }
                                }
                                int z=(j*2)%(1<<(2*k+1))+1;
                                jia(f[now][z],f[last][j]);
                        }
                }
                string ans;
                ans.clear();
                int res=0;
                for (int i=k;i<=min(k+n-1,2*k);i++) res+=(1<<i);
                for (int i=f[now][res][0];i>=1;i--)
                        ans+=char(f[now][res][i]+48);
                return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "3"; verify_case(0, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "6"; verify_case(1, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 3; string Arg2 = "19708"; verify_case(2, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 1; string Arg2 = "573147844013817084101"; verify_case(3, Arg2, countPermutations(Arg0, Arg1)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            FairTournament ___test;  
            ___test.run_test(0);
            system("pause");
            return 0;  
    }  
    // END CUT HERE  
