#ifndef COMMANDS_H
#define COMMANDS_H

#include <drivers/screen.h>
#include <libc/string.h>
#include <libc/stdlib.h>
#include <kernel/kernel_main.h>
#include <database/data.h>

// commands


char *commands_t =  "echo @text: Prints text on the screen.\nclear: Clears the command line.\nrestart: Restarts the machine.";


void help() {
printf("\nHelp\n");
color_print("----------------INFORMATION----------------\n", LIGHT_BROWN_COL);
color_print("Author: ", BLUE_COL);
color_print(author, LIGHT_MAGENTA_COL);
printf("\n");
color_print("Version: ", BLUE_COL);
color_print(version, LIGHT_MAGENTA_COL);
printf("\n");
color_print("Authors website: ", BLUE_COL);
color_print(website, LIGHT_MAGENTA_COL);
color_print("\n----------------COMMANDS----------------\n", LIGHT_BROWN_COL);
color_print(commands_t, BLUE_COL); 
}
void clear(){ clear_screen(); }
void echo(const char* buffer, const char* color){ 
    printf("\n"); color_print(buffer, color); 
}
void restart(){
 printf("Restarting..."); sleep(10); clear_buffer(); sleep(10); clear_screen(); sleep(10); init_keyboard(); init_prompt(); sleep(10); kernel_main(); }

struct {
  char *name;
  void (*func)();
} function_map [] = {
  { "help", help },
  { "clear", clear },
  { "restart", restart },
};

int run_command(char* name)
{
  
    if ((name[0] == 'e') && (name[1] == 'c') && (name[2] == 'h') && (name[3] == 'o'))
    {
        // Sadece echo mu yazdı ?
        if (strlen(name) == 4)
        {
            printf("\n ");
            return 0;
        }
        
             char *col = WHITE_COL;
            for (int i = 5, j = 0; i != strlen(name); i++, j++)
            {
                if (name[i] == '-' &&  name[i + 1] == 'c' &&  name[i + 2] == ' ' &&  name[i + 3] == '1')
                {
                    col = BLUE_COL;
                    name[i] = ' ';
                    name[i + 1] = ' ';
                    name[i + 2] = ' ';
                    name[i + 3] = ' ';
                }
                if (name[i] == '-' &&  name[i + 1] == 'n')
                {
                    printf("\n");
                }

            }

        if (name[4] == ' ')
        {
            int total = 0;

            for (int i = 5, j = 0; i != strlen(name); i++, j++)
            {
                if (name[i] == ' ')
                {
                    total++;
                }
            }

            if (total == (strlen(name) - 5))
            {
                printf("\n ");
                return 0;
            }

            int len = strlen(name) - 5;

            char* icerik = (char*)malloc(sizeof(char) * len + 1);

            for (int i = 5, j = 0; i != strlen(name); i++, j++)
            {
                icerik[j] = name[i];
            }

            // Son satırı bitir
            icerik[len] = 0;

            echo(icerik, col);

        }
        else
        {
   color_print("\nCommand ",RED_COL);
   color_print(name, RED_COL);
   color_print(" not found. \n", RED_COL);
   color_print(" Type help to see all commands.", MAGENTA_COL);
        }
    }
    else
    {
        for (int i = 0; i < sizeof(function_map) / sizeof(function_map[0]); i++)
        {
            if (!strcmp(function_map[i].name, name))
            {
                function_map[i].func();
                return 1;
            }
        }

   color_print("\nCommand ",RED_COL);
   color_print(name, RED_COL);
   color_print(" not found. \n", RED_COL);
   color_print(" Type help to see all commands.", MAGENTA_COL);
    }
    return 0;
}


#endif // COMMANDS_H
