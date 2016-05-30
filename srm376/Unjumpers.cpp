    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "Unjumpers.cpp"  
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
    int q[300000][3];
    bool f[35][35][35];
    int calc(int p[])
    {
        int tt[]={34,33,33};
        int h=0,t=0;
        for (int i=0;i<=2;i++)q[0][i]=p[i];
        memset(f,false,sizeof(f));
        f[p[0]][p[1]][p[2]]=true;
        while (h<=t)
        {
                for (int i=0;i<=2;i++)
                {
                        int next[3];
                        next[0]=q[h][0];next[1]=q[h][1];next[2]=q[h][2];
                        next[i]-=1;
                        bool flag=true;
                        for (int j=0;j<=2;j++)
                        {
                                if (j!=i) next[j]++;
                                if ((next[j]<0)||(next[j]>=tt[j])) flag=false;
                        }
                        if (!flag) continue;
                        if (!f[next[0]][next[1]][next[2]])
                        {
                                f[next[0]][next[1]][next[2]]=true;
                                t++;
                                q[t][0]=next[0];q[t][1]=next[1];q[t][2]=next[2];
                        }
                }
                for (int i=0;i<=2;i++)
                {
                        int next[3];
                        next[0]=q[h][0];next[1]=q[h][1];next[2]=q[h][2];
                        next[i]+=1;
                        bool flag=true;
                        for (int j=0;j<=2;j++)
                        {
                                if (j!=i) next[j]--;
                                if ((next[j]<0)||(next[j]>tt[j])) flag=false;
                        }
                        if (!flag) continue;
                        if (!f[next[0]][next[1]][next[2]])
                        {
                                f[next[0]][next[1]][next[2]]=true;
                                t++;
                                q[t][0]=next[0];q[t][1]=next[1];q[t][2]=next[2];
                        }
                }
                if (f[0][2][1])
                    int t=1;
                h++;
        }
    }
    class Unjumpers
    {  
            public:  
            int reachableTargets(string start, vector <string> targets)
            {
                int p[3];
                memset(p,0,sizeof(p));
                for (int i=0;i<start.length();i++)
                        if (start[i]=='*') p[i%3]++;
                int now=calc(p);
                int ans=0;
                for (int i=0;i<targets.size();i++)
                {
                        memset(p,0,sizeof(p));
                        for (int j=0;j<targets[i].length();j++)
                                if (targets[i][j]=='*') p[j%3]++;
                        if (f[p[0]][p[1]][p[2]]) ans++;
                }
                return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "**."; string Arr1[] = {
"..*",
"*.**",
".*.*"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, reachableTargets(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..***"; string Arr1[] = {
"..****..*",
"..***....",
"..****"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, reachableTargets(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "*..*"; string Arr1[] = {
"*..*......",
"*.....*...",
"...*.....*",
"...*..*...",
"*........*",
"*...***..*"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, reachableTargets(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "...***" ; string Arr1[] = {
"***...",
"..****",
"**....**",
".*.*.*"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, reachableTargets(Arg0, Arg1)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            Unjumpers ___test;  
            ___test.run_test(1);
            system("pause");
            return 0;
    }  
    // END CUT HERE  
