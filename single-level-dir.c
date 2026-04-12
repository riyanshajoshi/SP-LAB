#include <stdio.h>
#include <string.h>

#define MAX 50

int main() {
    char files[MAX][20];
    int n = 0, choice;
    char fname[20];
    int i, found;

    while(1) {
        printf("\n1. Create File\n2. Delete File\n3. Search File\n4. Display Files\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: // Create
                if(n < MAX) {
                    printf("Enter file name: ");
                    scanf("%s", fname);

                    // Check if file already exists
                    found = 0;
                    for(i = 0; i < n; i++) {
                        if(strcmp(files[i], fname) == 0) {
                            found = 1;
                            break;
                        }
                    }

                    if(found)
                        printf("File already exists!\n");
                    else {
                        strcpy(files[n], fname);
                        n++;
                        printf("File created.\n");
                    }
                } else {
                    printf("Directory full!\n");
                }
                break;

            case 2: // Delete
                printf("Enter file name to delete: ");
                scanf("%s", fname);

                found = 0;
                for(i = 0; i < n; i++) {
                    if(strcmp(files[i], fname) == 0) {
                        found = 1;

                        // Shift files
                        for(int j = i; j < n-1; j++) {
                            strcpy(files[j], files[j+1]);
                        }
                        n--;
                        printf("File deleted.\n");
                        break;
                    }
                }

                if(!found)
                    printf("File not found!\n");
                break;

            case 3: // Search
                printf("Enter file name to search: ");
                scanf("%s", fname);

                found = 0;
                for(i = 0; i < n; i++) {
                    if(strcmp(files[i], fname) == 0) {
                        found = 1;
                        break;
                    }
                }

                if(found)
                    printf("File found.\n");
                else
                    printf("File not found.\n");
                break;

            case 4: // Display
                if(n == 0)
                    printf("Directory is empty.\n");
                else {
                    printf("Files:\n");
                    for(i = 0; i < n; i++) {
                        printf("%s\n", files[i]);
                    }
                }
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
