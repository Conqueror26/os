#include<stdio.h>
#include<stdlib.h>
struct node
{
          	int data;
          	struct node *next;
};
void create(struct node *head,int n)
{
          	
          	
          	struct node *ptr = head;
          	while(n)
          	{
          	
                         	struct node *temp=(struct node*)malloc(sizeof(struct node));
                         	temp->data = 999;
                         	temp->next = NULL;
                         	ptr->next = temp;
                         	//printf("\t%d",ptr->data);
                         	ptr = ptr->next;
                         	//printf("\t%d",ptr->data);
                         	//i++;
                         	n--;
                         	
          	}
          	printf("\n");
          	
}
void display(struct node *h)
{
          	printf("\n");
          	struct node *ptr = h->next;
          	while(ptr!=NULL)
          	{
                         	if(ptr->data == 999)
                                       	printf("\t--");
                         	else
                                       	printf("\t%d",ptr->data);
                         	ptr = ptr->next;
          	}
}
int found(struct node *h,int ele)
{
          	struct node *ptr = h->next;
          	while(ptr!=NULL)
          	{
                         	if(ptr->data == ele)
                                       	return 1;
                         	ptr = ptr->next;
          	}
          	return 0;
}
 
int far(int temp[],int n,int arr[],int m,int vis[])
{
          	int ma = -1;
          	int f = -1;
          	for(int i=0;i<n;i++)
          	{
                         	f=-1;
                         	for(int j=0;j<m;j++)
                         	{
                                       	if(temp[i] == arr[j] && vis[j] == 0){
                                                      	f=1;
                                                      	if(j>ma)
                                                                    	ma = j;
                                                      	break;
                                       	}
                         	}
                         	if(f==-1)
                                       	return temp[i];
          	}
          	return arr[ma];
}
 
