    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "ThreeMines.cpp"  
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
int f[51][51],g[51][51],gg[51][51],s[51];
bool upletter(char x) {if ((x>='A')&&(x<='Z')) return true;else return false;}
int upord(char x) {return (int)x-(int)'A';}
int ord(char x) {return (int)x-(int)'a';}
int calc(int x1,int y1,int x2,int y2)
{
        int res=-maxint;
        if ((x1>x2)||(y1>y2)) return res;
        memset(f,0,sizeof(f));
        memset(gg,0,sizeof(gg));
        int n=(x2-x1)+1,m=(y2-y1)+1;
        for (int i=x1;i<=x2;i++)
                for (int j=y1;j<=y2;j++) gg[i-x1][j-y1]=g[i][j];
        for (int j=0;j<m;j++) f[0][j]=gg[0][j];
        for (int i=1;i<n;i++)
                for (int j=0;j<m;j++)
                        f[i][j]=f[i-1][j]+gg[i][j];
        for (int i=0;i<n;i++)
                for (int j=i;j<n;j++)
                {
                        int sum=0;
                        for (int k=0;k<m;k++)
                        {
                                if (i==0) s[k]=f[j][k];else s[k]=f[j][k]-f[i-1][k];
                                sum+=s[k];
                                res=max(res,sum);
                                if (sum<0) sum=0;
                        }
                }
        return res;
}      
    class ThreeMines  
    {  
            public:  
            int maximumProfit(vector <string> field)  
            {  
                int n=field.size(),m=field[0].length();
                for (int i=0;i<n;i++)
                        for (int j=0;j<m;j++)
                        {
                                if (upletter(field[i][j])) g[i][j]=-upord(field[i][j]);
                                else g[i][j]=ord(field[i][j]);
                        }
                int ans=-maxint;
                // 1
                //-1
                // 1
                for (int i=0;i<n-1;i++)
                        for (int j=1;j<m;j++) ans=max(ans,calc(0,0,i,j-1)+calc(i+1,0,n-1,j-1)+calc(0,j,n-1,m-1));
                //1
                //1-
                //1
                for (int i=0;i<n-1;i++)
                        for (int j=0;j<m-1;j++) ans=max(ans,calc(0,0,n-1,j)+calc(0,j+1,i,m-1)+calc(i+1,j+1,n-1,m-1));
                //---
                // 1
                for (int i=0;i<n-1;i++)
                        for (int j=0;j<m-1;j++) ans=max(ans,calc(0,0,i,m-1)+calc(i+1,0,n-1,j)+calc(i+1,j+1,n-1,m-1));
                // 1
                //---
                for (int i=1;i<n;i++)
                        for (int j=0;j<m-1;j++) ans=max(ans,calc(0,0,i-1,j)+calc(0,j+1,i-1,m-1)+calc(i,0,n-1,m-1));
                //1 1 1 1
                //1 1 1 1
                for (int i=0;i<m-2;i++)
                        for (int j=i+1;j<m-1;j++) ans=max(ans,calc(0,0,n-1,i)+calc(0,i+1,n-1,j)+calc(0,j+1,n-1,m-1));
                //----
                //----
                //----
                //----
                for (int i=0;i<n-2;i++)
                        for (int j=i+1;j<n-1;j++) ans=max(ans,calc(0,0,i,m-1)+calc(i+1,0,j,m-1)+calc(j+1,0,n-1,m-1));
              //  printf("%d\n",calc(0,0,0,m-1));
                return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"bbbb",
"bBBB",
"BBbb",
"BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, maximumProfit(Arg0)); }
	void test_case_1() { string Arr0[] = {"cfCBDCbcdZb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(1, Arg1, maximumProfit(Arg0)); }
	void test_case_2() { string Arr0[] = {"d", "c", "B", "m", "Z", "h", "g", "B", "z", "G", "H", "b", "Y"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; verify_case(2, Arg1, maximumProfit(Arg0)); }
	void test_case_3() { string Arr0[] = {
"hBhh", 
"BBBB",
"BBBB", 
"hBhh", 
"hBhh"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 62; verify_case(3, Arg1, maximumProfit(Arg0)); }
	void test_case_4() { string Arr0[] = {
"BB", 
"BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -3; verify_case(4, Arg1, maximumProfit(Arg0)); }
	void test_case_5() { string Arr0[] = {
"ZcabcaacacabcbbbcababacaccbZaa",
"acaaccccacbccbaaccabaccaacbZbc",
"bcbaacbcbbccbbcbabbbbaZcbcbccb",
"cccacbabccbZbcbabaacbbZcbacbab",
"cacbabbcabbabbcacbcbbcaacaabbc",
"bacZcacaaccbabbcccccabcaacbaca",
"cbcccacabcabacaccacaZbbcbcacbb",
"cZbbbcaacbaacaabZcaccbcZccbbab",
"Zcababaacbbbbccbcbbaccacacbbcc",
"cZcccaaabbcbcbccccbcbaabbbccbb",
"bbcaacacabccababacbccacccbbaba",
"cccbbcaZabccacabbccccabbabbbab",
"bbbacbccbbcaabaaabccbcaabcacaa",
"cbbababbccccbcccbaacacccaabaac",
"aaccaccaccbabbccaaaacbacccacca",
"bbbcabcabZZcabcabbaacZbaaabaZb",
"aaabbabcabaaacbcccccbbcabcccbc",
"bbbaccbacacaccbbaccabacbbbaaac",
"acaaacccbabbccbcbabbcbaaaccabb",
"bcaaaaabcbabaaabccacccbaacbbbc",
"bZcbcbcccaabccaabbccbababbbcca",
"cbbbbcccabcabcbacaaaaabbbbbcac",
"ccbbcbacacbbcacacbaabcbbacbaba",
"cbbbaabaabbbbaccabbcbcaccaaaac",
"abZcabaacbbcacbaaabccbabacacaa",
"aabccacbabaacaccccbbbbcccccaca",
"aabcbaaacbabcaccbaabbbabbabbca",
"ababcabaccaaaacccacbcbcabacbcb",
"bcaaaacabcabbbaccccccacabccacb",
"cbbabbbccaaaaacbccaabcbbccbacc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 671; verify_case(5, Arg1, maximumProfit(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            ThreeMines ___test;  
            ___test.run_test(5);
            system("pause");
            return 0;
    }  
    // END CUT HERE  
