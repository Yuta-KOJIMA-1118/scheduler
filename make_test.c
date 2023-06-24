#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int Q,N;
    srand((unsigned int)time(NULL));
    scanf("%d %d",&Q,&N);
    printf("%d %d\n",Q,N);

    int cnt=0, i=0, sum=0;
    while(cnt < N){
        int p=rand()%6;
        if(p==0 || sum <= i){
            int arrive = i;
            int length = rand()%10+1;
            sum += length;
            cnt++;
            printf("%d %d\n",arrive, length);
        }
        i++;
    }


    return 0;
}






