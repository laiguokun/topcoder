#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

string ans;
int n,k,tmp,want[30],have[30];
bool vis[30];
string aa[30];

int find(int k){
    FOR(i,1,n)
        if (have[i]==k) return i;
}

class YankeeSwap{
    public:
    string sequenceOfSwaps(vector <string> bb){
        ans="";
        memset(vis,0,sizeof(vis));    
        n=bb.size();
        FOR(i,1,n) aa[i]=bb[i-1];
        FORD(i,n,1)
          FOR(j,0,n-1)
              if(!vis[aa[i][j]-'A']){
                  want[i]=aa[i][j];
                  vis[aa[i][j]-'A']=true;
                  break;
              }
        FOR(i,1,n) have[i]='A'+i-1;
        FOR(i,1,n){
            k=i;
            do{
              k=find(want[k]);
            }
            while (k>i);
        
        if (k==i) ans+='-';
            else{
                ans+='a'+k-1;
                tmp=have[i];have[i]=have[k];have[k]=tmp;
            }
        }
        return ans;
    }
};

/*main(){
    ans="";
    memset(vis,0,sizeof(vis));    
    cin>>n;
    FOR(i,1,n) cin>>aa[i];
    FORD(i,n,1)
        FOR(j,0,n-1)
            if(!vis[aa[i][j]-'A']){
                want[i]=aa[i][j];
                vis[aa[i][j]-'A']=true;
                break;
            }
    FOR(i,1,n) have[i]='A'+i-1;
    FOR(i,1,n){
        k=i;
        do{
          k=find(want[k]);
        }
        while (k>i);
        
        if (k==i) ans+='-';
            else{
                ans+='a'+k-1;
                tmp=have[i];have[i]=have[k];have[k]=tmp;
            }
    }
    cout<<ans<<endl;
    system("pause");     
}*/
