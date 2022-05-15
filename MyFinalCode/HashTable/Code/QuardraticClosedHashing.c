#include<stdio.h>
#include<conio.h>
#define size 5

int arr[size]={NULL};

void quadinsert(){
    int value,fun,index,i;
    printf("Enter Value");
    scanf("%d",&value);
    fun=value%size;
    for(i=0;i<size;i++){
        index=(fun+(i*i))%size;
        if(arr[index]==NULL){
            arr[index]=value;
            break;
        }

    }
    if(size==i){
        printf("Array is full");
    }

}
void display()
{

  int i;

  printf("\nelements in the hash table are \n");

  for(i=0;i< size; i++)

  printf("\nat index %d \t value =  %d",i,arr[i]);

}

void quadsearch(){
    int value,fun,index,i;
    printf("Enter Value to search : ");
    scanf("%d",&value);
    fun=value%size;
    for(i=0;i<size;i++){
        index=(fun+(i*i))%size;
        if(arr[index]==value){
            printf("%d",index);
            break;
        }

    }
    if(size==i){
        printf("Value is not found");
    }
}
void main(){
        int arr[size];
    for(;;){
        int choise;
        printf("Enter Your Choise : ");
        scanf("%d",&choise);
        if(choise==1){
            quadinsert();
        }
        else if(choise==2){
            display();
        }
        else if(choise==3){
            quadsearch();
        }
}
}
