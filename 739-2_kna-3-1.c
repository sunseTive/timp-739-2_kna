#include <stdio.h>
#include <stdlib.h>

//структура узла
typedef struct node {
	int value;
	struct node* next;
} node;

typedef struct list {
	struct node* head;
} list;

// инициализация пустого списка
void init(list* l) {
	l->head = NULL;
}

// Вставка значения в начало списка
void push_front(list* l, int value) {
	node* tmp = malloc(sizeof(node));
	tmp->value = value;
	tmp->next = l->head;
	l->head = tmp;
}

// Вывод списка
void print(list* l) {
	node* tmp = l->head;
	while (tmp != NULL) {
		printf("%i ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

// Вставка узла в конец
void push_back(list* l, int value) {
	node* i = l->head;
	while (i->next != NULL) {
		i = i->next;
	}
	i->next = malloc(sizeof(node));
	i->next->value = value;
	i->next->next = NULL;
}

// проверка на пустоту
_Bool is_empty(list* l) {
	if (l->head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Поиск узла по значению
node* find(list* l, int value) {
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

//удаление элементов списка
void clean(list* l) {

	node* tmp = l->head;
	while (tmp->next != NULL) {
		node* i = tmp;
		tmp = tmp->next;
		free(i);
	}
	free(tmp);
	l->head = NULL;
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node* n, int value) {
	node* tmp = malloc(sizeof(node));
	tmp->next = n->next;
	tmp->value = value;
	n->next = tmp;
	return 0;
}

// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_node(list* l, int value) {
	node* tmp = l->head;
	node* previous = NULL;
	while (tmp->next != NULL)
	{
		if (l->head->value == value) {
			l->head = tmp->next;
			free(tmp);
			return 0;
		}
		if (tmp->value == value)
		{
			previous->next = tmp->next;
			free(tmp);
			return 0;
		}
		previous = tmp;
		tmp = tmp->next;
	}
	if ((tmp->next == NULL) && (tmp->value == value))
	{
		previous->next = NULL;
		free(tmp);
		return 0;
	}
	return 1;
}

// Поиск узла по индексу
node* some_func(list* l, int index) {
	node* i = l->head;
	long int p = 0;
	while (i->next != NULL) {
		if (p == index) {
			return i;
		}
		i = i->next;
		p++;
	}
	return NULL;
}


int main()
{
	//1
	long int n = 0;

	//Считываем количество элементов списка
	(void)scanf("%li", &n);

	//2
	list* l = (list*)malloc(sizeof(list));
	init(l);
	long int a;

	//Считываем первый элемент списка
	(void)scanf("%li", &a);
	push_front(l, a);

	long int i = 1;
	for (i; i < n; i++)
	{
		(void)scanf(" %li", &a);
		push_back(l, a);
	}

	//3
	//вывод списка
	print(l);

	//4
	//считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением
	//и "0", если нет (выводить через пробел, например "1 0 1");

	long int k = 0;
	i = 0;
	for (i; i < 3; i++)
	{
		(void)scanf(" %li", &k);
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
	long int m = 0;
	(void)scanf(" %li", &m);
	push_back(l, m);

	//6
	//выводит содержимое списка, используя функцию print;
	print(l);

	//7
	//считывает t, |t| <= 2147483647 и вставляет его в начало списка;
	long int t = 0;
	(void)scanf(" %li", &t);
	push_front(l, t);

	//8
	//выводит содержимое списка, используя функцию print;
	print(l);

	//9
	//считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;
	long int j = 0;
	(void)scanf(" %li", &j);
	long int x = 0;
	(void)scanf(" %li", &x);
	insert_after(some_func(l, (j - 1)), x);

	//10
	//выводит содержимое списка, используя функцию print;
	print(l);

	//11
	//считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;
	long int z = 0;
	(void)scanf(" %li", &z);
	if (find(l, z) != NULL)
	{
		remove_node(l, z);
	}

	//12
	//выводит содержимое списка, используя функцию print;
	print(l);

	//13
	//очищает список.
	clean(l);

	return 0;
}