#include <stdio.h>
#include <stdlib.h>

#include "func/shade.h"


int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1],"r");

    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, fp);

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, fp);

    printf("%d\n", bi.biHeight);
    printf("%d\n\n", bi.biWidth);

    //RGBTRIPLE (*image)[bi.biWidth] = calloc(bi.biHeight, bi.biWidth * sizeof(RGBTRIPLE));
    RGBTRIPLE *image = (RGBTRIPLE *) malloc(sizeof(RGBTRIPLE));

    fread(image, sizeof(RGBTRIPLE),1 ,fp);

    printf("%d\n", image->rgbtRed);
    printf("%d\n", image->rgbtBlue);
    printf("%d\n", image->rgbtGreen);
    

    /*
    BITMAPFILEHEADER bff;
    while(fread(&bff, sizeof(BITMAPFILEHEADER), 1, fp)){
        printf("%d", bff.bfType);
    }
    */
   

    fclose(fp);

}