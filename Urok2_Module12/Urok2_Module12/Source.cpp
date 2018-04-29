#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <iostream>
#include "Header.h"

FILE * fp;

struct pets {
	char name[80];
	double price;
};


void main()
{

	setlocale(LC_ALL, "RUS");
	printf("� ������ ������� 8 �������.\n");
	printf("��� ������ �������� 0.\n");
	int n;

	do
	{

		printf("\n������� ����� �������: \n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
		{
			/*1. ������� ��������� ����. ���������� ��� ������ � ������ ����.
			������� ����� �� ������ ����� ������:
			a.	��������� � �������� ����� � �������� �����;
			b.	���� �������� �� ��������� � ������� ����� � �������� �����. */

			char path1[30] = "01.file1.txt";
			char path2[30] = "01.file2.txt";

			char string1[40] = "� ����� ������ ���������";
			char string2[40];
			char string3[40];
			char string4[40];
			char string5[40];

			printf("a):\n");
			printf("���������� ������ � ���� 01.file1.txt\n");

			if ((fp = fopen(path1, "w+b")) != NULL) // ������� �������� ���� ��� ������/������
			{
				fwrite(&string1, sizeof(string1), 1, fp);

				rewind(fp);

				fread(&string2, sizeof(string2), 1, fp); // ������ ������ � string2

				printf("������ ������ �� ����� 01.file1.txt\n");
				printf("\n%s\n", string2);

			}
			else
			{
				printf("������!");
				exit(1);
			}

			if ((fp = fopen(path2, "w+b")) != NULL)
			{
				printf("\n���������� ������ � ���� 01.file2.txt\n");
				fwrite(&string2, sizeof(string2), 1, fp);

				rewind(fp);

				fread(&string3, sizeof(string3), 1, fp);

				printf("������ ������ �� ����� 01.file2.txt\n");
				printf("\n%s\n", string3);
			}
			else
			{
				printf("������!");
				exit(1);
			}
			printf("\n");
			printf("b):\n");

			if ((fp = fopen(path2, "w+b")) != NULL) // ������� �������� ���� ��� ������/������
			{
				printf("���������� ������ � �������� ������� � ���� 01.file2.txt\n");

				char *first, *last, *start;
				int flag = 0, i = 0;

				start = string2;
				while (*start)
				{
					if (!flag)
					{
						if (*start != ' ')
						{
							flag = 1;
							first = start;
						}
					}
					else
					{
						if (*start == ' ' || !*(start + 1))
						{
							flag = 0;
							last = start - 1;

							if (!*(start + 1))
								last = start;

							swapString(first, last);
						}
					}
					start++;
				}

				swapString(string2, start - 1);

				strcpy(string4, string2);

				fwrite(&string4, sizeof(string4), 1, fp);
				rewind(fp);

				fread(&string5, sizeof(string5), 1, fp);
				printf("������ ������ �� ����� 01.file2.txt\n");
				printf("\n%s\n", string5);
			}
			else
			{
				printf("������!");
				exit(1);
			}

			fclose(fp);
			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 2:
		{
			/*2.	������� ��������� ����. ���������� ��� ������ � �������� ������� (������ ������) � ������ ����.
			������� ����� �� ������ ����� ������:
			a.	��������� � �������� ����� � �������� �����;
			b.	���� �������� �� ��������� � ������� ����� � �������� �����. */

			char path3[30] = "02.file1.txt";
			char path4[30] = "02.file2.txt";

			char string1[30] = "� ��������� ��� �������";
			char string2[30];
			char string3[30];
			char string4[30];
			char string5[30];
			char string6[30];

			printf("a):\n");
			printf("���������� ������ � ���� 02.file1.txt\n");

			if ((fp = fopen(path3, "w+b")) != NULL) // ������� �������� ���� ��� ������/������
			{
				fwrite(&string1, sizeof(string1), 1, fp);

				rewind(fp);

				fread(&string2, sizeof(string2), 1, fp); // ������ ������ � string2

				printf("������ ������ �� ����� 02.file1.txt\n");
				printf("\n%s\n", string2);

			}
			else
			{
				printf("������!");
				exit(1);
			}
			printf("\n");
			if ((fp = fopen(path4, "w+b")) != NULL) // ������� �������� ���� ��� ������/������
			{
				strcpy(string3, string2);
				printf("���������� ������ � �������� ������� � ���� 02.file2.txt\n");

				char *first, *last, *start;
				int flag = 0, i = 0;

				start = string3;
				while (*start)
				{
					if (!flag)
					{
						if (*start != ' ')
						{
							flag = 1;
							first = start;
						}
					}
					else
					{
						if (*start == ' ' || !*(start + 1))
						{
							flag = 0;
							last = start - 1;

							if (!*(start + 1))
								last = start;

							swapString(first, last);
						}
					}
					start++;
				}

				swapString(string3, start - 1);

				strcpy(string4, string3);

				fwrite(&string4, sizeof(string4), 1, fp);
				rewind(fp);

				fread(&string5, sizeof(string5), 1, fp);
				printf("������ ������ �� ����� 02.file2.txt\n");
				printf("\n%s\n", string5);
			}
			else
			{
				printf("������!");
				exit(1);
			}
			printf("\n");
			printf("b):\n");

			if ((fp = fopen(path4, "w+b")) != NULL) // ������� �������� ���� ��� ������/������
			{
				printf("���������� ������ � ������ ������� � ���� 02.file2.txt\n");
				fwrite(&string2, sizeof(string2), 1, fp);

				rewind(fp);

				fread(&string6, sizeof(string6), 1, fp); // ������ ������ � string2

				printf("������ ������ �� ����� 02.file2.txt\n");
				printf("\n%s\n", string6);

			}
			else
			{
				printf("������!");
				exit(1);
			}

			fclose(fp);
			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 3:
		{
			/*3. ������� ��������� ����. �������� �����, � �������
			� ����� ������ ������ �� ��������� ����� �������� ��������������� ����.*/
			char path5[30] = "03.file1.txt";
			char path6[30] = "03.file2.txt";

			char string1[50] = "� ��������� ��� �������. ������ ���� �� ���� ���.";
			char string2[50];
			char string3[50];

			printf("���������� ������ � ���� 03.file1.txt\n");

			if ((fp = fopen(path5, "w+b")) != NULL) // ������� �������� ���� ��� ������/������
			{
				fwrite(&string1, sizeof(string1), 1, fp);

				rewind(fp);

				fread(&string2, sizeof(string2), 1, fp); // ������ ������ � string2

				printf("������ ������ �� ����� 03.file1.txt\n");
				printf("\n%s\n", string2);

			}
			else
			{
				printf("������!");
				exit(1);
			}

			if ((fp = fopen(path6, "w+b")) != NULL) // ������� �������� ���� ��� ������/������
			{
				printf("\n���������� ���������� ������ � ���� 03.file2.txt\n");

				for (int i = 0; string2[i] != '\0'; i++)
				{
					if (string2[i] == '.')
						string2[i] = '!';
				}

				fwrite(&string2, sizeof(string2), 1, fp);
				rewind(fp);

				fread(&string3, sizeof(string3), 1, fp);
				printf("������ ������ �� ����� 03.file2.txt\n");
				printf("\n%s\n", string3);
				printf("\n");
			}
			else
			{
				printf("������!");
				exit(1);
			}

			fclose(fp);
			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 4:
		{
			/*4. ��� ����, ���������� ��������� ����. ������ ���� - ��� �����,
			����� � ���. ����� ����� ������� ����.*/
			char path[30] = "04.file1.txt";
			int count = 10;
			DATE *dates = (DATE*)calloc(count, sizeof(DATE));

			printf("���������� ���� � ���� 04.file1.txt\n");

			if ((fp = fopen(path, "w+b")) != NULL) // ������� �������� ���� ��� ������/������
			{
				for (int i = 0; i < count; i++)
				{
					(dates + i)->day = 1 + rand() % 31;
					(dates + i)->month = 1 + rand() % 12;
					(dates + i)->year = 1980 + rand() % 40;
				}

				fwrite(dates, count * sizeof(DATE), 1, fp);
				fclose(fp);

				printf("\n");
			}
			else
			{
				printf("������!");
				exit(1);
			}

			DATE *dates1 = (DATE*)calloc(count, sizeof(DATE));

			if ((fp = fopen(path, "r+b")) != NULL) // ������� �������� ���� ��� ������/������
			{
				rewind(fp);

				fread(dates1, count * sizeof(DATE), 1, fp);

				int mDay = 0, mMonth = 0, mYear = 0, maxIndex;

				for (int i = 0; i < count; i++)
				{
					printf("%d.%d.%d  ", (dates1 + i)->day, (dates1 + i)->month, (dates1 + i)->year);

					if ((dates1 + i)->year > mYear)
					{
						mDay = (dates1 + i)->day;
						mMonth = (dates1)->month;
						mYear = (dates1 + i)->year;
						maxIndex = i;
					}
					else if ((dates1 + i)->month > mMonth && (dates1 + i)->year == mYear)
					{
						mDay = (dates1 + i)->day;
						mMonth = (dates1)->month;
						mYear = (dates1 + i)->year;
						maxIndex = i;
					}
					else if ((dates1 + i)->day > mDay && (dates1 + i)->month == mMonth && (dates1 + i)->year == mYear)
					{
						mDay = (dates1 + i)->day;
						mMonth = (dates1)->month;
						mYear = (dates1 + i)->year;
						maxIndex = i;
					}
					//printf("����� ������� ����: %d.%d.%d  \n", mDay, mMonth, mYear);
				}
				printf("\n");
				printf("\n����� ������� ����: %d.%d.%d\n", (dates1 + maxIndex)->day, (dates1 + maxIndex)->month, (dates1 + maxIndex)->year);

				printf("\n");

			}
			else
			{
				printf("������!");
				exit(1);
			}

			fclose(fp);

			system("pause");
			system("cls");

		}break;

		case 5:
		{
			char path1[15] = "05.f.txt";
			char path2[15] = "05.g.txt";
			char path3[15] = "05.h.txt";
			int count = 10, even = 0, odd = 0;

			int *f = (int*)calloc(count, sizeof(int)); // ��� ���� �����

			if ((fp = fopen(path1, "w+b")) != NULL)
			{
				// *pr = (Product*)calloc(count, sizeof(Product));
				if (f != NULL)
				{
					for (int i = 0; i < count; i++)
					{
						*(f + i) = 10 + rand() % 100;
					}
					//printInfoProduct(pr, count);
				}
				else
				{
					printf("������!");
					exit(1);
				}
				fwrite(f, count * sizeof(int), 1, fp);
			}
			fclose(fp);

			int *f1 = (int*)calloc(count, sizeof(int));

			printf("����� � ����� \"05.f.txt\" ��� ���� �����:\n");
			if ((fp = fopen(path1, "r+b")) != NULL)
			{
				fread(f1, count * sizeof(int), 1, fp);
				for (int i = 0; i < count; i++)
				{
					printf("%d  ", *(f1 + i));
				}
			}
			fclose(fp);

			for (int i = 0; i < count; i++)
			{
				if (*(f1 + i) % 2 == 0)
				{
					//*(g + i) = *(f1 + i);
					even++;
				}
				else if (*(f1 + i) % 2 != 0)
				{
					//*(h + i) = *(f1 + i);
					odd++;
				}
			}

			int *g = (int*)calloc(even, sizeof(int)); // ��� ������ �����
			int *h = (int*)calloc(odd, sizeof(int)); // ��� �������� �����
			even = 0, odd = 0;
			for (int i = 0; i < count; i++)
			{
				if (*(f1 + i) % 2 == 0)
				{
					*(g + even) = *(f1 + i);
					even++;
				}
				else if (*(f1 + i) % 2 != 0)
				{
					*(h + odd) = *(f1 + i);
					odd++;
				}
			}

			if ((fp = fopen(path2, "w+b")) != NULL)
			{
				fwrite(g, even * sizeof(int), 1, fp);
			}
			fclose(fp);
			if ((fp = fopen(path3, "w+b")) != NULL)
			{
				fwrite(h, odd * sizeof(int), 1, fp);
			}
			fclose(fp);

			int *g1 = (int*)calloc(even, sizeof(int));

			printf("\n\n����� � ����� \"05.g.txt\" ��� ������ �����:\n");
			if ((fp = fopen(path2, "r+b")) != NULL)
			{
				fread(g1, even * sizeof(int), 1, fp);
				for (int i = 0; i < even; i++)
				{
					printf("%d  ", *(g1 + i));
				}
			}

			printf("\n\n����� � ����� \"05.�.txt\" ��� �������� �����:\n");
			int *h1 = (int*)calloc(odd, sizeof(int));
			if ((fp = fopen(path3, "r+b")) != NULL)
			{
				fread(h1, odd * sizeof(int), 1, fp);
				for (int i = 0; i < odd; i++)
				{
					printf("%d  ", *(h1 + i));
				}
			}

			fclose(fp);

			printf("\n");
			system("pause");
			system("cls");
		}break;

		case 6:
		{


		}break;

		case 7:
		{
			char path[30] = "07.product.txt";
			int count = 10;

			if ((fp = fopen(path, "w+b")) != NULL)
			{

				Product *pr = (Product*)calloc(count, sizeof(Product));
				if (pr != NULL)
				{
					for (int i = 0; i < count; i++)
					{
						generateProduct(&pr[i].art);
						pr[i].quantity = 100 + rand() % 1000;
						pr[i].price = 1000 + rand() % 5000;
					}
					//printInfoProduct(pr, count);
				}
				else
				{
					printf("������!");
					exit(1);
				}
				fwrite(pr, count * sizeof(Product), 1, fp);
			}
			fclose(fp);

			Product *pr4 = (Product*)calloc(count, sizeof(Product));
			if ((fp = fopen(path, "r+b")) != NULL)
			{
				fread(pr4, count * sizeof(Product), 1, fp);
				printInfoProduct(pr4, count);
			}

			int sum = 0;
			float average;
			for (int i = 0; i < count; i++)
			{
				sum += (pr4 + i)->price;
			}
			printf("����� ��������� �������: %d\n", sum);
			printf("������� ��������� �������: %0.2f\n", (float)sum / count);

		}break;

		case 8:
		{
			char path[30] = "08.comp.txt";
			int count = 10;

			if ((fp = fopen(path, "w+b")) != NULL)
			{
				Computer *cmp = (Computer*)calloc(count, sizeof(Computer));

				if (&cmp != NULL)
				{
					for (int i = 0; i < count; i++)
					{
						generateComp(&cmp[i].cmpMkr);
						cmp[i].frequency = 1 + rand() % 4;
						cmp[i].RAM = 1 + rand() % 10;
						cmp[i].DVD = 0 + rand() % 2;
						cmp[i].price = 100000 + rand() % 500000;
					}
					//printInfoComp(cmp, 10);

				}
				else
				{
					printf("������!");
					exit(1);
				}

				fwrite(cmp, count * sizeof(Computer), 1, fp);
			}
			fclose(fp);

			Computer *cmp4 = (Computer*)calloc(10, sizeof(Computer));
			if ((fp = fopen(path, "r+b")) != NULL)
			{
				fread(cmp4, count * sizeof(Computer), 1, fp);
				printInfoComp(cmp4, count);
			}
			printf("\n���������� ASUS � �������� ���������� ����� 2 ���/���:\n");
			for (int i = 0; i < count; i++)
			{
				if ((strcmp((cmp4 + i)->cmpMkr.mkr, "ASUS ") == 0) && (cmp4 + i)->frequency > 2)
					printInfoCompInd(cmp4, i);
			}


			fclose(fp);

		}break;

		}
	} while (n != 0);

}
