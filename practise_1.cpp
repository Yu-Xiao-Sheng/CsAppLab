#include<stdio.h>

int fun1(int x,int y){
    return ~ x ^ y;
}

int main(){
    printf("%d", fun1(4,5));
    return 0;
}