#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *next;
}*start=NULL,*temp=NULL;

void create();
void insert_beg();
void insert_end();
void insert_loc();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_loc();
void delete_before();
void delete_after();
void display();


void main()
{
int ch,p;
while(1)
{
printf("\nEnter the following");
printf("\n1.Create:");
printf("\n2.Insert at beg:");
printf("\n3.Insert at end:");
printf("\n4.Insert at any location:");
printf("\n5.Insert before an element");
printf("\n6.Insert after an element");
printf("\n7.Delete from beg:");
printf("\n8.Delete from end:");
printf("\n9.Delete from given location:");
printf("\n10.Delete before an element");
printf("\n11.Delete after an element");
printf("\n12.Display:");
printf("\n13.Exit:");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:do
       {
        create();
        printf("Press 1 to enter more and 0 to exit:");
        scanf("%d",&p);
        }while(p!=0);
       break;
case 2:insert_beg();
       break;
case 3:insert_end();
       break;
case 4:insert_loc();
       break;
case 5:insert_before();
       break;
case 6:insert_after();
       break;
case 7:delete_beg();
       break;
case 8:delete_end();
       break;
case 9:delete_loc();
       break;
case 10:delete_before();
        break;
case 11:delete_after();
        break;
case 12:display();
       break;
case 13:exit(0);
default:printf("\nInvalid choice");
}
}
}

void create()
{
  struct Node *ptr;  
  ptr=(struct Node*)malloc(sizeof(struct Node));
  printf("\nEnter Data:");
  scanf("%d",&ptr->data);
  ptr->next=start;
   if(start==NULL){
      start=ptr;
      ptr->next=start;
    }
   else
   {
    temp=start;
    while(temp->next!=start){
    temp=temp->next;
   }
    temp->next=ptr;
  }
}

void insert_beg(){
  struct Node *ptr;
  ptr=(struct Node*)malloc(sizeof(struct Node));
  printf("\nEnter data to be inserted:");
  scanf("%d",&ptr->data);
  ptr->next=start;
  if(start==NULL){
  start=ptr;
  start->next=start;
  }
  else{
  while(temp->next!=start){
  temp=temp->next;
  }
  temp->next=ptr;
  start=ptr;
}
}

  void insert_end(){
  struct Node *ptr;
  ptr=(struct Node*)malloc(sizeof(struct Node));
  printf("\nEnter data to be inserted:");
  scanf("%d",&ptr->data);
  ptr->next=start;
  if(start==NULL){
  start=ptr;
  start->next=start;
  } 
  else{
  temp=start;
  while(temp->next!=start){
  temp=temp->next;
  }
  temp->next=ptr;
  ptr->next=start;
  //temp=ptr;
 }
}

  void insert_loc(){
  struct Node *ptr;int loc;
  ptr=(struct Node*)malloc(sizeof(struct Node));
  printf("\nEnter location where data is to be inserted:");
  scanf("%d",&loc);
  printf("\nEnter data to be inserted:");
  scanf("%d",&ptr->data);
  ptr->next=start;
  temp=start;
  if(temp==NULL){
  printf("Location not found");
  }
  else{
  for(int i=0;i<loc-1;i++){
  temp=temp->next;
  }
  ptr->next=temp->next;
  temp->next=ptr;
  }
 }
 
  void insert_after(){
  struct Node *ptr;
  int x;
  ptr=(struct Node*)malloc(sizeof(struct Node));
  printf("\nEnter the data to be inserted:");
  scanf("%d",&x);
  printf("\nEnter the element after which the data isto be inserted:");
  scanf("%d",&ptr->data);
  temp=start;
  do{
  temp=temp->next;
  }while(temp->data!=x && temp!=start);
  if(temp==NULL){
  printf("\nData not found");
  }
  else{
  ptr->next=temp->next;
  temp->next=ptr;
 }
}
 
  void insert_before(){
  struct Node *ptr,*prev;
  int x;
  ptr=(struct Node*)malloc(sizeof(struct Node));
  printf("\nEnter the element to be inserted:");
  scanf("%d",&x);
  printf("\nEnter the element before which the data isto beinserted:");
  scanf("%d",&ptr->data);
  temp=start;
  do{
  prev=temp;
  temp=temp->next;
  }while(temp->data!=x && temp!=start);
  if(temp==NULL)
  {
  printf("\nLocation not found");
  }
  else{
  ptr->next=temp;
  prev->next=ptr;
  }
 }
  void delete_beg(){
  struct Node* prev;
  if(start==NULL)
  printf("\nList is empty");
  else{
  prev=start;
  temp=start;
  while(temp->next!=start){
  temp=temp->next;
  }
  temp->next=start->next;
  start=start->next;
  free(prev);
 }
}
  void delete_end(){
  struct Node *prev;
  if(start==NULL)
  printf("\nList is empty");
  else{
  temp=start;
  do{
  prev=temp;
  temp=temp->next;
  }while(temp->next!=start);
  prev->next=start;
  free(temp);
 }
}

  void delete_loc()
  {
   struct Node *t1,*t2;
   int loc;
   printf("\nEnter location where data is to be deleted:");
   scanf("%d",&loc);
   temp=start;
   for(int i=0;i<loc-1;i++){
   temp=temp->next;
   }
   t1=temp->next;
   t2=temp->next->next;
   temp->next=t2;
   free(t1);
  } 
  
  void delete_before()
  {
   struct Node *prev,*t1;
   int x;
   printf("\nEnter data before which element is to be deleted");
   scanf("%d",&x);
   temp=start;
   while(temp->data!=x && temp!=NULL){
   t1=prev;
   prev=temp;
   temp=temp->next;
   }
   t1->next=temp;
   free(prev);
 }
 
  void delete_after(){
  struct Node *prev,*t1,*t2;
  int x; 
  printf("\nEnter the element after which the data is to be deleted:");
  scanf("%d",&x);
  temp=start;
  while(temp->data!=x && temp!=NULL){
  temp=temp->next;
  }
  t1=temp->next;
  t2=temp->next->next;
  temp->next=t2;
  free(t1);
}
  
  void display(){
  struct Node *temp;
  printf("\nThe data is:");
  temp=start;
  do{
  printf("%d",temp->data);
  temp=temp->next;
  }while(temp!=start);
}

