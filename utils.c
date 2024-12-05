#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<direct.h>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define RESET "\e[0m"

#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background 
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

// custom Movie Data type
struct movie
{
    char title[100];
    char director[50];
    int release_year;
    float rating;
};

// utilities

// clear Terminal cuffer or screen
void clear(){
    system("@cls||clear");
}
// pause operation & wait for user any keyboard input
void pause(){
    printf("Press any key to continue...");
    getch();
}

void lower(char *str){
    for(int i=0;i<strlen(str);i++){
        str[i] = tolower(str[i]);
    }
}
// prints the menu
void menu(char *path){
    char *menu = "\n[1] Add Movie\n"
    "[2] Display Movie\n"
    "[3] Search Movie\n"
    "\t[1] Title\n\t[2] Director\n"
    "[4] Update Movie Details\n"
    "\t[1] Title\n\t[2] Director\n\t[3] Release Year\n\t[4] Rating\n"
    "[0] Exit\n\n"
    BGRN "GroupSeven@CSE114" RESET
    BWHT ":" RESET
    YEL "(%s)" RESET
    BWHT "$ " RESET;
    printf(menu, path);
}
// print menu and highlight Search Movie Option
void search_menu(char *path){
    char menu[] = "\n[1] Add Movie\n"
    "[2] Display Movie\n"
    GRN "[3] Search Movie [*]\n" RESET
    "\t[1] Title\n\t[2] Director\n"
    "[4] Update Movie Details\n"
    "\t[1] Title\n\t[2] Director\n\t[3] Release Year\n\t[4] Rating\n"
    "[0] Exit\n\n"
    BGRN "GroupSeven@CSE114" RESET
    BWHT ":" RESET
    YEL "(%s)" RESET
    BWHT "$ " RESET;
    printf(menu, path);
}
// print menu and highlight Update Option
void update_menu(char *path){
    char menu[] = "\n[1] Add Movie\n"
    "[2] Display Movie\n"
    "[3] Search Movie\n"
    "\t[1] Title\n\t[2] Director\n"
    GRN "[4] Update Movie Details [*]\n" RESET
    "\t[1] Title\n\t[2] Director\n\t[3] Release Year\n\t[4] Rating\n"
    "[0] Exit\n\n"
    BGRN "GroupSeven@CSE114" RESET
    BWHT ":" RESET
    YEL "(%s)" RESET
    BWHT "$ " RESET;
    printf(menu, path);
}

// Functionalities

