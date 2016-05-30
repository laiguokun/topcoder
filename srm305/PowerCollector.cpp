    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "PowerCollector.cpp"  
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
    const int maxnum=1000000;
    const double eps=1e-9;
    string res1,res2;
    bool flag[maxnum+1];
   /* bool pf(double x)
    {
        if (abs(floor(sqrt(i))-sqrt(i))<eps) return true;else return false;
    } */
    class PowerCollector
    {
            public:
            string countPowers(string N)
            {
                    long long maxnn=0,maxn;
                    for (int i=0;i<N.length();i++) maxnn=maxnn*10+(int)N[i]-48;
                    maxn=maxnn;
                    int ans=(int)(sqrt((double)maxn));
                    int last=ans;
                    memset(flag,true,sizeof(flag));
                   // printf("%I64d\n",(long long)maxn);
                    for (int i=2;i<=maxnum;i++)
                    {
                        if (!flag[i]) continue;
                        LL now=(LL)i*(LL)i;
                        bool mark=true;
                        if (now<=maxnum) flag[(int)now]=false;
                        if (now<=last) ans--;
                        now=now*(LL)i;
                        while (now<=maxn)
                        {
                             /*   printf("%d",LL(now));*/
                                if (now<=last) ans--;
                                if ((mark)&&(now<=maxnum)) flag[(int)now]=false;
                                ans++;
                              //  if (i==2) printf("%I64d %d %d\n",(long long)now,(int)last,ans);
                                if (now>(maxn/(LL)i)) break;
                             //   if (ans==759250152)
                             //     int t=1;
                                now=now*i;
                        }
                    //    printf("%d\n",ans);
                    }
                    res1.erase(0,res1.length());
                    res2.erase(0,res2.length());
                    while (ans>0)
                    {
                        res1=res1+(char)(ans%10+48);
                        ans=ans/10;
                    }
                    for (int i=0;i<res1.length();i++) res2+=res1[res1.length()-1-i];
                    return res2;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cout << "Test Case #" << Case << "..."; if (Expected == Received) cout << "PASSED" << endl; else { cout << "FAILED" << endl; cout << "\tExpected: \"" << Expected << '\"' << endl; cout << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "576460752303423487"; string Arg1 = "760085355"; verify_case(0, Arg1, countPowers(Arg0)); }
	void test_case_1() { string Arg0 = "576460752303423489"; string Arg1 = "760085356"; verify_case(1, Arg1, countPowers(Arg0)); }
	void test_case_2() { string Arg0 = "1000000000000000000"; string Arg1 = "1001003332"; verify_case(2, Arg1, countPowers(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()
    {  
         //   freopen("output.txt","w",stdout);
            PowerCollector ___test;  
            ___test.run_test(0);
            return 0;
    }  
    // END CUT HERE  
