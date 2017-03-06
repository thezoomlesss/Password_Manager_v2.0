/*
    Mohamad Zabad
    
    Password_Manager_v2.0
        This program will safely save  all the passwords that you enter.
*/

/*
    TO DO LIST:
        - Create the interface
        - add the key stroke functions
        - make the login into the program
        - make sure that the program creates all the files needed
        - add te functions for each option
        - More to come...
*/
#include <stdio.h>
#include <stdlib.h> // For the delay()
#include <windows.h> // used for system("CLS")    could become useful
#include <conio.h> // for colours

// Structs
struct record
{
    char title[25];
    char username[30];
    char password[30];
    char email[35];
    char notes[50];
};

// Function Protorypes
void menu(int state);
int enter_record(void);

    

main()
{
    char ch;
    int menu_index=0;
    
    menu(0);
    while(1)
    {
        if(kbhit())
        {
            /*
                                We take in the input and check if it's either UP or DOWN arrow key
                                If it's one of them then we increment/decrement
                        */
            
            ch = getch();
            if(ch==72 && menu_index < 4)  // UP key
            {
                menu_index--;
            }
            else if(ch==80 && menu_index>-1)  // else if DOWN key
            {
                menu_index++;
            }
            if(menu_index > 3)
            {
                menu_index=0;
            }
            else if( menu_index < 0 )
            {
                menu_index=3;
            }
            menu(menu_index);
            Sleep(40);
        } // end if kbhit()
    } // end while
}

void menu(int state)
{
    
    clrscr();
    printf("\t\t\t\t\tMenu\n\n");
    switch(state)
    {
        case 0:
        {
            textcolor(LIGHTGREEN);
            printf("\t\t\t\t\t");
            cprintf("Enter Record");
            printf("\n");
            
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t");
            cprintf("Display Record");
            printf("\n");
            printf("\t\t\t\t\t");
            cprintf("Test2");
            printf("\n");
            printf("\t\t\t\t\t");
            cprintf("Test3");
            printf("\n");
            break;
        }
        case 1:
        {
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t");
            cprintf("Enter Record");
            printf("\n");
            
            
            textcolor(LIGHTGREEN);
            printf("\t\t\t\t\t");
            cprintf("Display Record");
            printf("\n");
            
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t");
            cprintf("Test2");
            printf("\n");
            printf("\t\t\t\t\t");
            cprintf("Test3");
            printf("\n");
            
            break;
        }
        case 2:
        {
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t");
            cprintf("Enter Record");
            printf("\n");
            printf("\t\t\t\t\t");
            cprintf("Display Record");
            printf("\n");
            
            
            textcolor(LIGHTGREEN);
            printf("\t\t\t\t\t");
            cprintf("Test2");
            printf("\n");
            
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t");
            cprintf("Test3");
            printf("\n");
           
            break;
        }
        case 3:
        {
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t");
            cprintf("Enter Record");
            printf("\n");
            printf("\t\t\t\t\t");
            cprintf("Display Record");
            printf("\n");
            printf("\t\t\t\t\t");
            cprintf("Test2");
            printf("\n");
            
            
            textcolor(LIGHTGREEN);
            printf("\t\t\t\t\t");
            cprintf("Test3");
            printf("\n");
            break;
        }
        default:
        {
            printf("TEST");
        }
    } // end switch
} // end menu()

int menu(void)
{
    struct record a;
    
    
    return(1);
}