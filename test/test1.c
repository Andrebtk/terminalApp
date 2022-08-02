#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../func/func.h"


//printf("\e[?25l"); // disable cursor
//printf("\e[?25h");  //  enable cursor



int main(){
    printf("\e[?25l");
    
    struct pixel *head = (pixel *) malloc(sizeof(pixel));
    

    drawOnFrame(head);


    drawHeart(head, 10, 18, 'X');
    drawHeart(head, 10, 30, 'O');

        
    for(int x=0; x!=-1; x++){
        system("clear");
        frame(head);
        speed(head);

        
        
        usleep(pow(10, 5));   
    }
    //memFree(head);
    
    printf("\e[?25h");
}
