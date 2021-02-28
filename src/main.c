#include "main.h"

int main(int argc, char **argv)
{
    char *filename;
    if (argc > 1)
    {
        filename = argv[1];
    }
    else
    {
        filename = "test.vr";
    }
    // Open the file
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Calculate the file length
    fseek(file, 0, SEEK_END);
    const size_t length = ftell(file);
    rewind(file);

    // Read the file into a buffer
    char *buffer = malloc(length + 1);
    if (fread(buffer, sizeof(char), length, file) != length)
    {
        perror("fread");
        return EXIT_FAILURE;
    }
    buffer[length] = 0;
    // Close the file
    fclose(file);
    // Print the file
    puts(buffer);
    // Free the buffer
    free(buffer);
    return EXIT_SUCCESS;
}
