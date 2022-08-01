#include "func.h"

//printf("\e[?25l"); // disable cursor
//printf("\e[?25h");  //  enable cursor


int main(){
    printf("\e[?25l");
    
    struct pixel *head = (pixel *) malloc(sizeof(pixel));
    

    drawOnFrame(head);

    for(int x=0; x!=-1; x++){
        system("clear");

        frame(head);
        speed(head);
        
        usleep(pow(10, 4.5));   
    }
    
    printf("\e[?25h");
}
