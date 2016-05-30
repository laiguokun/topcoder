    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "ContextFreeGrammars.cpp"  
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
    bool res;
    int arr=0,n=0;
    int ans[27][40][40];
    LL dp[100][100][100];
    vector <string> rule;
    string aim;
    const int maxn=1000000001;
    bool upletter(char a)
    {
    	if ((a>='A')&&(a<='Z')) return true;return false;
    }
    int f(char now,int left,int right)
    {
        if (res) return 0;
    	if (ans[(int)now-int('A')][left][right]>=0) return ans[(int)now-int('A')][left][right];
        int resnum=0;
        arr++;
        for (int i=0;i<n;i++)
        {
        	if (rule[i][0]==now)
                {
                        for (int j=left-1;j<=right;j++)
                        	for (int k=5;k<=rule[i].length();k++) dp[arr][j][k]=0;
                        dp[arr][left-1][5]=1;
                        for (int j=6;j<rule[i].length();j++)
                        {
                         	int ll=left+j-6,rr=right-(rule[i].length()-1-j);
                        	if (upletter(rule[i][j]))
                                {
                               		for (int x=ll;x<=rr;x++)
                                  	  	for (int y=x;y<=rr;y++)
                                                {
                                        		int last=dp[arr][x-1][j-1];
                                                        if (last==0) continue;
                                                	dp[arr][y][j]+=last*f(rule[i][j],x,y);
                                                        if (dp[arr][y][j]>=maxn) dp[arr][x][j]=maxn;
                                        	}
                                }
                                else
                                {                         
                                	for (int x=ll;x<=rr;x++)
                                          	if (rule[i][j]==aim[x-1])
                                                {
                                                	dp[arr][x][j]+=dp[arr][x-1][j-1];
                                                        if (dp[arr][x][j]>=maxn) dp[arr][x][j]=maxn;
                                                }
                                }
                        }
                        resnum+=dp[arr][right][rule[i].length()-1];
                        if (resnum>=maxn) {resnum=maxn;break;}
                }
        }
        arr--;
        ans[(int)now-(int)'A'][left][right]=resnum;
        return resnum;
    }
    class ContextFreeGrammars  
    {  
            public:  
            int countParsingTrees(vector <string> rules, char seed, string word)  
            {
                   memset(ans,-1,sizeof(ans));
                   res=false;
                   n=rules.size();
                   int insnum=n;             
                   for (int i=0;i<n;i++)
                   {
                   	int len=rules[i].length(),now=6,last=0;
                        string ins;
                        bool mark=false;
                        while (now<len)
                        {
                        	if (rules[i][now]==' ')
                                {
                                	if (last==0) last=now;
                                        if (mark) rules.push_back(ins);
                                        ins.erase(0,ins.length());
                                        for (int j=0;j<6;j++) ins+=rules[i][j];
                                        insnum++;
                                        now+=3;
                                        mark=true;
                                }
                                else
                                {
                                	if (mark) ins+=rules[i][now];
                                        now++;
                                }
                        }
                        if (mark)
                        {
                         	rules.push_back(ins);
                                rules[i].erase(last,rules[i].length()-last+1);
                        }
                   }
                   n=insnum;
                   rule=rules;
                   aim=word;

                   int resnum=f(seed,1,word.length());
                   if (resnum>=maxn) return -1; else return resnum;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A ::= BD",
 "B ::= bB | b | Bb",
 "D ::= dD",
 "D ::= d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'A'; string Arg2 = "bdd"; int Arg3 = 1; verify_case(0, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"A ::= BD",
 "B ::= bB | b | Bb",
 "D ::= dD",
 "D ::= d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'A'; string Arg2 = "bbd"; int Arg3 = 2; verify_case(1, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"A ::= BD",
 "B ::= bB | b | Bb",
 "D ::= dD",
 "D ::= d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'A'; string Arg2 = "ddbb"; int Arg3 = 0; verify_case(2, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"B ::= topcoder | topcoder",
 "B ::= topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'B'; string Arg2 = "topcoder"; int Arg3 = 3; verify_case(3, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"A ::= BCD",
 "Z ::= z",
 "B ::= Cz | Dz | Zz",
 "C ::= Bz | Dz",
 "D ::= Cz | Bz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'X'; string Arg2 = "zzz"; int Arg3 = 0; verify_case(4, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"B ::= bB | bB | bB | bB | b" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'B'; string Arg2 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"; int Arg3 = -1; verify_case(5, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {
            ContextFreeGrammars ___test;
            ___test.run_test(-1);
            return 0;  

    }
    // END CUT HERE  

