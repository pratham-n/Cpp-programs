//include required libraries
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
using namespace std;

int main()
{
	FILE *fptr, *ft; //file pointers to open the required files
	
	char another, choice;
	
	//creating a structure to store student info
	struct student
    {
        char first_name[50], last_name[50], course[100], section[10], grade[10];
    }stud;
    
    char nfirst_name[50], nlast_name[50];
    long int rec_size;
    
    //opening the .bin file for storing the info
    fptr = fopen("Students.bin","rb+");

    if (fptr == NULL)
    {
        fptr = fopen("Students.bin","wb+");

        if (fptr == NULL)
        {
            puts("Unable to open file!");
            return 0;
        }
    }
    
    //assigning the size of the structure variable to the record size variable
    rec_size = sizeof(stud);
    
    //designing a switch case for the user interface
    while(1)
    {
        system("cls"); //clearing the screen

        cout << "\t\t****** STUDENT DATABASE MANAGEMENT SYSTEM ******";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Add    Records";
        cout << "\n \t\t\t 2. List   Records";
        cout << "\n \t\t\t 3. Modify Records";
        cout << "\n \t\t\t 4. Delete Records";
        cout << "\n \t\t\t 5. Exit   Program";
        cout << "\n\n";
        cout << "\t\t\t Input Your Choice ==> ";
        fflush(stdin);  /*While taking an input string with spaces, 
						the buffer does not get cleared for the next input and 
						considers the previous input for the same. To solve
						this problem we use fflush*/
        choice = getche();
        
		switch(choice)
        {
        //adding records to the database
        case '1' :
            fseek(fptr , 0, SEEK_END); //seeks the pointer to the file end
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter the First Name : ";
                cin >> stud.first_name;
                cout << "Enter the Last Name : ";
                cin >> stud.last_name;
                cout << "Enter the Course    : ";
                cin >> stud.course;
                cout << "Enter the Section   : ";
                cin >> stud.section;
                fwrite(&stud, rec_size, 1, fptr);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        
        //viewing the records already entered
        case '2':
            system("cls");
            rewind(fptr);
            cout << "\t\t***** DATABASE RECORDS *****";
            cout << "\n";
            while (fread(&stud, rec_size, 1, fptr) == 1)
            {
                cout << "\n";
                cout <<"\nFirst Name: " << stud.first_name <<"\nLast name: "<< stud.last_name;
                cout <<"\nCourse: " << stud.course << "\nSection: "<<stud.section;
            }
            cout << "\n\n";
            system("pause"); //pauses the console to view the output
            break;
            
        //code to modify pre-existing records  
        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student : ";
                cin >> nlast_name;

                rewind(fptr);
                while (fread(&stud, rec_size, 1, fptr) == 1)
                {
                    if (strcmp(stud.last_name, nlast_name) == 0)
                    {
                        cout << "Enter new the First Name : ";
                        cin >> stud.first_name;
                        cout << "Enter new the Last Name : ";
                        cin >> stud.last_name;
                        cout << "Enter new the Course    : ";
                        cin >> stud.course;
                        cout << "Enter new the Section   : ";
                        cin >> stud.section;
                        fseek(fptr, - rec_size, SEEK_CUR);//brings the pointer to the location of that student
                        fwrite(&stud , rec_size, 1, fptr);
                        break;
                    }
                    else
                        cout<<"Record not found!";  //if record doesn't exist
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
            
        //code to delete the record
        case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student to delete : ";
                cin >> nlast_name;

                ft = fopen("temp.bin", "wb");

                rewind(fptr);
                while (fread (&stud, rec_size, 1, fptr) == 1)

                    if (strcmp(stud.last_name,nlast_name) != 0)
                    {
                        fwrite(&stud, rec_size, 1, ft);
                    }
                fclose(fptr);
                fclose(ft);
                remove("users.bin");
                rename("temp.bin","users.bin");

                fptr = fopen("users.bin","rb+");
				cout<<"\n\tRECORD DELETED";
                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
            
        //code to exit the software    
        case '5':
            fclose(fptr);
            cout << "\n\n";
            cout << "\t\t     THANK YOU FOR USING MY DBMS SOFTWARE";
            cout << "\n\n";
            exit(0);
        }
    }

    system("pause");
    return 0;
}

