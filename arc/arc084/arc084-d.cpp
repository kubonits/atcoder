#include<cstdio>
#include<deque>
using namespace std;
int k,co[100000],visited[100000];
deque<int> d;

void bfs(int x){
    d.pop_front();
    visited[x]=1;
    if(co[x*10%k]>co[x]){
        co[x*10%k]=co[x];
        d.push_front(x*10%k);
    }
    if(co[(x+1)%k]>co[x]+1){
        co[(x+1)%k]=co[x]+1;
        d.push_back((x+1)%k);
    }
}
int main(){
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        co[i]=1000;
    }
    co[1]=1;
    d.push_back(1);
    while(!d.empty()){
        if(visited[d.front()]==0){
            bfs(d.front());
        }
        else{
            d.pop_front();
        }
    }
    printf("%d\n",co[0]);
}