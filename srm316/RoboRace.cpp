    // BEGIN CUT HERE
    /*

    */
    // END CUT HERE
    #line 7 "RoboRace.cpp"
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


    int g1[2550][50][50],g2[2550][50][50];
    int n,m;
    inline void move(char ch,int& x,int& y)
    {
        if (ch=='N') x--;
        if (ch=='S') x++;
        if (ch=='W') y--;
        if (ch=='E') y++;
    }
    inline bool ok(int x,int y)
    {
        if ((x>=0)&&(x<n)&&(y>=0)&&(y<m)) return true;else return false;
    }
    inline int max(int a,int b){if (a>b) return a;else return b;}
    inline int min(int a,int b){if (a<b) return a;else return b;}
    class RoboRace  
    {
            public:
            int startTime(vector <string> board, vector <string> commands)
            {
                    int yx,fx,tx,yy,fy,ty;    
                    n=board.size();m=board[0].length();
                    for (int i=0;i<n;i++)
                        for (int j=0;j<m;j++)
                        {
                                if (board[i][j]=='Y')
                                {
                                        yx=i;yy=j;
                                }
                                if (board[i][j]=='F')
                                {
                                        fx=i;fy=j;
                                }
                                if (board[i][j]=='X')
                                {
                                        tx=i;ty=j;
                                }
                        }
                    for (int i=1;i<commands.size();i++) commands[0]=commands[0]+commands[i];
                    int slen=commands[0].length();
                    for (int k=0;k<slen;k++)
                        for (int i=0;i<n;i++)
                                for (int j=0;j<m;j++) {g1[k][i][j]=-1;g2[k][i][j]=-1;}
                    g1[0][yx][yy]=0;
                    for (int k=1;k<=slen;k++)
                    {
                        g1[k][yx][yy]=k;
                        for (int i=0;i<n;i++)
                                for (int j=0;j<m;j++)
                                {
                                        if (g1[k-1][i][j]==-1) continue;
                                        g1[k][i][j]=max(g1[k][i][j],g1[k-1][i][j]);
                                        int nx=i,ny=j;
                                        move(commands[0][k-1],nx,ny);
                                        if ((ok(nx,ny))&&(board[nx][ny]!='#')) g1[k][nx][ny]=max(g1[k][nx][ny],g1[k-1][i][j]);
                                 }
                    }
                    g2[0][fx][fy]=0;
                    for (int k=1;k<=slen;k++)
                    {
                        g2[k][fx][fy]=k;
                        for (int i=0;i<n;i++)
                                for (int j=0;j<m;j++)
                                {
                                        if (g2[k-1][i][j]==-1) continue;
                                        g2[k][i][j]=max(g2[k][i][j],g2[k-1][i][j]);
                                        int nx=i,ny=j;
                                        move(commands[0][k-1],nx,ny);
                                        if ((ok(nx,ny))&&(board[nx][ny]!='#')) g2[k][nx][ny]=max(g2[k][nx][ny],g2[k-1][i][j]);
                                 }
                    }
                    int ans=slen;
                    for (int k=1;k<slen;k++)
                    {
                        if (g1[k][tx][ty]!=-1)
                        {
                                if (g2[k][tx][ty]==-1) return 0;
                                if (g1[k][tx][ty]>g2[k][tx][ty]) ans=min(ans,g2[k][tx][ty]+1);
                        }
                    }
                    if (ans==slen) return -1;else return ans;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#F",
 "YX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NES"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, startTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"########",
 "#......#",
 "#.Y....#",
 "#.F.#..#",
 "#...X..#",
 "#...#..#",
 "#......#",
 "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SSEEESSW"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, startTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"########",
 "#......#",
 "#.Y....#",
 "#.F.#..#",
 "#...X..#",
 "#...#..#",
 "#......#",
 "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ESSEESSW"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, startTime(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"##.#.#.",
 "..##...",
 "..#...X",
 "Y...##.",
 "#...#.#",
 "..#..F."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SSSNWSSSEWNSENENENNNNENWNEWESE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, startTime(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#..#.........#...X##....",
 "#........#..........##.#",
 ".#.#........#.....#.#...",
 "..###...#..##.##...#....",
 "..#.#.....#....#.#.####.",
 "#...##.##.##..#.....##..",
 ".##...#.#....#.......#.#",
 "....##.#..#....#....#...",
 "....###.##.....###...#..",
 "#.#.......#.#......#..#.",
 ".##....##.#.##.......#.#",
 "......###...####......#.",
 "..#.##.#..#.#...#...#...",
 ".....#.#..........#...#.",
 "##.#....##F#.....#.##.#.",
 ".##....#.......##.##.##.",
 "..#...#..##....#..#...Y.",
 "#...........#...###..###",
 ".....#...#..#.........#.",
 ".#...##..#.#...#..#.##..",
 "#..#...######....###.#..",
 "#.#.....#.......#.##....",
 "#..#....###....#.#..#...",
 "..#...#.##.##.#.##.##..#",
 "#....##.##..........#..#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NWWSEWSSNWESSWES",
 "ESEEENSNWNNWSNSNWWNWWNNNWE",
 "NSNENENNSEENWWNSNNNNWWSSN",
 "EENEWNWESESEEESNNNSEENNEWNNESNEESSEESEEENENNNWSSW",
 "NWNNWSNWSWSSSSEEWSSWSESWWNNWWENSNNWWSSWWNNE",
 "NWEWNEWSNEN",
 "NNNEWNSWSNWESWNNNSWWNNNWWWNNEWNEEWSSWNSSWWNNWESEWS",
 "WSSSEESSEEEEENNSWEWWWENSENWNSEENES",
 "NNSNESESWNESNENSEESESWSENNESESNESNESEEW",
 "ESNENEENWSNS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(4, Arg2, startTime(Arg0, Arg1)); }

// END CUT HERE

    };

    // BEGIN CUT HERE
    int main()
    {
            RoboRace ___test;
            ___test.run_test(1);
            system("pause");
            return 0;
    }
    // END CUT HERE
