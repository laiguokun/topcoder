    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "MountainMap.cpp"  
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
    const int mode=12345678;
    const int num=14;
    int p[]={-1,0,1};
    bool g[4][7];
    int dp[30][1<<num],s1[1<<num],s[1<<num],n,m,ans;
    bool ok(int x,int y){return (x>=0 && x<n && y>=0 && y<m);}
    int calc(bool g[4][7])
    {
        int f[4][7];
        int id[4][7];
        int tot=-1;
        memset(id,-1,sizeof(id));
        memset(s,0,sizeof(s));
        memset(s1,0,sizeof(s1));
        for (int i=0;i<n;i++)
                for (int j=0;j<m;j++)
                        if (g[i][j])
                        {
                                tot++;
                                id[i][j]=tot;
                        }
        tot++;
        int need[4][7];
        memset(need,0,sizeof(need));
        for(int i=0;i<n;i++)
                for (int j=0;j<m;j++)
                        if (id[i][j]!=-1)
                        {
                                for (int x1=0;x1<3;x1++)
                                        for (int x2=0;x2<3;x2++)
                                        {
                                                if (x1==1 && x2==1) continue;
                                                if (ok(i+p[x1],j+p[x2])) need[i+p[x1]][j+p[x2]]+=1<<id[i][j];
                                        }
                        }
        for (int z=0;z<1<<tot;z++)
        {
                memset(f,0,sizeof(f));
                for(int i=0;i<n;i++)
                        for (int j=0;j<m;j++)
                                if (id[i][j]!=-1)
                                {
                                        if ((z & (1<<id[i][j]))!=0)
                                        {
                                                s1[z]++;
                                                for (int x1=0;x1<3;x1++)
                                                        for (int x2=0;x2<3;x2++)
                                                        {
                                                                if (x1==1 && x2==1) continue;
                                                                if (ok(i+p[x1],j+p[x2])) f[i+p[x1]][j+p[x2]]+=1<<id[i][j];
                                                        }

                                        }
                                }
                for(int i=0;i<n;i++)
                        for (int j=0;j<m;j++)
                                if (id[i][j]==-1 && f[i][j]==need[i][j]) s[z]++;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for (int i=1;i<=n*m;i++)
        {
                for (int z=0;z<1<<tot;z++)
                        if (dp[i-1][z]!=0)
                        {
                                dp[i][z]=(dp[i][z]+dp[i-1][z]*(s[z]-(i-1-s1[z])))% mode;
                                for (int j=0;j<tot;j++)
                                {
                                        if ((z & 1<<j)==0)
                                        {
                                                dp[i][z|1<<j]=(dp[i][z|1<<j]+dp[i-1][z])% mode;
                                        }
                                }
                        }
        }
        return dp[n*m][(1<<tot)-1];
    }
    void work(int x,int y,int k,bool g[4][7])
    {
        if (y==m) {x=x+1;y=0;}
        if (x==n)
        {
                int res=calc(g);
                if ((k&1)!=0)
                        ans=((ans-res)%mode+mode)%mode;
                else ans=(ans+res)%mode;
                return ;
        }
        if (!g[x][y])
        {
                /*if (!((ok(x-1,y) && g[x-1][y])
                ||(ok(x,y-1) && g[x][y-1])
                ||(ok(x+1,y) && g[x+1][y])
                ||(ok(x,y+1) && g[x][y+1])))*/
                bool o=true;
                for (int x1=0;x1<3;x1++)
                        for (int x2=0;x2<3;x2++)
                        {
                                if (x1==1 && x2==1) continue;
                                if (ok(x+p[x1],y+p[x2]) && g[x+p[x1]][y+p[x2]]) o=false;
                        }
                if (o)
                {
                        g[x][y]=true;
                        work(x,y+1,k+1,g);
                        g[x][y]=false;
                }
        }
        work(x,y+1,k,g);
    }
    class MountainMap  
    {  
            public:  
            int count(vector <string> data)  
            {  
                n=data.size();m=data[0].length();
                for (int i=0;i<n;i++)
                        for (int j=0;j<m;j++) g[i][j]=(data[i][j]=='X');
                bool o=false;
                for (int i=0;i<n;i++)
                        for (int j=0;j<m;j++)
                        {
                                if (g[i][j])
                                {
                                        o=true;
                                        for (int x1=0;x1<3;x1++)
                                                for (int x2=0;x2<3;x2++)
                                                {
                                                        if (x1==1 && x2==1) continue;
                                                        if (ok(i+p[x1],j+p[x2]) && g[i+p[x1]][j+p[x2]])
                                                                return 0;
                                                }
                                }
                        }
                if (!o) return 0;
                work(0,0,0,g);
                return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"X.",
 ".X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"X.",
 "..",
 ".X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"X.X",
 "...",
 "X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4800; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { string Arr0[] = {"..X.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(5, Arg1, count(Arg0)); }
	void test_case_6() { string Arr0[] = {"....X.",
 "......",
 ".X...X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 869490; verify_case(6, Arg1, count(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            MountainMap ___test;
            ___test.run_test(3);
            system("pause");
            return 0;  
    }  
    // END CUT HERE  
