#include<cstdio>
using namespace std;
int main(){
    char b;
    scanf("%c",&b);
    if(b=='A'){
        b='T';
    }
    else if(b=='T'){
        b='A';
    }
    else if(b=='C'){
        b='G';
    }
    else{
        b='C';
    }
    printf("%c\n",b);
}