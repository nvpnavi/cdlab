#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function prototypes
void compute_first(char non_terminal);
void compute_follow(char non_terminal);

// Global variables
int num_productions;    // Number of productions
int first_follow_count = 0;  // To track First/Follow set size
int i = 0, j = 0;       // Loop counters
char productions[10][10];    // Grammar productions
char first_follow_set[10];   // First/Follow set for a non-terminal
char non_terminals[10];      // List of unique non-terminals

// Check if character is a non-terminal
int is_non_terminal(char ch) {
    return isupper(ch);
}

int main(){
    // Input the number of productions
    printf("Enter the number of productions:\n");
    scanf("%d", &num_productions);

    // Input productions
    printf("Enter the productions (e.g., A->aB):\n");
    for (i = 0; i < num_productions; i++)
        scanf("%s", productions[i]);

    // Extract unique non-terminals
    for (i = 0; i < num_productions; i++) {
        char left_hand_side = productions[i][0];
        if (!strchr(non_terminals, left_hand_side)) {
            strncat(non_terminals, &left_hand_side, 1);
        }
    }

    // Compute First and Follow for each non-terminal
    printf("\n--- First and Follow Sets ---\n");
    for (i = 0; i < strlen(non_terminals); i++) {
        char non_terminal = non_terminals[i];

        // Compute and print First set
        first_follow_count = 0;
        compute_first(non_terminal);
        printf("First(%c) = {", non_terminal);
        for (j = 0; j < first_follow_count; j++)
            printf("%c", first_follow_set[j]);
        printf("}\n");

        // Compute and print Follow set
        first_follow_count = 0;
        compute_follow(non_terminal);
        printf("Follow(%c) = {", non_terminal);
        for (j = 0; j < first_follow_count; j++)
            printf("%c", first_follow_set[j]);
        printf("}\n");
    }

    return 0;
}

// Compute First set for a non-terminal
void compute_first(char non_terminal) {
    int k;
    if (!is_non_terminal(non_terminal)) {
        first_follow_set[first_follow_count++] = non_terminal;
        return;
    }
    for (k = 0; k < num_productions; k++) {
        if (productions[k][0] == non_terminal) {
            if (productions[k][2] == '$') {
                compute_follow(productions[k][0]);
            } else if (islower(productions[k][2])) {
                first_follow_set[first_follow_count++] = productions[k][2];
            } else {
                compute_first(productions[k][2]);
            }
        }
    }
}

// Compute Follow set for a non-terminal
void compute_follow(char non_terminal) {
    int i, j;
    if (productions[0][0] == non_terminal)
        first_follow_set[first_follow_count++] = '$';

    for (i = 0; i < num_productions; i++) {
        for (j = 2; j < strlen(productions[i]); j++) {
            if (productions[i][j] == non_terminal) {
                if (productions[i][j + 1] != '\0')
                    compute_first(productions[i][j + 1]);
                if (productions[i][j + 1] == '\0' && non_terminal != productions[i][0])
                    compute_follow(productions[i][0]);
            }
        }
    }
}
