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

#define prinln  printf    // because I can't seem to stop using println 


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
void menu1(int state, int condition);  // Login/Register menu
void menu1_input(void);
void menu1_select(int state);
void menu(int state);   // Main menu
void menu_input(void);
int enter_record(void);

    

main()
{
    menu1_input();
    menu_input();
}
void menu1(int state, int condition)
{
    clrscr();
    switch(state)
    {
        case 0:
        {
            printf("\n\n\t\t\t\t\t\t");
            textcolor(LIGHTCYAN);
            cprintf("Log in");
            printf("\n\n");
            
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t");
            cprintf("Register");
            printf("\n\n");
            
            printf("\t\t\t\t\t\t");
            cprintf("Exit");
            printf("\n");
            break;
        }
        
        case 1:
        {
            printf("\n\n\t\t\t\t\t\t");
            textcolor(LIGHTRED);
            cprintf("Log in");
            printf("\n\n");
            
            textcolor(LIGHTCYAN);
            printf("\t\t\t\t\t\t");
            cprintf("Register");
            printf("\n\n");
            
            printf("\t\t\t\t\t\t");
            textcolor(LIGHTRED);
            cprintf("Exit");
            printf("\n");
            
            break;
        }
        
        case 2:
        {
            printf("\n\n\t\t\t\t\t\t");
            textcolor(LIGHTRED);
            cprintf("Log in");
            printf("\n\n");
            
            printf("\t\t\t\t\t\t");
            cprintf("Register");
            printf("\n\n");
            
            printf("\t\t\t\t\t\t");
            textcolor(LIGHTCYAN);
            cprintf("Exit");
            printf("\n");
            break;
        }
        
        default :
        {
            printf("Bug %d", state);
        }
    }// end switch
    
    if( condition ) menu1_select(state);
} // end void menu1
void menu1_input(void)
{
    char ch;
    int menu_index=0;
    
    /*
                The Login menu
        */
    menu1(menu_index,0);
    while(1)
    {
        if(kbhit())
        {
            /*
                                We take in the input and check if it's either UP or DOWN arrow key
                                If it's one of them then we increment/decrement
                        */
            ch=getch();
            if(ch==72 && menu_index > -1)  // UP key
            {
                menu_index--;
            }
            else if(ch==80 && menu_index < 3)  // else if DOWN key
            {
                menu_index++;
            }
            
            if(menu_index > 2)
            {
                menu_index=0;
            }
            else if(menu_index < 0)
            {
                menu_index=2;
            }
            
            // If the user pressed enter
            if(ch == 13) 
            {
                menu1(menu_index,1);
            }
            menu1(menu_index, 0);
            Sleep(40);
        } // end kbhit()
    } // end while() 
} // end menu1_input
void menu1_select(int state)
{
    FILE *fp1;
    char username[20];
    
    switch(state)
    {
        case 0:
        {
            do
            {
                clrscr();
                printf("\n\n\t\t\t\t\t\t");
                textcolor(LIGHTCYAN);
                cprintf("Log In");
                
                textcolor(LIGHTGREEN);
                printf("\n\n\t\t\t\t\t");
                cprintf("Username"); 
                textcolor(WHITE);
                cprintf(" (max 20)");
                textcolor(LIGHTRED);
                cprintf(": ");
                scanf("%s", username);
                flushall();
                
                if(strlen( username ) > 19 )
                {
                    do
                    {    
                        clrscr();
                        printf("\n\n\t\t\t\t\t\t");
                        textcolor(LIGHTCYAN);
                        cprintf("Log In");
                        
                        textcolor(LIGHTRED);
                        printf("\n\n\t\t\t\t");
                        cprintf("The username can't be longer than 20 characters!");
                        textcolor(LIGHTGREEN);
                        printf("\n\t\t\t\t\t");
                        cprintf("Username: ");
                        scanf("%s", username);
                        flushall();
                    } while(strlen( username ) > 19 );
                } // end if username > 19 chars
            } while(strlen( username ) > 19 );
            break;
        }
        
        case 1:
        {
            // register new name and create file
            break;
        }
        
        case 3:
        {
            exit(0);
        }
        
        default :
        {
            printf("Bug");
        }
    } // end switch
    
    
    
} // end menu1_select

void menu(int state)
{
    
    clrscr();
    printf("\t\t\t\t\t\t  Menu\n\n");
    switch(state)
    {
        case 0:
        {
            textcolor(LIGHTGREEN);
            printf("\t\t\t\t\t\t");
            cprintf("Enter Record");
            printf("\n");
            
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t");
            cprintf("Display Record");
            printf("\n");
            printf("\t\t\t\t\t\t");
            cprintf("Test2");
            printf("\n");
            printf("\t\t\t\t\t\t");
            cprintf("Exit");
            printf("\n");
            break;
        }
        case 1:
        {
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t");
            cprintf("Enter Record");
            printf("\n");
            
            
            textcolor(LIGHTGREEN);
            printf("\t\t\t\t\t\t");
            cprintf("Display Record");
            printf("\n");
            
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t");
            cprintf("Test2");
            printf("\n");
            printf("\t\t\t\t\t\t");
            cprintf("Exit");
            printf("\n");
            
            break;
        }
        case 2:
        {
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t");
            cprintf("Enter Record");
            printf("\n");
            printf("\t\t\t\t\t\t");
            cprintf("Display Record");
            printf("\n");
            
            
            textcolor(LIGHTGREEN);
            printf("\t\t\t\t\t\t");
            cprintf("Test2");
            printf("\n");
            
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t");
            cprintf("Exit");
            printf("\n");
           
            break;
        }
        case 3:
        {
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t");
            cprintf("Enter Record");
            printf("\n");
            printf("\t\t\t\t\t\t");
            cprintf("Display Record");
            printf("\n");
            printf("\t\t\t\t\t\t");
            cprintf("Test2");
            printf("\n");
            
            
            textcolor(LIGHTGREEN);
            printf("\t\t\t\t\t\t");
            cprintf("Exit");
            printf("\n");
            break;
        }
        default:
        {
            printf("TEST");
        }
    } // end switch
} // end menu()

void menu_input(void)      // This should get passed the user string as a parameter once we know who the user is
{
    char ch;
    int menu_index=0;
    
    /*
                The main menu
        */
    menu(menu_index);
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
            
            // If the user pressed enter
            if(ch == 13)
            {                
                break;
            }
            menu(menu_index);
            Sleep(40);
        } // end if kbhit()
    } // end while
} // end menu input

