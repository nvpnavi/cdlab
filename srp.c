#include <stdio.h>
#include <string.h>

int k=0, z=0, i=0, j=0, c=0;
char input[16], ac[20], stack[15], act[10];
void check();

int main(){
    puts("GRAMMAR is: \n E->E+E \n E->E*E \n E->(E) \n E->id");
    puts("Enter input string: ");
    scanf("%s", input);
    c = strlen(input);
    strcpy(act, "SHIFT->");
    printf("---------------------------------------------------\n");
    puts("Stack\tInput\tAction");
    for (k=0, i=0; j<c; k++, i++, j++){
        if (input[j] == 'i' && input[j+1] == 'd'){
            strcat(stack, "id\0");
            input[j] = ' ';
            input[j+1] = ' ';
            printf("\n$%s\t%s$\t%s id", stack, input, act);
            check();
        }
        else{
            stack[i] = input[j];
            stack[i+1] = '\0';
            input[j] = ' ';
            printf("\n$%s\t%s$\t%s symbol", stack, input, act);
            check();
        }
    }
    // Final check to see if the entire input was processed
    if (strcmp(stack, "E") == 0)
        printf("\nInput accepted: Stack reduced to E\n\n");
    else
        printf("\nInput rejected: Final stack is $%s\n\n", stack);
}

void check(){
    strcpy(ac, "REDUCE TO E");
    for (z=0; z<c; z++)
        if (stack[z] == 'i' && stack[z+1] == 'd'){
            stack[z] = 'E';
            stack[z+1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, ac);
            j++;
        }
    for (z=0; z<c; z++)
        if (stack[z] == 'E' && stack[z+1] == '+' && stack[z+2] == 'E'){
            stack[z] = 'E';
            stack[z+1] = '\0';
            stack[z+2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, ac);
            i = i-2;
        }
    for (z=0; z<c; z++)
        if (stack[z] == 'E' && stack[z+1] == '*' && stack[z+2] == 'E'){
            stack[z] = 'E';
            stack[z+1] = '\0';
            stack[z+1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, ac);
            i = i-2;
        }
    for (z=0; z<c; z++)
        if (stack[z] == '(' && stack[z+1] == 'E' && stack[z+2] == ')'){
            stack[z] = 'E';
            stack[z+1] = '\0';
            stack[z+1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, ac);
            i = i-2;
        }
}