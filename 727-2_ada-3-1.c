#include<stdio.h>
#include<stdlib.h>
struct List
{
	struct Node *head;
	struct Node *tail;
};

struct Node 
{
	int value;
	struct Node *next;
};

void init(struct List *l)
{
	l->head = NULL;
	l->tail = NULL;
}

int push_back(struct List*l, int value)
{
	struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
	new_node->value = value;
	new_node->next=NULL;
	if (l->head==NULL){
		l->head = new_node;
		l->tail = new_node;
		return 0;
	}
	else{
	l->tail->next=new_node;
	l->tail = new_node;
	return 0;
	}
}

int push_front(struct List *l, int value)
{
	struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
	new_node->value=value;
	if (l->head==NULL){
                l->head=new_node;
                l->tail=new_node;
                new_node->next=NULL;
		 return 0;
        }
        else{
	new_node->next=l->head;
	l->head=new_node;
        return 0;
        }
}
void clear(struct List *l)
{
	struct Node *temp;
	while (l->head!=NULL){
		temp=(l->head)->next;
		free(l->head);
		l->head=temp;	
	}
	free(temp);
}

int isEmpty(struct List* l)
{
	if ((l->head==NULL) && (l->tail==NULL)){
	return 0;
	}
	else {
	return 1;
	}
}

struct Node* find(struct List* l, int value)
{
	struct Node* temp = l->head;
	while (temp){
                if (temp->value==value){
		return  temp;
		}
		else{
		temp=temp->next;
		}
        }
	return NULL;
}

int insertAfter(struct Node*n, int value)
{ 
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->value=value;
	new_node->next=n->next;
	n->next=new_node;
	return 0;	
}

int reMove(struct List* l, int value)
{
	struct Node* adress;
	struct Node* temp=l->head;
	adress = find(l, value);
	if (adress==NULL){
		return 1;
	}
	else{
		if (adress==l->head){
			l->head=l->head->next;
		}
		else{
			while (temp->next!=adress){
				temp=(temp)->next;
			}
			if (adress==l->tail){
                        	l->tail=temp;
	                }
			else{
			temp->next=adress->next;
			}
		}
		free(adress);
		return 0;
	}	
}

void print(struct List* l)
{
    struct Node* tmp;
    tmp=l->head;
    while (tmp->next!=NULL)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("%d\n", l->tail->value);
}

int main(){
	int n, a;
	scanf("%d", &n);
	struct List lis;
	init(&lis);
	for (int i=0; i<n; i++){
		scanf("%d", &a);
		push_back(&lis, a);
	}
	print(&lis);
	int k1, k2, k3;
	struct Node* temp;
	scanf("%d %d %d", &k1, &k2, &k3);
	temp=find(&lis, k1);
	if (temp!=NULL){
		printf("1");}
	else{
        	printf("0");}
	if (find(&lis, k2)){
        	printf("1");}
        else{
       		printf("0");}
	if (find(&lis, k3)){
        	printf("1");}
        else{
       		printf("0");}
	printf("\n");
	scanf("%d", &a);
        push_back(&lis, a);
	print(&lis);
	scanf("%d", &a);
        push_front(&lis, a);
        print(&lis);
	scanf ("%d %d", &n, &a);
	temp=lis.head;
	for (int i=1; i<n; i++)
	{ temp=temp->next;}
	insertAfter(temp, a);
	print(&lis);
	scanf("%d", &a);
	reMove(&lis, a);
	 print(&lis);
	clear(&lis);
}
