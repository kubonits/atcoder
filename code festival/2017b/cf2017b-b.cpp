#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m,d[200001],t[200000],j=0,i,flag=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&t[i]);
    }
    sort(d,d+n);
    sort(t,t+m);
    d[n]=t[m-1]+1;
    i=0;
    while(i<m){
        if(t[i]==d[j]){
            i++;
            j++;
        }
        else if(t[i]>d[j]){
            j++;
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}