void add(char title[100],char dir[50],int year,float rating){
    char result[1000];
    FILE *file; char data [1000];
    snprintf(result,sizeof(result),"%s;%s;%d;%.1f",title,dir,year,rating);
    file = fopen("film.txt", "a+");
    fputs(result,file);
    fclose(file);
    printf("%s has successfully added to Database\n", title);
}
void parse_print(char *line,int mode){
    char *title, *director;
    int year;
    float rating;
    title = strtok(line, ";");
    director = strtok(NULL, ";");
    sscanf(strtok(NULL, ";"), "%d", &year);
    sscanf(strtok(NULL, ";"), "%f", &rating);
    if (mode==1){ 
        printf(BCYN"Movie Title: %s\n"RESET, title);
    } else {
        printf(BCYN"Movie Title: %s"RESET, title);
        printf("\n\tDirector: %s", director);
        printf("\n\tRelease Year: %d", year);
        printf("\n\tRating: %.1f", rating);
        printf("\n\n");
    }
}
void display(){
    FILE *file = fopen("film.txt", "r");
    char line[200];
    if(file!=NULL){
        fflush(stdin);
        while(fgets(line, sizeof(line),file)){
            parse_print(line,0);
        }
        fclose(file);
    } else {
        printf("Failed to Open the Database.\n");
    }
}
void search(int option){
    char user_search[200]; char *field;
    fflush(stdin);
    if(option==1){
        field = "title";
    } else {
        field = "director name";
    }
    printf("Search movie by %s: ", field);
    fgets(user_search,sizeof(user_search),stdin);
    user_search[strcspn(user_search,"\n")] = '\0';
    lower(user_search);
    FILE *file = fopen("film.txt", "r");
    char line[200];char temp[200]; char *title;
    if(file!=NULL){
        fflush(stdin);
        while(fgets(line, sizeof(line),file)){
            strcpy(temp,line);
            char *title = strtok(temp,";");
            char *director = strtok(NULL,";");
            printf("\n");
            if(option==1){
                lower(title);
                if(strstr(title,user_search)){
                    parse_print(line,0);
                }
            } else if(option==2){
                lower(director);
                if(strstr(director, user_search)){
                    parse_print(line,0);
                }
            }
        }
        fclose(file);
    } else {
        printf("Failed to Open the Database.\n");
    }
}
void update(int option){
    int index=0; int count=1; int wrote=0; char *field;
    char updateData[100]; int updateYear; float updateRating;
    switch(option){
        case 1: printf(BMAG"[*] Update Movie Title \n"RESET); field = "movie title"; break;
        case 2: printf(BMAG"[*] Update Movie Director \n"RESET); field = "director name"; break;
        case 3: printf(BMAG"[*] Update Movie Release Year \n"RESET); field = "release year"; break;
        case 4: printf(BMAG"[*] Update Movie Rating \n"RESET); field = "rating"; break;
    }
    FILE *file, *temp;
    file = fopen("film.txt", "r"); temp = fopen("temp.txt", "w");
    char line[200];char updateLine[200];
    if(file!=NULL){
        fflush(stdin);
        while(fgets(line, sizeof(line),file)){
            printf("\t[%d] ",count);
            parse_print(line,1);
            count++;
        }
        printf("\t[0] Exit\nEnter Movie Index: "); scanf("%d", &index);
        if(index==0) exit(0);   
        fflush(stdin);
        printf("\nUpdate %s: ", field);
        if (option>0&&option<3){
            fgets(updateData,sizeof(updateData), stdin);
            updateData[strcspn(updateData,"\n")] = '\0';
        } else if(option==3){
            scanf("%d", &updateYear);
        } else if(option==4){
            scanf("%f", &updateRating);
        }
        if(index>0){
            fflush(stdin);
            count = 1;
            rewind(file);
            while(fgets(line, sizeof(line),file)){
                if(count == index){
                    char *title, *director; int year; float rating;
                    title = strtok(line, ";");
                    director = strtok(NULL, ";");
                    sscanf(strtok(NULL, ";"), "%d", &year);
                    sscanf(strtok(NULL, ";"), "%f", &rating);
                    switch(option){
                        case 1: snprintf(updateLine, sizeof(updateLine), "%s;%s;%d;%.1f\n", updateData, director, year, rating);  break;
                        case 2: snprintf(updateLine, sizeof(updateLine), "%s;%s;%d;%.1f\n", title, updateData, year, rating);  break;
                        case 3: snprintf(updateLine, sizeof(updateLine), "%s;%s;%d;%.1f\n", title, director, updateYear, rating);  break;
                        case 4: snprintf(updateLine, sizeof(updateLine), "%s;%s;%d;%.1f\n", title, director, year, updateRating);  break;
                    }
                    fputs(updateLine,temp);
                    wrote=1;
                } else {
                    fputs(line,temp);
                }
                count++;
            }
            fclose(file);
            fclose(temp);
            if(wrote){
                remove("film.txt");
                rename("temp.txt","film.txt");
                printf(BLKB BCYN"[*] Movie details updated successfully. [*]\n"RESET);
            } else {
                printf("Failed to write...\n");
                remove("temp.txt");
            }
        } else {
            printf("Invalid Index\n");
        }
    } else {
        printf("Failed to Open the Database.\n");
    }
}