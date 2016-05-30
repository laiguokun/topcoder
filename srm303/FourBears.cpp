    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "FourBears.cpp"  
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
    const int maxnum=1000000;
    const int maxn=15;
    const int step[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    int head,tail;
    int q[1000000][3],f[16][7][50],a[3],b[3],ma[7][50];
    int n,m;
    void insert(int now,int x,int y)
    {
        tail++;
        q[tail][0]=now;q[tail][1]=x;q[tail][2]=y;
    }
    bool ok(int x,int y)
    {
        if ((x>=0)&&(x<n)&&(y>0)&&(y<m-1)) return true;
        else return false;
    }
    class FourBears  
    {  
            public:  
            int clearPassages(vector <string> field)  
            {
                    n=field.size();
                    m=field[1].length();
                    int l=0,r=0;
                    memset(a,0,sizeof(a));
                    memset(b,0,sizeof(b));
                    for (int i=0;i<=maxn;i++)
                        for (int j=0;j<n;j++)
                                for (int k=0;k<m;k++) f[i][j][k]=maxnum;
                    for (int i=0;i<n;i++)
                    {
                        if (field[i][0]=='B') a[l++]=i;
                        if (field[i][m-1]=='B') b[r++]=i;
                    }
                    for (int i=0;i<n;i++)
                        for (int j=1;j<m-1;j++)
                                if (field[i][j]=='X') ma[i][j]=0;else ma[i][j]=1;
                    q[1][0]=1;q[1][1]=a[0];q[1][2]=0;
                    q[2][0]=2;q[2][1]=a[1];q[2][2]=0;
                    q[3][0]=4;q[3][1]=b[0];q[3][2]=m-1;
                    q[4][0]=8;q[4][1]=b[1];q[4][2]=m-1;
                    f[1][a[0]][0]=0;f[2][a[1]][0]=0;
                    f[4][b[0]][m-1]=0;f[8][b[1]][m-1]=0;
                    head=1;tail=4;
                    if (a[1]==a[0]+1)
                    {
                        f[3][a[0]][0]=0;f[3][a[1]][0]=0;
                        insert(3,a[0],0);insert(3,a[1],0);
                    }
                    if (b[1]==b[0]+1)
                    {
                        f[12][b[0]][m-1]=0;f[12][b[1]][m-1]=0;
                        insert(12,b[0],m-1);insert(12,b[1],m-1);
                    }
                    while (head<=tail)
                    {
                        int now=q[head][0],x=q[head][1],y=q[head][2];
                        for (int i=1;i<=maxn;i++)
                        {
                                if ((i|now)>now)
                                {
                                        if (f[i][x][y]==maxnum) continue;
                                        if (f[i|now][x][y]>f[now][x][y]+f[i][x][y]-ma[x][y])
                                        {
                                                f[i|now][x][y]=f[now][x][y]+f[i][x][y]-ma[x][y];
                                                insert(i|now,x,y);
                                        }
                                }
                        }
                        for (int i=0;i<4;i++)
                        {
                                int xx=x+step[i][0],yy=y+step[i][1];
                                if (ok(xx,yy)&&(f[now][x][y]+ma[xx][yy]<f[now][xx][yy]))
                                {
                                        f[now][xx][yy]=f[now][x][y]+ma[xx][yy];
                                        insert(now,xx,yy);
                                }
                        }
                        head++;
                    }
                    int ans=maxnum;
                    for (int i=0;i<n;i++)
                        for (int j=1;j<m-1;j++) ans=min(ans,f[maxn][i][j]);
                    return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
        ".......X.XX.......",
        "B....XXX..XXX....B",
        "....X.......XX....",
        ".............XX...",
        "....XX......XX....",
        "B....XXX..XX......",
        ".......XXXX......B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, clearPassages(Arg0)); }
	void test_case_1() { string Arr0[] = {
 "..................",
 "B..........XXXX..B",
 "..........X.......",
 "....XXXXXX........",
 "..........XX......",
 "B............XX..B",
 ".................."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(1, Arg1, clearPassages(Arg0)); }
	void test_case_2() { string Arr0[] = {
 "B.B",
 "...",
 "B.B"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, clearPassages(Arg0)); }
	void test_case_3() { string Arr0[] = {
 "..B",
 "B.B",
 "B.."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, clearPassages(Arg0)); }
	void test_case_4() { string Arr0[] = {
 "B..................XX.................XX.XXX.....B",
 "...XXXXX.....XXXX......XXXXX.....XXXX..XXX.XXXX...",
 "............XX..................XX................",
 ".......XXX........XX..X....XXX...........XXX......",
 "............XXX......X.XXX......XXX.XXX..X.XXX....",
 "....XXXX......XXX...X...XXXX......XXX.XXXX........",
 "B..XX..............XX............................B"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(4, Arg1, clearPassages(Arg0)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            FourBears ___test;  
            ___test.run_test(0);  
            return 0;  
    }  
    // END CUT HERE  
