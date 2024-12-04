#include<stdio.h>
#include<stdlib.h>
#include "manage.c"

int main(){
    int choice;
    while(1){
        clear();
        menu();
        if(scanf("%d", &choice)==EOF){
            printf("\nBye :)\n");
            exit(0);
        } else if((choice>2&&choice<31)||(choice>32&&choice<40)||choice>44||choice==0){
            printf("Invalid Choice\n");
            fflush(stdin);
            pause();
        } else {
            fflush(stdin);
            if(choice==1){ // Add Movie
                struct movie myMovie;
                printf("Enter Movie Name: ");
                fgets(myMovie.title,sizeof(myMovie.title),stdin);
                myMovie.title[strcspn(myMovie.title,"\n")] = '\0';
                printf("Enter Movie Director Name: ");
                fgets(myMovie.director,sizeof(myMovie.director),stdin);
                myMovie.director[strcspn(myMovie.director,"\n")] = '\0';
                printf("Enter Movie Year: ");
                scanf("%d", &myMovie.release_year);
                printf("Enter Movie Rating: ");
                scanf("%f", &myMovie.rating);
                add(myMovie.title,myMovie.director,myMovie.release_year,myMovie.rating);
            } else if(choice==2){
                clear();
                display();
            } else if(choice==3){
                continue;
            } else if(choice>=40){
                continue;
            }
        }
    }
    return 0;
}