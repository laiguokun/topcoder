#line 7 "RestoreExpression.cpp"  
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
    bool can[2][100];  
    bool ok(string a,string b,string c)
    {
        int lenc=c.length(),lena=a.length(),lenb=b.length();
        if ((lena>lenc)||(lenb>lenc)) return false;
        memset(can,false,sizeof(can));
        for (int i=0;i<lenc;i++)
        {
                int anow=lenc-i,bnow=lenc-i;
                int amin,amax,bmin,bmax,cmin,cmax;
                if (anow>lena)
                {
                        amin=0;amax=0;
                }
                else
                {
                        int now=lena-anow;
                        if (a[now]!='?') {amin=(int)a[now]-48;amax=amin;}
                        else
                        {
                                if ((now==0)&&(lena!=1)) {amin=1;amax=9;}
                                else {amin=0;amax=9;}
                        }
                }
                if (bnow>lenb)
                {
                        bmin=0;bmax=0;
                }
                else
                {
                        int now=lenb-bnow;
                        if (b[now]!='?') {bmin=(int)b[now]-48;bmax=bmin;}
                        else
                        {
                                if ((now==0)&&(lenb!=1)) {bmin=1;bmax=9;}
                                else {bmin=0;bmax=9;}
                        }
                }
                int now=i;
                if (c[now]!='?') {cmin=(int)c[now]-48;cmax=cmin;}
                else
                {
                        if ((now==0)&&(lenc!=1)) {cmin=1;cmax=9;}
                        else {cmin=0;cmax=9;}
                }
                bool f0,f1;
                for (int jw=0;jw<=1;jw++)
                        for (int cnum=cmin;cnum<=cmax;cnum++)
                                for (int anum=amin;anum<=amax;anum++)
                                          for (int bnum=bmin;bnum<=bmax;bnum++)
                                          {
                                                if (i==0)
                                                {
                                                        f0=true;
                                                        f1=false;
                                                }
                                                else
                                                {
                                                        f0=can[0][i-1];
                                                        f1=can[1][i-1];
                                                }
                                                if ((anum+bnum+jw==cnum)&&(f0)) can[jw][i]=true;
                                                if ((anum+bnum-10+jw==cnum)&&(f1)) can[jw][i]=true;
                                          }
        }
        return can[0][lenc-1];
    }
    class RestoreExpression  
    {  
            public:  
            string restore(string expression)  
            {  
                    int len=expression.length();
                    string a,b,c;
                    a.clear();b.clear();c.clear();
                    int now=0;
                    while (expression[now]!='+')
                    {
                        a=a+expression[now];
                        now++;
                    }
                    now++;
                    while (expression[now]!='=')
                    {
                        b=b+expression[now];
                        now++;
                    }
                    now++;
                    for (int i=now;i<len;i++) c=c+expression[i];
                    if (!ok(a,b,c)) return ("no solution");
                    for (int i=0;i<c.length();i++)
                    {
                        if (c[i]=='?')
                        {
                                for (int num=9;num>=0;num--)
                                {
                                        c[i]=char(num)+48;
                                        if (ok(a,b,c)) break;
                                }
                        }
                    }
                    for (int i=0;i<a.length();i++)
                    {
                        if (a[i]=='?')
                        {
                                for (int num=9;num>=0;num--)
                                {
                                        a[i]=char(num)+48;
                                        if (ok(a,b,c)) break;
                                }
                        }
                    }
                    for (int i=0;i<b.length();i++)
                    {
                        if (b[i]=='?')
                        {
                                for (int num=9;num>=0;num--)
                                {
                                        b[i]=char(num)+48;
                                        if (ok(a,b,c)) break;
                                }
                        }
                    }
                    return a+'+'+b+'='+c;
            }
            
  
    };  
      


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
