#include <stdio.h>


int main() {
    int count, src_router;
    int cost_matrix[100][100], dist[100];
    int flag[100];

    printf("\nEnter the number of routers: ");
    scanf("%d", &count);
    printf("\nEnter the cost matrix values:\n");

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            scanf("%d", &cost_matrix[i][j]);
        }
    }

    printf("\nEnter the source router: ");
    scanf("%d", &src_router);

    for (int i = 0; i < count; i++) {
        flag[i] = 0;
        dist[i] = cost_matrix[src_router][i];
    }

    flag[src_router] = 1;
    int source = src_router;

    for (int k = 0; k < count; k++) {
        int minimum = 1000;

        for (int j = 0; j < count; j++) {
            if (!flag[j]) {
                if (dist[j] > dist[source] + cost_matrix[source][j]) {
                    dist[j] = dist[source] + cost_matrix[source][j];
                }
                if (minimum > dist[j]) {
                    minimum = dist[j];
                    source = j;
                }
            }
        }

        flag[source] = 1;
    }

    printf("\nShortest distances from source router %d:\n", src_router);
    for(int i = 0; i < count; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
