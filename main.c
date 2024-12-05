#include "utils.c"

int main(){
    char dir[1024];
    getcwd(dir,sizeof(dir));
    int choice;
    while(1){
        clear();
        menu(dir);
        int input = scanf("%d", &choice);
        if(input==EOF){
            printf("\nBye :)\n");
            exit(0);
        } else if(input!=1){
            printf("Invalid Input\n");
            fflush(stdin);
            pause();
        } else if((choice>4&&choice<31)||(choice>32&&choice<41)||choice>44){
            printf("Invalid Input\n");
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
                pause();
            } else if(choice==2){ // Display All Movie
                clear();
                display();
                pause();
            } else if(choice==3){ // Search Menu
                clear();
                search_menu(dir);
                int search_option;
                scanf("%d", &search_option);
                if(search_option==1){
                    clear();
                    search(search_option); // title
                    pause();
                } else if(search_option==2){
                    clear();
                    search(search_option); // director
                    pause();
                } else if(search_option==0){
                    printf("\nBye :)\n");
                    exit(0);
                } else {
                    printf("Invalid Option\n");
                    pause();
                }
            } else if(choice==4){ // Update Menu
                clear();
                update_menu(dir);
                int search_option;
                scanf("%d", &search_option);
                if(search_option>0&&search_option<5){
                    clear();
                    update(search_option);
                } else if(search_option==0){
                    printf("\nBye :)\n");
                    exit(0);
                } else {
                    printf("Invalid Option\n");
                }
                pause();
            } else if(choice>30&&choice<33){
                if(choice==31){
                    search(1);
                    pause();
                } else if(choice==32){
                    search(2);
                    pause();
                }
            } else if(choice>40&&choice<45){
                clear();
                switch(choice){
                    case 41: update(1); break;
                    case 42: update(2); break;
                    case 43: update(3); break;
                    case 44: update(4); break;
                }
                pause();
            } else if(choice==0){
                printf("\nBye :)\n");
                exit(0);
            }
        }
    }
    return 0;
}