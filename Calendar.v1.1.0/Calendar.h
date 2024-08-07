#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

using namespace std;

// Calendar Display Flipper -- ThatMatthewFellow

enum eDir{
    NONE = 0,
    LEFT,
    RIGHT
};

class Calendar{
public:
    // Initialize all months with days
    Calendar(){
        allMonths = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        cal[allMonths[0]] = 31;
        cal[allMonths[1]] = 29;
        cal[allMonths[2]] = 31;
        cal[allMonths[3]] = 30;
        cal[allMonths[4]] = 31;
        cal[allMonths[5]] = 30;
        cal[allMonths[6]] = 31;
        cal[allMonths[7]] = 31;
        cal[allMonths[8]] = 30;
        cal[allMonths[9]] = 31;
        cal[allMonths[10]] = 30;
        cal[allMonths[11]] = 31;
        curMonth = 0;
        days = 0;
        month = "";
        quitCal = false;
        directionProcessed = true;
    }

    // Display the calendar
    void Draw(){
        system("cls");
        // The current month and days of that month
        month = allMonths[curMonth];
        days = cal.at(month);

        // Output the month this calendar is for
        cout << endl;
        cout << setw(14) << month << endl << endl;

        // Output the calendar month
        for (int i = 1; i <= days; ++i){
            cout << setw(3) << i;
            if (i % 7 == 0) { // End of the week
                cout << endl;
            }
        }
        cout << endl << endl;
        
        // Draw little arrows under the calendar
        cout << setw(10) << "<--" << setw(5) << "-->" << endl;

    }

    void Input(){
        if (_kbhit()){
            switch (getch()){
                case 75: // Left arrow key
                    if(directionProcessed){
                        Direction = RIGHT;
                        directionProcessed = false;
                    }
                    break;
                case 77: // Right arrow key
                    if(directionProcessed){
                        Direction = LEFT;
                        directionProcessed = false;
                    }
                    break;
                case 'q':
                    quitCal = true;
                    break;
            }
        } 
        else{
            directionProcessed = true; // Reset flag if no key is pressed
        }
    }

    void Logic(){
        // Switching between months
        switch (Direction){
            case LEFT:
                curMonth = (curMonth + 1) % allMonths.size();
                break;
            case RIGHT:
                curMonth = (curMonth - 1 + allMonths.size()) % allMonths.size();
                break;
            default:
                break;
        }
        Direction = NONE; // Reset direction after processing
    }

    void Run(){
        while (!quitCal){
            Draw();
            Input();
            Logic();
            Sleep(125);
        }
        system("pause");
    }

private:
    map<string, int> cal;        // All months tied with their amount of days
    vector<string> allMonths;   // All names of months
    string month;               // The month name
    int days;                   // The days of that month
    int curMonth;               // The number of that month
    eDir Direction;             // A direction for input
    bool quitCal;               // A bool to quit the program
    bool directionProcessed;    // Flag to check if direction has been processed
};