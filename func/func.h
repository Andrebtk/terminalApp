#ifndef HEADER_FILE
#define HEADER_FILE

void frame(struct pixel *pixels);
void termnialSize(int *lines, int *col);
void addPixel(int x, int y, char content, struct pixel *head, int movX, int movY);
void speed(struct pixel *head);
void drawOnFrame(struct pixel *head);

#endif