int near(int temp[],int n,int arr[],int m,int pos)
{
          	int ma = 9999;
          	int f;
          	for(int i=0;i<n;i++)
          	{
                         	f = -1;
                         	for(int j=pos-1;j>=0;j--)
                         	{
                                       	if(temp[i] == arr[j])
                                       	{
                                                      	f=1;
                                                      	if(j<ma)
                                                                    	ma = j;
                                                      	break;
                                       	}
                         	}
                         	if(f==-1)
                                       	return temp[i];
          	}
          	return arr[ma];
}
void fifo(struct node *head,int arr[],int m,int n)
{
          	int page = 0;
          	struct node *pos = head->next;
          	int j = 0;
          	
          	for(int i=0;i<m;i++)
          	{
                         	if(!found(head,arr[i]))
                         	{
                                       	pos->data = arr[i];
                                       	j++;
                                       	if(j%n == 0)
                                                      	pos = head->next;
                                       	else
                                                      	pos = pos->next;
                                       	page++;
                                       	display(head);
                         	}
                         	else
                                       	printf("\n---------------------------------------");
                         	
          	}         	
          	printf("\nNumber of pagefaults = %d",page);
          	
}
int filled(struct node *h,int n)
{
          	struct node *ptr = h->next;
          	int co = 0;
          	while(ptr!=NULL)
          	{
                         	if(ptr->data != 999)
                                       	co++;
                         	ptr = ptr->next;
          	}
          	if(co == n-1)
                         	return 1;
          	return 0;
}
void optimum(struct node *h,int arr[],int m,int n)
{
          	int page = 0;
          	struct node *pos = h->next;
          	struct node *t = h->next;
          	int j = 0;
          	int vis[100];
          	
          	for(int i=0;i<m;i++)
                         	vis[i] = 0;
          	
          	for(int i=0;i<m;i++)
          	{
                         	vis[i] = 1;
                         	if(filled(pos,n))
                         	{
                                       	if(!found(h,arr[i]))
                                       	{
                                                      	page++;
                                                      	int temp[10];
                                                      	int k=0;
                                                      	struct node *r = h->next;
                                                      	while(r!=NULL)
                                                      	{
                                                                    	temp[k++] = r->data;
                                                                    	r = r->next;
                                                      	}
                                                      	r = h->next;
                                                      	int e = far(temp,n,arr,m,vis);
                                                      	//printf("\n%d",e);
                                                      	while(r!=NULL)
                                                      	{
                                                                    	if(r->data == e)
                                                                                  	r->data = arr[i];
                                                                    	r = r->next;
                                                      	}
                                                      	display(h);
                                       	}
                                       	else
                                                      	printf("\n-------------------------------------");
                         	}
                         	else
                         	{
                                       	//printf("\nhere");
                                       	page++;
                                       	if(t==NULL)
                                       	{
                                                      	printf("\nSTOP!!");
                                                      	break;
                                       	}
                                       	t->data = arr[i];
                                       	t = t->next;
                                       	display(h);
                         	}
                         	
          	}         	
          	printf("\nNumber of pagefaults = %d",page);
}
void lru(struct node *h,int arr[],int m,int n)
{
          	int page = 0;
          	struct node *pos = h->next;
          	struct node *t = h->next;
          	int j = 0;
          	int vis[100];
          	
          	for(int i=0;i<m;i++)
                         	vis[i] = 0;
 
          	for(int i=0;i<m;i++)
          	{
                         	vis[i] = 1;
                         	if(filled(pos,n))
                         	{
                                       	if(!found(h,arr[i]))
                                       	{
                                                      	page++;
                                                      	int temp[10];
                                                      	int k=0;
                                                      	struct node *r = h->next;
                                                      	while(r!=NULL)
                                                      	{
                                                                    	temp[k++] = r->data;
                                                                    	r = r->next;
                                                      	}
                                                      	r = h->next;
                                                      	int e = near(temp,n,arr,m,i);
                                                      	//printf("\n%d",e);
          	                                       	while(r!=NULL)
                                                      	{
                                                                    	if(r->data == e)
                                                                    	{
                                                                                  	r->data = arr[i];
                                                                                  	break;
                                                                    	}
                                                                    	r = r->next;
                                                      	}
                                                      	display(h);
                                       	}
                                       	
                                       	else
                                                      	printf("\n--------------------------------------------");
                         	}
                         	else
                         	{
                                       	page++;
                                       	//printf("\nhere");
                                       	if(t==NULL)
                                       	{
                                                      	printf("\nSTOP!!");
                                                      	break;
                                       	}
                                       	t->data = arr[i];
                                       	t = t->next;
                                       	display(h);
                         	}
                         	
          	}
          	printf("\nNumber of pagefaults = %d",page);          	
}
void lfu(struct node *h,int arr[],int m,int n)
{
          	int page = 0;
          	struct node *pos = h->next;
          	struct node *t = h->next;
          	int counter[10];
          	int marked[100];
          	
          	for(int i=0;i<10;i++)
                         	counter[i] = 0;
 
          	for(int i=0;i<m;i++)
                         	marked[i] = 0;
 
          	//for(int i=0;i<m;i++)
          	//       	vis[i] = 0;
 
          	for(int i=0;i<m;i++)
          	{
                         	//vis[i] = 1;
                         	if(filled(pos,n))
                         	{
                                       	counter[arr[i]]++;
                                       	//printf("\nDelay starts here!!");
                                       	if(!found(h,arr[i]))
                                       	{
                                                      	page++;
                                                      	int temp[10];
                                                      	int k=0;
                                                      	struct node *r = h->next;
                                                      	while(r!=NULL)
                                                      	{
                                                                    	temp[k++] = r->data;
                                                                    	r = r->next;
                                                      	}
                                                      	r = h->next;
                                                      	int ma = 1000;
                                                      	int position = -1;
                                                      	//printf("\n k : %d",k);
                                                      	//printf("\nNew iteration");
                                                      	for(int j=0;j<k;j++)
                                                      	{
                                                                    	//printf("\nPOSITION : %d",position);
                                                                    	if(ma>counter[temp[j]])
                                                                    	{
                                                                                  	ma = counter[temp[j]];
                                                                                  	position = temp[j];
                                                                    	}
                                                                    	else if(ma == counter[temp[j]])
                                                                    	{
                                                                                  	for(int v=0;v<i;v++)
                                                                                                 	if((arr[v] == temp[j] && marked[v] == 0) || (arr[v] == position && marked[v] == 0))
                                                                                                 	{
                                                                                                               	ma = counter[arr[v]];
                         	                                                                                  	position = arr[v];
                                                                                                               	break;
                                                                                                 	}
                                                                    	}
                                                      	}
 
                                                      	counter[position]--;
                                                      	
                                                      	for(int y=0;y<i;y++)
                                                                    	if(arr[y] == position)
                                                                    	{
                                                                                  	marked[y] = 1;
                                                                                  	break;
                                                                    	}
 
                                                      	//printf("\n%d",e);
                                                      	while(r!=NULL)
                                                      	{
                                                                    	if(r->data == position)
                                                                    	{         	
                                                                                  	r->data = arr[i];
                                                                                  	//counter[arr[i]]++;
                                                                                  	break;
                                                                    	}
                                                                    	r = r->next;
                                                      	}
                                                      	display(h);
                                       	}
                                       	else
                                                      	printf("\n--------------------------------------------");
                         	}
                         	else
                         	{
                                       	page++;
                                       	//printf("\nhere");
                                       	if(t==NULL)
                                       	{
                                                      	printf("\nSTOP!!");
                                                      	break;
                                       	}
                                       	t->data = arr[i];
                                       	counter[arr[i]]++;
                                       	t = t->next;
                                       	display(h);
                         	}
                         	
          	}         	
          	printf("\nNumber of pagefaults = %d",page);          	
}
int main()
{
          	struct node *head = (struct node*)malloc(sizeof(struct node));
          	head->next = NULL;
          	create(head,4);
          	int arr[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
          	//lfu(head,arr,20,4);
          	char ask = ' ';
          	int size;
 
          	int ch;
          	do
          	{
                         	printf("\n0 ----> CREATE");
                         	printf("\n1 ----> FIFO");
                         	printf("\n2 ----> OPTIMUM");
                         	printf("\n3 ----> LRU");
                         	printf("\n4 ----> LFU");
 
                         	printf("\nEnter choice : ");
                         	scanf("%d",&ch);
                         	switch(ch)
                         	{
                                       	case 0 :
                                                      	
                                                      	printf("\nEnter total frames : ");
                                                      	scanf("%d",&size);
                                                      	create(head,size);
                                                      	printf("\nDo you want to continue?(y/n) : ");
                                                      	scanf(" %c",&ask);
                                                      	break;
                                       	case 1:
                                                      	create(head,size);
                                                      	fifo(head,arr,20,size);
                                                      	printf("\nDo you want to continue?(y/n) : ");
                                                      	scanf(" %c",&ask);
                                                      	break;
                                       	case 2:
                                                      	create(head,size);
                                                      	optimum(head,arr,20,size);
                                                      	printf("\nDo you want to continue?(y/n) : ");
                                                      	scanf(" %c",&ask);
                                                      	break;
                                       	case 3:
                                                      	create(head,size);
                                                      	lru(head,arr,20,size);
                                                      	printf("\nDo you want to continue?(y/n) : ");
                                                      	scanf(" %c",&ask);
                                                      	break;
                                       	case 4:
                                                      	create(head,size);
                                                      	lfu(head,arr,20,size);
                                                      	printf("\nDo you want to continue?(y/n) : ");
                                                      	scanf(" %c",&ask);
                                                      	break;
                                       	default:
                                                      	printf("\nInvalid case!!");
 
                         	}
          	}while(ask == 'y');
}
