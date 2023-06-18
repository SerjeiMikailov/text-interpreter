#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 5000
#define MAX_LENGTH 15
char lines[MAX_LENGTH];
char words1[MAX_WORDS][MAX_LENGTH];
char words2[MAX_WORDS][MAX_LENGTH];

void print_unique_words(const char *filename1, const char *filename2, FILE *result)
{
    char filepath1[100];
    snprintf(filepath1, sizeof(filepath1), "src/assets/%s", filename1);

    FILE *file1 = fopen(filepath1, "r");
    if (file1 == NULL)
    {
        printf("Error opening file: %s\n", filename1);
        return;
    }

    int count1 = 0;

    while (fscanf(file1, "%s", words1[count1]) == 1 && count1 < MAX_WORDS)
    {
        count1++;
    }
    fclose(file1);

    char filepath2[100];
    snprintf(filepath2, sizeof(filepath2), "src/assets/%s", filename2);

    FILE *file2 = fopen(filepath2, "r");
    if (file2 == NULL)
    {
        printf("Error opening file: %s\n", filename2);
        return;
    }

    int count2 = 0;
    bool found;

    while (fscanf(file2, "%s", words2[count2]) == 1 && count2 < MAX_WORDS)
    {
        found = false;

        for (int i = 0; i < count1; i++)
        {
            if (strcmp(words2[count2], words1[i]) == 0)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            printf("%s\n", words2[count2]);
            fprintf(result, "{%s}\n", words2[count2]);
        }

        count2++;
    }
    fclose(file2);
}

int main()
{
    bool start = false;
    char start_res[5];

    printf("Welcome to text fixer\n");
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
    result = fopen("src/assets/result.txt", "w");
    if (result == NULL)
    {
        printf("Error creating the result file\n");
        return 0;
    }

    while (start == true)
    {
        printf("Unique words from file 2:\n");
        print_unique_words("1.txt", "2.txt", result);

        start = false;
    }

    fclose(result);

    return 0;
}
