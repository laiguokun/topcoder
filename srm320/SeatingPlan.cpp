    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "SeatingPlan.cpp"  
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
    LL f[2][2000][21];
    LL cc[100][100];
    string change(LL x)
    {
        string s1,s2;
        s1.clear();s2.clear();
        if (x==0) return "0";
        while (x>0)
        {
                s1=s1+char((x%10)+48);
                x=x/10;
        }
        for (int i=s1.length()-1;i>=0;i--) s2=s2+s1[i];
        return s2;
    }      
    LL gcd(LL a,LL b)
    {
        if ((a%b)!=0) return gcd(b,a%b);else return b;
    }
    LL c(int a,int b)
    {
        cc[0][0]=1;
        for (int i=1;i<=a;i++)
        {
                cc[i][0]=1;
                for (int j=1;j<=b;j++)
                        cc[i][j]=cc[i-1][j-1]+cc[i-1][j];
        }
        return cc[a][b];
    }  
    class SeatingPlan  
    {  
            public:  
            string expectedTrial(int m, int n, int k)  
            {  
                    if (m>n){int t=m;m=n;n=t;};
                    if (k==0) return "1/1";
                    int now=0,last;
                    memset(f,0,sizeof(f));
                    f[now][0][0]=1;
                    for (int i=1;i<=n;i++)
                        for (int j=1;j<=m;j++)
                        {
                                last=now;now^=1;
                                memset(f[now],0,sizeof(f[now]));
                                for (int x=0;x<1<<(m+1);x++)
                                {
                                        for (int s=0;s<=k;s++)
                                        {
                                                if (f[last][x][s]==0) continue;
                                                if (s<k)
                                                {
                                                        if (((x&(1<<(j-1)))==0)&&((x&(1<<j))==0))
                                                        {
                                                                int zt=x+(1<<(j-1))+(1<<j);
                                                                if (j==m) zt=(zt*2)%(1<<(m+1));
                                                                f[now][zt][s+1]+=f[last][x][s];
                                                        }
                                                }
                                                int zt=x;
                                                if ((x&(1<<(j-1)))!=0) zt-=1<<(j-1);
                                                if ((x&(1<<(j)))!=0) zt-=1<<j;
                                                if (j==m) zt=(zt*2)%(1<<(m+1));
                                                f[now][zt][s]+=f[last][x][s];
                                        }
                                }
                        }
                    LL a=0,b=0;
                    for (int i=0;i<1<<(m+1);i++) b+=f[now][i][k];
                    if (b==0) return "Impossible!"; 
                    a=c(m*n,k);
                    LL c=gcd(a,b);
                    a=a/c;b=b/c;
                    string ra,rb;
                    ra=change(a);rb=change(b);
                    return ra+'/'+rb;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 3; string Arg3 = "Impossible!"; verify_case(0, Arg3, expectedTrial(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 0; string Arg3 = "1/1"; verify_case(1, Arg3, expectedTrial(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 2; string Arg3 = "15/8"; verify_case(2, Arg3, expectedTrial(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; string Arg3 = "3/2"; verify_case(3, Arg3, expectedTrial(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 7; int Arg2 = 18; string Arg3 = "70775996591300/172086661"; verify_case(4, Arg3, expectedTrial(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {
            SeatingPlan ___test;  
            ___test.run_test(-1);
            return 0;
    }  
    // END CUT HERE  
