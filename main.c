#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>

typedef struct pixel{
    int x;
    int y;
    char content;
    struct pixel *next;
}pixel;

void frame(struct pixel *pixels);
void termnialSize(int *lines, int *col);

//printf("\e[?25l"); // disable cursor
//printf("\e[?25h");  //  enable cursor



void addPixel(int x, int y, char content, struct pixel *head){
    

    pixel *current = head;
    
    while(current->next != NULL){
        current = current->next;
    }
    

    current->next = (pixel *) malloc(sizeof(pixel));

    current->next->x = x;
    current->next->y = y;
    current->next->content = content;

    current->next->next = NULL;   
    
   
}

void speed(struct pixel *head){
    pixel *current = head;

    while(current != NULL){
        current->x++;
        current = current->next;
    }
}

int main(){
    printf("\e[?25l");
    

    struct pixel *head = (pixel *) malloc(sizeof(pixel));
    
    addPixel(10, 9, '#', head);
    addPixel(11, 9, '#', head);
    addPixel(12, 9, '#', head);

    addPixel(10, 10, '#', head);
    addPixel(11, 10, '#', head);
    addPixel(12, 10, '#', head);

    addPixel(10, 11, '#', head);
    addPixel(11, 11, '#', head);
    addPixel(12, 11, '#', head);
    
    
    for(int x=0; x!=6; x++){
        system("clear");

        frame(head);
        speed(head);
        
        sleep(1);        
    }
    
    printf("\e[?25h");
}

void frame(struct pixel *pixels){
    
    int coodX, coodY = 0;
    int col, lines;
    int found = 0;

    termnialSize(&lines, &col);
    
    for(int i=0; i!= lines; i++){
        for(int x=0; x!= col-1; x++){
            pixel *current = pixels;
            found=0;
            while(current != NULL){
                if(current->x == coodX+1 && current->y == coodY+1){
                    printf("%c", current->content);
                    found = 1;
                }
                current = current->next;
            }
            if(found == 0 ){
                printf(" ");
                found = 1;
            }
            coodX++;
        }
        printf(" \n");
        coodX=0;
        coodY++;
    }
    fflush(stdout);
}

void termnialSize(int *lines, int *col){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    *lines = (int) w.ws_row - 1;
    *col = (int) w.ws_col;
}