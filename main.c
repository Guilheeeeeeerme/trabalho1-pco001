#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float run(int option)
{
	FILE *console_return;
	float duration;

	if (option == 2)
	{
		console_return = popen("sorter temp.in bubble.out bubble", "r");
	}
	else if (option == 3)
	{
		console_return = popen("sorter temp.in quick.out quick", "r");
	}
	else if (option == 4)
	{
		console_return = popen("sorter temp.in insertion.out insertion", "r");
	}
	else if (option == 5)
	{
		console_return = popen("sorter temp.in selection.out selection", "r");
	}
	else if (option == 6)
	{
		console_return = popen("sorter temp.in shell.out shell", "r");
	}
	else
	{
		console_return = popen("sorter temp.in heap.out heap", "r");
	}

	fscanf(console_return, "%f", &duration);
	pclose(console_return);

	return duration;
}

void show(char *fileName)
{
	FILE *input_file = fopen(fileName, "r");
	int num;

	while (fscanf(input_file, "%d", &num) != EOF)
	{
		printf("%d, ", num);
	}

	fclose(input_file);
}
int main()
{

	int randomnumber;
	unsigned int r_num;
	FILE *temp_file;
		int option;

	srand(time(NULL));

	while (1)
	{
		printf("\n");

		printf("\n1. Gerar vetor");
		printf("\n2. Ordenar - Bubble Sort");
		printf("\n3. Ordenar - Quick Sort");
		printf("\n4. Ordenar - Insert Sort");
		printf("\n5. Ordenar - Select Sort");
		printf("\n6. Ordenar - Shell Sort");
		printf("\n7. Ordenar - Heap Sort");
		printf("\n8. Ordenar e comparar");
		printf("\n9. Sair");

		printf("\nOption: ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			temp_file = fopen("temp.in", "w");

			printf("\nEnter a number between 1 and 100000: ");
			scanf("%d", &r_num);

			for (int i = 0; i < r_num; i++)
			{
				randomnumber = rand() % 100000;
				fprintf(temp_file, "%d\n", randomnumber);
			}

			fclose(temp_file);
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			printf("Time Spent %f (s)", run(option));
			break;
		case 8:
			printf("\nbubble: %f (s)", run(2));
			printf("\nquick: %f (s)", run(3));
			printf("\ninsertion: %f (s)", run(4));
			printf("\nselection: %f (s)", run(5));
			printf("\nshell: %f (s)", run(6));
			printf("\nheap: %f (s)", run(7));
			break;
		case 9:
			return 0;
			break;
		default:
			printf("\nInvalid Option");
			break;
		}
	}
}