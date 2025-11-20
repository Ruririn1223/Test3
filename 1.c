#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

int findLastEven() {
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			index = i;
		}
	}
	return index;
}

int findLastnotEven() {
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			index = i;
		}
	}
	return index;
}

int Elembigger10() {
	int kol = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) {
			kol++;
		}
	}
	return kol;
}
void printElements() {

	printf("< ");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf(">\n");

}
void keyboardInput() {
	printf("n = ");
	scanf_s("%d", &n);

	printf("input %d values : ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}
void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}
}
int findMin() {
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}
int findIndexMin() {
	int min = arr[0], index = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			index = i;
			min = arr[i];
		}
	}
	return index;
}
void aaaa() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] *= -1;
		}
	}
}

void bbbb() {
	for (int i = 0; i < n; i++) {
		if (arr[i] < 4) {
			arr[i] = 4;
		}
	}
}

int Maxindex() {
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > arr[index]) {
			index = i;
		}
	}
	return index;
}

void deleteElement(int index) {
	for (int i = index; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}

void insertElement(int insIndex, int value) {
	for (int i = n; i > insIndex; i--) {
		arr[i] = arr[i - 1];
	}
	n++;
	arr[insIndex] = value;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n");
		printf("------------------------------\n");
		printf("Содержимое массива:");
		printElements();
		printf("Выберите нужную вам операцию:\n");
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечетных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: Сколько элементов > 10\n");
		printf("5: х2 для последнего четного\n");
		printf("6: Сколько четных левее минимального\n");
		printf("9: Все четные элементы массива умножить на -1\n");
		printf("10: Все элементы массива имеющие значения меньше 4 заменить на 4\n");
		printf("11: В массиве все элементы, стоящие перед максимальным, заменить на 0\n");
		printf("12: Удалить заданный элемент\n");
		printf("13: Вставить новый элемент в заданое место\n");
		printf("14: Удалить минимальный элемент\n");
		printf("15: Перед минимальным элементом вставить 0\n");
		printf("16: После последнего нечетного элемента вставить 0\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);
		switch (item) {
		case 1:
			keyboardInput();
			break;

		case 2:
			oddsX10();
			break;

		case 3:
		{
			int min = findMin();
			printf("min = %d\n", min);
		}
		break;
		case 4:
		{
			int kol = Elembigger10();
			printf("%d элементов > 10\n", kol);
		}
		break;
		case 5:
		{
			int index = findLastEven();
			if (index >= 0) {
				arr[index] *= 2;
			} else {
				printf("В массиве не найдено четных элементов");
			}
		}
		break;
		case 6:
		{
			int index = findIndexMin();
			printf("Индекс минимального элемента = %d\n", index);

			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("Левее минимального %d четных элементов\n", cnt);
		}
		break;
		case 9:
		{
			aaaa();
		}
		break;
		case 10:
		{
			bbbb();
		}
		break;
		case 11:
		{
			int index = Maxindex();
			for (int i = 0; i < index; i++) {
				arr[i] = 0;
			}
		}
		break;
		case 12:
		{
			printf("Индекс удаляемого элемента = ");
			int index;
			scanf_s("%d", &index);

			deleteElement(index);
		}
		break;
		case 13:
		{
			printf("Перед каким элементом нажно вставить наовый? Индекс = ");
			int index;
			scanf_s("%d", &index);

			printf("Значение которое нужно вставить = ");
			int value;
			scanf_s("%d", &value);

			insertElement(index, value);
		}
		break;
		case 14:
		{
			deleteElement(findIndexMin());
		}
		break;
		case 15:
		{
			int IndexMin = findIndexMin();
			printf("Индекс минимального элемента = %d\n", IndexMin);

			insertElement(findIndexMin()-1, 0);
		}
		break;
		case 16:
		{
			if (findLastnotEven() >= 0) {
				insertElement(findLastnotEven() + 1, 0);
			} else {
				printf("В масиве нет нечетных элементов");
			}
			
		}
		break;
		}

	} while (item != 0);
}
