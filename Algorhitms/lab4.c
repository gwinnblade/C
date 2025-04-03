#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

int M, N;
char map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

typedef struct {
    int x, y;
} Point;

Point queue[MAX_SIZE * MAX_SIZE];
int front = 0, rear = 0;

int canMove(int x, int y, int dir) {
    if (x < 0 || y < 0 || x >= M || y >= N) return 0;
    
    int hex = (map[x][y] >= 'A') ? (map[x][y] - 'A' + 10) : (map[x][y] - '0');
    if (dir == 0) return !(hex & 1);
    if (dir == 1) return !(hex & 2);
    if (dir == 2) return !(hex & 4);
    if (dir == 3) return !(hex & 8);
    return 0;
}

void bfs() {
    queue[rear++] = (Point){0, 0};
    visited[0][0] = 1;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (front < rear) {
        Point p = queue[front++];
        int x = p.x, y = p.y;

        if (x == M - 1 && y == N - 1) return;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (canMove(x, y, i) && !visited[nx][ny]) {
                visited[nx][ny] = visited[x][y] + 1;
                queue[rear++] = (Point){nx, ny};
            }
        }
    }
}

void markPath() {
    int x = M - 1, y = N - 1;
    if (!visited[x][y]) {
        printf("no way\n");
        return;
    }

    while (x != 0 || y != 0) {
        map[x][y] = '*';
        int minStep = visited[x][y];
        int bestX = x, bestY = y;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < M && ny < N && visited[nx][ny] > 0 && visited[nx][ny] < minStep) {
                minStep = visited[nx][ny];
                bestX = nx;
                bestY = ny;
            }
        }
        x = bestX;
        y = bestY;
    }
    map[0][0] = '*';
}

void readFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error reading file\n");
        exit(1);
    }

    fscanf(file, "%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        fscanf(file, "%s", map[i]);
    }
    fclose(file);
}
void writeFile(char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error zapis\n");
        exit(1);
    }

    for (int i = 0; i < M; i++) {
        fprintf(file, "%s\n", map[i]);
    }
    fclose(file);
}

int main() {
    readFile("3x4");
    bfs();
    markPath();
    writeFile("output.txt");

    printf("Kratchayshiy put: %d shagov\n", visited[M - 1][N - 1] - 1);
    return 0;
}
