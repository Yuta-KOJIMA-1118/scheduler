//作成者  : 小島佑太
//作成年月: 2023/7/30
#include "scheduler.h"

int main()
{
    int Q, N; //Q:アルゴリズムの選択, N:プロセス数
    srand((unsigned int)time(NULL));
    scanf("%d %d",&Q,&N);
    if(N<0){
        printf("error: N >= 0\n");
        return 0;
    }
    if(N!=0){
        process *pro = (process*)malloc(sizeof(process)*N);
        init(pro,N);
        for(int i=0;i<N;i++){
            scanf("%d %d",&pro[i].arrive,&pro[i].length);
            if(pro[i].arrive < 0 || pro[i].length <= 0){
                printf("error arrive >= 0, length > 0\n");
                return 0;
            }
            pro[i].label = i;
            pro[i].remain = pro[i].length;
        }

        switch(Q){
            case FCFS: fcfs(pro,N);       break;
            case SPT: spt(pro,N);         break;
            case R_R: Round_Robin(pro,N); break;
            default: printf("error Q=0,1,2\n"); return 0;
        }
    }
    else{
        switch(Q){
            case FCFS: fcfs(NULL,N);        break;
            case SPT: spt(NULL, N);         break;
            case R_R: Round_Robin(NULL, N); break;
            default: printf("error Q=0,1,2\n"); return 0;
        }
    }
    return 0;
}

