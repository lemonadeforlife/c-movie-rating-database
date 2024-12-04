#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void clear(){
    system("@cls||clear");
}
void pause(){
    printf("Press any key to continue...");
    getch();
}
struct movie
{
    char title[100];
    char director[50];
    int release_year;
    float rating;
};

void menu(){
    char menu[] = "\n[1] Add Movie\n"
    "[2] Display Movie\n"
    "[3] Search Movie\n"
    "\t[1] Title\n\t[2] Director\n"
    "[4] Update Movie Details\n"
    "\t[1] Title\n\t[2] Director\n\t[3] Release Year\n\t[4] Rating\n\t[0] All\n"
    "[To Exit Press Ctrl-c]\n"
    ">> ";
    printf("%s", menu);
}
void add(char title[100],char dir[50],int year,float rating){
    char result[1000];
    FILE *file; char data [1000];
    snprintf(result,sizeof(result),"%s;%s;%d;%.1f",title,dir,year,rating);
    file = fopen("film.txt", "a+");
    fputs(result,file);
    fclose(file);
    printf("%s has successfully added to Database\n", title);
    pause();
}
void display(){
    FILE *file = fopen("film.txt", "r");
    char line[200];
    if(file!=NULL){
        fflush(stdin);
        while(fgets(line, sizeof(line),file)){
            for(int i=0,c=0;line[i]!='\0';i++){
                if(i==0){
                    printf(ANSI_COLOR_YELLOW "Movie Title: %c", line[i]);
                    c++;
                } else if(i>0&&line[i]==';'&&c==1){
                    printf(ANSI_COLOR_RESET "\n\tDirector: ");
                    c++;
                } else if(i>0&&line[i]==';'&&c==2){
                    printf("\n\tRelease Year: ");
                    c++;
                } else if(i>0&&line[i]==';'&&c==3){
                    printf("\n\tRating: ");
                    c++;
                } else {
                    printf("%c", line[i]);
                }
            }
            printf("\n\n");
        }
        pause();
    } else {
        printf("Failed to Open the Database.\n");
        pause();
    }
}
void search();
int update();