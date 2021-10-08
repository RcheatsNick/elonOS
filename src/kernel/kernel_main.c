#include <drivers/keyboard.h>
#include <drivers/screen.h>
#include <sys/shell.h>
#include <sys/gdt.h>
#include <sys/idt.h>
#include <sys/timer.h>
#include <sys/main.h>
#include <libc/stdint.h>
#include <libc/string.h>
#include <libc/stdlib.h>
#include <database/data.h>
#include <kernel/kernel_main.h>

int kernel_main(){
  clear_screen();
  init_gdt();
  init_idt();

  char *str = "elonOS - a operating system with command line.\n";
  printf("%s",str);
  printf("Version: ");
  color_print(version, BLUE_COL);
  printf("\nAuthor: ");
  color_print(author, CYAN_COL);
  color_print("\nType help for information.", LIGHT_GREEN_COL);
  /* Example interrupts
   * asm volatile("int $0x3");
   * asm volatile("int $0x2"); */

  // Initialize keyboard
  init_keyboard();
  // Initialize prompt
  init_prompt();
  while(1){
    keyboard_handler();
  }
  
   sleep(20); 
      return 0;

  }