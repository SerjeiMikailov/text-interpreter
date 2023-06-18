#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 5000
#define MAX_LENGTH 15
char lines[MAX_LENGTH];

void print_words(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error to open the file: %s\n", filename);
        return;
    }

    char words[MAX_WORDS][MAX_LENGTH];
    int count = 0;
    
    while (fscanf(file, "%s", words[count]) == 1 && count < MAX_WORDS)
    {
        count++;
    }
    fclose(file);

    for (int i = 0; i < count; i++)
    {
        printf("%s\n", words[i]);
    }
}

int main()
{
    bool start = false;
    char start_res[5];

    printf("Welcome to Between-Project, your text fixer\n");
    printf("Now, just type start\n");
    scanf("%s", start_res);

    if (strcmp(start_res, "start") == 0)
    {
        start = true;
    }
    else
    {
        printf("Execution aborted\n");
        return 0;
    }

    FILE *result;
    result = fopen("result.txt", "w");

    while (start == true)
    {
        printf("Words from file 1:\n");
        print_words("1.txt");

        printf("Words from file 2:\n");
        print_words("2.txt");
        start = false;
    }

    fclose(result);

    return 0;
}