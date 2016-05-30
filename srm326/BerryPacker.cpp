    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "BerryPacker.cpp"  
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
    struct T{double a;int b;};
    int f[200000];
    int s1[100],s2[100];
    T cost[100];
    bool cmp(T a,T b){return a.a>b.a;}
    class BerryPacker  
    {  
            public:  
            double bestPacking(vector <int> first, vector <int> period, int berries)  
            {  
                    int n=first.size();
                   // bool ok=true;
                    for (int i=0;i<n;i++)
                    {
                        int now=first[i]+1;
                        //if (now<=berries) ok=false;
                        while (now<=berries)
                        {
                                f[now]=f[now]+(1<<i);
                                now+=period[i];
                        }
                    }
                   // if (ok) return 0;
                    memset(s1,0,sizeof(s1));
                    memset(s2,0,sizeof(s2));
                    for (int i=1;i<=berries;i++)
                    {
                        for (int j=0;j<n;j++) if ((f[i]&(1<<j))>0) s1[j]++;
                        s2[f[i]]++;
                    }
                    double ans=0;
                    for (int box=berries;box>0;box--)
                    {
                        if (box*9<berries)
                          break;
                        int leave=berries-box;
                        cost[0].a=0;cost[0].b=0;
                        for (int i=0;i<n;i++)
                                for (int j=0;j<(1<<i);j++)
                                {
                                        if (s1[i]!=0) cost[j+(1<<i)].a=cost[j].a+(1.0/(double)s1[i])/(double)n;
                                        else cost[j+(1<<i)].a=cost[j].a;
                                        cost[j+(1<<i)].b=j+(1<<i);
                                }
                        sort(cost,cost+(1<<n),cmp);
                        double res=0;
                        for (int i=0;i<1<<n;i++)
                        {
                                if (8*s2[cost[i].b]>=leave)
                                {
                                        res=res+(double)leave*cost[i].a;
                                        //if ((box==210)) {printf("%f %d %d\n",cost[i].a*n,cost[i].b,leave);printf("%f\n",res);}
                                        break;
                                }
                                else
                                {
                                        leave=leave-8*s2[cost[i].b];
                                        res=res+(double)s2[cost[i].b]*8.0*cost[i].a;
                                        //if ((box==210)&&(s2[cost[i].b]!=0)) {printf("%f %d %d\n",cost[i].a*n,cost[i].b,s2[cost[i].b]*8);printf("%f\n",res);}
                                }
                        }
                        int r=0;
                        for (int i=0;i<n;i++) if (s1[i]!=0) r++;
                        s2[f[box]]--;
                        for (int j=0;j<n;j++) if ((f[box]&(1<<j))>0) s1[j]--;
                        ans=max(ans,(res+(double)r/(double)n)*(double)box);
                    }
                    return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] ={78, 292, 29922, 4774, 27171}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] ={928, 2817, 88, 1, 992}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 500; double Arg3 = 12.0; verify_case(0, Arg3, bestPacking(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = 9.0; verify_case(1, Arg3, bestPacking(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,5,9,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,11,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; double Arg3 = 251.50649350649354; verify_case(2, Arg3, bestPacking(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()
    {  
            BerryPacker ___test;  
            ___test.run_test(0);
            system("pause");  
            return 0;
    }  
    // END CUT HERE  
