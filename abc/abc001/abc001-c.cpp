#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int d,w;
    char s[5];
    scanf("%d %d",&d,&w);
    if(d<=112){
        strcpy(s,"N");
    }
    else if(d<=337){
        strcpy(s,"NNE");
    }
    else if(d<=562){
        strcpy(s,"NE");
    }
    else if(d<=787){
        strcpy(s,"ENE");
    }
    else if(d<=1012){
        strcpy(s,"E");
    }
    else if(d<=1237){
        strcpy(s,"ESE");
    }
    else if(d<=1462){
        strcpy(s,"SE");
    }
    else if(d<=1687){
        strcpy(s,"SSE");
    }
    else if(d<=1912){
        strcpy(s,"S");
    }
    else if(d<=2137){
        strcpy(s,"SSW");
    }
    else if(d<=2362){
        strcpy(s,"SW");
    }
    else if(d<=2587){
        strcpy(s,"WSW");
    }
    else if(d<=2812){
        strcpy(s,"W");
    }
    else if(d<=3037){
        strcpy(s,"WNW");
    }
    else if(d<=3262){
        strcpy(s,"NW");
    }
    else if(d<=3487){
        strcpy(s,"NNW");
    }
    else{
        strcpy(s,"N");
    }
    if(w<15){
        printf("C 0\n");
    }
    else if(w<93){
        printf("%s 1\n",s);
    }
    else if(w<201){
        printf("%s 2\n",s);
    }
    else if(w<327){
        printf("%s 3\n",s);
    }
    else if(w<477){
        printf("%s 4\n",s);
    }
    else if(w<645){
        printf("%s 5\n",s);
    }
    else if(w<831){
        printf("%s 6\n",s);
    }
    else if(w<1029){
        printf("%s 7\n",s);
    }
    else if(w<1245){
        printf("%s 8\n",s);
    }
    else if(w<1467){
        printf("%s 9\n",s);
    }
    else if(w<1707){
        printf("%s 10\n",s);
    }
    else if(w<1959){
        printf("%s 11\n",s);
    }
    else{
        printf("%s 12\n",s);
    }
}