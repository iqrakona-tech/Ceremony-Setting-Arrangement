#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int seating[MAX_ROWS][MAX_COLS];

void initializeSeating(){
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            seating[i][j] = 0;
        }
    }
}

void displaySeating(){
    printf("\nSeating Arrangement:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++){
            printf("%d ", seating[i][j]);
        }
        printf("\n"); }}

void addSeat(){
    int row, col;
    printf("Enter row (0-%d): ", MAX_ROWS-1);
    scanf("%d", &row);
    printf("Enter column (0-%d): ", MAX_COLS-1);
    scanf("%d", &col);

    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        if (seating[row][col] == 0) {
            seating[row][col] = 1;
            printf("Seat successfully booked! Your seat number is: Row %d, Column %d\n", row, col);
        } else {
            printf("Seat already occupied!\n");
        }
    } else {
        printf("Invalid seat position!\n");
    }
}

void removeSeat()
{
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);
    if (seating[row][col] == 1){
        seating[row][col] = 0;
        printf("Seat successfully removed!\n");}
    else
        printf("Seat already empty!\n");
}

void updateSeat()
{
    int oldRow, oldCol, newRow, newCol;
    printf("Enter current row and column: ");
    scanf("%d %d", &oldRow, &oldCol);
    if (seating[oldRow][oldCol] == 0) {
        printf("No seat at this position!\n");
        return;
    }
    printf("Enter new row and column: ");
    scanf("%d %d", &newRow, &newCol);
    if (seating[newRow][newCol] == 0) {
        seating[newRow][newCol] = 1;
        seating[oldRow][oldCol] = 0;
        printf("Seat updated successfully!\n");
        printf("New seat number is: Row %d, Column %d\n", newRow, newCol);
    } else {
        printf("New seat position already occupied!\n");
    }
}

void saveSeatingToFile()
{
    FILE *file = fopen("seating.txt", "w");
    if (!file) {
        printf("Unable to open file for writing!\n");
        return;
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            fprintf(file, "%d ", seating[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Seating arrangement saved.\n");
}

void loadSeatingFromFile()
{
    FILE *file = fopen("seating.txt", "r");
    if (!file) {
        printf("Unable to open file for reading!\n");
        return;
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            fscanf(file, "%d", &seating[i][j]);
        }
    }
    fclose(file);
    printf("Seating arrangement loaded.\n");
}

int main() {
    int choice;
    char str[100];
    printf("Enter your name:\n");
    scanf(" %[^\n]",str);


    printf("\nHello, %s.\n\nWelcome to our ceremony seat arrangement system.\n\nChoose what kind of service you want.\n\n");

    initializeSeating();

    do {
        printf("\nCeremony Seat Management System\n\n");
        printf("1. Add a seat\n");
        printf("2. Remove a seat\n");
        printf("3. Update a seat\n");
        printf("4. Display seating arrangement\n");
        printf("5. Save seating arrangement\n");
        printf("6. Load seating arrangement\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n======ADD SEAT======\n");
                addSeat();
                break;
            case 2:
            printf("\n======RREMOVE SEAT======\n");
                removeSeat();
                break;
            case 3:
            printf("\n======UPDATE SEAT======\n");
                updateSeat();
                break;
            case 4:
            printf("\n======DISPLAYING THE SEATING ARRANGEMENT======\n");
                displaySeating();
                break;
            case 5:
                saveSeatingToFile();
                break;
            case 6:
                loadSeatingFromFile();
                break;
            case 7:
                printf("\nGood Bye %s.\n\nThank you for using our system....\n",str);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
