#include <stdio.h>
#include <string.h>

int main() {
    int u, f[10];
    char user[10][20], file[10][20][20];

    printf("Enter number of users: ");
    scanf("%d", &u);

    // Input users and their files
    for(int i = 0; i < u; i++) {
        printf("\nEnter username: ");
        scanf("%s", user[i]);

        printf("Enter number of files for %s: ", user[i]);
        scanf("%d", &f[i]);

        for(int j = 0; j < f[i]; j++) {
            printf("Enter file %d name: ", j + 1);
            scanf("%s", file[i][j]);
        }
    }

    // Display directory structure
    printf("\n--- Two Level Directory Structure ---\n");
    for(int i = 0; i < u; i++) {
        printf("\nUser: %s\n", user[i]);
        for(int j = 0; j < f[i]; j++) {
            printf("  %s\n", file[i][j]);
        }
    }

    return 0;
}
