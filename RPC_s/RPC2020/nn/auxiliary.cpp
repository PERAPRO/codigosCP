#include<stdio.h>
int main(void){
    int input;
    int r;
    scanf("%d", &input);
    r = input/3;
    if (input % 3 == 0){
        r = r * 7;
    }
    else if (input % 3 ==1)
    {
        r = ((r-1)*7) + 4;
    }
    else
    {
        r = (r*7) + 1;
    }
    printf("%d\n", r);
    return 0;
}