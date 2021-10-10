#include "includes/types.h"
#include "includes/functions.h"
#include "includes/colors.h"
#include "includes/keyboard.h"
using namespace std;

typedef void (*constructor)();
extern "C" constructor* start_ctors;
extern "C" constructor* end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i=start_ctors;i!=end_ctors;i++){
        (*i)();
    }
}

extern "C" void kernelMain(void* multiboot_structure, uint32_t magicnumber)
{ 
  
  /* print_title(COLOR_RED, "elona - emir berken yuksel urunudur.");
   print(COLOR_BLUE, "eglencesine yapilmistir");
   print(COLOR_BLUE, "Duyurular: ");*/

int st = outb(0x60, KEY_A);
print(COLOR_RED, st);
//outportb(0x60, 0x1E)
//0x60 ,KEY_A
    while(1);
}
