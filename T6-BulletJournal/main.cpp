#include "Bujo.hpp"




int main(){
    BulletJournal mybulletjournal;

    if(!mybulletjournal.LoadBulletJournal()){
        cout << "Failed to load" << endl;
        return 1;
    }

    string day;
    cout << "Welcome to your bullet journal!" << endl;
    cout << "Please enter today's date (dd/mm/aaaa):";
    cin >> day;
    vector < string > todaysvec = split(day, '/');
    Date Today(todaysvec[0], todaysvec[1], todaysvec[2]);


    for(;;){
        if(!mybulletjournal.SaveBulletjournal()){
            cout << "Failed to save" << endl;
            return 2;
        }

        cout << "Options:" << endl;
        cout << "1. View future log" << endl;
        cout << "2. View monthly log" << endl;
        cout << "3. View daily log" << endl;
        cout << "4. See description" << endl;
        cout << "5. See key" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter an option: ";
        char ch;
        cin >> ch;
        cin.ignore();

        if(ch == '1'){
            ShowOptions();
            cin >> ch;
            cin.ignore();
            if(ch == '1'){

            }
            if(ch == '2'){
                
            }
            if(ch == '3'){
                break;
            }
        }

        if(ch == '2'){
            ShowOptions();
            cin >> ch;
            cin.ignore();
            if(ch == '1'){

            }
            if(ch == '2'){
                
            }
            if(ch == '3'){
                break;
            }
        }

        if(ch == '3'){
            ShowOptions();
            cin >> ch;
            cin.ignore();
            if(ch == '1'){

            }
            if(ch == '2'){
                
            }
            if(ch == '3'){
                break;
            }
        }

        if(ch == '4'){
            cout << "Future Log: a year at a glance This is where events occurring in future months are shown." << endl;
            cout << "Monthly Log: a month at a glance. This minimal calendar is designed to provide a birdseye view of the month." << endl;
            cout << "Daily Log: designed for day-to-day use. This is where your Tasks, Events, and Notes for the day are shown." << endl;
        }

        if(ch == '5'){
            cout << "Key:" << endl;
            cout << "• Task - Precedes any Task you write down." << endl;
            cout << "X Task completed - Once you’ve completed a Task, mark it with a X" << endl;
            cout << "> Migrated - If you didn’t complete a Task, it Migrates to another Collection." << endl;
            cout << "< Scheduled - Tasks with specific dates in the future. These can be added to the Future Log." << endl;
            cout << "o Event - These are date-specific. You would add them to the according Collections: Future Log, Monthly Log, and Daily Log." << endl;
            cout << "- Note - Facts, ideas, thoughts, and observations. They're used to capture information or data you don't want to forget." << endl;
            cout << "# Task deleted" << endl;
        }

        if(ch == '6'){
            break;
        }

    return 0;
}