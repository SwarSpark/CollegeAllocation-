#include <stdio.h>
#include <string.h>

struct name {
    char fname[50];
    char mname[50];
    char lname[50];
};

struct DOB {
    char date[50];
    char month[50];
    char year[50];
};

struct Student {
    struct name n;
    struct DOB birth;
};

int main() {
    char id[50], pass[50], rid[50], rpass[50];

    printf("\n\n\n\n\t\t\t**Registration**\n\n");
    printf("\t\t\tEnter your id: ");
    scanf("%s", id);
    printf("\t\t\tEnter your password: ");
    scanf("%s", pass);
    printf("\n\n\n\n\n\n\n\t\t\tYour account has been created...!!\n\n\n\n\n\n\n\n");

    printf("\n\n\n\n\n\n\t\t\t*Login Page*\n\n\n\n");
user:
    printf("\t\t\tEnter Username:");
    scanf("%s", rid);
    printf("\t\t\tEnter password:");
    scanf("%s", rpass);

    if (strcmp(id, rid) == 0 && strcmp(pass, rpass) == 0) {
        printf("\t\tYou have successfully logged in.\n");
    } else {
        printf("\t\tInvalid username or password. Please try again.\n");
        goto user;
    }

    return 0;
}
