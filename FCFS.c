#include "scheduler.h"
void fcfs_enqueue(int j, process *pro, queue **head, int N) //queueの末尾に追加
{
    queue *new = gen_queue(pro[j]);
    pro[j].status = WAITING;
    if(*head==NULL){
        *head = new;
        return;
    }

    queue *p = *head;
    while(1){
        if(p->next==NULL) break;
        p=p->next;
    }
    p->next = new;
}

void fcfs(process* pro, int N) //到着順
{
    printf("\nstart FCFS\n");
    queue *head;
    process running;
    init(&running,1);
    running.status = NOT_EXIST;
    int sum=0;
    int cnt=0;
    int label=0;

    int i=0;
    while(1){
        printf("\nTime: %d\n",i);
        arrive(pro,N,i,FCFS,&head,&label);  //queueにWAITINGで追加
        if(running.status == NOT_EXIST){
            if(terminate(pro,running,i,N,&sum,&cnt)==0){   //N=0かつ1以外を入力でbreak;
                break;
            }
            if(checking_finish(pro,N)){ //N=0のときはbreakしない
                break;
            }
            running = start_run(&head,i);
        }
        if(running.status == RUNNING){
            run(&running,i); //終了したら，NOT_EXISTに変更
        }
        else{
            printf("No process to run\n");
        }
        if(running.status == NOT_ARRIVED || running.status == WAITING){
            printf("error: running.status = NOT_ARRIVED or WAITING\n");
            return;
        }
        //print_queue(head);
        i+=1;

    }
    free(head);

    if(N!=0){
        write_log(pro,N,FCFS);
        print_pro(pro,N,sum);
    }
    printf("\nfinish FCFS\n");
}
