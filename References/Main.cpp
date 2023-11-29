#include<iostream>
// Урок 46. Ссылки

void p_swap(int* pointer1, int* pointer2) {
	int tmp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = tmp;
}
void ref_swap(int& reference1, int& reference2) {
	int tmp = reference1;
	reference1 = reference2;
	reference2 = tmp;
}
// прототип функции по Глобальному массиву
int mx[10][2];

int& mx_at(int index) {
	return mx[index][1];
}
int& ref_max(int arr[], const int length) {
	int max_index = 0;	// Так как переменная max удалится после того как фунция закончится, поэтому ссылаемся на индекс максимального элемента в массиве
	for (int i = 1; i < length; i++)
		if (arr[i] > arr[max_index])
			max_index = i;
	return arr[max_index];	// поэтому ссылаемся на индекс максимального элемента в массиве
}
template<typename T>
void print_arr(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "RU");
	int n = 7, m;

	// Ссылки
	
	// int& refn; // ссылку не возможно создать без инициализации.

	int& refn = n; // создание ссылки , ассоциирующаяся с переменной n.

	std::cout << "refn = " << refn << std::endl;

	// Ссылка - это альтернативное имя какой-либо существующей переменной. Отличие от указателя (в указателях мы должны выполнять разыменование)
	// Ссылка - "синтаксический сахар" (Чуть удобнее указателя, не надо разыменовать указатель).

	refn = 15; // можно менять значение переменную через ссылку.
	std::cout << "n = " << n << std::endl;
	refn++;		// можно инкрементировать ссылку.
	std::cout << "n = " << n << std::endl;
	// Примечание:
	// 1. см. урок на диске...
	// 2.
	// 3. 
	
	// Ссылки как параметры функции:
	
	n = 7, m = 15;
	std::cout << n << ' ' << m << std::endl;
	//p_swap(&n, &m);	// Работате но, неудобная.
	ref_swap(n, m);		// передаем в функцию переменные
	std::cout << n << ' ' << m << std::endl;
	
	// Ссылки как результат работы функций:
	
	std::cout << "Ввод данных в массив:\n";
	for (int i = 0; i < 10; i++) {
		std::cout << "Элемент i" << i << " -> ";
		std::cin >> mx[i][0];
		mx_at(i) = mx[i][0];
	}
	
	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < 10; i++)
		std::cout << mx[i][0] << ' ' << mx_at(i) << std::endl;
	
	const int size = 5;
	int arr[size]{ 6, 7, 5, 4, 7 };
	print_arr(arr, size);
	std::cout << "Максимум: " << ref_max(arr, size) << std::endl;

	ref_max(arr, size) = 0;
	print_arr(arr, size);

	return 0;
}