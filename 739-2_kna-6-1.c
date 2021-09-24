#include <stdio.h>
#include <stdlib.h>


//Возведение числа а в степень б 
int r_u_serious(int a, int b){
    int i = 0;
    int result = a;
    for(i; i<(b-1); i++)
    {
        result = result * a;
    }
    return result;
}


// Структура для хранения узла дерева.
// Необходимо хранить ссылки на потомков, предка и некоторое значение
typedef struct node {
    struct node *right;
    struct node *left;
    struct node *parent;
    int value;
} node;


// Структура для хранения дерева.
// Хранит ссылку на корень дерева и количество элементов в дереве
typedef struct tree {
    struct node* head;
    int sum;
} tree;


// Инициализация дерева
void init(tree* t){
    t->head = NULL;
}

node* new_node(node* n,int value) {
    node* tmp = (node*) malloc(sizeof(node));
    tmp->left = tmp->right = NULL;
    tmp->value = value;
    tmp->parent = n;
    return tmp;
}
////////////////////////////////////////////////////////////////////////////////

//структура узла
typedef struct list_node {
	double list_value; 
	struct list_node* list_next;
} list_node;

typedef struct list {
	struct list_node* list_head;
} list;

// инициализация пустого списка
void list_init(list* l) {
	l->list_head = NULL;
}


// Вставка узла в конец
void push_back(list* l, double value) {
	list_node* i = l->list_head;
    if(l->list_head == NULL){
        i = malloc(sizeof(list_node));
    	i->list_value = value;
    	i->list_next = NULL;
    	l->list_head = i;
    	return;
    }
	while (i->list_next != NULL) {
		i = i->list_next;
	}
	i->list_next = malloc(sizeof(list_node));
	i->list_next->list_value = value;
	i->list_next->list_next = NULL;
}

// удалить все элементы из списка
void list_clean(list *l){
    list_node* tmp = l->list_head;
	while (tmp->list_next != NULL) {
		list_node* i = tmp;
		tmp = tmp->list_next;
		free(i);
	}
	free(tmp);
	l->list_head = NULL;
}
/////////////////////////////////////////////////////////////////////////////////
node* my_own_super_puper_find(node* tmp, int value){
    if(tmp == NULL)
    {
        return NULL;
    }
    while(tmp){
        if(tmp->value == value)
        {
            return tmp;
        }
        else{
            if(value < tmp->value){
                tmp = tmp->left;
            }
            else{
                tmp = tmp->right;
            }
        }
    }
}

void fu(node* r, tree* t){
    if (r) {
        fu(r->left,t);
        fu(r->right,t);
        free(r);
    }
}
// Удалить все элементы из дерева
void clean(tree* t){
    fu(t->head, t);
    t->head = NULL;
}


// Поиск элемента по значению. Вернуть NULL если элемент не найден
node* find(tree* t, int value){
    if(t->head == NULL)
    {
        return NULL;
    }
    node* tmp = t->head;
    while(tmp){
        if(tmp->value == value)
        {
            return tmp;
        }
        else{
            if(value < tmp->value){
                tmp = tmp->left;
            }
            else{
                tmp = tmp->right;
            }
        }
    }
}

// Вставка значения в дерево:
// 0 - вставка выполнена успешно
// 1 - элемент существует
// 2 - не удалось выделить память для нового элемента
int insert(tree* t, int value){
    
    node* k = t->head;
    
    if(find(t, value)!= NULL){
        return 1;
    }
    if(t->head == NULL)
    {
        node* tmp = malloc(sizeof(node));
        if(tmp == NULL){
            return 2;
        }
    	tmp->left = tmp->right = NULL;
    	tmp->value = value;
    	tmp->parent= t->head;//!!!!!!!!!!!!!!!
    	t->head = tmp;
    	return 0;
    }
    else {
        while(k)
        {
            if(value < k->value)
            {
                if(k->left!= NULL){
                k = k->left;}
                else{
                    
                    k->left = new_node(k, value);
                    return 0;
                }
            }
            else
            {
                if(k->right!=NULL){
                k = k->right;
                }
                else{
                    k->right = new_node(k, value);
                    return 0;
                }
            }
        }
    }
}

int nodes = 0;
//количество узлов под данным узлом
void vsego_under_node(node* root) {
    if (root) {
        nodes++;
        vsego_under_node(root->left);
        vsego_under_node(root->right);
    }
}

void my_own_super_puper_print(node* n)
{
    list* l = (list*)malloc(sizeof(list));
	list_init(l);
	
	push_back(l,n->value);
	list_node* i = l->list_head;
	vsego_under_node(n);
	int sum = 0;
	int nazvania_zakonchilis = 0;
	int n2 = 1;
	int u = 1;
	while(1 == 1)
	{
        if(i->list_value == 0.54243725)
	    {
	        push_back(l, 0.54243725);
	        push_back(l, 0.54243725);
    	}
        else
        {
            node* aaa = my_own_super_puper_find(n, i->list_value);
            if(aaa->left!=NULL)
            {
                push_back(l, aaa->left->value);
            }
            else
            {
                push_back(l, 0.54243725);
            }
            if(aaa->right!=NULL){
                push_back(l, aaa->right->value);
            }
            else{
                push_back(l, 0.54243725);
            }
        } 
        if(i->list_value != 0.54243725)
            {
                printf("%i ", (int)i->list_value);
                sum++;
            }
        nazvania_zakonchilis++;
        u++;
        if(nazvania_zakonchilis == (r_u_serious(2,n2)-1) )
        {
            n2++;
            u=0;
        }
        i=i->list_next;
        if((u == 0) && (sum == nodes))
        {
            break;
        }
	}
	nodes = 0;
	list_clean(l);
}

// Вывести все значения дерева t, аналогично функции print
void print_tree(tree* t){
    if(t->head==NULL){
        printf("-\n");
    }
    else{
        my_own_super_puper_print(t->head);
    }
}



int main() {
    //создает пустое дерево, считывает 4 элемента ai, |ai| <= 2147483647 и заносит их в дерево;
    
    //Инициализация дерева
    tree* t = (tree*)malloc(sizeof(tree));
    init(t);
    
    //Ввод первых значений
    int i = 0;
    int a = 0;
    for (i; i<7; i++){
        (void)scanf(" %i", &a);
        insert(t, a);
    }
    print_tree(t);
    printf("\n");
    clean(t);
	return 0;
};
