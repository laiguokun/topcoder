    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "Wardrobe.cpp"  
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
    const int maxn=50;
    int f[2][51][51][2][2],ss[200];
    void clear(int x)
    {
        for (int i=0;i<=maxn;i++)
                for (int j=0;j<=maxn;j++)
                        for (int i1=0;i1<2;i1++)
                                for (int j1=0;j1<2;j1++)
                                        f[x][i][j][i1][j1]=-1;
    }  
    int max(int a,int b){if (a>b) return a;return b;}
    class Wardrobe  
    {  
            public:  
            int countUnscrewedHoles(vector <int> bolts)
            {
                int n=bolts.size();
                memset(ss,0,sizeof(ss));
                if (n==1) return 0;
                for (int i=0;i<n;i++) ss[bolts[i]]++;
                int now=0;
                clear(now);
                //放完
                if (ss[0]<ss[1]) f[now][ss[0]][ss[1]-ss[0]][0][0]=0;
                else f[now][ss[1]][0][0][0]=0;
                //没放完
                for (int i=1;i<=ss[0];i++) f[now][ss[0]-i][ss[1]][1][1]=i;
                for (int i=1;i<=100;i++)
                {
                        int next=now^1;
                     //   if (i==58)
                        //  int t=1;
                       clear(next);
                        for (int x=0;x<=ss[i-1];x++)
                                for (int y=0;y<=ss[i];y++)
                                {
                                        //放完
                                        if (x+y+ss[i+1]>=ss[i])
                                        {
                                                int k=ss[i]-ss[i+1];
                                                int a,b;
                                                //0 0
                                                b=max(ss[i+1]-ss[i],0);
                                                if (k>=0) a=max(y-k,0);else a=y;
                                                f[next][a][b][0][0]=max(f[next][a][b][0][0],f[now][x][y][0][0]);
                                                int k_=ss[i]-x;
                                                if (k_>=0)
                                                {
                                                        //1 0
                                                        k=k_;
                                                        b=max(ss[i+1]-k,0);
                                                        k=k-ss[i+1];
                                                        if (k>=0) a=max(y-k,0);else a=y;
                                                        f[next][a][b][0][0]=max(f[next][a][b][0][0],f[now][x][y][1][0]);
                                                        //1 1
                                                        k=k_;
                                                        a=max(y-k,0);
                                                        k=k-y;
                                                        if (k>=0) b=max(ss[i+1]-k,0);else b=ss[i+1];
                                                        f[next][a][b][1][0]=max(f[next][a][b][1][0],f[now][x][y][1][1]);
                                                }
                                        }
                                        //没放完
                                        for (int s=1;s<=ss[i];s++)
                                        {
                                               // if ((x==0)&&(y==2))
                                               //  int t=1;
                                                int need=ss[i]-s,a,b;
                                                if (x+y+ss[i+1]<need) continue;
                                                if (need<x) continue;
                                                need-=x;
                                                a=max(y-need,0);
                                                need-=y;
                                                if (need>=0) b=max(ss[i+1]-need,0);else b=ss[i+1];
                                                if (f[now][x][y][0][0]!=-1) f[next][a][b][1][1]=max(f[next][a][b][1][1],f[now][x][y][0][0]+s);
                                                if (f[now][x][y][0][1]!=-1) f[next][a][b][1][1]=max(f[next][a][b][1][1],f[now][x][y][0][1]+s);
                                                if (f[now][x][y][1][1]!=-1) f[next][a][b][1][1]=max(f[next][a][b][1][1],f[now][x][y][1][1]+s);
                                        }
                                }
                        now=next;
                }
                int ans=0;
                ans=max(f[now][0][0][1][1],f[now][0][0][1][0]);
                for (int i=0;i<=ss[n-1];i++) ans=max(ans,f[now][i][0][0][0]);
                return ans;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countUnscrewedHoles(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 3, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, countUnscrewedHoles(Arg0)); }
	void test_case_2() { int Arr0[] = {57, 59, 60, 60, 54, 53, 60, 57, 55, 56, 50, 52, 51, 58, 56, 52, 59, 50, 56, 58}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, countUnscrewedHoles(Arg0)); }
	void test_case_3() { int Arr0[] =  {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, countUnscrewedHoles(Arg0)); }
	void test_case_4() { int Arr0[] = 	{52, 51, 50, 53, 59, 57, 54, 54, 53, 55}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, countUnscrewedHoles(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()
    {  
            Wardrobe ___test;
            ___test.run_test(2);
            return 0;
    }  
    // END CUT HERE
