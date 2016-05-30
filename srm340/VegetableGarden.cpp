    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "VegetableGarden.cpp"  
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
    const int mode=5000000;
    const int maxint=1000000000;
    int f[3001][1025],mark[51][51],Map[101],q[5000001][2],last[50001],pre[50001],b[50001],c[50001],ans[11][1001];
    bool ff[3001][1025];
    char str[11];
    int tot;
    void ins(int x,int y,int k)
    {
        tot++;
        pre[tot]=last[x];
        last[x]=tot;
        b[tot]=y;
        c[tot]=k;
    }
    void dfs(int k,int x,int sum)
    {
        if (k==tot+1)
        {
                ans[sum][0]++;
                ans[sum][ans[sum][0]]=x;
        }
        else
        {
                if (str[k]=='I') dfs(k+1,x+(1<<k),sum+1);
                dfs(k+1,x,sum);
        }
    }
    void bfs()
    {
        int x,opt,k,l,h,t;
        memset(f,127,sizeof(f));
        memset(ff,true,sizeof(ff));
        h=0;t=0;q[0][0]=1;q[0][1]=0;
        f[1][0]=0;ff[1][0]=false;
        while (h<=t)
        {
                l=h%mode;
                x=q[l][0];opt=q[l][1];
                ff[x][opt]=true;
                k=last[x];
                while (k!=0)
                {
                        if (f[x][opt]+1<f[b[k]][opt^c[k]])
                        {
                                f[b[k]][opt^c[k]]=f[x][opt]+1;
                                if (ff[b[k]][opt^c[k]])
                                {
                                        t++;
                                        l=t%mode;
                                        q[l][0]=b[k];q[l][1]=opt^c[k];
                                        ff[b[k]][opt^c[k]]=false;
                                }
                        }
                        k=pre[k];
                }
                h++;
        }
    }    
    class VegetableGarden  
    {  
            public:  
            vector <int> getMinDistances(vector <string> garden)  
            {  
                int n=garden.size(),m=garden[0].length();
                memset(mark,-1,sizeof(mark));
                memset(Map,0,sizeof(Map));
                tot=-1;
                int max=0;
                for (int i=1;i<=n;i++)
                        for (int j=1;j<=m;j++)
                        {
                                char ch=garden[i-1][j-1];
                                if (ch!='.')
                                {
                                        tot++;
                                        mark[i][j]=tot;
                                        str[tot]=ch;
                                        if (ch=='I')max++;
                                }
                        }
                dfs(0,0,0);
                tot=0;
                int sum=n*(m+1);
                for (int i=1;i<=m;i++)
                {
                        ins(sum+i,sum+i+1,0);
                        ins(sum+i+1,sum+i,0);
                }
                for (int i=n;i>=1;i--)
                {
                        sum-=(m+1);
                        for (int j=1;j<=m;j++)
                        {
                                if (mark[i][j]>=0) Map[j]=Map[j]+(1<<mark[i][j]);
                                ins(sum+j,sum+j+1,Map[j]);
                                ins(sum+j+1,sum+j,Map[j]);
                        }
                }
                for (int i=1;i<=m+1;i++)
                        for (int j=1;j<=n;j++)
                        {
                                int k1=(j-1)*(m+1)+i,k2=j*(m+1)+i;
                                ins(k1,k2,0);
                                ins(k2,k1,0);
                        }
                bfs();
                VI r;
                r.clear();
                for (int i=1;i<=max;i++)
                {
                        int res=maxint;
                        for (int j=1;j<=ans[i][0];j++)
                                res=min(res,f[1][ans[i][j]]);
                        r.PB(res);
                }
                return r;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"I"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMinDistances(Arg0)); }
	void test_case_1() { string Arr0[] = {"XX", 
 "XI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMinDistances(Arg0)); }
	void test_case_2() { string Arr0[] = {"III", 
 "IXI",
 "III"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 6, 8, 10, 12, 14, 16, 18 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMinDistances(Arg0)); }
	void test_case_3() { string Arr0[] = {"X.I", 
 ".I.", 
 "I.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 10, 14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMinDistances(Arg0)); }
	void test_case_4() { string Arr0[] = {"IIXIIXIXII"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 6, 12, 14, 20, 26, 28 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getMinDistances(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            VegetableGarden ___test;  
            ___test.run_test(1);
            system("pause");
            return 0;  
    }  
    // END CUT HERE  
