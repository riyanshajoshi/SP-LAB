#include<stdio.h>

int main() {
    int n, start[10], count[10], block[10][20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    // Input details
    for(int i = 0; i < n; i++) {
        printf("\nFile: %d\n", i + 1);

        printf("Enter start block: ");
        scanf("%d", &start[i]);

        printf("Enter number of blocks: ");
        scanf("%d", &count[i]);

        printf("Enter linked blocks: ");
        for(int j = 0; j < count[i]; j++) {
            scanf("%d", &block[i][j]);
        }
    }

    // Display file details
    printf("\nFile\tStart\tBlocks");
    for(int i = 0; i < n; i++) {
        printf("\n%d\t%d\t%d", i + 1, start[i], count[i]);
    }

    // Display chain of selected file
    int choice;
    printf("\nEnter file number to display its chain: ");
    scanf("%d", &choice);

    int idx = choice - 1;

    printf("Chain: %d -> ", start[idx]);
    for(int j = 0; j < count[idx]; j++) {
        printf("%d -> ", block[idx][j]);
    }
    printf("NULL\n");

    return 0;
}
