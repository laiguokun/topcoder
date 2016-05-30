    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "NormalizingTrees.cpp"  
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
    VI tr[51],res;
    int n,tot,mark[51];
    bool g[51][51];
    int cmp(int x,int y)
    {
        int q1[51],q2[51];
        int h=0,t=0;
        q1[0]=x;q2[0]=y;
        while (h<=t)
        {
                int i=q1[h],j=q2[h];
                if (tr[i].size()>tr[j].size()) return 0;
                if (tr[i].size()<tr[j].size()) return 1;
                int t_=t;
                for (int next=0;next<tr[i].size();next++)
                {
                        t++;
                        q1[t]=tr[i][next];
                }
                t=t_;
                for (int next=0;next<tr[j].size();next++)
                {
                        t++;
                        q2[t]=tr[j][next];
                }
                h++;
        }
        return 0;
    }
    void pre(int x,int fa)
    {
        for (int i=0;i<n;i++)
                if ((i!=fa)&&(g[x][i]))
                {
                        pre(i,x);
                        tr[x].PB(i);
                }
        int son=tr[x].size();
        for (int i=0;i<son;i++)
                for (int j=i+1;j<son;j++)
                        if (cmp(tr[x][i],tr[x][j])==1)
                        {
                                int t;
                                t=tr[x][i];tr[x][i]=tr[x][j];tr[x][j]=t;
                        }
    }
    void work(int x,int fa)
    {
        for (int i=0;i<n;i++)
        {
                int son=tr[mark[i]].size();
                for (int j=0;j<son;j++)
                {
                        tot++;
                        res.PB(i);
                        mark[tot]=tr[mark[i]][j];
                }
        }
    }
    VI bj(VI a,VI b)
    {
        if (a.size()==0) return b;
        for (int i=0;i<n;i++)
        {
                if (a[i]<b[i]) return a;
                if (a[i]>b[i]) return b;
        }
        return a;
    }
    class NormalizingTrees  
    {  
            public:  
            vector <int> normalize(vector <int> tree)  
            {
                n=tree.size();
                memset(g,false,sizeof(g));
                for (int i=0;i<n;i++)
                {
                        g[i][tree[i]]=true;
                        g[tree[i]][i]=true;
                }
                VI ans;
                ans.clear();
                for (int i=0;i<n;i++)
                {
                        for (int j=0;j<n;j++) tr[j].clear();
                        memset(mark,0,sizeof(mark));
                        tot=0;
                        res.clear();
                        res.PB(-1);
                        mark[0]=i;
                        pre(i,-1);
                        work(i,-1);
                        ans=bj(ans,res);
                }
                return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2,0,-1,4,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 0, 0, 1, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, normalize(Arg0)); }
	void test_case_1() { int Arr0[] = {-1,0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 0, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, normalize(Arg0)); }
	void test_case_2() { int Arr0[] = {3,3,3,4,-1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, normalize(Arg0)); }
	void test_case_3() { int Arr0[] = {10,9,6,10,6,9,7,-1,9,7,7,10,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 0, 0, 0, 1, 1, 5, 5, 5, 6, 6, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, normalize(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 24};vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 0, 0, 0, 1, 1, 5, 5, 5, 6, 6, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, normalize(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()
    {  
            NormalizingTrees ___test;  
            ___test.run_test(4);
            system("pause");
            return 0;  
    }  
    // END CUT HERE
