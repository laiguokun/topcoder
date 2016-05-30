#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

string s[10],str;
bool vis[30],used[30],flag;
int a[6][6],b[6][6],need[30];
vector <string> ans;

bool ok(int r,int a1,int a2,int a3,int a4,int a5){
        if (a[r][1] && a[r][1]!=a1) return false;
        if (a[r][2] && a[r][2]!=a2) return false;
        if (a[r][3] && a[r][3]!=a3) return false;
        if (a[r][4] && a[r][4]!=a4) return false;
        if (a[r][5] && a[r][5]!=a5) return false;
        return true;
}
bool check(int r){
        if(r>5) return true;
        memcpy(used,vis,sizeof(used));
        int size=0;
        FOR(i,r,5){
                flag=false;
                FOR(j,1,5)
                if (a[i][j]){
                        FORD(k,j-1,1) need[++size]=a[i][j]+k-j;
                        flag=true;
                        break;
                }
                if (!flag)FOR(j,1,5) need[++size]=20+j;
        }
        if (size){
                sort(need+1,need+size+1);
                int p=1;
                FOR(i,1,25)if (!used[i]){
                        if (i>need[p]) return false;
                        used[i]=true;
                        p++;
                        if (p>size) break;
                }
                if (p<=size) return false;
                
        }
        size=0;
        FOR(i,r,5)FORD(j,5,1)
                if (a[i][j]){
                        FOR(k,j+1,5) need[++size]=a[i][j]+k-j;
                        break;
                }
        if (size){
                sort(need+1,need+size+1);
                int p=size;
                FORD(i,25,1)if (!used[i]){
                        if (i<need[p]) return false;
                        used[i]=true;
                        p--;
                        if (!p) break;
                }
                if (p) return false;
                
        }
        return true;
}
bool solve(int r){
        FOR(a1,1,25)if (!vis[a1] || a1==a[r][1])
        FOR(a2,a1+1,25) if (!vis[a2] || a2==a[r][2])
        FOR(a3,a2+1,25) if (!vis[a3] || a3==a[r][3])
        FOR(a4,a3+1,25) if (!vis[a4] || a4==a[r][4])
        FOR(a5,a4+1,25) if (!vis[a5] || a5==a[r][5])
        if (ok(r,a1,a2,a3,a4,a5)){
                vis[a1]=vis[a2]=vis[a3]=vis[a4]=vis[a5]=true;
                if (check(r+1))    {
                        char str[100];
                        sprintf(str,"%02d %02d %02d %02d %02d",a1,a2,a3,a4,a5);
                        ans.push_back(str);
                        return true;
                }
                vis[a1]=vis[a2]=vis[a3]=vis[a4]=vis[a5]=false;
        }
        return false;
        
}
class NewMagicSquare{
        public:
        vector <string> completeTheSquare(vector <string> square){
                FOR(i,0,4) s[i+1]=square[i];
                FOR(i,1,5){
                        istringstream sin(s[i]);
                        FOR(j,1,5){
                                sin>>str;
                                if (str=="??") a[i][j]=0;
                                else {
                                        sscanf(str.c_str(),"%d",&a[i][j]);  
                                        vis[a[i][j]]=true;
                                }
                        }
                }
                vector<string> empty;
                FOR(row,1,5)
                        if(!solve(row)) return empty;
                return ans;
        }
};
/*int main(){
        vector <string> completeTheSquare(vector <string> square){
                FOR(i,0,4) s[i+1]=square[i];
                FOR(i,1,5){
                        istringstream sin(s[i]);
                        FOR(j,1,5){
                                sin>>str;
                                if (str=="??") a[i][j]=0;
                                else {
                                        sscanf(str.c_str(),"%d",&a[i][j]);  
                                        vis[a[i][j]]=true;
                                }
                        }
                }
                a[1][3]=20;a[3][4]=5;
                vis[20]=vis[5]=true;
                
                vector<string> empty;
                FOR(row,1,5)
                        if(!solve(row)) return 0;
                FOR(i,0,ans.size())
                cout<<ans[i];
                return 0;
}*/

