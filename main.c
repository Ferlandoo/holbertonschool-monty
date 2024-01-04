#include "monty.h"

int main(int argc, char *argv[])
{
    stack_t *top = NULL;
    char *line = NULL, opcode = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "Error monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file");
        exit(EXIT_FAILURE);
    }
    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        printf("%s", line);
        get_func(opcode)(top, line_number);
    }
    free(line);
    fclose(file);
    return (0);
}
