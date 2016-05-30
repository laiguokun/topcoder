    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "WeighingScale.cpp"  
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
    int m[100][100],m1[100],m2[100],mark[10],fa[100],q[100],g[100][100],t1,t2,t3,p[4],n;
    bool f[100][100];  
    bool bfs(int now)
    {
        if (now==4)
                int t=1;
        int q[5000];
        int h=0,t=0;q[h]=now;
        m[now][now]=0;
        while (h<=t)
        {
                int x=q[h];
                for (int i=0;i<n;i++)
                {
                        if (f[x][i])
                        {
                                if (m[now][x]+g[x][i]>m[now][i])
                                {
                                        m[now][i]=m[now][x]+g[x][i];
                                        m1[now]=max(m1[now],m[now][i]);
                                        m2[i]=max(m2[i],m[now][i]);
                                        q[++t]=i;
                                }
                        }
                }
                h++;
        }
    }
                                      
    void dfs(int x)
    {
        if (x==4)
        {
                if (mark[0]+mark[1]<mark[2]+mark[3]) t1=1;
                if (mark[0]+mark[1]==mark[2]+mark[3]) t2=1;
                if (mark[0]+mark[1]>mark[2]+mark[3]) t3=1;
                return;
        }
        int now=p[x];
        for (int i=m2[now];i<=2-m1[now];i++)
        {
                mark[x]=i;
                bool ok=true;
                for (int j=0;j<x;j++)
                {
                        if (mark[x]==mark[j])
                        {
                                if (m[now][p[j]]<=0 && m[p[j]][now]<=0) continue;
                                else {ok=false;break;}
                        }
                        if (mark[x]<mark[j])
                        {
                                if (m[p[j]][now]!=-1) {ok=false;break;}
                                if (m[now][p[j]]!=-1 && mark[j]-mark[x]<m[now][p[j]]) {ok=false;break;}
                        }
                        if (mark[x]>mark[j])
                        {
                                if (m[now][p[j]]!=-1) {ok=false;break;}
                                if (m[p[j]][now]!=-1 && mark[x]-mark[j]<m[p[j]][now]) {ok=false;break;}
                        }
                }
                if (ok)
                {
                        dfs(x+1);
                        mark[x]=-1;
                }
        }
        return;
    }
    class WeighingScale  
    {  
            public:  
            vector <int> count(vector <string> measures, int A, int B)  
            {
                 n=measures.size();
                memset(f,false,sizeof(f));
                for (int i=0;i<n;i++)
                        for (int j=0;j<n;j++)
                        {
                                if (measures[i][j]=='?') continue;
                                if (measures[i][j]=='+')
                                {
                                        f[j][i]=true;g[j][i]=1;
                                }
                                if (measures[i][j]=='=')
                                {
                                        f[i][j]=true;f[j][i]=true;
                                        g[i][j]=0;g[j][i]=0;
                                }
                                if (measures[i][j]=='-')
                                {
                                        f[i][j]=true;g[i][j]=1;
                                }
                        }
                for (int i=0;i<n;i++) fa[i]=-1;
                memset(m,-1,sizeof(m));
                for (int i=0;i<n;i++)
                        bfs(i);
                int ans1=0,ans2=0,ans3=0;
                for (int i=0;i<n;i++)
                {
                        if ((i==A)||(i==B)) continue;
                        for (int j=i+1;j<n;j++)
                        {
                                if ((j==A)||(j==B)) continue;
                                p[0]=i;p[1]=j;p[2]=A;p[3]=B;
                                t1=0;t2=0;t3=0;
                                memset(mark,-1,sizeof(mark));
                                if (i==3 && j==4)
                                        int t=1;
                                dfs(0);
                                if (t1+t2+t3==1)
                                {
                                        if (t1==1) ans1++;
                                        if (t2==1) ans2++;
                                        if (t3==1) ans3++;
                                }
                        }
                }
                VI ans;
                ans.clear();
                ans.PB(ans1);ans.PB(ans2);ans.PB(ans3);
                return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"?+????","-?+???","?-????","????+?", "???-?+","????-?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; int Arr3[] = {1, 4, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"?+?????","-?+????","?-?????","????+??", "???-?+?","????-??", "???????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; int Arr3[] = {10, 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"?+?????","-?+????","?-?????","????+??", "???-?+?","????-??", "???????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; int Arr3[] = {1, 4, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"??+?", "???+", "-???", "?-??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arr3[] = {1, 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"??+??", "???+?", "-???=", "?-???", "??=??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arr3[] = {3, 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"?+???++?????++","-??=?=???????=","??????????=???","?=??+?==??????",
"???-???-???-??","-=????????????","-??=???=?-+???","???=+?=???????",
"??????????????","??????+???????","??=???-????-??","????+?????+???",
"-?????????????","-=????????????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 2; int Arr3[] = {1, 10, 36 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            WeighingScale ___test;  
            ___test.run_test(4);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE
