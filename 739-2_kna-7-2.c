#include <stdio.h>
#include <stdlib.h>

//Размер массива
int N;

//Меняем местми элементы
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void heapify(int* a, int n, int i) {
    int max = i; // Максимальный элемент в корне
    int left = 2 * i + 1;//Индекс элемента слева
    int right = 2 * i + 2;//Индекс элемента справа
    if (left < n && a[left] > a[max]){// Если левый больше, то меняем макс на него
        max = left;
    }
    if (right < n && a[right] > a[max]){// Если правый больше, то меняем макс на него
        max = right;
    }
    if (max != i) { // Если меняли макс
        swap(&a[i], &a[max]); //меняем местами корень с максимальным
        heapify(a, n, max); // Прогоняем снова для ступени ниже
    }
}

void hps(int* a, int n) {
    for (int i = (n-1) / 2; i >= 0; i--){//Для всех мини деревьев)
        heapify(a, n, i);// "сортируем" кучу
    }
    
    for (int i = n - 1; i >= 0; i--) { //Для всего массива, уменьшая его размер на каждом шагу на 1
        swap(&a[0], &a[i]);//меняем первый и последний элементы
        heapify(a, i, 0);//"сортируем" новое дерево с размером на 1 меньше
    }
}

//вывод дерева
void print(int* a){
    for(int i = 0; i < N; i++)
    {
        printf("%i ", a[i]);
    }
}

int main()
{
    scanf("%i", &N);
    int a[N];
    int i;
    for (i = 0; i<N; i++) 
    {
        scanf("%d", &a[i]);
    }
    
    printf("\n");
    hps(a, N);//сортируем
    print(a);
    return 0;
}
