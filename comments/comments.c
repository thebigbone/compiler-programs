#include <stdio.h>
#include <string.h>

void main() {
    FILE *f;
    char contents[1000];
    int i;
    int in_multiline_comment = 0;

    f = fopen("hello.txt", "r");

    while (fgets(contents, 1000, f) != NULL) {
        char* start_comments;
        char* end_comments;
        char* single_line_comments;

        start_comments = strstr(contents, "/*");
        if (start_comments != NULL) {
            in_multiline_comment = 1;
            printf("%s", start_comments);
        }

        if (in_multiline_comment) {
            end_comments = strstr(contents, "*/");
            if (end_comments != NULL) {
                in_multiline_comment = 0;
                printf("%.*s", (int)(end_comments - contents + 2), contents);
            } else {
                printf("%s", contents);
            }
        }

        if (!in_multiline_comment) {
            single_line_comments = strstr(contents, "//");
            if (single_line_comments != NULL) {
                printf("%s", single_line_comments);
            }
        }
    }
    fclose(f);
}
