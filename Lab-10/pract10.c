#include <stdio.h>

int main() {
    FILE *src, *dest;
    char sname[50], dname[50], ch;

    printf("Enter source file name: ");
    scanf("%s", sname);
    printf("Enter destination file name: ");
    scanf("%s", dname);

    src = fopen(sname, "r");
    dest = fopen(dname, "w");

    if (!src || !dest) {
        printf("Error opening file!\n");
        return 1;
    }

    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);
    return 0;
}
