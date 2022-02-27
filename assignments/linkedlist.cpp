#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node*next;
};
struct node*start=NULL;
int insert()
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	int n;
	printf("insert the data");
	scanf("%d",&n);
	temp->data=n;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		struct node*current=start;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=temp;
	}
}
int print()
{
	struct node*current=start;
	printf("%d\n",current->data);
	while (current->next!=NULL)
	{
		current=current->next;
		printf("%d\n",current->data);
	}
}
int search()
{
	int g;
	printf("enter the value to be searched");
	scanf("%d",&g);
	struct node*current=start;
	if(current->data==g)
	{
		printf("value found\n");
	}
	int flag;
	flag=0;
	while(current->next!=NULL)
	{
		current=current->next;
		if(current->data==g)
		{
			printf("value found\n");
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("value not found\n");
	}
}

int main()
{	int f;
	while(f!=5)
	{
		printf("1.to insert data \n2.to delete data \n3. to search data \n4.print data \n5.exit");
		scanf("%d",&f);
		if(f==1)
		{
			insert();
		}
		else if(f==3)
		{
			search();
		}
		else if(f==4)
		{
			print();
		}
		else
		{
			break;
		}
	}
}

