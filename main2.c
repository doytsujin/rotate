#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *filename;
    if(argc > 1)
        filename = argv[1];
    else
        filename = "test.vr";
    
    FILE *file = fopen(filename, "r");
    if(!file){
        perror("fopen");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    const size_t length = ftell(file);
    rewind(file);

    char *buffer = malloc(length+1);
    if(fread(buffer, sizeof(char), length, file)!= length)
    {
        perror("fread");
        return 1;
    }
    buffer[length] = 0;
    fclose(file);
    puts(buffer);
    free(buffer);
    return 0;
}