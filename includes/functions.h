#include "keyboard.h"
#include "colors.h"


static unsigned short* VideoMemory=(unsigned short*)0xb8000;

int pos_print = 0;

void print_title( unsigned char colour, const char *string) {
    volatile unsigned char *vid = (unsigned char*) VideoMemory;
    while(*string != 0)
    {
        *(vid) = *string;
        *(vid+1) = colour;
        ++string;
        vid+=2;
    }
}


void setChar(char character, short col, short row, unsigned char attr) {
    volatile unsigned char* vid_mem = (unsigned char *) VideoMemory;
    int offset = (row*80 + col)*2;
    vid_mem += offset;
    if(!attr) {
        attr = 0x0f;
    }
    *(unsigned short int *)vid_mem = (attr<<8)+character;
}

void print_line( unsigned char colour, const char *string, int pos ) {
    volatile unsigned char *vid = (unsigned char*) VideoMemory;
    vid+=pos*160;
    while(*string != 0)
    {
        *vid = *string;
        *(vid+1) = colour;
        ++string;
        vid+=2;
    }

}

void print( unsigned char colour, char string ) {
    volatile unsigned char *vid = (unsigned char*) VideoMemory;
    pos_print+=1;
    vid+=pos_print*160;
    while(string != 0)
    {
        *vid = string;
        *(vid+1) = colour;
        ++string;
        vid+=2;
    }

}

void clear_screen(char clear_to, char attrib)
{
  char *text_video = (char*)0xB8000;
  int pos=0;

  while(pos<(80*25*2))
  {
    *text_video = clear_to;
    *text_video++;
    *text_video = attrib;
    pos++;
  }
}

int inb (unsigned short port)
{
   char value;
  asm volatile ("inb    %w1, %0" : "=a" (value) : "Nd" (port));
  return value;
}
int outb (unsigned short port, unsigned char value)
{
asm volatile ("outb   %b0, %w1" : : "a" (value), "Nd" (port));
}
