#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

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
    FILE *f; char content [1000];
    snprintf(result,sizeof(result),"%s;%s;%d;%.1f",title,dir,year,rating);
    f = fopen("film.txt", "a+");
    fputs(result,f);
    fclose(f);
    printf("%s has successfully added to Database\n", title);
    pause();
}
void display();
void search();
int update();