#include <stdio.h>
#include <string.h>
// #include <unistd.h>
// #include <termios.h>

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void user_register();
int user_login(); //? return user index
void fix_fgets_input(char *);
void input_credential(char *username, char *password);

void user_register()
{
    if (user_count == MAX_USERS)
    {
        printf("maximum %d users are supported! no more registration allowed!!!!\n", MAX_USERS);
        return;
    }

    int new_index = user_count;
    printf("\nRegister a new user:\n");
    input_credential(users[new_index].username, users[new_index].password);
    user_count++;
    printf("\nRsgistration Successfull\n");
}

int user_login()
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

    input_credential(username, password);

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
        {
            return i;
        }
    }
    return -1;
}

void input_credential(char *username, char *password)
{
    printf("Enter Username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin); //! te return a extra \n we need to replace \n into \0
    fix_fgets_input(username);

        /*
        FIXME:  we are not enabled masking
        */

    printf("Enter password: ");
    fgets(password, CREDENTIAL_LENGTH, stdin); //! te return a extra \n we need to replace \n into \0
    fix_fgets_input(password);

}

void fix_fgets_input(char *string)
{
    int index = strcspn(string, "\n");
    string[index] = '\0';
}

int main()
{
    int option;
    int user_index;
    while (1)
    {
        printf("\nWelcome to User Management\n");
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit");
        printf("\nSelect an Option: ");
        scanf("%d", &option);
        getchar(); //*   consume extra enter from the input buffer.

        switch (option)
        {
        case 1:
            user_register();
            break;
        case 2:
            user_index = user_login();
            if (user_index >= 0)
            {
                printf("login successful,Welcome %s!\n", users[user_index].username);
            }
            else
            {
                printf("login failed,Incorrect username or password!\n");
            }
            break;
        case 3:
            printf("Existing program\n");
            return 0;
            break;
        default:
            printf("invalid option,please try again!");
            break;
        }
    }
    return 0;
}