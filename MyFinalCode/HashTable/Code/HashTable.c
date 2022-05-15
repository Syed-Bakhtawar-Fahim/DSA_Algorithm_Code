#include<stdio.h>
#include<stdlib.h>
#define size 5
struct Node{
    int data;
    struct Node *next;
};
struct Start{
    struct Node *st;
};
struct Start Hash_Table[size];

void insert(int value){
    struct Node *tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->data=value;
    tmp->next=NULL;
    int h=value%size;
    if(Hash_Table[h].st==NULL){
        Hash_Table[h].st=tmp;
        printf("%d",tmp->data);
    }
    else{
        struct Node *curr=Hash_Table[h].st;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=tmp;
    }
}
void display(){
    for(int i=0;i<size;i++){
        struct Node *tmp=Hash_Table[i].st;
      //  printf("index %d is\n",i);
        while(tmp){
        printf("index %d %d\n",i,tmp->data);
        tmp=tmp->next;
    }
    }
}
void main(){
    for(;;){
        int choise,value;
        printf("Enter Your Choise : ");
        scanf("%d",&choise);
        if(choise==1){
        printf("Enter Value : ");
        scanf("%d",&value);
            insert(value);
        }
        else if(choise==2){
            display();
        }

}
}