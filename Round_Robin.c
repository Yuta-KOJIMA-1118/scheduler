//作成者  : 小島佑太
//作成年月: 2023/7/30
#include "scheduler.h"

void R_R_enqueue(int j, process *pro, queue **head, int N)
{
    fcfs_enqueue(j,pro,head,N);
}

void R_R_replace(process running, queue **head)
{
    if(*head==NULL){
        return;
    }
    queue *p = *head;
    queue *new = gen_queue(running);
    printf("---stop and replace process%d, remain=%d\n",running.label,running.remain);
    while(1){
        if(p->next == NULL){
            p->next = new;
            break;
        }
        p=p->next;
    }
}

void Round_Robin(process* pro, int N)
{
    printf("\nstart Round_Robin\n");
    queue *head;
    process running;
    init(&running,1);
    running.status = NOT_EXIST;
    int sum=0;
    int cnt=0;
    int label=0;
    int slice=0;

    int i=0;
    while(1){
        printf("\nTime: %d\n",i);
        arrive(pro,N,i,R_R,&head,&label);  //queueにWAITINGで追加
        if(slice == 2 && running.remain != 0 && head != NULL){
            slice = 0;
            R_R_replace(running,&head);
            running = start_run(&head,i);
        }
        if(running.status == NOT_EXIST){
            if(terminate(pro,running,i,N,&sum,&cnt)==0){   //N=0のときだけbreakする可能性あり
                break;
            }
            if(checking_finish(pro,N)){ //N=0のときはbreakしない
                break;
            }
            slice = 0;
            running = start_run(&head,i);
        }
        if(running.status == RUNNING){
            slice += 1;
            run(&running,i); //終了したら，NOT_EXISTに変更
        }
        if(running.status == NOT_ARRIVED || running.status == WAITING){
            printf("error: running.status = NOT_ARRIVED or WAITING\n");
            return;
        }
        i+=1;
    }

    if(N!=0){
        write_log(pro,N,R_R);
        print_pro(pro,N,sum);
    }
    printf("\nfinish Round_Robin\n");
}

