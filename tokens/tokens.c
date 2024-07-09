#include <stdio.h>
#include <regex.h>
#include <string.h>

const char *c_keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "lon    g", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "complex", "imaginary", "_Al    ignas", "_Alignof", "_Atomic", "_Generic", "_Noreturn", "_Static_assert", "_Thread_local", NULL};

typedef enum {
    CHARACTER_SET,
    KEYWORD,
    LITERAL,
    IDENTIFIER,
    OPERATOR,
    SPECIAL_SYMBOL
} token_types;

void main() {
    token_types token;

    regex_t reg;
    char* compareRegex[100];

     printf("enter string: ");
    scanf("%s", &compareRegex);

    if (!keywords(compareRegex, token)) {
      if (!characterSet(compareRegex, token, reg)) {
        printf("no valid token found.");
      }
    }
}

int characterSet(char* compareRegex, token_types token, regex_t reg) {
    int alphaNumeric;

    alphaNumeric = regcomp(&reg, "[[:alnum:]]", 0);
    alphaNumeric = regexec(&reg, compareRegex, 0, NULL, 0);

    if (alphaNumeric == 0) {
        token = CHARACTER_SET;
        if (token == 0) {
            printf("%s is CHARACTER_SET\n", compareRegex);
            return 1;
        }
    }
    
    return 0;
}

int keywords(char* compareRegex, token_types token) {
    int i;
    char* compare;

    for (i=0; c_keywords[i] != NULL; i++) {
        compare = strstr(compareRegex, c_keywords[i]);

        if (compare) {
            token = KEYWORD;
            if (token == 1) {
                printf("%s is KEYWORD\n", compareRegex);
                return 1;
            }
        }
    }

    return 0;
}

