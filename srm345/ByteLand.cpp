    // BEGIN CUT HERE
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "ByteLand.cpp"  
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
    int id[60],mark[60],loop[60],mark_[60],loop_[60],g[60][60],rr[60],r[60],q[60],c[60],dist[60];
    bool cas[60];
    int n,h,t;
   void dfs(int x,int k)
    {
        id[x]=k;
        for (int i=0;i<n;i++)
                if ((id[i]==0)&&(g[x][i])) dfs(i,k);
    }
    int ff(int a,int b)
    {
        if (a>=0) return a+b;
        if ((a<0)&&(a+b<0)) return a+b;
        return 0;
    }
    void merge(int& a,int b)
    {
          if (a>=0) if (abs(a)<abs(b)) a=b;
          if (a<0) if (abs(a)<=abs(b)) a=b;
    }
   void del(int x)
    {
        rr[c[x]]--;
        if (rr[c[x]]==0)
        {
                t++;q[t]=c[x];
        }
    } 
    void fz(int a[],int b[]){for (int i=0;i<50;i++) a[i]=b[i];}
    int ok(int now,int sum)
    {
        if (sum==76)
                int t=1;
        int res=0;
        h=0;t=-1;
        for (int i=0;i<n;i++)
                if (id[i]==now)
                {
                        if (rr[i]==0)
                        {
                                t++;
                                q[t]=i;
                        }
                }
        while (h<=t)
        {
                int x=q[h];
                if (((mark[x]>=0)&&(mark[x]+dist[x]>sum))||cas[x])
                {
                        res++;
                        merge(mark[c[x]],ff(-sum-1,dist[x]));
                        if (cas[x]) res--;
                }
                else merge(mark[c[x]],ff(mark[x],dist[x]));
                del(x);h++;
        }
        int p=-1;
        for (int i=0;i<n;i++) if ((id[i]==now)&&(rr[i]==1)) p=i;
        memset(loop,0,sizeof(loop));
        loop[0]=p;loop[1]=c[p];
        int len=0;
        while (loop[len+1]!=p)
        {
                len++;
                loop[len+1]=c[loop[len]];
        }
        fz(mark_,mark);
        bool ex=true;
        if (len>0)
        {
        for (int i=0;i<=len;i++)
        {
                if (cas[loop[i]]) mark[loop[i]]=-sum-1;
                merge(mark[loop[(i+1)%(len+1)]],ff(mark[loop[i]],dist[loop[i]]));
        }
        for (int i=0;i<=len;i++)
        {
                //if (mark[loop[i]]>sum) {ex=false;break;}
                if (i<len) merge(mark[loop[i+1]],ff(mark[loop[i]],dist[loop[i]]));
        }
        for (int i=2*len;i>0;i--)  merge(mark[loop[(i-1)%(len+1)]],ff(mark[loop[i%(len+1)]],dist[loop[(i-1)%(len+1)]]));}
        for (int i=0;i<=len;i++) if (mark[loop[i]]>=0) ex=false;
        //if (mark[loop[len]]>=0) ex=false;
        if (ex) return res;
       int res_=res;int lr=100000;
         fz(loop_,loop);
        if (sum==12)
          int t=1;
        for (int k=0;k<=len;k++)
        {
                fz(mark,mark_);
                for (int i=0;i<=len;i++) loop[i]=loop_[(i+k)%(len+1)];
                mark[loop[0]]=-sum-1;
                if (loop[0]==14)
                  int t=1;
                int tt=-sum-1;
                if (!cas[loop[0]]) res=res_+1;else res=res_; 
                for (int i=len;i>0;i--)
                {
                        tt=tt+dist[loop[i]];
                        if ((tt<0)&&(abs(tt)>abs(mark[loop[i]]))) mark[loop[i]]=tt;else break;
                }
                for (int i=0;i<len;i++)
                {
                        if (((mark[loop[i]]>=0)&&(mark[loop[i]]+dist[loop[i]]>sum))||cas[loop[i]])
                        {
                                res++;
                                merge(mark[loop[i+1]],ff(-sum-1,dist[loop[i]]));
                                if (cas[loop[i]]) res--;
                        }
                        else merge(mark[loop[i+1]],ff(mark[loop[i]],dist[loop[i]]));
                }
                if (mark[loop[len]]>=0) res++;
                lr=min(lr,res);
        }
        return lr;
    }
    class ByteLand  
    {  
            public:  
            int buildCastles(vector <int> road, vector <int> distance, vector <int> castle, int k)  
            {
                memset(g,0,sizeof(g));
                n=road.size();
                int mm=0;
                if (castle.size()+k>=n) return 0;
                for (int i=0;i<n;i++)
                {
                        r[road[i]]++;
                        mm=mm+distance[i];
                        if (g[i][road[i]]==0) g[i][road[i]]=distance[i];
                        if (g[road[i]][i]==0) g[road[i]][i]=distance[i];
                        g[i][road[i]]=min(g[i][road[i]],distance[i]);
                        g[road[i]][i]=min(g[road[i]][i],distance[i]);
                }
                for (int i=0;i<n;i++) distance[i]=min(distance[i],g[i][road[i]]);
                for (int i=0;i<n;i++) c[i]=road[i];
                memset(cas,0,sizeof(cas));
                for (int i=0;i<castle.size();i++) cas[castle[i]]=true;
                for (int i=0;i<n;i++) dist[i]=distance[i];
                memset(id,0,sizeof(id));
                int tot=0;
                for (int i=0;i<n;i++)
                {
                        if (id[i]==0)
                        {
                                tot++;
                                dfs(i,tot);
                        }
                }
                int h=1,t=mm;
                while (h<t)
                {
                        int mid=(h+t)/2;
                        int sum=0;
                        fz(rr,r);
                        memset(mark,0,sizeof(mark));
                        if (mid==76)
                                int t=1;
                        for (int j=1;j<=tot;j++)
                        {
                                sum=sum+ok(j,mid);
                        }
                        if (sum<=k) t=mid;else h=mid+1;
                }
                return h;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
      	void test_case_0() { int Arr0[] = {1,2,3,4,0};vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));int Arr1[] = {1,1,1,1,1};vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));vector <int> Arg2; Arg2.clear();int Arg3 = 1; int Arg4 = 2; verify_case(0, Arg4, buildCastles(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0, 4, 3, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 1, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 3; verify_case(1, Arg4, buildCastles(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] ={0, 41, 14, 45, 16, 49, 46, 34, 21, 12, 13, 41, 17, 39, 32, 36, 17, 14, 31, 38, 20, 3, 49, 18, 0, 27, 35, 12, 5, 36, 44, 7, 29, 10, 4, 45, 12, 0, 32, 33, 14, 47, 27, 31, 36, 9, 19, 4, 25, 2};vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] =  {95, 96, 56, 94, 64, 9, 23, 1, 21, 80, 89, 18, 37, 18, 28, 43, 16, 40, 94, 98, 76, 60, 45, 53, 44, 33, 12, 63, 89, 39, 66, 83, 35, 73, 29, 50, 81, 51, 3, 2, 31, 91, 71, 19, 61, 50, 62, 76, 90, 7};vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 8, 15, 16, 18, 21, 22, 23, 31, 39};vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; int Arg4 =87; verify_case(2, Arg4, buildCastles(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,2,0,0,2,2,8,3,8,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,9,1,8,1,3,7,2,8,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,4,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 3; verify_case(3, Arg4, buildCastles(Arg0, Arg1, Arg2, Arg3)); }
       	void test_case_4(){}; //{ int Arr0[] = {1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 5; verify_case(4, Arg4, buildCastles(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

    };  
      
    // BEGIN CUT HERE  
    int main()
    {  
            ByteLand ___test;  
            ___test.run_test(2);
            system("pause");
            return 0;  
    }  
    // END CUT HERE  
