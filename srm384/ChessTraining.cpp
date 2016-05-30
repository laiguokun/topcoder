    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "ChessTraining.cpp"  
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
    const int maxn=100;
    int f[maxn][maxn];
    bool p[maxn*5];
    void work(int x,int y)
    {
        if (f[x][y]!=-1) return;
        int &res=f[x][y];
        for (int i=x-1;i>=1;i--) if (i!=y) work(i,y);
        for (int i=y-1;i>=1;i--) if (x!=i) work(x,i);
        for (int i=1;i<=min(x,y);i++) if (x-i!=y-i) work(x-i,y-i);
        memset(p,true,sizeof(p));
        for (int i=x-1;i>=1;i--) if (i!=y) p[f[i][y]]=false;
        for (int i=y-1;i>=1;i--) if (x!=i) p[f[x][i]]=false;
        for (int i=1;i<=min(x-1,y-1);i++) if (x-i!=y-i) p[f[x-i][y-i]]=false;
        for (int i=0;i<=200;i++)
                if (p[i])
                {
                        res=i;
                        break;
                }
        return ;
    }
    class ChessTraining  
    {  
            public:  
            string game(vector <int> x, vector <int> y)  
            {  
                string ans1="Alice will win",ans2="Bob will win";
                int n=x.size();
                for (int i=0;i<n;i++)
                {
                        if (x[i]==0) return ans1;
                        if (y[i]==0) return ans1;
                        if (x[i]==y[i]) return ans1;
                }
                memset(f,-1,sizeof(f));
                for (int i=1;i<maxn;i++)
                        for (int j=1;j<maxn;j++)
                        {
                                if (i==j) continue;
                                bool t1=false,t2=false;
                                if (i-1==0 || i-1==j) t1=true;
                                if (j-1==0 || j-1==i) t2=true;
                                if (t1 && t2) f[i][j]=0;
                        }
                int ans=0;
                for (int i=0;i<n;i++)
                {
                        work(x[i],y[i]);
                        ans^=f[x[i]][y[i]];
                }
                if (ans!=0) return ans1; else return ans2;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice will win"; verify_case(0, Arg2, game(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob will win"; verify_case(1, Arg2, game(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,7,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,3,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob will win"; verify_case(2, Arg2, game(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3,3,18,6,0,14,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,11,9,9,9,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice will win"; verify_case(3, Arg2, game(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice will win"; verify_case(4, Arg2, game(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {3,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob will win"; verify_case(5, Arg2, game(Arg0, Arg1)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            ChessTraining ___test;  
            ___test.run_test(5);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE  
