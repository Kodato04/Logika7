#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream> 
#include <locale.h>

void DFS(int** G, int numG, int* visited, int s) {
	visited[s] = 1;
	printf("%3d", s);
	for (int i = 0; i < numG; i++) {
		if (G[s][i] == 1 && visited[i] == 0)
			DFS(G, numG, visited, i);
	}
}

int main()
{ 
	setlocale(LC_ALL, "");
	int** G;
	int* visited;
	int numG;
	int current;

	printf("=================================\n");
	printf("    ALGORITHM DFS (Depth First Search)\n");
	printf("=================================\n");

	printf("Количество вершин: ");
	scanf("%d", &numG);

	G = (int**)malloc(numG * sizeof(int*));
	visited = (int*)malloc(numG * sizeof(int));
	for (int i = 0; i < numG; i++) {
		G[i] = (int*)malloc(numG * sizeof(int));
		visited[i] = 0;
	}

	printf("\nМатрица смежности:\n");
	printf("-------------------\n");
	for (int i = 0; i < numG; i++) {
		for (int j = 0; j < numG; j++) {
			G[i][j] = (i == j ? 0 : rand() % 2);
		}
	}

	for (int i = 0; i < numG; i++) {
		for (int j = 0; j < numG; j++) {
			printf("%3d", G[i][j]);
		}
		printf("\n");
	}

	printf("\n-------------------\n");
	printf("Стартовая вершина: ");
	scanf("%d", &current);

	printf("\n");
	printf("Путь обхода: ");
	DFS(G, numG, visited, current);
	printf("\n\n");

	for (int i = 0; i < numG; i++) {
		free(G[i]);
	}
	free(G);
	free(visited);

	return 0;
} 