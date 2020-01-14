#include "pathfinder.h"

static int **initialize_pred(int g, int startnode);
static void initialize_visited(int *visited, int g, int startnode);
static void initialize_distance(int *distance, int g, int startnode, int **dex);

int **mx_alg_deijkstra(int **dex, int *distance, int g, int startnode) {
	int visited[g];
	int count = 1;
    long INF = 1410065407;
    t_alg alg;

    alg.pred = initialize_pred(g, startnode);
	initialize_visited(visited, g, startnode);
	initialize_distance(distance, g, startnode, dex);

	while (count < g - 1) {
        alg.mindistance = INF;
		for (int i = 0; i < g; i++)
			if (distance[i] < alg.mindistance && !visited[i]) {
                alg.mindistance = distance[i];
                alg.nextnode = i;
			}
		visited[alg.nextnode] = 1;
		for (int i = 0; i < g; i++)
			if (!visited[i]) {
				if (alg.mindistance + dex[alg.nextnode][i] < distance[i]) {
					distance[i] = alg.mindistance + dex[alg.nextnode][i];
                    alg.pred[0][i] = alg.nextnode;
                    alg.pred[1][i] = alg.nextnode;
				}
				if (alg.mindistance + dex[alg.nextnode][i] == distance[i])
                    alg.pred[1][i] = alg.nextnode;
			}
		count++;
	}
	return alg.pred;
}

static int **initialize_pred(int g, int startnode) {
	int **pred = malloc (3 * sizeof(int *));
	pred[0] = malloc(g * sizeof(int));
	pred[1] = malloc(g * sizeof(int));
	pred[2] = NULL;

	for (int i = 0; i < g; i++) {
		pred[0][i] = startnode;
		pred[1][i] = startnode;
	}
	return pred;
}

static void initialize_visited(int *visited, int g, int startnode) {
	for (int i = 0; i < g; i++)
		visited[i] = 0;
	visited[startnode] = 1;
}

static void initialize_distance(int *distance, int g, int startnode, int **dex) {
	for (int i = 0; i < g; i++)
		distance[i] = dex[startnode][i];
	distance[startnode] = 0;
}
