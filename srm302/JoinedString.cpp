    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "JoinedString.cpp"  
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
    const int anum=(int)'A';
    const int maxn=500000;
    int trie[700][26],q[1000],fail[700],mark[700],f[5000][600];
    int que[500000][2];
    bool danger[700];
    string ans[5000][600],bj;
    int now,tot=1;
    void ins(char a)
    {
        int x=(int)a-anum;
        if (trie[now][x]==0)
        {
        	tot++;
                trie[now][x]=tot;
                now=tot;
        }
        else now=trie[now][x];
    }
    void bulid()
    {
    	int head=1,tail=0;
        for (int i=0;i<26;i++)
        {
        	if (trie[1][i]!=0)
                {
                	q[++tail]=trie[1][i];
                        fail[trie[1][i]]=1;
                }
                else trie[1][i]=1;
        }
        while (head<=tail)
        {
        	int x=q[head];
          	danger[x]=danger[fail[x]]||danger[x];
                for (int i=0;i<26;i++)
                {
                	if (trie[x][i]!=0)
                        {
                        	q[++tail]=trie[x][i];
                                fail[trie[x][i]]=trie[fail[x]][i];
                        }
                        else trie[x][i]=trie[fail[x]][i];
                }
                head++;
        }
    }
    string com(string a,string b)
    {
    	for (int i=0;i<a.length();i++)
        {
        	if (a[i]<b[i]) return a;
                if (a[i]>b[i]) return b;
        }
        return a;
    }
    bool inn(string a,string b)
    {
    	for (int i=0;i<a.length();i++)
        {
          	bool res=true;
             	for (int j=0;j<b.length();j++)
                {
                	if (a[i+j]!=b[j]) {res=false;break;};
                }
                if (res) return res;
        }
        return false;
    }
    class JoinedString  
    {  
            public:  
            string joinWords(vector <string> words)  
            {
                    int n=words.size(),resnum=10000,last=(1<<n)-1;
                    bj=words[0];
                    string res;
                    memset(fail,0,sizeof(fail));
                    memset(trie,0,sizeof(trie));
                    memset(mark,0,sizeof(mark));
                    memset(danger,false,sizeof(danger));
                    tot=1;
                    for (int i=0;i<n;i++)
                    {
                    	now=1;
                        for (int j=0;j<words[i].length();j++) ins(words[i][j]);
                        danger[now]=true;
                        mark[now]=i+1;
                    }
                    bulid();
                    memset(f,-1,sizeof(f));
                    int head=1,tail=1;
                    que[tail][0]=0;que[tail][1]=1;
                    f[0][1]=0;
                    while (head<=tail)
                    {
                    	int x=que[head%maxn][0],y=que[head%maxn][1];
                        for (int i=0;i<26;i++)
                	    {
                        	int now=trie[y][i],xx,next;
                                xx=now;next=x;
                                while ((danger[xx])&&(xx!=0))
                                {
                                	if (mark[xx]!=0) next=next|(1<<(mark[xx]-1));
                                        xx=fail[xx];
                                }
                        	if (f[next][now]==f[x][y]+1) ans[next][now]=com(ans[next][now],ans[x][y]+(char)(i+anum));
                                if (f[next][now]==-1)
                                {
                                        tail++;
                                	que[tail%maxn][0]=next;que[tail%maxn][1]=now;
                                        f[next][now]=f[x][y]+1;
                                        ans[next][now]=ans[x][y]+(char)(i+anum);
                                }
                        }
                        head++;
                    }
                    for (int i=1;i<=tot;i++)
                    {
                    	if (f[last][i]==resnum) res=com(res,ans[last][i]);
                    	if ((f[last][i]>=0)&&(f[last][i]<resnum))
                        {
                        	res=ans[last][i];
                                resnum=f[last][i];
                        }
                    }
                    return res;   
                }
            
// BEGIN CUT HERE
	public:
      	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cout << "Test Case #" << Case << "..."; if (Expected == Received) cout << "PASSED" << endl; else { cout << "FAILED" << endl; cout << "\tExpected: \"" << Expected << '\"' << endl; cout << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CACBABCACCCCACCAACACAACBBBCCACAACBCACCCCCBB", "BACACBABCA", "CBBCAACCCACCABABCAACBCBBBACABCCACBBCBCC", "BABCABABBBCABABACCACBABACACB", "BAAABCBBCABBCBBAABABBC", "CCBBCBCBABAAABCBBCABBCBBAABABBCCBAABACABBCCABBACAA", "BCBCCABCCAACCCBABAA", "BCACCBAACBC", "ABACCBCBCABACBCCBCACCABCCBBCBBCACCABCB", "BBCCBBCBCBABAAABCBBCABBCBBAABABBCCBAAB", "BACAABAABACAC", "CAABCCACBBCBCCBCACCACBACAABAABACAC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BABCABABBBCABABACCACBABACACBABCACCCCACCAACACAACBBBCCACAACBCACCCCCBBCAACCCACCABABCAACBCBBBACABCCACBBCBCCABCCAACCCBABAABACCBCBCABACBCCBCACCABCCBBCBBCACCABCBBCCBBCBCBABAAABCBBCABBCBBAABABBCCBAABACABBCCABBACAABCCACBBCBCCBCACCACBACAABAABACACBCACCBAACBC"; verify_case(0, Arg1, joinWords(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABABA", "AKAKA", "AKABAS", "ABAKA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABABAKAKABAS"; verify_case(1, Arg1, joinWords(Arg0)); }
	void test_case_2() { string Arr0[] = {"AAA","BBB", "CCC", "ABC", "BCA", "CAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAABBBCABCCC"; verify_case(2, Arg1, joinWords(Arg0)); }
	void test_case_3() { string Arr0[] = {"OFG", "SDOFGJTILM", "KBWNF", "YAAPO", "AWX", "VSEAWX", "DOFGJTIL", "YAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "KBWNFSDOFGJTILMVSEAWXYAAPO"; verify_case(3, Arg1, joinWords(Arg0)); }
	void test_case_4() { string Arr0[] = {"NVCSKFLNVS", "HUFSPMRI", "FLNV", "KMQD", "RPJK", "NVSQORP", "UFSPMR", "AIHUFSPMRI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AIHUFSPMRINVCSKFLNVSQORPJKMQD"; verify_case(4, Arg1, joinWords(Arg0)); }
	void test_case_5() { string Arr0[] = {"STRING", "RING"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "STRING"; verify_case(5, Arg1, joinWords(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()
    {
            JoinedString ___test;  
           ___test.run_test(1);  
            return 0;  
    }  
    // END CUT HERE
  

