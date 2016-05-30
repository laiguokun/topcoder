    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "WSNParentsAssignment.cpp"  
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
    int res[60],match[3000],mark[60];
    bool g[60][3000],g_[60][60],ck[3000];
    int n,m;
    VI ans;
    bool search(int x,int k)
    {
        for (int i=0;i<=m;i++)
        {
                if (ck[i] && g[x][i])
                {
                        ck[i]=false;
                        int t=match[i],t1=mark[x];
                        if (t!=-1 && t<k) continue;
                        match[i]=x;
                        mark[x]=i;
                        if (t==-1 || search(t,k)) return true;
                        mark[x]=t1;
                        match[i]=t;
                }
        }
        return false;
    }
    bool calc(int x)
    {
        memset(g,false,sizeof(g));
        memset(match,-1,sizeof(match));
        memset(mark,-1,sizeof(mark));
        m=-1;
        for (int j=0;j<n;j++)
                for (int k=0;k<x;k++)
                {
                        m++;
                        for (int i=0;i<n;i++)   g[i][m]=g_[i][j];
                }
        for (int k=0;k<n;k++)
        {
                m++;
                for (int i=0;i<n;i++) g[i][m]=g_[i][n];
        }
        int sum=0;
        for (int i=n-1;i>=0;i--)
        {
                memset(ck,true,sizeof(ck));
                if (search(i,0)) sum++;
        }
        ans.clear();
        if (sum==n)
        {
                if (x==0) { for (int i=0;i<n;i++) ans.PB(n);return true;}
                for (int i=0;i<n;i++)
                {
                        memset(ck,true,sizeof(ck));
                        for (int j=0;j<=m;j++)
                        {
                                if (mark[i]==j) break;
                                if (ck[j] && g[i][j])
                                {
                                        ck[j]=false;
                                        int t=match[j],t1=mark[i];
                                        if (t!=-1 && t<i) continue;
                                        match[mark[i]]=-1;
                                        match[j]=i;
                                        mark[i]=j;
                                        if (t==-1 || search(t,i)) break;
                                        match[t1]=i;
                                        match[j]=t;
                                        mark[i]=t1;
                                }
                        }
                }
                for (int i=0;i<n;i++) ans.PB(min(mark[i]/x,n));
                return true;
        }
        else return false;
    }
    class WSNParentsAssignment  
    {  
            public:  
            vector <int> minNetworkBurdenLevel(vector <string> network, string nearest)  
            {  
                n=network.size();
                memset(g_,false,sizeof(g_));
                for (int i=0;i<n;i++)
                        for (int j=0;j<n;j++) g_[i][j]=network[i][j]=='Y';
                for (int i=0;i<n;i++) g_[i][n]=nearest[i]=='Y';
                int h=0,t=n+1;
                while (h<t)
                {
                        int mid=(h+t)/2;
                        if (calc(mid)) t=mid;else h=mid+1;
                }
                calc(h);
                return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] =
{"NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNNYNNNYNNYNNNNNNNNNNN", 
"NNNNNNYNNYNNYNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNYNNNYNNNNNNNNY",
 "NNNNNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNYNNYNNNNNNYNNNN",
 "YNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNNNYNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNYNN",
 "NNNNNNNNNYNNNYYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNYN",
 "NNYNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNYNNNYNNNNNNNNY",
 "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNYYNYNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYYNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNYN",
 "NYNNNNNNNNNNYNNNNNNYNNNNNNYNNNNNNNNNNNNNNNNNYNNNNN", 
"NNNNNYNNNNNNNNNNNNNNNYNNNNNNYNNNNNNNNNNNNNNYNNNYNN", 
"NNNNNNYNNYNNNYYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNN", 
"NNNNNYNNNNNYNNNNNNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNYN", 
"NNNNNNNNNNNYNYNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNYN",
 "NNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNYNNNN",
 "YNNYYNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNNNNNNNNNNNNNNN",
 "YNNNYNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNYNNNNNNNN",
 "NYNNNNNNNNYNNNNNNNNYNNNNNNYNNNNNNNNNNNNNNNNNYNNNNN",
 "NNNNNNYNNYNNYNYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNYNNNNYNNNNNNNNYNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNYNN",
 "NNNNNNNNYNNNNNNNNNNNYNNNNNNNNYNNNYYNNNNNNNNNNNNNNN", 
"NNNNNYNNNNNYNNNNNNNNNYNNNNNNYNNNNNNNNNNNNNNNNNNYNN", 
"YNNYNNNNNNNNNNNNNNNNNNNNNNNYNNNYNNNNNNYNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNYN", 
"NYNNNNYNNNNNYNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN", 
"NNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNYNNNYNNYNNYNNNN", 
"NNNNNYNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNYNN", 
"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNYNYNNNNYNNNNNNNNYNNN", 
"NNNNNNNNNNYNNNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", 
"NNNYNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNYNNYNNNNNNNNNNN", 
"NNNNNNNNNNYNNNNNNNYNNNNNNNNNNNYNNNNNNYNNNNNNNNYNNN", 
"NNNNNNNNYNNNNNNNNNNNYNNNNNNNNYNNYNYNNNNNNNNNNNNNNN", 
"NNNNNNNNNNNNNNNNNNNNYNNNNNNNNYYNYNNNNYNNNNNNNNNNNN", 
"NNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNYNNYNNYNNNN", 
"NNNNNNNNYNNNNNNNNNNNNNYNNNNNNNNNNYYNNNNNNNNNNNNNNY", 
"NYNNNNNNNNYNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNYNNN", 
"NNNNNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNYNNNNNNYNNYNNNN", 
"NNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNYNNNNNNNNY", 
"NNNNNNNNYNNNNNNNNNNNNNYNNNNNNNNNNYNNYNNNNNNNNNNNNY", 
"YNNNYNNNNNNNNNNNYNNNNNNNYNNNNNNYNNNNNNNNNNNNNNNNNN", 
"NNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYYNNNNNNNNN", 
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNYNNYNNYNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNYNNNNNNN", 
"NYNNNNNNNNYNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNYNNNNN", 
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNN", 
"NNNNNYNNNNNYNNNNNNNNNYNYNNNNYNNNNNNNNNNNNNNNNNNNNN", 
"NNNNNNNNYNNNNNNNNNNNYNYNNNNNNNNNNYYNNNNNNNNNNNNNNN"};vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
string Arg1 ="NNYYNYNNYNNYNNNNYNYNNNNNNYNYNYYNNNNNNYNNNNNYNNNNNN"; int Arr2[] = {2, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYY","NNY","NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NNY"; int Arr2[] = {1, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNNNN","NNNNNN","NYNYNN","NNNNNN","NYNYNN","NYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NYNYNN"; int Arr2[] = {1, 6, 3, 6, 3, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Y"; int Arr2[] = {1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }
     	void test_case_4(){}// { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "N"; int Arr2[0]; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NNNNN","YNNNY","NNNYN","NNNNN","YNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YNNYN"; int Arr2[] = {5, 4, 3, 5, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            WSNParentsAssignment ___test;  
            ___test.run_test(5);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE  
