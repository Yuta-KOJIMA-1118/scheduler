//作成者  : 小島佑太
//作成年月: 2023/7/30
#include "scheduler.h"

void spt_enqueue(int j, process *pro, queue **head, int N){
    queue *new = gen_queue(pro[j]);
    pro[j].status = WAITING;
    if(*head==NULL){
        *head = new;
        return;
    }
    if((*head)->next==NULL){
        if((*head)->pro.length <= pro->length){
            (*head)->next = new;
            return;
        }
        else{
            new->next = *head;
            *head = new;
            return;
        }
    }

    queue *p = *head;
    while(1){
        if(p->next==NULL || p->next->pro.length > pro->length) break;
        p=p->next;
    }
    new->next = p->next;
    p->next = new;
}

void spt(process* pro, int N) //処理時間順
{
    printf("\nstart SPT\n");
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
        arrive(pro,N,i,SPT,&head,&label);  //queueにWAITINGで追加
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

    if(N!=0){
        write_log(pro,N,SPT);
        print_pro(pro,N,sum);
    }
    printf("\nfinish SPT\n");
}
