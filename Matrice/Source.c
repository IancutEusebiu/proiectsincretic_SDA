#include <stdio.h>
#include <stdlib.h>


int  main()
{
	printf("\nProgram realizat de Iancut Eusebiu Sebastian\n");
	int A[100][100];
	int M, N, i, j;
	int suma;
	int minim_sub_dp = INT_MAX;
	int max_sub_dp = INT_MIN;
	int min_sub_se = INT_MAX;
	int max_sub_se = INT_MIN;
	time_t t;
	printf("Numarul de linii ale matricei : ");
	scanf("%d", &M);
	printf("Numarul de coloane ale matricei : ");
	scanf("%d", &N);


	// generarea valorilor din matrice:
	srand((unsigned)time(&t));

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			A[i][j] = rand() % 100;

	printf("\n\nMatricea generata este:\n");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)

			printf("%5d", A[i][j]);
		printf("\n");
		printf("\n");
	}
	printf("\n");
	printf("Apasa o tasta pentru a continua!\n");
	getch();

	int opt;
	do
	{
		system("cls"); // sterge ecranul
		printf("Alegeti optiunea!\n");
		printf("1. Suma elementelor aflate pe diagonala principala.\n");
		printf("2. Suma elementelor aflate pe diagonala secundara. \n");
		printf("3. Minimul elementelor aflate sub diagonala principala.\n");
		printf("4. Maximul elementelor aflate sub diagonala principala.\n");
		printf("5. Minimul elementelor aflate sub diagonala secundara.\n");
		printf("6. Maximul elementelor aflate sub diagonala secundara.\n");
		printf("7. Exit\n");
		printf("\n\nAlegeti o optiune:");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			if (M != N)
			{
				printf("Introduceti o matrice patratica!");
				getch();
			}

			if (M == N)
			{
				suma = 0;
				for (i = 0; i < M; i++)
					 

					suma =suma+ A[i][i];

				printf("Suma elementelor de pe diagonala principala este:%d\n", suma);
				printf("\n");
				printf("Matricea:\n");
				for (i = 0; i < M; i++)
				{
					for (j = 0; j < N; j++)

						printf("%5d", A[i][j]);
					printf("\n");
					printf("\n");
				}
				getch();
			}
			break;
		case 2:
			if (M != N)
			{
				printf("Introduceti o matrice patratica!");
				getch();
			}



			if (M == N)
			{
				suma = 0;
				for (i = 0; i < M; i++)
					suma = suma + A[i][M - i - 1];



			}

			printf("Suma elementelor de pe diagonala secundara este:%d\n", suma);
			printf("\n");
			printf("Matricea:\n");
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)

					printf("%5d", A[i][j]);
				printf("\n");
				printf("\n");
			}
			getch();



			break;
		case 3:
			printf("Elementele de sub diagonala principala sunt:");
			for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
				{
					if (i > j) // Sub diagonala principala
					{
						printf("%d ", A[i][j]);
						if (A[i][j] < minim_sub_dp)
							minim_sub_dp = A[i][j];
					}
				}
			printf("\nMinimul este:%d\n", minim_sub_dp);


			printf("\nMatricea:\n");
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)

					printf("%5d ", A[i][j]);
				printf("\n");
				printf("\n");
			}
			getch();
			break;
		case 4:
			printf("Elementele de sub diagonala principala sunt:");
			for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
				{
					if (i > j) // Sub diagonala principala
					{
						printf("%d ", A[i][j]);
						if (A[i][j] > max_sub_dp)
							max_sub_dp = A[i][j];
					}
				}
			printf("\nMaximul este:%d\n", max_sub_dp);


			printf("\nMatricea:\n");
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)

					printf("%5d ", A[i][j]);
				printf("\n");
				printf("\n");
			}
			getch();
			break;
		case 5:
			printf("Elementele de sub diagonala secundara sunt:");
			for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
				{
					if (i + j > M - 1) // Sub diagonala secundara
					{
						printf("%d ", A[i][j]);
						if (A[i][j] < min_sub_se)
							min_sub_se = A[i][j];
					}
				}
			printf("\nMinimul este:%d\n", min_sub_se);


			printf("\nMatricea:\n");
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)

					printf("%5d ", A[i][j]);
				printf("\n");
				printf("\n");
			}
			getch();
			break;
		case 6:
			printf("Elementele de sub diagonala principala sunt:");
			for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
				{
					if (i + j > M - 1) // Sub diagonala secundara
					{
						printf("%d ", A[i][j]);
						if (A[i][j] > max_sub_se)
							max_sub_se = A[i][j];
					}
				}
			printf("\nMaximul este:%d\n", max_sub_se);


			printf("\nMatricea:\n");
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)

					printf("%5d ", A[i][j]);
				printf("\n");
				printf("\n");
			}
			getch();
			break;

		case 7: exit(0);
		default: printf("\nOptiune invalida!");
		}
	} while (1);

	return 0;
}