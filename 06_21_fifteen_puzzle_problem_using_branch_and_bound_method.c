#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4
#define SIZE 16

typedef struct Node {
    int mat[SIZE];
    int x, y;       
    int cost, level;
    struct Node* parent;
} Node;

int row[] = {0, 0, -1, 1};
int col[] = {-1, 1, 0, 0};

int heuristic(int mat[]) {
    int dist = 0;
    for(int i=0;i<SIZE;i++){
        if(mat[i] != 0){
            int targetX = (mat[i]-1)/N;
            int targetY = (mat[i]-1)%N;
            int curX = i/N;
            int curY = i%N;
            dist += abs(targetX - curX) + abs(targetY - curY);
        }
    }
    return dist;
}

int isGoal(int mat[]) {
    for(int i=0;i<SIZE-1;i++) if(mat[i] != i+1) return 0;
    return mat[SIZE-1]==0;
}

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

void printMat(int mat[]){
    for(int i=0;i<SIZE;i++){
        if(i%N==0) printf("\n");
        printf("%2d ", mat[i]);
    }
    printf("\n");
}

void solve(Node* node) {
    if(isGoal(node->mat)){
        Node* tmp = node;
        printf("Solution (reverse order):\n");
        while(tmp){
            printMat(tmp->mat);
            printf("\n");
            tmp = tmp->parent;
        }
        return;
    }

    for(int i=0;i<4;i++){
        int newX = node->x + row[i];
        int newY = node->y + col[i];
        if(newX>=0 && newX<N && newY>=0 && newY<N){
            Node* child = (Node*)malloc(sizeof(Node));
            memcpy(child->mat,node->mat,sizeof(node->mat));
            swap(&child->mat[node->x*N + node->y], &child->mat[newX*N + newY]);
            child->x = newX; child->y = newY;
            child->level = node->level + 1;
            child->cost = child->level + heuristic(child->mat);
            child->parent = node;
            solve(child); 
        }
    }
}

int main() {
    int mat[SIZE] = {
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,15,14,0
    };
    int x, y;
    for(int i=0;i<SIZE;i++){
        if(mat[i]==0){ x=i/N; y=i%N; break;}
    }
    Node* root = (Node*)malloc(sizeof(Node));
    memcpy(root->mat,mat,sizeof(mat));
    root->x=x; root->y=y; root->level=0;
    root->cost=heuristic(mat); root->parent=NULL;

    solve(root);
    return 0;
}
