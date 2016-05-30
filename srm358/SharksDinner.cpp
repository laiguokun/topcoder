// BEGIN CUT HERE

// END CUT HERE
#line 5 "SharksDinner.cpp"
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
const int maxint=100000000; 
struct T {int a,b;}; 
T g[100000]; 
int s,t,tot,pre[100000],last[100000],h[10000],vh[10000]; 
int f[10000]; 
void ins(int a,int b,int c) 
{ 
        tot++; 
        pre[tot]=last[a];last[a]=tot; 
        g[tot].a=b;g[tot].b=c; 
        tot++; 
        pre[tot]=last[b];last[b]=tot; 
        g[tot].a=a;g[tot].b=0; 
} 
int dfs(int x,int flow) 
{ 
        if (x==t) 
        return flow; 
        int res=0; 
        int k=last[x]; 
        while (k!=0) 
        { 
                if ((h[x]==h[g[k].a]+1)&&(g[k].b>0)) 
                { 
                        int tmp=dfs(g[k].a,min(flow-res,g[k].b)); 
                        res+=tmp; 
                        g[k].b-=tmp; 
                        if ((k&1)==0) g[k-1].b+=tmp; else g[k+1].b+=tmp; 
                        if (res==flow) return flow; 
                } 
                k=pre[k]; 
        } 
        if (h[s]==t+1) return res;
        vh[h[x]]--;
        if (vh[h[x]]==0) h[s]=t+1; 
        vh[++h[x]]++; 
        return res; 
} 

class SharksDinner
{
        public:
        int minSurvivors(vector <int> size, vector <int> speed, vector <int> intelligence)
        {
                int n=size.size();
                s=2*n;t=2*n+1;
                int ans=n;
                for (int i=0;i<n;i++)
                {
                        f[i]=1;
                        for (int j=0;j<i;j++)
                        {
                                if (size[i]==size[j] && speed[i]==speed[j] && intelligence[i]==intelligence[j])
                                {
                                        f[j]++;f[i]=0;break;
                                }
                        }
                }
                for (int i=0;i<n;i++)
                {
                        if (f[i]==0) continue;
                   //     printf("%d %d %d\n",size[i],speed[i],intelligence[i]);
                        ins(s,i*2,2*f[i]);
                        ins(i*2+1,t,f[i]);
                        for (int j=0;j<n;j++)
                        {
                                if (f[j]==0) continue;
                                if (i==j) continue;
                                if (size[i]>=size[j] && speed[i]>=speed[j] && intelligence[i]>=intelligence[j])
                                {
                                        ins(i*2,j*2+1,1);
                                }
                        }
                        ins(i*2,i*2+1,f[i]-1);
                }
                vh[0]=t+1;
                while (h[s]<t+1) ans-=dfs(s,maxint);
                return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 1, 2, 2, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 1, 1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 1, 1, 1, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1, 2, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, minSurvivors(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 4, 10, 5, 8, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 5, 10, 7, 7, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 5, 8, 10, 7, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, minSurvivors(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 1, 2, 3, 4, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4, 3, 2, 1, 100 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 2, 4, 1, 3, 100 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(2, Arg3, minSurvivors(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 4, 4, 4, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3, 3, 3, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 8, 8, 8, 8 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, minSurvivors(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        SharksDinner ___test;
        ___test.run_test(0);
        system("pause");
        return 0;
}
// END CUT HERE
