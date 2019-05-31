#include<stdio.h>
#include<stdlib.h>
struct List{
	struct Node* head;
	struct Node* tail;
};

struct Node{
	int value;
	struct Node* next;
	struct Node* prev;
};

void init(struct List *l)
{
        l->head = NULL;
        l->tail = NULL;
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


int push_back(struct List*l, int value)
{
        struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
        new_node->value = value;
        new_node->next=NULL;
        if (l->head==NULL){
		new_node->prev=NULL;
                l->head = new_node;
                l->tail = new_node;
                return 0;
        }
        else{
	        l->tail->next=new_node;
		new_node->prev=l->tail;
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
		new_node->prev=NULL;
                return 0;
        }
        else{
		new_node->prev=NULL;
	       	new_node->next=l->head;
	        l->head->prev=new_node;
		l->head=new_node;
	        return 0;
        }
}

int insertAfter(struct Node*n, int value)
{
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->value=value;
	new_node->prev=n;
        new_node->next=n->next;
	n->next->prev=new_node;
        n->next=new_node;
        return 0;
}


int insertBefore(struct Node*n, int value)
{
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->value=value;
        new_node->next=n;
	new_node->prev=n->prev;
	n->prev->next=new_node;
        n->prev=new_node;
        return 0;
}

int removeFirst(struct List* l, int value)
{
        struct Node* adress;
        adress = find(l, value);
        if (adress==NULL){
                return 1;
        }
        else{
                if (adress==l->head){
                        l->head=l->head->next;
			adress->next->prev=NULL;
                }
                else{
                        if (adress==l->tail){
                                l->tail=adress->prev;
				adress->prev->next=NULL;
                        }
                        else{
	                        adress->prev->next=adress->next;
				adress->next->prev=adress->prev;
                        }
                }
                free(adress);
                return 0;
        }
}

int removeLast(struct List* l, int value)
{
        struct Node* adress;
        adress = l->tail;
	int flag=0;
	while (flag==0){
		if (adress){
			if (adress->value==value) {flag=1;}
			else {adress=adress->prev;}
		}
		else {flag=1;}
	}
        if (adress==NULL){
                return 1;
        }
        else{
                if (adress==l->head){
                        l->head=l->head->next;
			adress->next->prev=NULL;
                }
                else{
                        if (adress==l->tail){
                                l->tail=adress->prev;
				adress->prev->next=NULL;
                        }
                        else{
                        adress->prev->next=adress->next;
			adress->next->prev=adress->prev;
                        }
                }
                free(adress);
                return 0;
        }
}

void print(struct List*l)
{
	struct Node* temp=l->head;
	while (temp->next){
		printf("%d ", temp->value);
		temp=temp->next;
	}
	printf("%d\n", l->tail->value);
}

void print_invers(struct List*l)
{
	struct Node* temp=l->tail;
	while (temp->prev){
		printf("%d ", temp->value);
		temp=temp->prev;
	}
	printf("%d\n", l->head->value);
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
        if (find(&lis, k1)){
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
	print_invers(&lis);
	scanf("%d", &a);
	push_front(&lis, a);
        print(&lis);
	scanf("%d %d",&n, &a);
	temp=lis.head;
        for (int i=1; i<n; i++)
        { temp=temp->next;}
        insertAfter(temp, a);
        print_invers(&lis);
	 temp=lis.head;
	scanf("%d %d",&n, &a);
        for (int i=1; i<n; i++)
        { temp=temp->next;}
        insertBefore(temp, a);
        print(&lis);
        scanf("%d", &a);
        removeFirst(&lis, a);
        print_invers(&lis);
        scanf("%d", &a);
        removeLast(&lis, a);
        print(&lis);
	clear(&lis);
}
