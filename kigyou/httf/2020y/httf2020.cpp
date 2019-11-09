#include<cstdio>
#include<set>
#include<utility>
#include<vector>
using namespace std;

struct ans{
    int y;
    int x;
    char c;
};
int main(){
    int n,m,rx,ry,by[300],bx[300],b,gx,gy,x,y;
    char c;
    scanf("%d %d %d",&n,&m,&b);
    scanf("%d%d",&gy,&gx);
    set<pair<int,int> > bs,as;
    vector<ans> v;
    for(int i=0;i<m;i++){
        scanf("%d %d %c",&ry,&rx,&c);
    }
    for(int i=0;i<b;i++){
        scanf("%d%d",&by[i],&bx[i]);
        bs.insert({by[i],bx[i]});
    }
    as.insert({gy,gx});
    decltype(bs)::iterator it = bs.find(make_pair((n+gy-1)%n,(n+gx)%n));
    if(it==bs.end()){
        v.push_back({(n+gy-1)%n,(gx+n)%n,'D'});
        as.insert({(n+gy-1)%n,(gx+n)%n});
    }
    it = bs.find(make_pair((n+gy+1)%n,(n+gx)%n));
    if(it==bs.end()){
        v.push_back({(n+gy+1)%n,(gx+n)%n,'U'});
        as.insert({(n+gy+1)%n,(gx+n)%n});
    }
    it = bs.find(make_pair((n+gy)%n,(n+gx-1)%n));
    if(it==bs.end()){
        v.push_back({(n+gy)%n,(gx+n-1)%n,'R'});
        as.insert({(n+gy)%n,(gx+n-1)%n});
    }
    it = bs.find(make_pair((n+gy)%n,(n+gx+1)%n));
    if(it==bs.end()){
        v.push_back({(n+gy)%n,(gx+n+1)%n,'L'});
        as.insert({(n+gy)%n,(gx+n+1)%n});
    }
    decltype(bs)::iterator it2;
    for(int i=0;i<b;i++){
        y=(n+by[i]-1)%n;
        x=(bx[i]+n)%n;
        it = bs.find({y,x});
        it2 = as.find({y,x});
        if(it==bs.end()&&it2==as.end()){
            c='X';
            if(bs.find({(x-1+n)%n,(y+n)%n})==bs.end()){
                c='L';
            }
            else if(bs.find({(x+1+n)%n,(y+n)%n})==bs.end()){
                c='R';
            }
            else if(bs.find({(x+n)%n,(y+n-1)%n})==bs.end()){
                c='D';
            }
            else if(bs.find({(x+n)%n,(y+n+1)%n})==bs.end()){
                c='U';
            }
            if(c!='X'){
                v.push_back({y,x,c});
                as.insert({y,x});
            }
        }

        y=(n+by[i]+1)%n;
        x=(bx[i]+n)%n;
        it = bs.find({y,x});
        it2 = as.find({y,x});
        if(it==bs.end()&&it2==as.end()){
            c='X';
            if(bs.find({(x-1+n)%n,(y+n)%n})==bs.end()){
                c='L';
            }
            else if(bs.find({(x+1+n)%n,(y+n)%n})==bs.end()){
                c='R';
            }
            else if(bs.find({(x+n)%n,(y+n-1)%n})==bs.end()){
                c='D';
            }
            else if(bs.find({(x+n)%n,(y+n+1)%n})==bs.end()){
                c='U';
            }
            if(c!='X'){
                v.push_back({y,x,c});
                as.insert({y,x});
            }
        }

        y=(n+by[i])%n;
        x=(bx[i]+n-1)%n;
        it = bs.find({y,x});
        it2 = as.find({y,x});
        if(it==bs.end()&&it2==as.end()){
            c='X';
            if(bs.find({(x-1+n)%n,(y+n)%n})==bs.end()){
                c='L';
            }
            else if(bs.find({(x+1+n)%n,(y+n)%n})==bs.end()){
                c='R';
            }
            else if(bs.find({(x+n)%n,(y+n-1)%n})==bs.end()){
                c='D';
            }
            else if(bs.find({(x+n)%n,(y+n+1)%n})==bs.end()){
                c='U';
            }
            if(c!='X'){
                v.push_back({y,x,c});
                as.insert({y,x});
            }
        }

        y=(n+by[i])%n;
        x=(bx[i]+n+1)%n;
        it = bs.find({y,x});
        it2 = as.find({y,x});
        if(it==bs.end()&&it2==as.end()){
            c='X';
            if(bs.find({(x-1+n)%n,(y+n)%n})==bs.end()){
                c='L';
            }
            else if(bs.find({(x+1+n)%n,(y+n)%n})==bs.end()){
                c='R';
            }
            else if(bs.find({(x+n)%n,(y+n-1)%n})==bs.end()){
                c='D';
            }
            else if(bs.find({(x+n)%n,(y+n+1)%n})==bs.end()){
                c='U';
            }
            if(c!='X'){
                v.push_back({y,x,c});
                as.insert({y,x});
            }
        }
    }
    printf("%ld\n",v.size());
    for(int i=0;i<v.size();i++){
        printf("%d %d %c\n",v[i].y,v[i].x,v[i].c);
    }
}