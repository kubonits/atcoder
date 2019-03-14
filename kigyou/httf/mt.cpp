#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

int t,n,m,a[30000],b[30000],s[30000][10],sl[10][2],f[30000]={},p,flag;
long c[30000],money=1000,ad,aaa,cost[10];
vector<int> v[1000];

long calc(int x,int y){
    double add;
    add=(double)c[x];
    add*=(1 + 9 * (double)(y - a[x]) / (b[x] - a[x]));
    int slack=0;
    for(int i=0;i<n;i++){
        slack+=max(0,s[x][i]-sl[i][0]);
    }
    if(slack==0){
        add*=10;
    }
    else{
        for(int i=0;i<slack;i++){
            add/=2;
        }
        add+=1e-9;
    }
    return (long)add;
}

int main(){
    srand((unsigned)time(NULL));
    scanf("%d %d %d",&t,&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %ld",&a[i],&b[i],&c[i]);
        for(int j=a[i];j<=b[i];j++){
            v[j].push_back(i);
        }
        for(int j=0;j<n;j++){
            scanf("%d",&s[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        cost[i]=10000;
    }
    for(int i=0;i<t;i++){
        p=-1;
        ad=1000;
        flag=0;
        if(rand()%500>i){
            ad=20000000;
            for(int j=0;j<n;j++){
                if(money>=cost[j]){
                    flag=1;
                    ad=min(ad,cost[j]);
                }
            }
            if(flag){
                for(int j=0;j<n;j++){
                    if(ad==cost[j]){
                        p=j;
                        break;
                    }
                }
                s[p][1]++;
                money-=ad;
                if(s[p][0]<s[p][1]){
                    s[p][0]++;
                    s[p][1]=0;
                    cost[p]*=2;
                }
                printf("1 %d\n",p+1);
            }
        }
        if(flag==0){
            ad=1000;
            for(int j=0;j<v[i].size();j++){
                aaa=calc(v[i][j],i);
                if(f[v[i][j]]==0&&ad<aaa){
                    p=v[i][j];
                    ad=aaa;
                }
            }
            if(p==-1){
                printf("3\n");
                money+=ad;
            }
            else{
                f[p]=1;
                money+=ad;
                printf("2 %d\n",p+1);
            }
        }
    }
}
