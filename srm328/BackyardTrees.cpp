    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "BackyardTrees.cpp"  
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
    const int maxn=501;  
    const mode=1000000000;
    const double eps=1e-15;
    LL s[2][502][502];
    int lx,ly;
    int jiao1(int x1,int y1,int x2,int y2)
    {
        if (y1<=ly) return (min(y2,ly)-y1+1)*(x2-x1+1);else return 0;
    }
    int jiao2(int x1,int y1,int x2,int y2)
    {
        if ((y2>ly)&&(x1<=lx)) return (y2-max(y1,ly+1)+1)*(min(x2,lx)-x1+1);else return 0;
    }
    int gcd(int x,int y)
    {
        if ((x%y)==0) return y;return gcd(y,x%y);
    }
    class BackyardTrees  
    {  
            public:  
            int countWays(int treeCount, int width, int height, int distance)  
            {
                if (treeCount==1) return (width+1)*(height+1);
                int now=0,last=1;
                for (int i=1;i<=maxn;i++)
                        for (int j=1;j<=maxn;j++)
                        {
                              //  f[now][i][j]=1;
                                s[now][i][j]=i;
                        }
                for (int step=2;step<=treeCount;step++)
                {
                        last=now;
                        now^=1;
                        memset(s[now],0,sizeof(s[now]));
                      //  memset(f[now],0,sizeof(f[now]));
                        for (int i=1;i<=maxn;i++)
                        {
                                for (int j=1;j<i;j++)
                                {
                                      //  f[now][i][j]=s[last][i-j][j];
                                        s[now][i][j]=(s[now][i-1][j]+s[last][i-j][j])% mode;
                                }
                        }
                }
                int n=width+1,m=height+1;
                LL ans=0;
                for (int x=1;x<=width;x++)
                        for (int y=1;y<=height;y++)
                        {
                                lx=x;ly=y;
                                if (x>y) {if (gcd(x,y)!=1) continue;}
                                else if (gcd(y,x)!=1) continue;
                                if (x==0) lx=n;if(y==0) ly=m;
                                double bc=distance/(sqrt((double)x*(double)x+(double)y*(double)y));
                                int bb;
                                if (!(abs(floor(bc)-bc)<eps)) bb=int(bc)+1;else bb=int(bc);
                                for (int k=bb*(treeCount-1);k<=maxn;k++)
                                {
                                        if ((x==1)&&(y==1))
                                          int t=1;
                                        int maxx=n-(k-1)*x,minx=max(n-k*x+1,1);
                                        int maxy=m-(k-1)*y,miny=max(m-k*y+1,1);
                                        if ((maxx<=0)||(maxy<=0)) break;
                                      /*  int a=(maxx-minx+1),b=(maxy-miny+1);
                                        int area=a*b;
                                        if (maxx>lx)
                                        {
                                                minx=max(minx,lx+1);
                                                area-=(m-ly)*(maxx-minx+1);
                                        }
                                        if (maxy>ly)
                                        {
                                                miny=max(miny,ly+1);
                                                area-=(n-lx)*(maxy-miny+1);
                                        }
                                        if ((maxx>lx)||(maxy>ly)) area+=(maxx-minx+1)*(maxy-miny+1);
                                        ans=(ans+area*s[now][k][bb])%mode;*/
                                        if (k==5)
                                          int t=1;
                                        LL area=jiao1(minx,1,maxx,maxy)+jiao2(minx,1,maxx,maxy);
                                           area=area+jiao1(1,miny,maxx,maxy)+jiao2(1,miny,maxx,maxy);
                                           area=area-jiao1(minx,miny,maxx,maxy)-jiao2(minx,miny,maxx,maxy);
                                        ans=(ans+area*s[now][k][bb])% mode;
                                      //  printf("%d %d %d %d\n",x,y,k,area);
                                }
                        }
                ans=(ans*2+(s[now][n][distance]*(LL)m+s[now][m][distance]*(LL)n))% mode;
                return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 4; int Arg3 = 1; int Arg4 = 300; verify_case(0, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 36; int Arg2 = 48; int Arg3 = 5; int Arg4 = 2; verify_case(1, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 16; verify_case(2, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 49; int Arg2 = 49; int Arg3 = 1; int Arg4 = 102; verify_case(3, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 5; int Arg2 = 5; int Arg3 = 2; int Arg4 = 0; verify_case(4, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 55; int Arg2 = 75; int Arg3 = 5; int Arg4 = 490260662; verify_case(5, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            BackyardTrees ___test;  
            ___test.run_test(-1);
            return 0;
    }  
    // END CUT HERE

