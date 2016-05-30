    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "DrivingAround.cpp"  
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
    const LL mode=1000003;
    const int num=51;
    LL ans[num][num],matrix[num][num],g[10][10],f[num][num];
    void fz(LL a[num][num],LL b[num][num])
    {
        for (int i=0;i<num;i++)
                for (int j=0;j<num;j++) a[i][j]=b[i][j];
    }
    void multiply(LL a[num][num],LL b[num][num])
    {
        LL c[num][num];
        fz(c,a);
        for (int i=0;i<num;i++)
                for (int j=0;j<num;j++) a[i][j]=0;
        for (int i=0;i<num;i++)
                for (int j=0;j<num;j++)
                        for (int k=0;k<num;k++)
                        {
                                a[i][j]=(a[i][j]+(c[i][k]*b[k][j]))%mode;
                                if (a[0][48]!=0)
                                        int t=1;
                        }
    }      
    class DrivingAround  
    {  
            public:  
            int numberOfWays(vector <string> adj, int start, int finish, int time)  
            {
                int n=adj.size();
                for (int i=0;i<n;i++)
                        for (int j=0;j<n;j++)
                                if (adj[i][j]!='.') g[i][j]=(int)adj[i][j]-48;
                memset(matrix,0,sizeof(matrix));
                f[0][start]=1;ans[0][start]=1;
                for (int i=1;i<=4;i++)
                        for (int j=0;j<n;j++)
                        {
                                for (int k=0;k<n;k++)
                                        if ((g[k][j]!=0)&&(i>=g[k][j]))
                                                f[i][j]=(f[i][j]+f[i-g[k][j]][k])%mode;
                                ans[0][i*n+j]=f[i][j];
                        }
                if (time<=4) return f[time][finish];
                time-=4;
                for (int i=0;i<=3;i++)
                        for (int j=0;j<n;j++) matrix[(i+1)*n+j][i*n+j]=1;
                for (int i=0;i<n;i++)
                        for (int j=0;j<n;j++)
                        {
                                if (g[i][j]==0) continue;
                                int k1=(5-g[i][j])*n+i;int k2=4*n+j;
                                matrix[k1][k2]=1;
                        }
                while (time>0)
                {
                        if ((time%2)==1)
                        {
                                multiply(ans,matrix);
                        }
                        LL matrix_[num][num];
                        fz(matrix_,matrix);
                        multiply(matrix,matrix_);
                        time/=2;
                }
                return ans[0][4*n+finish];
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".12",
 "2.1",
 "12."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; int Arg3 = 5; int Arg4 = 8; verify_case(0, Arg4, numberOfWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"....52....",
 "..5.......",
 "..........",
 ".......1..",
 "......42.2",
 "5...4.....",
 ".5...4...1",
 "......5...",
 ".3244.....",
 ".........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 10; int Arg4 = 0; verify_case(1, Arg4, numberOfWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"...14....1",
 "......13..",
 ".2...4....",
 "....52.5..",
 "1.3..4....",
 ".3....35.5",
 "4......1.1",
 "..4.4.1.54",
 "....4.11.5",
 "31144.2.4."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 2; int Arg3 = 100; int Arg4 = 316984; verify_case(2, Arg4, numberOfWays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {
                freopen("output.txt","w",stdout);
            DrivingAround ___test;  
            ___test.run_test(2);
            system("pause");
            return 0;  
    }  
    // END CUT HERE  
