#include<stdio.h>
#include<stdlib.h>
#include "manage.c"

int main(){
    const char *welcome_screen = "/* .-----------------------------------------------------------------------------. */\n"
    "/* |__        __   _                            _____                            | */\n"
    "/* |\\ \\      / /__| | ___ ___  _ __ ___   ___  |_   _|__                         | */\n"
    "/* | \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\   | |/ _ \\                        | */\n"
    "/* |  \\ V  V /  __/ | (_| (_) | | | | | |  __/   | | (_) |                       | */\n"
    "/* | _ \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| _ |_|\\___/_  __            _      | */\n"
    "/* || |    ___ _ __ ___   ___  _ __   __ _  __| | ___  |  \\/  | _____   _(_) ___ | */\n"
    "/* || |   / _ \\ '_ ` _ \\ / _ \\| '_ \\ / _` |/ _` |/ _ \\ | |\\/| |/ _ \\ \\ / / |/ _ \\| */\n"
    "/* || |__|  __/ | | | | | (_) | | | | (_| | (_| |  __/ | |  | | (_) \\ V /| |  __/| */\n"
    "/* ||_____\\___|_| |_| |_|\\___/|_| |_|\\__,_|\\__,_|\\___| |_|  |_|\\___/ \\_/ |_|\\___|| */\n"
    "/* '-----------------------------------------------------------------------------' */\n";
    printf("%s\n",welcome_screen);
    struct movie myMovie;
    return 0;
}