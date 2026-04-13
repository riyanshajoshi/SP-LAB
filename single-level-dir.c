#include <stdio.h>
#include <string.h>

#define MAX 50

char files[MAX][20];
int n = 0;

// Function to search file
int search(char fname[]) {
    for(int i = 0; i < n; i++) {
        if(strcmp(files[i], fname) == 0)
            return i; // return index if found
    }
    return -1; // not found
}

int main() {
    int choice;
    char fname[20];

    while(1) {
        printf("\n1.Create  2.Delete  3.Search  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: // Create
                if(n == MAX) {
                    printf("Directory full!\n");
                    break;
                }

                printf("Enter file name: ");
                scanf("%s", fname);

                if(search(fname) != -1)
                    printf("File already exists!\n");
                else {
                    strcpy(files[n++], fname);
                    printf("File created.\n");
                }
                break;

            case 2: // Delete
                printf("Enter file name: ");
                scanf("%s", fname);

                int pos = search(fname);

                if(pos == -1) {
                    printf("File not found!\n");
                } else {
                    for(int i = pos; i < n-1; i++)
                        strcpy(files[i], files[i+1]);
                    n--;
                    printf("File deleted.\n");
                }
                break;

            case 3: // Search
                printf("Enter file name: ");
                scanf("%s", fname);

                if(search(fname) != -1)
                    printf("File found.\n");
                else
                    printf("File not found.\n");
                break;

            case 4: // Display
                if(n == 0)
                    printf("Directory is empty.\n");
                else {
                    for(int i = 0; i < n; i++)
                        printf("%s\n", files[i]);
                }
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
