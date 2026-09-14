
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MEMORY_FILE "jarvis_memory.txt"
#define MAX_LENGTH 1000

void remove_newline(char *text)
{
    text[strcspn(text, "\n")] = '\0';
}

void make_lowercase(char *text)
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        text[i] = (char)tolower((unsigned char)text[i]);
    }
}

int find_answer(char *question, char *answer)
{
    FILE *file;
    char saved_question[MAX_LENGTH];
    char saved_answer[MAX_LENGTH];

    file = fopen(MEMORY_FILE, "r");

    if (file == NULL)
    {
        return 0;
    }

    while (fgets(saved_question, MAX_LENGTH, file) != NULL)
    {
        if (fgets(saved_answer, MAX_LENGTH, file) == NULL)
        {
            break;
        }

        remove_newline(saved_question);
        remove_newline(saved_answer);

        if (strcmp(saved_question, question) == 0)
        {
            strcpy(answer, saved_answer);

            fclose(file);

            return 1;
        }
    }

    fclose(file);

    return 0;
}

void save_memory(char *question, char *answer)
{
    FILE *file;

    file = fopen(MEMORY_FILE, "a");

    if (file == NULL)
    {
        printf("JARVIS: ERROR - I could not save my memory.\n");
        return;
    }

    fprintf(file, "%s\n", question);
    fprintf(file, "%s\n", answer);

    fclose(file);
}

int main()
{
    char question[MAX_LENGTH];
    char answer[MAX_LENGTH];
    char search_question[MAX_LENGTH];

    printf("\n");
    printf("====================================================\n");
    printf("                  J A R V I S\n");
    printf("====================================================\n");
    printf("\n");

    printf("HI, I'm JARVIS, your personal assistant.\n");
    printf("You built me for a specific reason: storing data.\n");
    printf("I can learn answers from you and remember them forever.\n");

    printf("\n");
    printf("Ask me anything.\n");
    printf("If I don't know, teach me the answer.\n");
    printf("I will save it in my permanent memory.\n");

    printf("\n");
    printf("Type 'exit' to close JARVIS.\n");

    printf("\n");
    printf("====================================================\n");
    printf("\n");

    while (1)
    {
        printf("You: ");
        fflush(stdout);

        if (fgets(question, MAX_LENGTH, stdin) == NULL)
        {
            break;
        }

        remove_newline(question);

        if (strlen(question) == 0)
        {
            continue;
        }

        strcpy(search_question, question);

        make_lowercase(search_question);

        if (strcmp(search_question, "exit") == 0)
        {
            printf("\nJARVIS: Goodbye.\n");
            printf("JARVIS: Don't worry, I will remember everything.\n\n");
            break;
        }

        if (find_answer(search_question, answer))
        {
            printf("JARVIS: %s\n\n", answer);
        }
        else
        {
            printf("JARVIS: I don't know the answer to that yet.\n");
            printf("JARVIS: Please give me the answer.\n");

            printf("You: ");
            fflush(stdout);

            if (fgets(answer, MAX_LENGTH, stdin) == NULL)
            {
                break;
            }

            remove_newline(answer);

            if (strlen(answer) == 0)
            {
                printf("JARVIS: You didn't give me an answer.\n\n");
                continue;
            }

            save_memory(search_question, answer);

            printf("\nJARVIS: Got it.\n");
            printf("JARVIS: I'll never forget.\n\n");
        }
    }

    return 0;
}
