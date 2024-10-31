#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_KEYWORDS 100
#define MAX_SPECIAL 100
#define MAX_OPERATORS 100
#define MAX_INTEGERS 100

int main(){
    FILE *fp;
    char buffer[100];
    char keywords[MAX_KEYWORDS][100];
    char special[MAX_SPECIAL][100];
    char operators[MAX_OPERATORS][100];
    char integers[MAX_INTEGERS][100];
    int keywordCount = 0, specialCount = 0, operatorCount = 0, integerCount = 0;

    // Read keywords from file
    FILE *kw = fopen("keywords.txt", "r");
    while(fscanf(kw, "%s", keywords[keywordCount]) == 1)
        keywordCount++;
    fclose(kw);

    // Read special characters from file
    FILE *sc = fopen("special.txt", "r");
    while(fscanf(sc, "%s", special[specialCount]) == 1)
        specialCount++;
    fclose(sc);

    // Read operators from file
    FILE *op = fopen("operators.txt", "r");
    while(fscanf(op, "%s", operators[operatorCount]) == 1)
        operatorCount++;
    fclose(op);

    // Read integers from file
    FILE *in = fopen("integers.txt", "r");
    while(fscanf(in, "%s", integers[operatorCount]) == 1)
        integerCount++;
    fclose(in);


    fp = fopen("program.txt", "r");
    if(fp == NULL){
        printf("Error opening file");
        return 0;
    }

    while(fscanf(fp, "%s", buffer) == 1){
        int flag = 4; // 0 = keyword, 1 = special, 2 = operator, 3 = integer, 4 = identifier
        for(int i = 0; i < keywordCount; i++){
            if(strcmp(buffer, keywords[i]) == 0){
                printf("Keyword:\t%s\n", buffer);
                flag = 0;
                break;
            }
        }

        for(int i = 0; i < specialCount; i++){
            if(strcmp(buffer, special[i]) == 0){
                printf("Special char:\t%s\n", buffer);
                flag = 1;
                break;
            }
        }

        for(int i = 0; i < operatorCount; i++){
            if(strcmp(buffer, operators[i]) == 0){
                printf("Operator:\t%s\n", buffer);
                flag = 2;
                break;
            }
        }
        int tempflag = flag;
        for(int i = 0; i < strlen(buffer); i++){
            if(isdigit(buffer[i]))
                flag = 3;
            else{
                flag = tempflag;
                break;
            }
        }
        if(flag == 3){
            printf("Integer:\t%s\n", buffer);
        }

        if(flag == 4){
            printf("Identifier:\t%s\n", buffer);
        }
    }
    fclose(fp);

    return 0;
}
