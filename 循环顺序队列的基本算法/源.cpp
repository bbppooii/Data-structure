#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ture 1
#define false 0
#define max 5
typedef struct {
	int data[max];
	int front,rear;
}cteam,*team;
static int num=0; 
int Initteam(team &L){
	L=(cteam *)malloc(sizeof(cteam));
	if(L==NULL){
		printf("����ռ�ʧ�ܣ�");
		return false;
	}
	L->front=L->rear=-1;
	return true;
}
int pushteam(team &L,char x){
	if(num==max){
		printf("����");
		return false;
	}else{
		L->rear=(L->rear+1)%max;
		L->data[L->rear]=x; 
		num++;
		return true;
	}
} 
int popteam(team &L,int &x){
	if(num==0){
		printf("�ӿգ�");
		return false;
	}else{
		L->front=(L->front+1)%max;
		x=L->data[L->front];
		num--;
		printf("%c����\n",x);
		return x;
	} 
}
void printteam(team L){
	int p;
	p=L->front+1;
	if(L->front<L->rear){
		while(p<=L->rear){
		printf("%c ",L->data[p]);
		p++;}
	}else{
		while((p-1)!=L->rear){
			printf("%c ",L->data[p]);
			p=(p+1)%max;
		}
	}
  }
 int teamlength(team L){
 	int p;
 	if(L->front<L->rear){
 		p=(L->rear)-(L->front);  
	 }else{
	 	p=L->rear+(max-(L->front)); 
	 }
	printf("\n�ӳ�Ϊ��%d",p);
	return 0;
 }
  int gettop(team L){
  	if(L->front==L->rear){
  		printf("�ӿգ�");
  		return false;
	  }else{
	  	int t=L->data[L->front+1];
	  	return t;
	  }
  }  
int main(){
	team s;
	int w;
	Initteam(s);
	pushteam(s,'a');
	pushteam(s,'b');
	pushteam(s,'c');
	printf("��ʱ����Ϊ��");
	printteam(s);
	printf("\n");
   	popteam(s,w);
	popteam(s,w);
	printf("��ʱ����Ϊ��");
	printteam(s);
	pushteam(s,'d');
	pushteam(s,'e');
	pushteam(s,'f');
	printf("��ʱ����Ϊ��");
	printteam(s);
	teamlength(s);
	int T=gettop(s);
	printf("\n��ͷԪ��Ϊ��%c",T);
}