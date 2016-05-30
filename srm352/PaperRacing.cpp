    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE 

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
    const int len=500000;
    int q[len][5];
    bool f[51][51][101][101];
    int p[]={-1,0,1};
    int next[105][105][105][3];
    const int maxint=100000;
    int n,m,k;
    void ins(int i,int j,int x,int y,int t)
    {
        next[i+50][j+50][++k][0]=x;
        next[i+50][j+50][k][1]=y;
        next[i+50][j+50][k][2]=t;
    }
    bool inside(int x,int y)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    class PaperRacing  
    {  
            public:  
            int minMoves(vector <string> track, int vRow, int vCol)
            {
                n=track.size(),m=track[0].size();
                memset(f,sizeof(f),false);
                for (int i=0;i<=50;i++)
                        for (int j=0;j<=50;j++)
                        {
                                if ((i==0)&&(j==0))
                                {
                                        next[i+50][j+50][0][2]=-1;
                                        continue;
                                }
                                if ((i==1)&&(j==0))
                                        int t=1;
                                int xx=i+50,yy=j+50;
                                int x=0,y=0;
                                k=-1;
                                while (!(x==i&&y==j))
                                {
                                        if ((x*2+1)*j>(y*2+1)*i)
                                        {
                                                y++;
                                                ins(i,j,x,y,0);
                                        }
                                        if ((x*2+1)*j<(y*2+1)*i)
                                        {
                                                x++;
                                                ins(i,j,x,y,0);
                                        }
                                        if ((x*2+1)*j==(y*2+1)*i)
                                        {
                                                ins(i,j,x+1,y,1);
                                                ins(i,j,x,y+1,1);
                                                x++;y++;
                                                ins(i,j,x,y,0);
                                        }
                                }
                                next[i+50][j+50][k+1][2]=-1;
                                if (next[51][50][0][2]==-1)
                                   int t=1;
                        }
                for (int i=-50;i<=50;i++)
                        for (int j=-50;j<=50;j++)
                        {
                                if (i>=0 && j>=0) continue;
                                int k1=abs(i),k2=abs(j),x,y,t;
                                bool t1=i<0,t2=j<0;
                                int s=0;
                                if (i==-1 && j==0)
                                        int t=1;
                                k=-1;
                                while (next[k1+50][k2+50][s][2]!=-1)
                                {
                                        x=next[k1+50][k2+50][s][0];
                                        y=next[k1+50][k2+50][s][1];
                                        if (t1) x*=-1;
                                        if (t2) y*=-1;
                                        t=next[k1+50][k2+50][s][2];
                                        ins(i,j,x,y,t);
                                        s++;
                                }
                                next[i+50][j+50][k+1][2]=-1;
                        }
                int sx=0,sy=0;
                for (int i=0;i<n;i++)
                        for (int j=0;j<m;j++)
                                if (track[i][j]=='S')
                                {
                                        sx=i;sy=j;
                                }
                int h=0,t=0;
                q[h][0]=sx;q[h][1]=sy;q[h][2]=vRow+50;q[h][3]=vCol+50;q[h][4]=1;
                f[sx][sy][vRow+50][vCol+50]=true;
                while (h<=t)
                {
                        int now=h%len;
                        int x,y,r,c,vr,vc;
                        x=q[now][0];y=q[now][1];r=q[now][2];c=q[now][3];
                        for (int t1=0;t1<3;t1++)
                                for (int t2=0;t2<3;t2++)
                                {
                                        if (x==0 && y==1 && r==50 && c==51)
                                                int t=1;
                                        vr=r+p[t1];vc=c+p[t2];
                                        int k=0;
                                        bool ok1=true,ok2=false;
                                        int x1=0,y1=0;
                                        while (next[vr][vc][k][2]!=-1)
                                        {
                                                x1=next[vr][vc][k][0];y1=next[vr][vc][k][1];
                                                if (next[vr][vc][k][2]==0)
                                                {
                                                        if (inside(x1+x,y1+y)&&(track[x1+x][y1+y]=='F')) {ok2=true;break;}
                                                        if ((!inside(x1+x,y1+y))||(track[x1+x][y1+y]=='X')) {ok1=false;break;}
                                                }
                                                else
                                                {
                                                        if (inside(x1+x,y1+y)&&(track[x1+x][y1+y]=='F')){ok2=true;break;}
                                                }
                                                k++;
                                        }
                                        if (ok2) return q[now][4];
                                        if (x==0 && y==1 && vr==50 && vc==52)
                                                int t=1;
                                      //  if ((ok1))
                                     //          printf("%d %d\n",x+x1,y+y1);
                                        if ((ok1)&&(!f[x+x1][y+y1][vr][vc]))
                                        {
                                                t++;
                                                int now_=t%len;
                                                q[now_][0]=x+x1;
                                                q[now_][1]=y+y1;
                                                q[now_][2]=vr;
                                                q[now_][3]=vc;
                                                q[now_][4]=q[now][4]+1;
                                                f[x+x1][y+y1][vr][vc]=true;
                                        }
                                }
                        h++;
                }
                return -1;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"S.................F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 6; verify_case(0, Arg3, minMoves(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"S.................F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 8; int Arg3 = 2; verify_case(1, Arg3, minMoves(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"FX",
 "X.",
 ".X",
 "X.",
 "SX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; int Arg3 = 8; verify_case(2, Arg3, minMoves(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"S..X",
 "X..X",
 "XX.X",
 "XXFX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; int Arg2 = 50; int Arg3 = 1; verify_case(3, Arg3, minMoves(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"S.......X.........F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = -1; verify_case(4, Arg3, minMoves(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {
            PaperRacing ___test;  
            ___test.run_test(0);
            system("pause");
            return 0;  
    }  
    // END CUT HERE
