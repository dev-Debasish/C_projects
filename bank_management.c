#include <stdio.h>
#include <string.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

const char *ACCOUNT_FILE = "account.dat";

typedef struct
{
    char name[40];
    int acc_no;
    float balance;
} Account;

int main()
{
    while (1)
    {
        int choice;
        printf("\n\n*** Bank Management System ***");
        printf("\n1. Creat Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
            deposit_money();
            break;
        case 3:
            withdraw_money();
            break;
        case 4:
            check_balance();
            break;
        case 5:
            printf("\nClosing the Bank,Thanks for your Visit(0_0)");
            return 0;
            break;
        default:
            printf("\nInvalid Choice.\n");
            break;
        }
    }

    return 0;
}

void create_account()
{
    Account acc;
    FILE *file = fopen(ACCOUNT_FILE, "ab+");
    if (file == NULL)
    {
        printf("Unable to open the File!!");
        return;
    }

    char c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);

    printf("\nEnter your name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    int ind = strcspn(acc.name, "\n");
    acc.name[ind] = '\0';
    printf("\nEnter your Account number: ");
    scanf("%d", &acc.acc_no);
    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, file);
    fclose(file);
    printf("\nAccount created successfully!!");
}
void deposit_money()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL)
    {
        printf("Unable to open the File!!");
        return;
    }

    int acc_no;
    float money;
    Account acc_r;
    printf("\nEnter your Account number: ");
    scanf("%d", &acc_no);
    printf("\nEnter amount to deposite: ");
    scanf("%f", &money);

    while (fread(&acc_r, sizeof(acc_r), 1, file))
    {
        if (acc_r.acc_no == acc_no)
        {
            acc_r.balance += money;
            fseek(file, -sizeof(acc_r), SEEK_CUR);
            fwrite(&acc_r, sizeof(acc_r), 1, file);
            fclose(file);
            printf("\nSuccessfully deposit Rs.%.2f.New balance is Rs.%.2f", money, acc_r.balance);
            return;
        }
    }
    fclose(file);
    printf("\nMoney couldn't be deposited as the Account no %d was not found in records.\n", acc_no);
}
void withdraw_money()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL)
    {
        printf("Unable to open the File!!");
        return;
    }

    int acc_no;
    float money;
    Account acc_r;
    printf("\nEnter your Account number: ");
    scanf("%d", &acc_no);
    printf("\nEnter amount you wish to withdraw: ");
    scanf("%f", &money);

    while (fread(&acc_r, sizeof(acc_r), 1, file))
    {
        if (acc_r.acc_no == acc_no)
        {
            if (acc_r.balance >= money)
            {
                acc_r.balance -= money;
                fseek(file, -sizeof(acc_r), SEEK_CUR);
                fwrite(&acc_r, sizeof(acc_r), 1, file);
                printf("\nSuccessfully withdrawn Rs.%.2f.Remaining balance is Rs.%.2f", money, acc_r.balance);
            }else{
                printf("\nInsufficient balance!!");
            }
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("\nMoney couldn't be withdrawn as the Account no %d was not found in records.\n", acc_no);
}
void check_balance()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (file == NULL)
    {
        printf("Unable to open the File!!");
        return;
    }

    int acc_no;
    Account acc_read;
    printf("Enter your Account number: ");
    scanf("%d", &acc_no);

    while (fread(&acc_read, sizeof(acc_read), 1, file))
    {
        if (acc_read.acc_no == acc_no)
        {
            printf("\nYour Current Balance is Rs.%.2f", acc_read.balance);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("\nAccount no:%d is not found.\n", acc_no);
}