// BEGIN CUT HERE

// END CUT HERE
#line 5 "TwistyPassages.cpp"
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
struct T{int a,b,c,d;};
const int m=500000;
T q[500000];
int f[50][50][50][50],gg[50][50],s[50];
VI g[50];
int h,t;
void add(int i,int j,int x,int y)
{
        if (f[i][j][x][y]==1) return;
        f[i][j][x][y]=1;
        t++;q[t%m].a=i;q[t%m].b=j;q[t%m].c=x;q[t%m].d=y;
}
class TwistyPassages
{
        public:
        vector <int> similarRooms(vector <string> maze)
        {
                int n=maze.size();
                for (int i=0;i<n;i++)
                {
                        int num=0,len=maze[i].length();
                        for (int j=0;j<len;j++)
                        {
                                if (maze[i][j]==' ')
                                {
                                        g[i].PB(num);
                                        num=0;
                                }
                                else num=num*10+(int)maze[i][j]-48;
                        }
                        if (len!=0)g[i].PB(num);
                        s[i]=g[i].size();
                }
                for (int i=0;i<n;i++)
                        for (int x=0;x<s[i];x++)
                                for (int y=0;y<s[g[i][x]];y++)
                                        if (g[g[i][x]][y]==i) {gg[i][x]=y;break;}
                memset(f,0,sizeof(f));
                h=0;t=-1;
                for (int i=0;i<n;i++)
                        for (int j=0;j<n;j++)
                        {
                                if (s[i]!=s[j])
                                        for (int x=0;x<s[i];x++)
                                                for (int y=0;y<s[j];y++) add(i,j,x,y);
                        }
                while (h<t)
                {
                        T now=q[h%m];
                        int i=g[now.a][now.c],j=g[now.b][now.d],x=gg[now.a][now.c],y=gg[now.b][now.d];
                        if (now.a==0&& now.b==3&& now.c==0 && now.d==1)
                                int t=1;
                        if (s[i]==s[j])
                        {
                                for (int k=0;k<s[i];k++)
                                {
                                        int t1=(x+k)%s[i],t2=(y+k)%s[i];
                                        add(i,j,t1,t2);
                                }
                        }
                        h++;
                }
                VI ans;
                ans.clear();
                for (int i=0;i<n;i++)
                {
                        int res=0;
                        for (int j=0;j<n;j++)
                        {
                                if (i==j) continue;
                                if ((s[j]==0 && s[i]==0)) res++;
                                if (s[j]!=s[i]) continue;
                                bool o=false;
                                for (int x=0;x<s[j];x++)
                                        if (f[i][j][0][x]==0)
                                                o=true;
                                if (o)  res++;
                        }
                        ans.PB(res);
                }
                return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] ={"14 31 1 48 32 24 21 20 10 43 3 47 2 28 39", 
"6 33 8 21 4 27 40 0 47 13 28 16 26 35 37",
 "30 0 45 31 22 28 41 21 4 8 42 37 15 29 49", 
"18 42 10 32 5 0 25 47 7 35 48 38 16 33 45",
 "14 7 25 37 18 34 17 47 1 39 2 15 24 42 41",
 "23 14 21 26 19 25 9 22 49 30 3 29 31 42 13", 
"12 32 40 22 38 19 18 16 37 9 41 48 10 1 39", 
"30 46 23 4 3 11 20 34 33 47 44 15 31 43 35", 
"30 24 32 42 41 1 49 2 33 48 25 31 20 43 37", 
"27 6 22 5 12 10 32 18 40 49 25 48 42 26 33",
 "14 46 9 34 36 41 44 47 31 0 45 11 17 3 6",
 "19 15 16 7 35 10 28 14 48 47 44 49 46 17 13",
 "41 48 15 35 29 33 36 13 30 39 9 19 14 6 43",
 "20 12 17 21 33 43 19 39 1 23 27 49 11 32 5", 
"39 10 25 38 19 0 20 11 5 12 16 21 17 15 4", 
"24 48 21 2 14 7 35 40 4 41 11 27 12 45 16",
 "14 41 15 1 3 18 17 38 28 23 37 6 11 45 19", 
"14 11 44 37 19 26 34 4 25 10 16 46 38 36 13", 
"30 34 6 4 9 21 36 29 22 46 26 16 3 28 37", 
"38 12 44 25 16 11 13 14 17 27 5 36 6 37 45", 
"46 14 31 40 13 7 0 24 35 49 32 42 34 8 21",
 "14 35 18 31 28 5 26 2 34 15 30 20 0 1 13",
 "18 27 47 43 2 5 31 28 6 36 24 9 32 45 46",
 "5 13 44 37 24 46 35 16 7 33 30 26 28 41 40",
 "29 8 15 40 20 26 4 37 35 22 33 0 23 44 32",
 "34 8 4 3 39 9 29 5 14 42 44 38 17 19 43", 
"45 23 18 1 29 37 9 28 17 5 35 21 24 43 48",
 "46 29 22 19 38 39 34 41 13 15 35 1 47 9 28", 
"0 49 1 31 18 27 11 23 2 16 21 26 48 22 43", 
"36 2 24 27 26 47 46 48 25 38 40 18 5 41 12",
 "12 18 2 5 8 38 23 32 36 43 7 37 42 21 48",
 "0 8 36 21 2 5 32 20 10 22 28 7 43 40 33",
 "6 20 8 0 39 3 22 35 30 24 38 31 45 13 9", 
"23 42 9 12 13 44 8 41 31 34 1 24 7 39 3", 
"45 4 7 20 25 18 27 36 10 21 33 40 46 41 17",
 "23 21 12 32 47 15 43 24 26 3 7 20 27 11 1", 
"42 45 18 47 30 46 34 22 19 29 12 40 17 10 31", 
"19 30 49 45 2 18 17 1 16 4 6 8 26 23 24",
 "29 6 42 19 17 44 14 30 32 27 45 25 16 49 3",
 "12 4 14 0 33 48 44 25 32 6 46 49 40 27 13",
 "24 34 29 49 20 46 1 9 23 15 39 6 36 31 41",
 "48 12 23 2 15 8 40 10 4 34 33 27 6 29 16",
 "38 4 8 2 45 25 5 3 36 20 9 49 44 33 30", 
"28 47 26 49 8 0 25 48 12 22 7 13 31 30 35", 
"11 33 19 10 47 25 7 39 24 46 23 38 42 45 17", 
"2 44 37 3 10 42 22 36 19 16 32 34 15 26 38", 
"7 40 36 23 44 22 27 10 18 20 17 29 39 34 11", 
"1 35 11 7 43 10 0 4 44 3 27 29 49 22 36", 
"43 3 8 9 41 29 12 15 26 0 30 28 6 39 11", 
"5 28 40 38 9 39 11 37 43 20 13 2 42 8 47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, similarRooms(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 2 3", "0", "0", "0 4", "3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, similarRooms(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 2 3", "0", "0", "0 4", "3",
 "6 7 8", "5", "5", "5 9", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, similarRooms(Arg0)); }
	void test_case_3() { string Arr0[] = {"1 2 3 4",  "0", "0 5",  "0", "6 0",  "2", "4",
"8 10 9 11", "7", "7 12", "7", "13 7", "9", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, similarRooms(Arg0)); }
	void test_case_4() { string Arr0[] = {"1 2", "2 0", "0 1", "4 6", "5 3", "6 4", "3 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 6, 6, 6, 6, 6, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, similarRooms(Arg0)); }
	void test_case_5() { string Arr0[] = {"1 2 3", "4 5 0", "6 7 0", "8 9 0", "10 11 1", "12 13 1", 
 "14 15 2", "16 17 2", "18 19 3", "20 21 3", "22 23 4", 
 "24 25 4", "26 27 5", "28 29 5", "30 31 6", "32 33 6", 
 "34 35 7", "36 37 7", "38 39 8", "40 41 8", "42 43 9", 
 "44 45 9", "10", "10", "11", "11", "12", "12", "13", "13",
 "14", "14", "15", "15", "16", "16", "17", "17", "18", "18",
 "19", "19", "20", "20", "21", "21"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, similarRooms(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TwistyPassages ___test;
        ___test.run_test(0);
        system("pause");
        return 0;
}
// END CUT HERE
