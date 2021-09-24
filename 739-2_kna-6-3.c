#include <stdio.h>
#include <stdlib.h>

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

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    printf("%i ", root -> value);
}

int main() {
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
    
    //выводит дерево
    postorder(t->head);
    clean(t);
	return 0;
};
