// LAB-EXERCISE-1 : MATRIX MANIPULAITON 
// SUVAJIT KARMAKAR 

#include <stdio.h>
#include <stdlib.h>

//MACRO DECLARATION 
#define MAX_ROWS 3
#define MAX_COLS 3

// FUNCTION PROTOTYPE DECLARATION 
void displayMatrix(int matrix[MAX_ROWS][MAX_COLS]);
void insertElement(int matrix[MAX_ROWS][MAX_COLS], int row, int col, int value);
void deleteElement(int matrix[MAX_ROWS][MAX_COLS], int row, int col);
void linearSearch(int matrix[MAX_ROWS][MAX_COLS], int value);

void matrixAddition(int MATRIX_A[MAX_ROWS][MAX_COLS], int MATRIX_B[MAX_ROWS][MAX_COLS]);
void matrixMultiplication(int MATRIX_A[MAX_ROWS][MAX_COLS], int MATRIX_B[MAX_ROWS][MAX_COLS]);

int main() {
    int option;
    int element;
    int choose ;

    int position_1;
    int position_2;

    int MATRIX_A[MAX_ROWS][MAX_COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int MATRIX_B[MAX_ROWS][MAX_COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    //TAKING USER INPUT FOR OPERATION 
    printf("---- MATRIX MANIPULATION -----\n");
    printf("------------------------------\n");
    printf("1. MATRIX DISPLAY A\n");
    printf("2. MATRIX DISPLAY B\n");
    printf("3. ELEMENT INSERSION\n");
    printf("4. ELEMENT DELETION\n");
    printf("5. LINEAR SEARCH\n");
    printf("6. MATRIX ADDITION\n");
    printf("7. MATRIX MULTIPLICATION\n");

    printf("------------------------------\n");
    printf("OPTION -> ");
    scanf("%d", &option);


    //SWITCH CASE 
    switch( option ) {
        case 1: 
            printf("MATRIX A -> \n");
            displayMatrix(MATRIX_A);
            break;
        
        case 2:
            printf("MATRIX B ->\n");
            displayMatrix(MATRIX_B);
            break;

        case 3:

            printf("1. MATRIX A \n");
            printf("2. MATRIX B \n");
            printf("CHOOSE THE MATRIX -> ");
            scanf("%d", &choose);

            switch ( choose ) {
                case 1: 
                        printf("ENTER THE ELEMENT TO PERFORM INSERSION -> ");
                        scanf("%d", &element);

                        printf("ENTER THE POSITION A -> ");
                        scanf("%d", &position_1);

                        printf("ENTER THE POSITION B -> ");
                        scanf("%d",&position_2);

                        insertElement(MATRIX_A, position_1, position_2, element);
                        displayMatrix(MATRIX_A);
                        break;

                case 2: 
                        printf("ENTER THE ELEMENT TO PERFORM INSERSION -> ");
                        scanf("%d", &element);

                        printf("ENTER THE POSITION A -> ");
                        scanf("%d", &position_1);

                        printf("ENTER THE POSITION B -> ");
                        scanf("%d",&position_2);

                        insertElement(MATRIX_B, position_1, position_2, element);
                        displayMatrix(MATRIX_B);
                        break;


                default:
                        printf("PLEASE CHOOSE THE RIGHT MATRIX \n");


            }
            break;


        case 4:

            printf("1. MATRIX A \n");
            printf("2. MATRIX B \n");
            printf("CHOOSE THE MATRIX -> ");
            scanf("%d", &choose);

            switch ( choose ) {
                case 1: 

                        printf("ENTER THE POSITION A -> ");
                        scanf("%d", &position_1);

                        printf("ENTER THE POSITION B -> ");
                        scanf("%d",&position_2);

                        deleteElement(MATRIX_A, position_1, position_2);
                        displayMatrix(MATRIX_A);
                        break;


                case 2: 

                        printf("ENTER THE POSITION A -> ");
                        scanf("%d", &position_1);

                        printf("ENTER THE POSITION B -> ");
                        scanf("%d",&position_2);

                        deleteElement(MATRIX_B, position_1, position_2);
                        displayMatrix(MATRIX_B);
                        break;


                default:
                        printf("PLEASE CHOOSE THE RIGHT MATRIX \n");
        

            }
            break;

            case 5:

                printf("1. MATRIX A \n");
                printf("2. MATRIX B \n");
                printf("CHOOSE THE MATRIX -> ");
                scanf("%d", &choose);

                switch ( choose ) {
                    case 1: 

                        printf("ENTER THE ELEMENT TO FIND USING LINEAR SEARCH -> ");
                        scanf("%d", &element);

                        linearSearch(MATRIX_A, element);
                        displayMatrix(MATRIX_A);
                        break;


                    case 2: 

                        printf("ENTER THE ELEMENT TO FIND USING LINEAR SEARCH -> ");
                        scanf("%d", &element);

                        linearSearch(MATRIX_A, element);
                        displayMatrix(MATRIX_A);
                        break;


                    default:
                        printf("PLEASE CHOOSE THE RIGHT MATRIX \n");
        

            }
            break;

        case 6:
            matrixAddition(MATRIX_A, MATRIX_B);
            break;

        case 7:
            matrixMultiplication(MATRIX_A,MATRIX_B);
            break;

        default:
            printf("PLEASE ENTER A VALID OPTION\n");

    }

    return 0;
}

// DISPLAYING THE MATRIX
void displayMatrix(int matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

//MATRIX INSERSION
void insertElement(int matrix[MAX_ROWS][MAX_COLS], int row, int col, int value) {
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        matrix[row][col] = value;
        printf("ELEMENT %d INSERTED AT POSTITION ->  (%d, %d)\n", value, row, col);
    } else {
        printf("INVALID POSITION FOR INSERTION.\n");
    }
}

//MATIRX DELETION
void deleteElement(int matrix[MAX_ROWS][MAX_COLS], int row, int col) {
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        int deletedValue = matrix[row][col];
        matrix[row][col] = 0;
        printf("ELEMENT %d DELETED FORM POSTION ->  (%d, %d)\n", deletedValue, row, col);
    } else {
        printf("INVALID POSITION FOR DELETION.\n");
    }
}

//LINEAR SEARCH OPERATION
void linearSearch(int matrix[MAX_ROWS][MAX_COLS], int value) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            if (matrix[i][j] == value) {
                printf("ELEMENT %d FOUND AT POSITION ->  (%d, %d)\n", value, i, j);
                return;
            }
        }
    }
    printf("ELEMENT  %d NOT FOUND IN THE MATRIX\n", value);
}

//MATRIX ADDITION
void matrixAddition(int MATRIX_A[MAX_ROWS][MAX_COLS], int MATRIX_B[MAX_ROWS][MAX_COLS]) {
    int result[MAX_ROWS][MAX_COLS];

    printf("THE RESULTANT MATRIX ADDITION IS -> \n");

    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            result[i][j] = MATRIX_A[i][j] + MATRIX_B[i][j];
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

//MATRIX MULTIPLICATON
void matrixMultiplication(int MATRIX_A[MAX_ROWS][MAX_COLS], int MATRIX_B[MAX_ROWS][MAX_COLS]) {
    int result[MAX_ROWS][MAX_COLS];

    printf("THE RESULTANT MATRIX MULTIPLICATION IS -> \n");

    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < MAX_COLS; ++k) {
                result[i][j] += MATRIX_A[i][k] * MATRIX_B[k][j];
            }
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}
