#include <stdio.h>
#include <stdlib.h>

 
int verificare(int M,int N) {
	
	if (M != N)
	{
		printf("Numarul de linii trebuie sa fie egal cu nr de coloane!");

		getch();
		exit(0);
	}
}

int suma_diag(int M,int B[100][100],int y)
{
	int x = M;
	int suma = 0;
	for (int i = 0; i < x; i++)
	{
		if (y == 1)
			suma = suma + B[i][i];
		if (y == 2)
			suma = suma + B[i][M - i - 1];
	}
	return suma;
}
int min_sub_dp_sec(int M,int N, int B[100][100],int y)
{
	int min=INT_MAX;
	 
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			if (i > j && y==3) // Sub diagonala principala
			{
				if (B[i][j] < min)
					min = B[i][j];
			}
			if (i + j > M - 1 && y==5) // Sub diagonala secundara
			{
				if (B[i][j] < min)
					min= B[i][j];
			}
		}
	return min;
}
int max_sub_dp_sec(int M, int N, int B[100][100], int y)
{
	int max = INT_MIN;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			if (i > j && y == 4) // Sub diagonala principala
			{
				if (B[i][j] > max)
					max = B[i][j];
			}

			if (i + j > M - 1 && y == 6) // Sub diagonala secundara
			{
				if (B[i][j] > max)
					max = B[i][j];
			}
		}
	return max;
}
int  main()
{
	int y;
	int A[100][100];
	int M, N, i, j;
	int suma;
	int minim_sub_dp;
	int max_sub_dp;
	int minim_sub_se ;
	int max_sub_se;
	time_t t;
	printf("Numarul de linii : ");
	scanf("%d", &M);
	printf("Numarul de coloane : ");
	scanf("%d", &N);

	// generarea valorilor din matrice:
	srand((unsigned)time(&t));

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			A[i][j] = rand() % 100;
	int opt;
	verificare(M, N);
	do
	{
		printf("\n\nMatricea generata este:\n");

		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)

				printf("%5d", A[i][j]);
			printf("\n");
			printf("\n");
		}
		printf("\n");
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
			    y = 1;
			   suma= suma_diag(M,A,y);
				printf("Suma elementelor de pe diagonala principala este:%d\n", suma);
				getch(); system("cls");	
			break;
		case 2:
			y = 2;
			suma = suma_diag(M, A, y);
			 printf("Suma elementelor de pe diagonala secundara este:%d\n", suma);
			 getch();  system("cls");
			break;
		case 3:
			y = 3;
			  minim_sub_dp = min_sub_dp_sec(M,N,A,y);
			printf("\nMinimul este:%d\n", minim_sub_dp);
			getch(); system("cls");
			
			break;
		case 4:
			y = 4;
			max_sub_dp = max_sub_dp_sec(M, N, A, y);
			printf("\nMaximul este:%d\n", max_sub_dp);
			getch(); system("cls");
			 
			break;
		case 5:
			y = 5;
			minim_sub_se = min_sub_dp_sec(M, N, A, y);
			printf("\nMinimul este:%d\n", minim_sub_se);
			getch(); system("cls");
			break;
		case 6:
			y = 6;
			max_sub_se = max_sub_dp_sec(M, N, A, y);
			printf("\nMaximul este:%d\n", max_sub_se);
			getch(); system("cls");
			break;

		case 7: exit(0);
		default: printf("\nOptiune invalida!");
		}
	} while (1);

	return 0;
}