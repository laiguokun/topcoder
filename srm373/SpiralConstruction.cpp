    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "SpiralConstruction.cpp"  
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
    const int maxn=16;
    const double eps=1e-9;
    struct T{double x,y;};
    T p[20];
    bool f[1<<maxn][maxn];
    int n;
    double cross(T a,T b,T c,T d)
    {
        double x1=b.x-a.x;double y1=b.y-a.y;
        double x2=d.x-c.x;double y2=d.y-c.y;
        return x1*y2-x2*y1;
    }
    bool check(int x,int a,int b)
    {
        for (int i=0;i<n;i++)
                if (x & (1<<i))
                {
                        if (i==a) continue;
                        double k=cross(p[a],p[b],p[a],p[i]);
                        if (k<-eps) return false;
                        if (fabs(k)<eps)
                        {
                                if (fabs(p[a].x-p[b].x)<eps)
                                {
                                        if (p[a].y>p[b].y && p[a].y>p[i].y) return false;
                                        if (p[a].y<p[b].y && p[a].y<p[i].y) return false;
                                }
                                else
                                {
                                        if (p[a].x>p[b].x && p[a].x>p[i].x) return false;
                                        if (p[a].x<p[b].x && p[a].x<p[i].x) return false;
                                }
                        }
                }
        return true;
    }
    class SpiralConstruction  
    {  
            public:  
            int longestSpiral(vector <string> points)  
            {
                n=points.size();
                for (int i=0;i<n;i++)
                {
                        int len=points[i].length();
                        int j;
                        int a=0,b=1;
                        for (j=0;j<len;j++)
                        {
                                if (points[i][j]==' ') break;
                                if (points[i][j]=='-') {b=b*-1;continue;}
                                a=a*10+(int)points[i][j]-48;
                        }
                        p[i].x=a*b;
                        a=0;b=1;
                        for (j=j+1;j<len;j++)
                        {
                                if (points[i][j]=='-') {b=b*-1;continue;}
                                a=a*10+(int)points[i][j]-48;
                        }
                        p[i].y=a*b;
                }
                n++;
                p[n-1].x=0;p[n-1].y=0;
                memset(f,false,sizeof(f));
                f[1<<(n-1)][n-1]=true;
                int ans=0;
                for (int i=1;i<1<<n;i++)
                        for (int j=0;j<n;j++)
                        {
                                if (!f[i][j]) continue;
                                int s=0;
                                for (int k=0;k<n;k++)
                                {
                                        if (i & (1<<k)) {s++;continue;}
                                       /* printf("%d %d %d\n",i,j,k);
                                        if (i==64 && j==6 && k==9)
                                                int t=1;*/
                                        if (((i+(1<<k))==15))
                                                int t=1;
                                        if (check(i,j,k))
                                                f[i+(1<<k)][k]=true;
                                }
                                ans=max(ans,s-1);
                                if (ans==3)
                                        int t=1;
                        }
                return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 1", "1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, longestSpiral(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 1", "2 2", "-1 -1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, longestSpiral(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 1", "1 1", "0 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, longestSpiral(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 1", "-1 0", "0 -1", "1 2", "2 -2", "-2 1", "1 0", "-1 -1", "1 3", "-3 -2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, longestSpiral(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            SpiralConstruction ___test;  
            ___test.run_test(1);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE  
