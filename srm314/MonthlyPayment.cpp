    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "MonthlyPayment.cpp"  
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
    const long long maxint=1000000000000000LL;  
    long long p1,p2,b1,b2,tot;
    LL max(LL a,LL b){if (a>b) return a;return b;}
    double min(double a,double b){if (a<b) return a;return b;}
    void change(string a,long long& b)
    {
        b=0;
        for (int i=0;i<a.length();i++) b=b*10+(int)a[i]-48;
    }
    long long calc(long long x)
    {
        double res=0;
        LL sum=0;
        sum=tot-x*b1;
        LL t=sum/b2;
        res=(t+1)*p2;
        for (LL i=t;i>=max(t-10LL,0LL);i--)
                res=min(res,i*p2+(sum-i*b2)*(double)10);
        return res;
    }
    long long calc1(long long x)
    {
        double res=0;
        LL sum=0;
        sum=tot-x*b2;
        LL t=sum/b1;
        res=(t+1)*p1;
        for (LL i=t;i>=max(t-10LL,0LL);i--)
                res=min(res,i*p1+(sum-i*b1)*(double)10);
        return res;
    }  
    class MonthlyPayment  
    {  
            public:  
            long long minimalPayment(string totalSMS, string pack1, string pay1, string pack2, string pay2)  
            {  
                    change(totalSMS,tot);
                    change(pack1,b1);
                    change(pay1,p1);
                    change(pack2,b2);
                    change(pay2,p2);
                    if ((double)p1/(double)b1>10) p1=b1*10LL;
                    if ((double)p2/(double)b2>10) p2=b2*10LL;
                    LL ans=maxint;
                    for (int i=0;i<=5000000;i++)
                    {
                        LL sa=i,sb=max(0,(tot-b1*sa)/b2),sc=max(0,(tot-b1*sa-b2*sb));
                        ans=min(ans,sa*p1+sb*p2+sc*10LL);
                        sb++;sc=0;
                        ans=min(ans,sa*p1+sb*p2+sc*10LL);
                    }
                    for (int i=0;i<=5000000;i++)
                    {
                        LL sb=i,sa=max(0,(tot-b2*sb)/b1),sc=max(0,(tot-b1*sa-b2*sb));
                        ans=min(ans,sa*p1+sb*p2+sc*10LL);
                        sa++;sc=0;
                        ans=min(ans,sa*p1+sb*p2+sc*10LL);
                    }
                    return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "93596042432"; string Arg1 = "343"; string Arg2 = "3479"; string Arg3 = "111"; string Arg4 = "1053"; long long Arg5 = 790LL; verify_case(0, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arg0 = "90"; string Arg1 = "10"; string Arg2 = "90"; string Arg3 = "20"; string Arg4 = "170"; long long Arg5 = 770LL; verify_case(1, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arg0 = "99"; string Arg1 = "10"; string Arg2 = "90"; string Arg3 = "20"; string Arg4 = "170"; long long Arg5 = 850LL; verify_case(2, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arg0 = "10"; string Arg1 = "1"; string Arg2 = "11"; string Arg3 = "20"; string Arg4 = "300"; long long Arg5 = 100LL; verify_case(3, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arg0 = "0"; string Arg1 = "10"; string Arg2 = "80"; string Arg3 = "50"; string Arg4 = "400"; long long Arg5 = 0LL; verify_case(4, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arg0 = "28"; string Arg1 = "1"; string Arg2 = "10"; string Arg3 = "1"; string Arg4 = "8"; long long Arg5 = 224LL; verify_case(5, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { string Arg0 = "450702146848"; string Arg1 = "63791"; string Arg2 = "433956"; string Arg3 = "115281"; string Arg4 = "666125"; long long Arg5 = 2604279739220LL; verify_case(6, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { string Arg0 = "45"; string Arg1 = "6"; string Arg2 = "12"; string Arg3 = "7"; string Arg4 = "14"; long long Arg5 = 90LL; verify_case(7, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            MonthlyPayment ___test;  
            ___test.run_test(0);
            system("pause");
            return 0;
    }  
    // END CUT HERE  

