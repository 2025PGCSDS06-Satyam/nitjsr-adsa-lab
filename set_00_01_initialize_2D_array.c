#include <stdio.h>

#define ROWS 5
#define COLS 5

int main() {
    int arr[ROWS][COLS] = {0};
    int r, c, val;
    char choice;

    printf("Initial 2D Array (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    do {
        printf("\nEnter row (0-%d): ", ROWS - 1);
        scanf("%d", &r);
        printf("Enter column (0-%d): ", COLS - 1);
        scanf("%d", &c);
        printf("Enter value: ");
        scanf("%d", &val);

        if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
            arr[r][c] = val;
        } else {
            printf("Invalid row or column index!\n");
        }

        printf("\nUpdated Array:\n");
        
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        printf("\nDo you want to insert another value? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nFinal Array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
} 
