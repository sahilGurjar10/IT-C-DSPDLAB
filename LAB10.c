#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source, *dest;
    char inputFile[100], outputFile[100];
    char buffer[1024];
    size_t bytesRead;

    printf("Enter source file name: ");
    scanf("%s", inputFile);
    printf("Enter destination file name: ");
    scanf("%s", outputFile);

    source = fopen(inputFile, "r");
    if (source == NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }

    dest = fopen(outputFile, "w");
    if (dest == NULL) {
        printf("Cannot create destination file.\n");
        fclose(source);
        exit(1);
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(dest);
    return 0;
}
