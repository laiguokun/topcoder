#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
const double inf=1e100;
int TimeLeft,n,m,sx,sy;
double f[50][50][110][5],SpeedingTicket,RedLight;
string CityMap[50];

double solve(int x,int y,int t,int way){
    if (CityMap[x][y]=='X') return inf;
    if (t>TimeLeft) return inf;
    if (t<TimeLeft && CityMap[x][y]=='C') return inf;
    if (t==TimeLeft) return (CityMap[x][y]=='C')?0:inf;
    if (f[x][y][t][way]>-1) return f[x][y][t][way];
    
    int nx,ny;
    double tmp=inf,t1=0,t2=0;
    FOR(i,0,3)
        if((i^1)!=way){
            nx=x+dx[i];ny=y+dy[i];
            if (nx<0 || ny<0 || nx>n || ny>m) continue;
            t1=solve(nx,ny,t+1,i);
            if (CityMap[nx][ny]=='S') t1=t1+SpeedingTicket;
            else if (CityMap[nx][ny]=='T'){
                t2=solve(nx,ny,t+2,i);
                t1=t1+0.7*RedLight;
                if (t2<t1) t1=t2;
            }
            if (t1<tmp) tmp=t1;
            
        }
    f[x][y][t][way]=tmp;
    return tmp;
}
class LateForConcert{
    public:
    double bestRoute(vector <string>cityMap,int timeLeft,double speedingTicket,double redLight){
        n=cityMap.size();
        m=cityMap[0].length();
        n--;m--;
        FOR(i,0,n) CityMap[i]=cityMap[i];
        TimeLeft=timeLeft;SpeedingTicket=speedingTicket;RedLight=redLight;
        FOR(i,0,n)FOR(j,0,m)FOR(k,0,timeLeft)FOR(z,0,4) f[i][j][k][z]=-inf;
        FOR(i,0,n)FOR(j,0,m)
            if (cityMap[i][j]=='Y') {
                sx=i;sy=j;
                break;
            }
        
        double ans=solve(sx,sy,0,4);
        if (ans<inf) return ans;
                else return -1;
    }
};
/*
int main(){
    cin>>n>>m;
    n--;m--;
    FOR(i,0,n)cin>>cityMap[i];
    cin>>timeLeft;
    cin>>speedingTicket;
    cin>>redLight;
    FOR(i,0,n)FOR(j,0,m)FOR(k,0,timeLeft)FOR(z,0,4) f[i][j][k][z]=-2;
    FOR(i,0,n)FOR(j,0,m)
        if (cityMap[i][j]=='Y') {
            sx=i;sy=j;
            break;
        }
    
    cout<<solve(sx,sy,0,4)<<endl;    
    system("pause");
}*/
