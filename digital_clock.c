#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void get_time(char *, int);
void get_date(char *);
int input_formate();
void clear_screen();

int main()
{
    char time[50], date[100];
    int format = input_formate();

    while (1)
    {
        get_time(time, format);
        get_date(date);
        clear_screen();
        printf("CURRENT TIME = %s\n", time);
        printf("DATE = %s\n", date);
        sleep(1); //? sleep for 1 second
    }

    return 0;
}

int input_formate()
{
    int formate;
    printf("Choose the time format:\n");
    printf("1)24hr. formate:\n");
    printf("2)12hr. formate(Default):\n");
    printf("Enter your choice(1/2):");
    scanf("%d", &formate);
    return formate;
}

void get_time(char *buffer, int formate)
{
    time_t rawtime;
    struct tm *current_time;

    time(&rawtime);
    current_time = localtime(&rawtime);

    if (formate == 1)
    {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    }
    else
    {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
}

void get_date(char *buffer)
{
    time_t rawtime;
    struct tm *current_time;

    time(&rawtime);
    current_time = localtime(&rawtime);
    strftime(buffer, 100, "%A %B %d %Y", current_time);
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}