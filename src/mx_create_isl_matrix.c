#include "pathfinder.h"

int **mx_create_isl_matrix(int **matrix, int g) {
    long INF = 9999999999;
    int **alg;
	alg = mx_create_matrix(g, INF);
	for (int i = 0; i < g; i++)
		for (int j = 0; j < g; j++)
			if (matrix[i][j] != 0)
				alg[i][j] = matrix[i][j];
    return alg;
}
