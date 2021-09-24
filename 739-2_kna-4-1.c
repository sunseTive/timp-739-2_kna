#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//структура узла
typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
	struct node *prev;  // ссылка на предыдущий элемент списка
} node;

//Структура двусвязного списка
typedef struct list {
	struct node *head;  // начало списка
	struct node *tail;  // конец списка
} list;

// инициализация пустого списка
void init(list *l){
    l->head = NULL;
    l->tail = NULL;
}

// удалить все элементы из списка
void clean(list *l){
    node* tmp = l->head;
	while (tmp->next != NULL) {
		node* i = tmp;
		tmp = tmp->next;
		free(i);
	}
	free(tmp);
	l->head = NULL;
    l->tail = NULL;
}

// проверка на пустоту списка
bool is_empty(list *l){
    if((l->head = NULL) && (l->tail = NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

// поиск элемента по значению. вернуть NULL если элемент не найден
node *find(list *l, int value){
    node* i = l->head;
	while (i->next != NULL) {
		if (i->value == value)
		{
			return i;
		}
		i = i->next;
	}
	if (i->value == value) {
		return i;
	}
	return NULL;
}

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value){
    node* tmp = malloc(sizeof(node));
	tmp->next = NULL;
	tmp->value = value;
	if ((l->head == NULL) && (l->tail == NULL)) {
        l->head = tmp;
		l->tail = tmp;
		tmp->prev = NULL;
		return 0;
    }
    tmp->prev = l->tail;
    l->tail->next = tmp;
    l->tail = tmp;
	return 0;
}

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value){
	node* tmp = malloc(sizeof(node));
    tmp->prev = NULL;
    tmp->value = value;
	if ((l->head == NULL) && (l->tail == NULL)){
		l->head = tmp;
		l->tail = tmp;
		tmp -> next = NULL;
		return 0;
	}
    tmp->next = l->head;
    l->head->prev = tmp;
    l -> head = tmp;
	return 0;
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, node *n, int value){
    if(n->next == NULL)
    {
        push_back(l, value);
        return 0;
    }
    node* tmp = malloc(sizeof(node));
	tmp->next = n->next;
	tmp->value = value;
	n->next->prev = tmp;
	tmp->prev = n;
	n->next = tmp;
	return 0;
}

// вставка значения перед указанным узлом, вернуть 0 если успешно
int insert_before(list *l, node *n, int value){
    if(n->prev == NULL)
    {
        push_front(l, value);
        return 0;
    }
    node* tmp = malloc(sizeof(node));
	tmp->next = n;
	tmp->value = value;
	n->prev->next = tmp;
	tmp->prev = n->prev;
	n->prev = tmp;
	return 0;
}

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_first(list *l, int value){
    
    node* tmp = l->head;
	node* previous = NULL;
	while (tmp->next != NULL)
	{
		if (l->head->value == value) {
			l->head = tmp->next;
		    tmp->next->prev = NULL;
			free(tmp);
			return 0;
		}
		if (tmp->value == value)
		{
			previous->next = tmp->next;
			tmp->next->prev= previous;
			free(tmp);
			return 0;
		}
		previous = tmp;
		tmp = tmp->next;
	}

	if ((tmp->next == NULL) && (tmp->value == value))
	{
	    l->tail=previous;
		previous->next = NULL;
		free(tmp);
		return 0;
	}
	return 1;
}

// удалить последний элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_last(list *l, int value){
    node* tmp = l->tail;
	node* previous = NULL;
	while (tmp->prev != NULL)
	{
		if (l->tail->value == value) {
			l->tail = tmp->prev;
		    tmp->prev->next = NULL;
			free(tmp);
			return 0;
		}
		if (tmp->value == value)
		{
			previous->prev = tmp->prev;
			tmp->prev->next= previous;
			free(tmp);
			return 0;
		}
		previous = tmp;
		tmp = tmp->prev;
	}

	if ((tmp->prev == NULL) && (tmp->value == value))
	{
	    l->head=previous;
		previous->prev = NULL;
		free(tmp);
		return 0;
	}
	return 1;
}

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l){
    node* tmp = l->head;
	while (tmp != NULL) {
		printf("%i ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

// вывести все значения из списка в обратном порядке через пробел,
// после окончания вывода перейти на новую строку
void print_invers(list *l){
    node* tmp = l->tail;
	while (tmp != NULL) {
		printf("%i ", tmp->value);
		tmp = tmp->prev;
	}
	printf("\n");
}

// Поиск узла по индексу
node* some_func(list* l, int index) {
	node* i = l->head;
	int p = 0;
	while (i->next != NULL) {
		if (p == index) {
			return i;
		}
		i = i->next;
		p++;
	}
	if (p == index) {
		return i;
	}
	return NULL;
}

int main() {
	//1
	//считывает количество элементов n, 0 < n <= 2147483647;
	int n = 0;
	(void)scanf("%i", &n);
    
    //2
    //создает пустой список, считывает n элементов a, |a| <= 2147483647 и заносит их в список;
    
    list* l = (list*)malloc(sizeof(list));
	init(l);
	
	int a;
	//Считываем первый элемент списка
	(void)scanf("%i", &a);
	push_front(l, a);
	
	int i = 1;
	for (i; i < n; i++)
	{
		(void)scanf(" %i", &a);
		push_back(l, a);
	}
	
	//3
	//выводит содержимое списка, используя функцию print;
	print(l);
	
	//4
	//считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и
	//"0" если нет (выводить через пробел, например "1 0 1");
	int k = 0;
	i = 0;
	for (i; i < 3; i++)
	{
		(void)scanf(" %i", &k);
		if (find(l, k) == NULL)
		{
			printf("0 ");
		}
		else
		{
			printf("1 ");
		}
	}
	printf("\n");
    
    //5
    //считывает m, |m| <= 2147483647 и вставляет его в конец списка;
    int m = 0;
	(void)scanf(" %i", &m);
	push_back(l, m);

    //6
    //выводит содержимое списка, используя функцию print_invers;
    print_invers(l);
    
    //7
    //считывает t, |t| <= 2147483647 и вставляет его в начало списка;
    int t = 0;
	(void)scanf(" %i", &t);
	push_front(l, t);
    
    //8
    //выводит содержимое списка, используя функцию print;
    print(l);
    
    //9
    //считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;
    int j = 0;
	(void)scanf(" %i", &j);
	int x = 0;
	(void)scanf(" %i", &x);
	
	insert_after(l,some_func(l, (j - 1)), x);

    //10
    //выводит содержимое списка, используя функцию print_invers;
    print_invers(l);
    
    //11
    //считывает u и y (0 < u <= 2147483647, |y| <= 2147483647) и вставляет значение y перед u-ым элементом списка;
    int u = 0;
	(void)scanf(" %i", &u);
	int y = 0;
	(void)scanf(" %i", &y);
	insert_before(l,some_func(l, (u - 1)), y);
    
    //12
    //выводит содержимое списка, используя функцию print;
    print(l);
    
    //13
    //считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;
    int z = 0;
	(void)scanf(" %i", &z);
	if (find(l, z) != NULL)
	{
		remove_first(l, z);
	}
	
    //14
    //выводит содержимое списка, используя функцию print_invers;
    print_invers(l);
    
    
    //15
    //считывает r, |r| <= 2147483647 и удаляет последний элемент (при его наличии), хранящий значение r из списка;
    int r = 0;
	(void)scanf(" %i", &r);
	if (find(l, r) != NULL)
	{
		remove_last(l, r);
	}
	
	//16
    //выводит содержимое списка, используя функцию print;
    print(l);
    
    //17
    //очищает список.
    clean(l);
    
	return 0;
}

