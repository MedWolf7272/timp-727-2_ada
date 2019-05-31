#include<stdio.h>
#include<stdlib.h>
//list
struct List
{
        struct Node *head;
        struct Node *tail;
};

struct Node
{
        struct node* adress;
        struct Node *next;
};

//tree
struct tree{
        int amount;
        struct node* root;
};

struct node{
        int value;
        struct node* left;
        struct node* right;
        struct node* parent;
};

//list function
void init_list(struct List *l)
{
        l->head = NULL;
        l->tail = NULL;
}

int push_back(struct List*l, struct node* adress)
{
        struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
        new_node->adress = adress;
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

char valpop(struct List* l, struct node* left, struct node* right)
{
        struct Node* tmp=l->head;
        l->head=tmp->next;
        if (l->head==NULL) {l->tail=NULL;}
        int val;
        val=tmp->adress->value;
        left=tmp->adress->left;
        right=tmp->adress->right;
        free(tmp);
        if (val){return (char)val;}
        else{return '_';}
}

//tree function
void init(struct tree* t){
	t->amount=0;
	t->root=NULL;
}

int find(struct tree* t, int value, struct node** n){
	struct node* tmp=t->root;
	int flag=0;
	if (t->root==NULL){return 1;}
	while (flag==0){
		if (value!=tmp->value){
			if (value>tmp->value){
				if (tmp->right==NULL) {flag=1;}
				else {tmp=tmp->right;}
			}			
			else{
	                        if (tmp->left==NULL) {flag=1;}
                                else {tmp=tmp->left;}
			}
		}
		else {flag=2;}
	}
	if (flag==1){return 1;}
	else{
		*n=tmp;
		return 0;
	}
}

int insert(struct tree* t, int value){
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	if (new_node==NULL){return 2;}
	else{
		struct node* tmp=NULL;
		find(t, value, &tmp);
		if (tmp!=NULL){return 1;}
		else{
			new_node->value=value;
			new_node->left=NULL;
			new_node->right=NULL;
			if (t->root==NULL) {
				t->root=new_node;
				new_node->parent=NULL;
				t->amount++;
printf("insert root\n");				
				return 0;
			}
			else{ 
				tmp=t->root;
				int flag=0;
				while (flag==0){
	                        	if (value>tmp->value){
	                                	if (tmp->right==NULL) {
							flag=1;
							tmp->right=new_node;
							new_node->parent=tmp;
							t->amount++;
printf("insert right\n"); 
							return 0;
						}
	                                	else {tmp=tmp->right;
printf("go right\n");}
                        		}
                        		else{
                                		if (tmp->left==NULL){
							flag=1;
                                               		tmp->left=new_node;
                                                	new_node->parent=tmp;
							t->amount++;
printf("insert left\n");
							return 0;
                                        	}	
                                		else {tmp=tmp->left;
printf("go left\n");}
                     			}
	        		}
			}		
		}
	}
}

int reMove(struct tree* t, int value){
	struct node* tmp=NULL;
	find(t, value, &tmp);
        if (tmp==NULL){return 1;}
	else{
		struct node* tmp2=tmp->parent;
		if (tmp2->left==tmp){
			if ((tmp->left==NULL)&&(tmp->right==NULL)){
			tmp2->left=NULL;
			free(tmp);
			}
			else{
				if ((tmp->left==NULL)&&(tmp->right!=NULL)){
	                	tmp2->left=tmp->right;
	                	free(tmp);
				t->amount--;
				return 0;
	                	}
				if ((tmp->left!=NULL)&&(tmp->right==NULL)){
                                tmp2->left=tmp->left;
                                free(tmp);
				t->amount--;
                                return 0;
                                }
			}
		}
	}
}

int removeMin(struct node* n){
	struct node* tmp;
	int val;
	tmp=n->left;
	while (tmp->left) {tmp=tmp->left;}
	tmp->parent->left=tmp->right;
	if (tmp->right) {tmp->right->parent=tmp->parent;}
	val=tmp->value;
	free(tmp);
	return val;
}

int rotateLeft(struct node* n){
	if (n->right==NULL){ return 1;}
	else{
		if (n->parent==NULL){
			struct node* tmp1;
			struct node* tmp2;
			tmp1=n;
			tmp2=n->right;
			tmp1->right=tmp2->left;
			if (tmp1->right) {tmp1->right->parent=tmp1;}
			tmp2->left=n;
			n->parent=tmp2;
			tmp2->parent=NULL;
			return 0;
		}
		else{
			struct node* tmp1;
			struct node* tmp2;
			tmp1=n;
			tmp2=n->right;
			tmp1->right=tmp2->left;
			if (tmp1->right) {tmp1->right->parent=tmp1;}
			tmp2->left=n;
			tmp2->parent=n->parent;
			n->parent=tmp2;
			if (tmp1==tmp2->parent->left) {tmp2->parent->left=tmp2;}
			else{ tmp2->parent->right=tmp2;}
			return 0;
		}
	}
}

void checkroot(struct tree* t){
	while (t->root->parent){
		t->root=t->root->parent;
	}
	return;
}

int rotateRight(struct node* n){
	if (n->left==NULL){ return 1;}
	else{
		if (n->parent==NULL){
			struct node* tmp1;
			struct node* tmp2;
			tmp1=n;
			tmp2=n->left;
			tmp1->left=tmp2->right;
			if (tmp1->left) {tmp1->left->parent=tmp1;}
			tmp2->right=n;
			n->parent=tmp2;
			tmp2->parent=NULL;
			return 0;
		}
		else{
			struct node* tmp1;
			struct node* tmp2;
			tmp1=n;
			tmp2=n->left;
			tmp1->left=tmp2->right;
			if (tmp1->left) {tmp1->left->parent=tmp1;}
			tmp2->right=n;
			tmp2->parent=n->parent;
			n->parent=tmp2;
			if (tmp1==tmp2->parent->left) {tmp2->parent->left=tmp2;}
			else{ tmp2->parent->right=tmp2;}
			return 0;
		}
	}
}

void clear(struct tree* t){
        struct List l_first;
        struct List l_second;
	struct node* tmp;
        init_list(&l_first);
        init_list(&l_second);
        struct node* left;
        struct node* right;
        int flag_two=0;
        int flag_change=0;
        int flag_next=0;
        int fir_amount=0;
        int sec_amount=0;
        push_back(&l_first, t->root);
        fir_amount++;
        while(flag_next==0){
                if (flag_two==0){
                        for (int i=0; i<fir_amount-1; i++){
				tmp=l_first.head->adress;
				valpop(&l_first, left, right);
                                push_back(&l_second, left);
                                sec_amount++;
                                push_back(&l_second, right);
                                sec_amount++;
                                if (flag_change==0){
                                        if (left||right){
                                                flag_next=0;
                                                flag_change=1;
                                        }
                                        else {flag_next=1;}
                                }
				free(tmp);
				t->amount--;
                         }
			tmp=l_first.head->adress;
                        valpop(&l_first, left, right);
                        push_back(&l_second, left);
                        sec_amount++;
                        push_back(&l_second, right);
                        sec_amount++;
                        if (flag_change==0){
                                if (left||right){
                                        flag_next=0;
                                        flag_change=1;
                                }
                                else {flag_next=1;}
                        }
			free(tmp);
			t->amount--;
                        flag_two=1;
                        fir_amount=0;
                        flag_change=0;
		}
                else{
                        for (int i=0; i<sec_amount-1; i++){
				tmp=l_second.head->adress;
                                valpop(&l_second, left, right);
                                push_back(&l_first, left);
                                fir_amount++;
                                push_back(&l_first, right);
                                fir_amount++;
                                if (flag_change==0){
                                        if (left||right){
                                                flag_next=0;
                                                flag_change=1;
                                        }
                                        else {flag_next=1;}
                                }
				free(tmp);
				t->amount--;
                         }
			tmp=l_second.head->adress;
                        valpop(&l_second, left, right);
                        push_back(&l_first, left);
                        fir_amount++;
                        push_back(&l_first, right);
                        fir_amount++;
                        if (flag_change==0){
                                if (left||right){
                                        flag_next=0;
                                        flag_change=1;
                                }
                                else {flag_next=1;}
                        }
			free(tmp);
			t->amount--;
                        flag_two=0;
                        sec_amount=0;
                        flag_change=0;
                }
        }
}

void print(struct node* n){
	struct List l_first;
	struct List l_second;
	init_list(&l_first);
	init_list(&l_second);
	struct node* left;
	struct node* right;
	int flag_two=0;
	int flag_change=0;
	int flag_next=0;
	int fir_amount=0;
	int sec_amount=0;	
	int i=0;
	char val_out;
printf("start printnig\n");
	push_back(&l_first, n);
	fir_amount++;
printf("strart while\n");
	while(flag_next==0){
		if (flag_two==0){
			flag_next=1;
			for (i=0; i<fir_amount-1; i++){
printf("flag two 0. i =%d\n", i);
                                val_out=valpop(&l_first, left, right);
                                push_back(&l_second, left);
                                sec_amount++;
                                push_back(&l_second, right);
                                sec_amount++;
                                
				//	if ((left!=NULL) ||(right!=NULL)){
                                  //              flag_next=0;
                                    //            flag_change=1;
                                      //  }
                                 printf("%c ", val_out);

if (i>7){flag_next=1;break;}
                         }
printf("flag two 0. out of i\n");
                        val_out=valpop(&l_first, left, right);
                        push_back(&l_second, left);
                        sec_amount++;
                        push_back(&l_second, right);
                        sec_amount++;
                        //if (flag_change==0){
                               // if ((left!=NULL) || (right!=NULL)){
                                  //     flag_next=0;
                                 //       flag_change=1;
                               // }
                       //         else {flag_next=1;}
                       // }
                        printf("%c\n", val_out);
                        flag_two=1;
                        fir_amount=0;
                       // flag_change=0;	
		}
		else{
			flag_next=1;
			for (i=0; i<sec_amount-1; i++){
printf("flag two 1. i=%d\n", i);		
			        val_out=valpop(&l_second, left, right);
				push_back(&l_first, left);
				fir_amount++;
	                        push_back(&l_first, right);
				fir_amount++;
			//	if (flag_change==0){
	                       	//	if ((left!=NULL) || (right!=NULL)){
				//		flag_next=0;
						//flag_change=1;
				//	}
	                  //     		else {flag_next=1;}
				//}
	                        printf("%c ", val_out);
if (i>10) {flag_next=1; break;}
	                 }
printf("flag two 1. out of i\n");
	                val_out=valpop(&l_second, left, right);
	 		push_back(&l_first, left);
			fir_amount++;
                        push_back(&l_first, right);
			fir_amount++;
		//	if (flag_change==0){
                        //	if ((left!=NULL) || (right!=NULL)){
                          //      	flag_next=0;
                            //            flag_change=1;
		//		}
                  //              else {flag_next=1;}
                        
                        printf("%c\n", val_out);
                        flag_two=0;
			sec_amount=0;
		//	flag_change=0;
		}
	}
}
void printTree(struct tree* t){
	print(t->root);
}

int main(){
	struct tree a;
    struct node* b;
    int n, k, m, l;
    init(&a);
    scanf("%d %d %d %d", &n, &k, &m, &l);
	 insert(&a, n);
	printf("first got\n");
	 insert(&a, k); 
printf("second got\n");
    insert(&a, m); 
printf("third got\n");
    insert(&a, l); 
printf("foufth got\n");
	printTree(&a);
}
