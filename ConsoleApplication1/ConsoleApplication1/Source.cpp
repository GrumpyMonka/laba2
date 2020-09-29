#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iostream>

using namespace std;

void shell(int *items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int *items, int left, int right) //����� �������: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;

	/* ����� ���������� */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int N = 100000;
int a[100000], a1[100000];

void main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // ��������� ���������� ��� ����������� ������� ����������

	int i = 0;
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	printf("---------------------------------\n");
	printf("|Data\t|Shell\t|Qs\t|QSort\t|\n");
	printf("---------------------------------\n");

	start = clock();

	shell(a, N);

	end = clock();
	
	printf("|rand\t|%.1f\t|", difftime(end, start));
	////////////////////////////////////////////////////////////////////////////////////
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0;
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	start = clock();

	qs(a, 0, N);

	end = clock();

	printf("%.1f\t|", difftime(end, start));
	//////////////////////////////////////////////////////////////////////////////////
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0;
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	start = clock();

	qsort(a, N, sizeof(int), compare);

	end = clock();

	printf("%.1f\t|\n", difftime(end, start));
	printf("---------------------------------\n");
	//////////////////////////////////////////////////////////////////////////////////





	//////////////////////////////////////////////////////////////////////////////////
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0;
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	qs(a, 0, N);

	start = clock();

	shell(a, N);

	end = clock();

	printf("|up\t|%.1f\t|", difftime(end, start));
	////////////////////////////////////////////////////////////////////////////////////
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0;
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	qs(a, 0, N);

	start = clock();

	qs(a, 0, N);

	end = clock();

	printf("%.1f\t|", difftime(end, start));
	//////////////////////////////////////////////////////////////////////////////////
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0;
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	qs(a, 0, N);

	start = clock();

	qsort(a, N, sizeof(int), compare);

	end = clock();

	printf("%.1f\t|\n", difftime(end, start));
	printf("---------------------------------\n");
	//////////////////////////////////////////////////////////////////////////////////





	//////////////////////////////////////////////////////////////////////////////////
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0;
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	qs(a, 0, N);

	i = 0;
	while (i<N)
	{
		a1[i] = a[99999 - i];
		i++;
	}

	start = clock();

	shell(a1, N);

	end = clock();

	printf("|down\t|%.1f\t|", difftime(end, start));
	////////////////////////////////////////////////////////////////////////////////////
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0;
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	qs(a, 0, N);

	i = 0;
	while (i<N)
	{
		a1[i] = a[99999 - i];
		i++;
	}

	start = clock();

	qs(a1, 0, N);

	end = clock();

	printf("%.1f\t|", difftime(end, start));
	//////////////////////////////////////////////////////////////////////////////////
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0;
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	qs(a, 0, N);

	i = 0;
	while (i<N)
	{
		a1[i] = a[99999 - i];
		i++;
	}

	start = clock();

	qsort(a1, N, sizeof(int), compare);

	end = clock();

	printf("%.1f\t|\n", difftime(end, start));
	printf("---------------------------------\n");
	//////////////////////////////////////////////////////////////////////////////////





	//////////////////////////////////////////////////////////////////////////////////
	i = 0;
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	i = 0;
	while (i<50000)
	{
		a1[i] = a[50000 + i];
		i++;
	}

	shell(a, 50000);
	shell(a1, 50000);

	i = 0;
	while (i < 50000) {
		a[50000 + i] = a1[49999 - i];
		i++;
	}

	start = clock();

	shell(a, N);

	end = clock();

	printf("|up/dw\t|%.1f\t|", difftime(end, start));
	////////////////////////////////////////////////////////////////////////////////////
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0;
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	i = 0;
	while (i<50000)
	{
		a1[i] = a[50000 + i];
		i++;
	}

	shell(a, 50000);
	shell(a1, 50000);

	i = 0;
	while (i < 50000) {
		a[50000 + i] = a1[49999 - i];
		i++;
	}

	start = clock();

	qs(a, 0, N);

	end = clock();

	printf("%.1f\t|", difftime(end, start));
	//////////////////////////////////////////////////////////////////////////////////
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0;
	while (i<N)
	{
		a[i] = rand() % 100 + 1; // ��������� ������ ���������� �������
		i++;
	}

	i = 0;
	while (i<50000)
	{
		a1[i] = a[50000 + i];
		i++;
	}

	shell(a, 50000);
	shell(a1, 50000);

	i = 0;
	while (i < 50000) {
		a[50000 + i] = a1[49999 - i];
		i++;
	}

	start = clock();

	qsort(a, N, sizeof(int), compare);

	end = clock();

	printf("%.1f\t|\n", difftime(end, start));
	printf("---------------------------------\n");
	//////////////////////////////////////////////////////////////////////////////////
	_getch();
}