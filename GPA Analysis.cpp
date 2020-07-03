/*
Oleg Kolesnikov
GPA Analysis
21SEP2019
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std ;

// Function Prototype
int userInput ( int ) ;
void printScores( int * , int ) ;
int computeGpa ( int * , int ) ;
void printLetterGrade ( int ) ;
void studentId ( ) ;
void sort ( int* , int ) ;
void to_TextFile (int * , int );

// Specification A1 - OOP
class Student
{
public:
string Student_ID;
void display_studentId (string Student_ID);
};

int main ( )
{
    int MAXSCORE = 100 ; //this variable stores the value 100 for the maximum possible allows to be entered
    int SIZE = 1 ;// this variable sets the size of the scores  array
    int counter =0 ;// this variable counts the number of scores the user enteres into to dynamicly allocated array
    int Gpa = 0 ; // this variable stores the average of all scores entered by the user
    int score = 0 ; // this variable stores the individual scores the user enters

    // Program Greeting
    cout << "Welcome to the GPA Analysis!" << endl ;

    Student studentObject;

    cout << "Student ID : " ;
    cin >> studentObject.Student_ID ;
    studentObject.display_studentId(studentObject.Student_ID);

    // Specification B1 - Dynamic Array
    // Specification C1 - REPLACED
    int * scores ;// this is a pointer termed array
    scores = new int [ SIZE ] ;// This is a dynamicly allocated array with the size of equal to 1 when initialized

    for (int i = 0 ; i < SIZE ; i++ )
    {
        score = userInput ( MAXSCORE ) ;

        // after the user enters a valid value for the score the size of the dynamily allocated array  is increased by 1.
        SIZE++ ;

        if ( score == -1 )
        {
            counter = i ;
            break ;
        }

        scores [ i ] = score ;
    }

    sort ( scores , counter ) ;

    printScores ( scores , counter ) ;

    Gpa = computeGpa ( scores , counter ) ;
    cout << " GPA :" << Gpa ;

    printLetterGrade( Gpa ) ;

    to_TextFile ( scores , counter );

    delete [ ] scores ;

    return 0 ;
}


void Student::display_studentId (string Student_ID)
//this member function promps user to enter the student ID then verifies it meets requiresment befor displaying onto the screen.
{
    //Specification B2 - Validate Student ID
    if ( Student_ID.length() == 8 && Student_ID [ 7 ] % 2 == 0 )
    {
        if ( Student_ID [ 0 ] == '1' && Student_ID[1] == '2' && Student_ID[2] == '7' )
            cout << "User ID Verified!"<<endl;


        if ( Student_ID [ 0 ] == '3' && Student_ID[ 1 ] == '7' && Student_ID [ 2 ] == '9' )
            cout << "User ID Verified!"<<endl;


        if ( Student_ID [ 0 ] == '8' && Student_ID[1] == '3' && Student_ID[2] == '3' )
            cout << "User ID Verified!" << endl ;

    }

    else
    {
        cout << "Invalid Student ID. Good-Bye! " << endl ;
        exit ( EXIT_FAILURE ) ;
    }

}

int userInput ( int MAXSCORE )
//this function prompts the user to enter a score and verifies it to be between 0 and 100. If not within  specified range the user is re-prompted . Function return the users input only until the value is within a specific range
{
    string input ;//// this variable stores the user input and returns it to the main function
    int num ;

    cout << "Enter Score :" ;
    cin >> input ;

    if ( input == "calc" )
    {
        return -1 ;
    }

    num = stoi ( input ) ;

    if ( num >= 0 && num <= MAXSCORE )
    {
        return num ;
    }

    else
    {
        // Specification C4 - Validate Test Scores
        while ( num < 0 || num > MAXSCORE )
        {
            cout << "Invalid Input. Please enter a number between 0 and 100 :" ;
            cin >> num ;
        }

        return num ;
    }

}

void printScores(int * scores , int SIZE )
//this function displays the scores entered into an array
{
    int num ;// this variable stores an element from the scores array and passes it to the printLetterGrade function

    cout << endl ;
    cout << "#\tScore\tGrade" << endl ;

    // Specification C2 - Print Scores
    for (int i = 0 ; i <= SIZE - 1 ; i++ )
    {
        num = scores [ i ] ;

        cout << i + 1 << "\t" << scores [ i ] << "\t" ;

        // Specification B3 - Letter Grades
        // Code below displays letter grade for each individual test score
        printLetterGrade ( num ) ;
        cout << endl ;
    }

}

int computeGpa ( int * scores , int SIZE )
// Compute the average grade for the client and display it.
{
    int Gpa = 0 ;
    int sum = 0 ;

    // Specification C3 - Compute GPA
    for (int i = 0 ; i <= SIZE - 1 ; i++ )
    {
        sum += scores [ i ] ;
    }

    Gpa = sum / SIZE ;
    return Gpa ;
}

void printLetterGrade( int num )
//This function takes in a value and displays a letter grade for the GDP or a individual score.
{
    // Specification C5 - Print Letter Grade
    if (num <= 100 && num >= 90 )
   {
       cout << " A";
   }
    if (num <= 89 && num >= 80 )
   {
       cout << " B";
   }
    if (num <= 79 && num >= 70 )
   {
       cout << " C";
   }
    if (num <= 69 && num >= 60 )
   {
       cout << " D";
   }
    if (num <= 59 && num >= 0 )
   {
       cout << " F";
   }
}


void sort ( int * scores , int SIZE )
// This function sorts the scores array from highest to lowest
{
    int max;// this variable stores the highest value

    // Specification A2 - Sort Grades
    for ( int i = 0; i < SIZE ; i++ )
    {
        max = i ;

        for ( int j = i + 1 ; j < SIZE ; j++ )
        {
            if ( scores [ max ] < scores [ j ] )
            // if the initial element is less then the the preceeding element then the max variable is updated
            {
                max = j ;
            }

        }

        if ( max != i )
        //this code swaps the greater element in the array with the smaller element
        {
            int temp = scores [ i ] ;
            scores [ i ] = scores[ max ] ;
            scores [ max ] = temp ;
        }

    }

}

void to_TextFile (int * scores , int SIZE)
// This function creats a text file called GPA_Analysis.txt. A Header file  and students individual scores are uploaded to the text file.
{


    // Specification A3 - Logfile
    //code below specified the name of the text file that will created and data uploaded to.
    ofstream myfile ("GPA_Analysis.txt");

    if (myfile.is_open ( ) )
    {
        //code below uploads the  authors name, class, assignment number, date, and prefessors name.
        myfile << "Oleg Kolesnikov\nCISP 400\nAssignment 2 : GPA Analysis\n21SEP2019\nProfessor: Caleb Fowler\n";



        //code below
        myfile <<"#\tScore\tGrade" << endl ;
        for ( int i = 0 ; i < SIZE ; i ++ )
        {

            myfile << i+1 << "\t" << scores [ i ] << "\t\t" << "\n"  ;
        }

        myfile.close ( ) ;
    }

    else
    {
        cout << "Unable to open file";
    }

}
