#include<stdio.h>
#include<stdlib.h>

struct secondm
{
           int info;
           struct secondm *next,*prev;
};

void ratio(struct secondm* h,int* a,int* hits,int* fault);
void manual(struct secondm**);
void disp(struct secondm*);

int main()
{
           int ch,hit=0,fault=0;
           int mainm[3]={10,10,10};
           struct secondm* head=NULL;
           printf("Do you want the numbers to be generated manually or randomly ?\n1.Manual\n0.Random\n");
           scanf("%d",&ch);
           if(ch)
           manual(&head);
	       disp(head);
           ratio(head,mainm,&hit,&fault);
           printf("The HITS to FAULT ratio is\n\t\t%d:%d\n",hit,fault);
           return 0;
}

void manual(struct secondm** h)
{
     int ch,choice;
     struct secondm *t,*p;
     do
     {
               t=(struct secondm*)malloc(sizeof(struct secondm));
	       printf("Enter a number between 0-9\n");
               scanf("%d",&ch);
               if((ch<-1)||(ch>9))
                printf("Invalid choice\n");
               else{
               t->info=ch;
               t->next=NULL;
               if(*h==NULL)
               {
                *h=t;
                t->prev=NULL;
               }
               else
               {
                p=*h;
                while(p->next!=NULL)
                p=p->next;
                p->next=t;
                t->prev=p;
               }}
              printf("Do you want to continue?\n1.Yes\n2.No\n");
              scanf("%d",&choice);
     }while(choice==1);
}

void ratio(struct secondm* h,int* m,int* hits,int* fault)
{
     int a,b,c,z,j,i,flag=1;
     struct secondm* t;
     while(h!=NULL)
     {
       t=h;
       if((m[0]==h->info)||(m[1]==h->info)||(m[2]==h->info))
        {
          (*hits)++;
          flag=0;
        }
       else
       {
          (*fault)++;
          for(j=1,a=b=c=z=0;(j<4)&&(t->next!=NULL);j++)
          {
            t=t->next;
            if(m[0]==t->info)
                a=1;
	    if(m[1]==t->info)
                b=1;
	    if(m[2]==t->info)
                c=1;
	    if(h->info==t->info)
                z=1;
          }
	 if(z==1)
	 {
		if(a==0)
		{
		 i=0;
		 flag=1;
		}
		if(b==0)
		{
		 i=1;
		 flag=1;
		}
		if(c==0)
		{
		 i=2;
		 flag=1;
		}
	}
       if(flag==1)
       m[i]=h->info;

     }
     h=h->next;
     }
}


void disp(struct secondm* h)
{
	if(h==NULL)
	printf("EMPTY!\n");
	else
	{
	 while(h!=NULL)
	 {
		printf("%d\t",h->info);
	 	h=h->next;
	 }
	  printf("\n");
	}
}
