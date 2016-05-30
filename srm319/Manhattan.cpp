    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "Manhattan.cpp"  
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
    int x[250000],y[250000];
    const int maxn=2000000005;  
      
    class Manhattan  
    {  
            public:  
            vector <int> furthestPair(int n, int a, int b, int m)  
            {
                    memset(x,0,sizeof(x));
                    memset(y,0,sizeof(y));
                    vector <int> res;
                    res.clear();
                    for (int i=0;i<n;i++)
                    {
                        if (i!=0) x[i]=((LL)a*(LL)y[i-1]+(LL)b)%(LL)m;
                        y[i]=((LL)a*(LL)x[i]+(LL)b)%(LL)m;
                    }
                    int aa=maxn,bb=maxn;
                    LL min=maxn,max=-maxn;
                    for (int i=0;i<n;i++)
                    {
                        if (x[i]+y[i]<min) {min=x[i]+y[i];aa=i;}
                        if ((x[i]+y[i]==min)&&(i<aa)) aa=i;
                    }
                    for (int i=0;i<n;i++)
                    {
                        if (i==aa) continue;
                        if (x[i]+y[i]>max) {max=x[i]+y[i];bb=i;}
                        if ((x[i]+y[i]==max)&&(i<bb)) bb=i;
                    }
                    int t;
                    if (aa>bb) {t=aa;aa=bb;bb=t;}
                    int la=aa,lb=bb;
                    LL ans=max-min;
                    a=maxn;b=maxn;min=maxn;max=-maxn;
                    for (int i=0;i<n;i++)
                    {
                        if (x[i]-y[i]<min) {min=x[i]-y[i];aa=i;}
                        if ((x[i]-y[i]==min)&&(i<aa)) aa=i;
                    }
                    for (int i=0;i<n;i++)
                    {
                        if (i==aa) continue;
                        if (x[i]-y[i]>max) {max=x[i]-y[i];bb=i;}
                        if ((x[i]-y[i]==max)&&(i<bb)) bb=i;
                    }
                    if (aa>bb) {t=aa;aa=bb;bb=t;}
                    if (max-min==ans)
                    {
                        if (la==aa)
                        {
                                res.push_back(aa);
                                if (lb<bb) res.push_back(lb); else res.push_back(bb);
                        }
                        else
                        {
                                if (la<aa)
                                {
                                        res.push_back(la);
                                        res.push_back(lb);
                                }
                                else
                                {
                                        res.push_back(aa);
                                        res.push_back(bb);
                                }
                        }
                        return res;
                    }
                    if (max-min>ans)
                    {
                        res.push_back(aa);
                        res.push_back(bb);
                    }
                    else
                    {
                        res.push_back(la);
                        res.push_back(lb);
                    }
                    return res;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 75586; int Arg1 = 284763544; int Arg2 = 899436620; int Arg3 = 72; int Arr4[] = {1, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, furthestPair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 17; int Arg2 = 17; int Arg3 = 17; int Arr4[] = {0, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, furthestPair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 912; int Arg2 = 1023; int Arg3 = 103871; int Arr4[] = {0, 54 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, furthestPair(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            Manhattan ___test;  
            ___test.run_test(-1);  
            return 0;  
    }  
    // END CUT HERE
