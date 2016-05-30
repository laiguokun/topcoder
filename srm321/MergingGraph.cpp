    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "MergingGraph.cpp"  
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
    VI g[60],g_[60];
    int id[60],mark[60],sl,loop[60],n;
    bool f[60][60];
    int ord(char x) {return (int)x-48;}
    int getgcd(int a,int b)
    {
        if (a<b) {int t=a;a=b;b=t;}
        while ((a%b)!=0)
        {
                int c=a%b;
                a=b;
                b=c;
        }
        return b;
    }
    void merge(int x,int y)
    {
        if (x==y) return;
        for (int i=0;i<g[y].size();i++)
        {
                int k=id[g[y][i]];
                if (!f[x][k])
                {
                        f[x][k]=true;
                        g[x].push_back(k);
                }
        }
        for (int i=0;i<g_[y].size();i++)
        {
                int k=id[g_[y][i]];
                if (!f[k][x])
                {
                        f[k][x]=true;
                        g_[x].push_back(k);
                }
        }
        g[y].clear();g_[y].clear();
        for (int i=0;i<n;i++) if (id[i]==y) id[i]=x;
    }
    void dfs(int x,int k)
    {
        mark[x]=k;
        if (g[x].size()==0) return;
        if (mark[id[g[x][0]]]==0) dfs(id[g[x][0]],k+1);
        else
        {
                sl++;
                loop[sl]=(k-mark[id[g[x][0]]]+1);
        }
    }
    class MergingGraph  
    {  
            public:  
            int distanceToCycle(vector <string> adj)  
            {
                for (int i=0;i<50;i++) {g[i].clear();g_[i].clear();}
                memset(f,false,sizeof(f));
                n=adj.size();
                for (int i=0;i<n;i++)
                {
                        id[i]=i;
                        int now=0;
                        while (now<adj[i].length())
                        {
                                int x=0;
                                while ((now<adj[i].length())&&(adj[i][now]!=' '))
                                {
                                        x=x*10+ord(adj[i][now]);
                                        now++;
                                }
                                if (i==x) return n-1;
                                if (!f[i][x])
                                {
                                        g[i].push_back(x);
                                        g_[x].push_back(i);
                                }
                                f[i][x]=true;
                                now++;
                        }
                }
                while (true)
                {
                        bool change=true;
                        for (int now=0;now<n;now++)
                        {
                                if (id[now]!=now) continue;
                                int s=g[now].size();
                                for (int i=s-1;i>0;i--)
                                {
                                        int k1=id[g[now][0]],k2=id[g[now][i]];
                                        merge(k1,k2);
                                        f[now][g[now][i]]=false;
                                        g[now].pop_back();
                                        change=false;
                                }
                                s=g_[now].size();
                                for (int i=s-1;i>0;i--)
                                {
                                        int k1=id[g_[now][0]],k2=id[g_[now][i]];
                                        merge(k1,k2);
                                        f[g_[now][i]][now]=false;
                                        g_[now].pop_back();
                                        change=false;
                                }
                        }
                        if (change) break;
                }
                for (int i=0;i<n;i++)
                        if ((id[i]==i)&&(g[i].size()>0)&&(g[i][0]==i)) return n-1;
                int s=0;
                for (int i=0;i<n;i++) if (id[i]==i) s++;
                memset(mark,0,sizeof(mark));
                sl=0;
                int t=g_[0].size();
                for (int i=0;i<n;i++)
                {
                        if ((id[i]==i)&&(g_[i].size()==0))
                        {
                                dfs(i,1);
                                s--;
                        }
                }
                for (int i=0;i<n;i++)
                {
                        if ((id[i]==i)&&(mark[i]==0)) dfs(i,1);
                }
                int gcd=loop[1];
                for (int i=2;i<=sl;i++) gcd=getgcd(gcd,loop[i]);
                if (sl==0) return n-s;
                else return n-gcd;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 1", "2", "0 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, distanceToCycle(Arg0)); }
	void test_case_1() { string Arr0[] ={"2", "3", "4", "1", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, distanceToCycle(Arg0)); }
	void test_case_2() { string Arr0[] = {"1", "", "3", ""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, distanceToCycle(Arg0)); }
	void test_case_3() { string Arr0[] = {"2", "5 4", "", "0", "0", "0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, distanceToCycle(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            MergingGraph ___test;  
            ___test.run_test(1);
            return 0;
    }
    // END CUT HERE  
