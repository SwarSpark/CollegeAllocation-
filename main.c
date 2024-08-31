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

char* eligible_clg(float marks, char category[10]) {
    char clg[5][50];
    char interest;
    float Harvard[] = {98, 92, 88};
    float Stanford[] = {93, 89, 85};
    float MIT[] = {94, 90, 86};
    float Caltech[] = {95, 92, 89};
    float Oxford[] = {97, 95, 92};
    float eligible_colleges = 0;
    int i;

    if (strcmp(category, "Open") == 0) {
        if (marks >= Harvard[0]) {
            strcpy(clg[(int)eligible_colleges++], "Harvard University");
        }
        if (marks >= Stanford[0]) {
            strcpy(clg[(int)eligible_colleges++], "Stanford University");
        }
        if (marks >= MIT[0]) {
            strcpy(clg[(int)eligible_colleges++], "MIT");
        }
        if (marks >= Caltech[0]) {
            strcpy(clg[(int)eligible_colleges++], "Caltech");
        }
        if (marks >= Oxford[0]) {
            strcpy(clg[(int)eligible_colleges++], "Oxford University");
        }
    } else if (strcmp(category, "Minor") == 0) {
        if (marks >= Harvard[1]) {
            strcpy(clg[(int)eligible_colleges++], "Harvard University");
        }
        if (marks >= Stanford[1]) {
            strcpy(clg[(int)eligible_colleges++], "Stanford University");
        }
        if (marks >= MIT[1]) {
            strcpy(clg[(int)eligible_colleges++], "MIT");
        }
        if (marks >= Caltech[1]) {
            strcpy(clg[(int)eligible_colleges++], "Caltech");
        }
        if (marks >= Oxford[1]) {
            strcpy(clg[(int)eligible_colleges++], "Oxford University");
        }
    } else if (strcmp(category, "Reserved") == 0) {
        if (marks >= Harvard[2]) {
            strcpy(clg[(int)eligible_colleges++], "Harvard University");
        }
        if (marks >= Stanford[2]) {
            strcpy(clg[(int)eligible_colleges++], "Stanford University");
        }
        if (marks >= MIT[2]) {
            strcpy(clg[(int)eligible_colleges++], "MIT");
        }
        if (marks >= Caltech[2]) {
            strcpy(clg[(int)eligible_colleges++], "Caltech");
        }
        if (marks >= Oxford[2]) {
            strcpy(clg[(int)eligible_colleges++], "Oxford University");
        }
    }

    if (eligible_colleges == 0) {
        printf("\t\tCongrats! for %f percent in 10th\n", marks);
        printf("\t\tBUT,You aren't eligible for any college\n");
    } else {
        printf("\t\tCongrats! for %f percent in SSC\n", marks);
        printf("\t\tYou are eligible for the following colleges:\n");
        for (i = 0; i < (int)eligible_colleges; i++) {
            printf("\t\t%d. %s\n", i + 1, clg[i]);
            printf("\t\tAre you interested in this college?");
            printf("\n\t\tEnter 'Y' for Yes otherwise just Enter 'N'\n");
            scanf(" %c", &interest);
            if (interest == 'Y') {
                break;
            } 
        }
        printf("\t\tYou have chosen %s\n", clg[i]);
        printf("\t\tCongrats!\n");
    }
    return clg[i];
}

int main() {
    char id[50], pass[50], rid[50], rpass[50];
    float marks;
    struct Student s1;
    char category[10];
    int gender, age;

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

        printf("\n\n\t\t*Student's Academic Details*\n\n");
        printf("\t\tPlease Enter the Following Details:\n\n");

        printf("\t\tEnter your category (Open/Reserved/Minor): ");
        scanf("%s", category);

        printf("\t\tEnter your 10th class percentage: ");
        scanf("%f", &marks);

        printf("\t\tChoose your gender:\n");
        printf("\t\t1 for Male \n\t\t2 for Female \n\t\t3 for Others\n\t\t:");
        scanf("%d", &gender);

        printf("\t\tEnter your age:");
        scanf("%d", &age);

        // Call the function to check eligible colleges
        eligible_clg(marks, category);
    } else {
        printf("\t\tInvalid username or password. Please try again.\n");
        goto user;
    }

    return 0;
}
