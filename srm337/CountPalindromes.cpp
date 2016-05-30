    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "CountPalindromes.cpp"  
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
    const int mode=835454957;
    int f[5][50][15][50][15],qq[6],q[5][50*15*50*15][4],n,len[100],tt;
    inline void ins(int x,int a,int b,int c,int d,int s)
    {
        x=x%5;
        if (f[x][a][b][c][d]==0)
        {
                qq[x]++;
                q[x][qq[x]][0]=a;
                q[x][qq[x]][1]=b;
                q[x][qq[x]][2]=c;
                q[x][qq[x]][3]=d;
        }
        f[x][a][b][c][d]=f[x][a][b][c][d]+s;
        if (f[x][a][b][c][d]>=mode) f[x][a][b][c][d]-=mode;
        tt++;
    }
    inline void inss(int x,int a,int b,int c,int d,int s)
    {
        if (b==0)
        {
                for (int k=0;k<n;k++)
                        ins(x+2,k,len[k]-1,c,d,s);
        }
        else ins(x+1,a,b-1,c,d,s);
    }
    inline void ins2(int x,vector <string> words)
    {
                for (int i=0;i<n;i++)
                        for (int j=0;j<len[i];j++)
                                inss(x,i,j,i,j,1);
    }
    class CountPalindromes  
    {  
            public:  
            int count(vector <string> words, int k)  
            {  
                n=words.size();
                int ans=0;
                int now=0,next;
                for (int i=0;i<n;i++)
                {
                        len[i]=words[i].length();
                        for (int j=0;j<len[i];j++)
                        {
                                if ((j==0)&&(j==(len[i]-1))) ans++;
                                ins(now,i,j,i,j,1);
                        }
                }
                for (int i=1;i<k;i++)
                {
                        if (i==2) ins2(0,words);
                        next=(now+1)%5;
                        for (int j=1;j<=qq[now];j++)
                        {
                                int zy=now;
                                int l1=q[now][j][0],l2=q[now][j][1],r1=q[now][j][2],r2=q[now][j][3];
                                int s=f[now][l1][l2][r1][r2];
                                if (r2!=(len[r1]-1))
                                {
                                        zy++;
                                        if (words[l1][l2]==words[r1][r2+1])
                                        {
                                                if ((l2==0)&&((r2+1)==(len[r1]-1))&&(i+1<=k))
                                                {
                                                        ans=(ans+s);
                                                        if (ans>=mode) ans-=mode;
                                                }
                                                inss(zy,l1,l2,r1,r2+1,s);
                                        }
                                }
                                else
                                {
                                        zy+=2;
                                        for (int t=0;t<n;t++)
                                        {
                                                if (words[l1][l2]==words[t][0])
                                                {
                                                        if ((l2==0)&&(0==(len[t]-1))&&(i+2<=k))
                                                        {
                                                                ans=(ans+s);
                                                                if (ans>=mode) ans-=mode;
                                                        }
                                                        inss(zy,l1,l2,t,0,s);
                                                }
                                        }
                                }
                        }
                        for (int t=1;t<=qq[now];t++)
                        {
                                f[now][q[now][t][0]][q[now][t][1]][q[now][t][2]][q[now][t][3]]=0;
                        }
                        qq[now]=0;
                        now=next;
                }
                printf("%d\n",tt);
                return ans;
            }
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"tragic","cigar"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"z","zz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"aba","acaba","baca","cac","b","c","a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; int Arg2 = 370786966; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"a", "aaaaaaaaab", "aaa", "aaaaaaaaaaaa", "aabbaaa", "babaaaaaaaa", "aaaaaabaaaba", "aaaa", "aaaaaaaaa", "aaaaaaaaaa", "aab", "aaaaaababaaaaa", "aaaaaaaaaaabba", "aaaaaabaa", "aaabaaaaaa", "abaaaaaaaa", "aaaaaa", "aabaaaaaaaaaba", "ab", "bbbaabaaaab", "aaaabaaaaa", "aa", "baaaaaaaaaaaa", "aabaa", "aabaaaaaaaabbaa", "aaaaaaaabaaaaaa", "aaaaaaaa", "aaaaa", "aaaaaaaaaaa", "aabaaaaa", "baabaaaaaaaaa", "baaaaa", "aaaaaaaabaaaaa", "aaaaaaaaaaaaaaa", "abaaaaaaaaaaa", "aaabababaaaa", "aaaaaaaaaabaaaa", "abaaa", "aaaaabaaaab", "aaaabaaaaaaa", "aaaaaaaba", "babbbaaaaaba", "aaaaaaaaaaaaa", "aaababaabaab", "aaabaabaaab", "aaaabbaaabaaaaa", "abaaaaaaaaaaaaa", "aaaaaaa", "abaaaaabaaaaaaa", "aaabaaaaaaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
  
    };
      
    // BEGIN CUT HERE  
    int main()  
    {  
            CountPalindromes ___test;  
            ___test.run_test(3);
            system("pause");  
            return 0;  
    }  
    // END CUT HERE
