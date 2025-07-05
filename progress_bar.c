#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int BAR_LENGTH = 50;
const int MAX_TASKS = 3;

typedef struct
{
    int id;
    int progress;
    int step;
} Task;

void print_bar(Task task);

void clear_screen();

int main()
{
    Task tasks[MAX_TASKS];
    srand(time(NULL));

    //!  Initialize
    for (int i = 0; i < MAX_TASKS; i++)
    {
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].step = rand() % 5 + 1;
    }

    int task_incomplete = 1;   //*   set the flag that initialize that the is incomplete and continue the loop
    while (task_incomplete)
    {
        task_incomplete = 0;   //*    Resets the flag at the beginning of each iteration.
        clear_screen();
        for (int i = 0; i < MAX_TASKS; i++)
        {
            tasks[i].progress += tasks[i].step;
            if (tasks[i].progress > 100)
            {
                tasks[i].progress = 100;
            }
            else if (tasks[i].progress < 100)
            {
                task_incomplete = 1;
            }
            print_bar(tasks[i]);
        }
        sleep(1);     //* sleep for 1 second
    }

    printf("All Tasks Completed!\n");
    return 0;
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_bar(Task task)
{
    int bar_to_show = (task.progress * BAR_LENGTH) / 100;
    printf("Task %d: [", task.id);
    for (int i = 0; i < BAR_LENGTH; i++)
    {
        if (i < bar_to_show)
        {
            printf("=");
        }
        else
        {
            printf(" ");
        }
    }
    printf("] %d%%\n", task.progress);
}
