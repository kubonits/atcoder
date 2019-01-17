#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
int main(){
    long w,h,a,b,p,ans=0;
    pair<long,int> c[200000];
    scanf("%ld %ld",&w,&h);
    for(long i=0;i<w;i++){
        scanf("%ld",&p);
        c[i]=make_pair(p,0);
    }
    for(long i=0;i<h;i++){
        scanf("%ld",&p);
        c[i+w]=make_pair(p,1);
    }
    sort(c,c+w+h);
    a=w+1;
    b=h+1;
    for(int i=0;i<w+h;i++){
        if(c[i].second){
            ans+=a*c[i].first;
            b--;
        }
        else{
            ans+=b*c[i].first;
            a--;
        }
    }
    printf("%ld\n",ans);
}