#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    int n;
    pair<int,int> p[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].first);
        p[i].second=i+1;
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
        printf("%d ",p[i].second);
    }
}