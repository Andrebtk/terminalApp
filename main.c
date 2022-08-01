#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <math.h>

typedef struct pixel{
    int x;
    int y;

    char content;
    struct pixel *next;

    int movX;
    int movY;
}pixel;


void frame(struct pixel *pixels);
void termnialSize(int *lines, int *col);
void addPixel(int x, int y, char content, struct pixel *head, int movX, int movY);
void speed(struct pixel *head);
void drawOnFrame(struct pixel *head);

//printf("\e[?25l"); // disable cursor
//printf("\e[?25h");  //  enable cursor

//to implement
/*
void memFree(struct pixel *head){

    while(head != NULL){
        
        free(head->x);
        free(head->y);

        free(head->movX);
        free(head->movY);

        free(head->content);
        
        head = head->next;
    }

}*/

int main(){
    printf("\e[?25l");
    
    struct pixel *head = (pixel *) malloc(sizeof(pixel));
    

    drawOnFrame(head);

    for(int x=0; x!=-1; x++){
        system("clear");

        frame(head);
        speed(head);
        
        usleep(pow(10, 4));   
    }
    //memFree(head);

    printf("\e[?25h");
}


void drawOnFrame(struct pixel *head){

    
    addPixel(10, 2, '#', head, 1, 0);
    addPixel(11, 2, '#', head, 1, 0);
    addPixel(12, 2, '#', head, 1, 0);

    addPixel(10, 3, '#', head, 1, 0);
    addPixel(11, 3, '#', head, 1, 0);
    addPixel(12, 3, '#', head, 1, 0);
    
    addPixel(10, 4, '#', head, 1, 0);
    addPixel(11, 4, '#', head, 1, 0);
    addPixel(12, 4, '#', head, 1, 0);


    addPixel(10, 10, '#', head, 1, 0);
    addPixel(11, 10, '#', head, 1, 0);
    addPixel(12, 10, '#', head, 1, 0);

    addPixel(10, 11, '#', head, 1, 0);
    addPixel(11, 11, '#', head, 1, 0);
    addPixel(12, 11, '#', head, 1, 0);
    
    addPixel(10, 12, '#', head, 1, 0);
    addPixel(11, 12, '#', head, 1, 0);
    addPixel(12, 12, '#', head, 1, 0);

    int col, lines;
    termnialSize(&lines, &col);


    //corner point
    
    addPixel(1, 1, 'X', head, 0, 0);
    addPixel(1, lines, 'X', head, 0, 0);
    addPixel(col, 1, 'X', head, 0, 0);
    addPixel(col, lines, 'X', head, 0, 0);
    
    
    

}

void addPixel(int x, int y, char content, struct pixel *head, int movX, int movY){
    
    pixel *current = head;
    
    while(current->next != NULL){
        current = current->next;
    }
    
    current->next = (pixel *) malloc(sizeof(pixel));

    current->next->x = x;
    current->next->y = y;

    current->next->movX = movX;
    current->next->movY = movY;

    current->next->content = content;
    
    current->next->next = NULL;   
}





void frame(struct pixel *pixels){
    
    int col, lines;
    int found = 0;

    termnialSize(&lines, &col);

    
    for(int i=0; i!= lines; i++){
        for(int x=0; x!= col; x++){
            pixel *current = pixels;
            found=0;

            
            
            while(current != NULL){
                if(current->x > col){current->x = 0;}

                if(current->x == x+1 && current->y == i+1){
                    printf("%c", current->content);
                    found = 1;
                }
                current = current->next;
            }


            //HOW THE FUCK IS IT WORKING
            if(found == 0 ){
                printf(" ");
                found = 1;
            }
        
            if(found == 0 ){
                printf(" \n");
                found = 1;
            }
                
            
        }
        
    }
    fflush(stdout);

}


void speed(struct pixel *head){
    pixel *current = head;

    while(current != NULL){
        if(current->movX == 1){ current->x++; }
        if(current->movX == -1){ current->x--; }

        if(current->movY == 1){ current->y--; }
        if(current->movY == -1){ current->y++; }
        
        current = current->next;
    }
}

void termnialSize(int *lines, int *col){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    *lines = (int) w.ws_row - 1;
    *col = (int) w.ws_col;
}