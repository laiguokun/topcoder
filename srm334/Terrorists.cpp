    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "Terrorists.cpp"  
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
    struct T{int a,b;};
    const int maxint=1000000000;
    T g[10000],g_[10000];
    int last[10000],last_[10000],pre[10000],h[100],vh[100];
    int tot,s,t;
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
      
    class Terrorists  
    {  
            public:  
            int requiredCost(vector <string> roads)  
            {  
                int n=roads.size();
                s=n,t=n+1;
                int tot_=tot;
                int ans=maxint;
                for (int i=0;i<n;i++)
                        for (int j=i+1;j<n;j++)
                        {
                                tot=0;
                                memset(last,0,sizeof(last));
                                for (int x=0;x<n;x++)
                                        for (int y=0;y<n;y++)
                                        {
                                                if (x==y) continue;
                                                ins(x,y,(int)roads[x][y]-48);
                                        }
                                ins(s,i,maxint);
                                ins(j,t,maxint);
                                int maxflow=0;
                                memset(vh,0,sizeof(vh));
                                memset(h,0,sizeof(h));
                                vh[0]=t+1;
                                while (h[s]<t+1) maxflow+=dfs(s,maxint);
                                ans=min(ans,maxflow);
                        }
                return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0911",
 "9011",
 "1109",
 "1190"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, requiredCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"0399",
 "3033",
 "9309",
 "9390"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, requiredCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"030900",
 "304120",
 "040174",
 "911021",
 "027207",
 "004170"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, requiredCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"044967263",
 "409134231",
 "490642938",
 "916036261",
 "634306024",
 "742660550",
 "229205069",
 "633625604",
 "318140940"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(3, Arg1, requiredCost(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            Terrorists ___test;  
            ___test.run_test(0);   \
            system("pause");
            return 0;  
    }  
    // END CUT HERE
