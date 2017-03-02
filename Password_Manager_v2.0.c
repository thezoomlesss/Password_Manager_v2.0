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
#include <windows.h> // used for system("CLS")    could become useful
#include <conio.h>

void menu(char state);

char key;
    

main()
{
    
    while(1)
    {
        if( kbhit() )
        {
            key=getch();
            menu(key);
        }
    }
}

void menu(char state)
{
    
    clrscr();
    printf("\t\t\t\t\tMenu\n\n");
    switch(state)
    {
        case '0':
        {
            printf("\t\t\t\t\tMenu1\n");
            break;
        }
        case '1':
        {
            printf("\t\t\t\t\tMenu2\n");
            break;
        }
        case '2':
        {
            
            break;
        }
        case '3':
        {
            
            break;
        }
        default:
        {
            printf("\t\t\t\t\tTest\n");
        }
    } // end switch
} // end menu()