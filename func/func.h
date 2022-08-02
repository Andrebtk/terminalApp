#ifndef HEADER_FILE
#define HEADER_FILE

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
void printStr(char *text, int coodX, int coodY, struct pixel *head);
void drawHeart(struct pixel *head, int coodX, int coodY, char content);

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



void printStr(char *text, int coodX, int coodY, struct pixel *head){

    for(int x=0; x < strlen(text); x++){
        addPixel(coodX + x, coodY, text[x], head, 0, 0);
    }

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


void drawHeart(struct pixel *head, int coodX, int coodY, char content){

    addPixel(coodX, coodY-1, content, head, 0, 0);
    addPixel(coodX, coodY, content, head, 0, 0);
    addPixel(coodX, coodY+1, content, head, 0, 0);

    addPixel(coodX+1, coodY-2, content, head, 0, 0);
    addPixel(coodX+1, coodY+2, content, head, 0, 0);

    addPixel(coodX+2, coodY-3, content, head, 0, 0);
    addPixel(coodX+2, coodY+3, content, head, 0, 0);

    addPixel(coodX+3, coodY-3, content, head, 0, 0);
    addPixel(coodX+3, coodY+4, content, head, 0, 0);

    addPixel(coodX+4, coodY-3, content, head, 0, 0);
    addPixel(coodX+4, coodY+5, content, head, 0, 0);

    addPixel(coodX+5, coodY-2, content, head, 0, 0);
    addPixel(coodX+5, coodY+6, content, head, 0, 0);


    addPixel(coodX+6, coodY-1, content, head, 0, 0);
    addPixel(coodX+6, coodY+7, content, head, 0, 0);


    addPixel(coodX+7, coodY-2, content, head, 0, 0);
    addPixel(coodX+7, coodY+6, content, head, 0, 0);

    addPixel(coodX+8, coodY-3, content, head, 0, 0);
    addPixel(coodX+8, coodY+5, content, head, 0, 0);

    addPixel(coodX+9, coodY-3, content, head, 0, 0);
    addPixel(coodX+9, coodY+4, content, head, 0, 0);

    addPixel(coodX+10, coodY-3, content, head, 0, 0);
    addPixel(coodX+10, coodY+3, content, head, 0, 0);

    addPixel(coodX+11, coodY-2, content, head, 0, 0);
    addPixel(coodX+11, coodY+2, content, head, 0, 0);

    addPixel(coodX+12, coodY-1, content, head, 0, 0);
    addPixel(coodX+12, coodY, content, head, 0, 0);
    addPixel(coodX+12, coodY+1, content, head, 0, 0);
}

#endif