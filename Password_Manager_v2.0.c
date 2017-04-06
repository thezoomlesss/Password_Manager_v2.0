/*
    Mohamad Zabad
    
    Password_Manager_v2.0
        This program will safely save  all the passwords that you enter.
*/

/*
    TO DO LIST:
        - Create the interface
        - add the key stroke functions
        - Check the indexes of the usernames and passwords for the login 
        - add the functions for each option
        - More to come...
        
        
         CRASH after unsername > 19 
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
void menu1_input(int condition);
void menu1_select(int state);
void menu(int state, int condition);   // Main menu
void menu_input(void);
int enter_record(void);

    

main()
{
    menu1_input(0);
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
void menu1_input(int condition)
{
    char ch;
    int menu_index=0;
    
    /*
                The Login menu
        */
    menu1(menu_index,0);
    while(condition != 1)
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
            else
            {
                menu1(menu_index, 0);
                Sleep(40);
            }
            
        } // end kbhit()
    } // end while() 
    
    menu(menu_index,0);
} // end menu1_input
void menu1_select(int state)
{
    FILE *fp1, *fp2;
    char username[20], name_login[20], pass[20], pass_login[20];
    bool access_name=false, access_pass=false, reg_name=false;
    int username_index=0, pass_index=0;
    switch(state)
    {
        case 0:
        {
            /*
                                Reading in the username and we make sure that it is not longer than 19 chars
                        */
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
                
                // Username too long
                while(strlen( username ) > 19 )
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
                }

                // Creating the "Access.bin" file if it doesn't already exist
                fp1= fopen("Access.bin", "r");
                if(fp1==NULL)
                {
                    fclose(fp1);
                    fp1=fopen("Access.bin","w");
                    fclose(fp1);                                                  
                    fp1=fopen("Access.bin","r");
                }
                
                /*
                                        Reading from the login list and comparing the username input to the list of logins that we have
                                */
                while(fscanf(fp1, "%s", name_login) != EOF )
                {
                    username_index++;
                    if( strcmp( name_login, username) == 0 )
                    {
                        access_name = true;
                        break;
                    }
                }
                
                // Error message for bad input
                if(access_name == false)
                {
                    textcolor(LIGHTRED);
                    printf("\t\t\t\t\t");
                    cprintf("Username unrecognized");
                    printf("\n");
                    getch();
                }
                
                
                
                // Getting and checking the password
                
                clrscr();
                printf("\n\n\t\t\t\t\t\t");
                textcolor(LIGHTCYAN);
                cprintf("Log In");
                
                textcolor(LIGHTGREEN);
                printf("\n\n\t\t\t\t\t");
                cprintf("Password"); 
                textcolor(WHITE);
                cprintf(" (max 20)");
                textcolor(LIGHTRED);
                cprintf(": ");
                scanf("%s", pass);
                flushall();
                
                while(strlen( pass ) > 19 )
                {    
                    clrscr();
                    printf("\n\n\t\t\t\t\t\t");
                    textcolor(LIGHTCYAN);
                    cprintf("Log In");
                    
                    textcolor(LIGHTRED);
                    printf("\n\n\t\t\t\t");
                    cprintf("The password can't be longer than 20 characters!");
                    textcolor(LIGHTGREEN);
                    printf("\n\t\t\t\t\t");
                    cprintf("Password: ");
                    scanf("%s", pass);
                    flushall();
                }
                
                fp2= fopen("Access2.bin", "r"); // Accesss2 is the file for the passwords
                
                if(fp2 == NULL)
                {
                    fclose(fp2);
                    fp2=fopen("Access2.bin","w");
                    fclose(fp2);                              // Creating the "Access.bin" file if it doesn't already exist
                    fp2=fopen("Access2.bin","r");
                }
                                                                                                    // MAKE THE USERNAME AND PASS CORRESPOND TO EACH OTHER
                /*
                                        Reading from the login list and comparing the username input to the list of logins that we have
                                */
                while(fscanf(fp2, "%s", pass_login) != EOF )
                {
                    pass_index++;
                    if( strcmp( pass_login, pass) == 0 )
                    {
                        access_pass = true;
                        break;
                    }
                }
                
                if(access_pass == false || username_index != pass_index)
                {
                    textcolor(LIGHTRED);
                    printf("\t\t\t\t\t");
                    cprintf("Username & password combination does not match");
                    printf("\n");
                    access_name=false;
                    access_pass=false;
                    username_index=0;
                    pass_index=0;
                    getch();
                }
                
            } while( access_name == false || access_pass == false  );
            fclose(fp1);
            fclose(fp2);
            break;
            
        } // end case 0
        
        case 1:
        {
            // Opening the files to register a new person
            
            fp1= fopen("Access.bin", "r"); 
            if(fp1 == NULL)
            {
                fclose(fp1);
                fp1=fopen("Access.bin","w");
                fclose(fp1);                              // Creating the "Access.bin" file if it doesn't already exist
                fp1=fopen("Access1.bin","r");
            }
            fp2= fopen("Access2.bin", "r"); // Accesss2 is the file for the passwords                
            if(fp2 == NULL)
            {
                fclose(fp2);
                fp2=fopen("Access2.bin","w");
                fclose(fp2);                              // Creating the "Access.bin" file if it doesn't already exist
                fp2=fopen("Access2.bin","r");
            }
            
            
            do
            {
                reg_name=false;
                clrscr();
                printf("\n\n\t\t\t\t\t\t");
                textcolor(LIGHTCYAN);
                cprintf("Register");
                
                textcolor(LIGHTGREEN);
                printf("\n\n\t\t\t\t\t");
                cprintf("Username"); 
                textcolor(WHITE);
                cprintf(" (max 20)");
                textcolor(LIGHTRED);
                cprintf(": ");
                scanf("%s", username);
                flushall();
                
                while(strlen( username ) > 19 )
                {    
                    clrscr();
                    printf("\n\n\t\t\t\t\t\t");
                    textcolor(LIGHTCYAN);
                    cprintf("Register");
                    
                    textcolor(LIGHTRED);
                    printf("\n\n\t\t\t\t");
                    cprintf("The username can't be longer than 20 characters!");
                    textcolor(LIGHTGREEN);
                    printf("\n\t\t\t\t\t");
                    cprintf("Username: ");
                    scanf("%s", username);
                    flushall();
                }
                while(fscanf(fp1, "%s", name_login) != EOF)
                {
                    if(strcmp( name_login, username) == 0)
                    {
                        reg_name=true;
                        break;
                    }
                }
                if( reg_name == true)
                {
                    textcolor(LIGHTRED);
                    printf("\t\t\t\t\t");
                    cprintf("The username is already taken. Please choose again");
                    printf("\n");
                    getch();
                }
                else
                {
                    // The pass
                    clrscr();
                    printf("\n\n\t\t\t\t\t\t");
                    textcolor(LIGHTCYAN);
                    cprintf("Register");
                    
                    textcolor(LIGHTGREEN);
                    printf("\n\n\t\t\t\t\t");
                    cprintf("Password"); 
                    textcolor(WHITE);
                    cprintf(" (max 20)");
                    textcolor(LIGHTRED);
                    cprintf(": ");
                    scanf("%s", pass);
                    flushall();
                    
                    while(strlen( pass ) > 19 )
                    {    
                        clrscr();
                        printf("\n\n\t\t\t\t\t\t");
                        textcolor(LIGHTCYAN);
                        cprintf("Register");
                        
                        textcolor(LIGHTRED);
                        printf("\n\n\t\t\t\t");
                        cprintf("The password can't be longer than 20 characters!");
                        textcolor(LIGHTGREEN);
                        printf("\n\t\t\t\t\t");
                        cprintf("Password: ");
                        scanf("%s", pass);
                        flushall();
                    }
                    
                    fclose(fp1);
                    fclose(fp2);
                    fp1= fopen("Access.bin", "a");
                    fp2= fopen("Access2.bin", "a");
                    fseek(fp1, 0, SEEK_END);
                    fseek(fp2, 0, SEEK_END);
                    clrscr();
                    fprintf(fp1, "%s\n", username);
                    fprintf(fp2, "%s\n", pass);
                    
                    textcolor(LIGHTGREEN);
                    printf("\t\t\t\t\t");
                    cprintf("Registration successful!");
                    printf("\n");
                    getch();
                
                }
                
            }while(reg_name == true); // If reg_name is true it means that the username is already taken
            
            
            fclose(fp1);
            fclose(fp2);
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
    
    menu1_input(1);
    
} // end menu1_select

void menu(int state, int condition)
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
    menu(menu_index, 0);
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
            menu(menu_index, 0);
            Sleep(40);
        } // end if kbhit()
    } // end while
} // end menu input

