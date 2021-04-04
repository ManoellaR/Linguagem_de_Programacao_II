#include "Bujo.hpp"

int main(){
    cout << "Welcome to your bullet journal!" << endl;
    /*string day;
    cout << "Please enter today's date (dd/mm/yyyy):";
    cin >> day;
    vector < string > todaysvec = split(day, '/');
    Date Today(todaysvec[0], todaysvec[1], todaysvec[2]);*/

    BulletJournal mybulletjournal;
    mybulletjournal.LoadBulletJournal();

    for(;;){
        mybulletjournal.SaveBulletJournal();

        cout << "Options:" << endl;
        cout << "1. View future log" << endl;
        cout << "2. View monthly log" << endl;
        cout << "3. View daily log" << endl;
        cout << "4. Edit an entry status" << endl;
        cout << "5. Add an entry" << endl;
        cout << "6. See description" << endl;
        cout << "7. See key" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter an option: ";
        char ch;
        cin >> ch;
        cin.ignore();

        if(ch == '1') mybulletjournal.GetFutureLog();
        if(ch == '2') mybulletjournal.GetMonthlyLog();
        if(ch == '3') mybulletjournal.GetDailylog();

        if(ch == '4'){
            size_t i;
            string newstatus;
            cout << "Collections:" << endl;
            cout << "1. Future Log" << endl;
            cout << "2. Monthly Log" << endl;
            cout << "3. Daily Log" << endl;
            cout << "Enter a collection number: ";
            cin >> ch;
            cout << "Enter the entry number: ";
            cin >> i;
            cout << "Enter the new status (task, completed, migrated, scheduled, event, note or deleted): ";
            cin.ignore();
            getline(cin, newstatus);

            if(ch == '1') mybulletjournal.SetFutureLogStatus(i, newstatus);
            if(ch == '2') mybulletjournal.SetMonthlyLogStatus(i, newstatus);
            if(ch == '3') mybulletjournal.SetDailyLogStatus(i, newstatus);
        }

        if(ch == '5'){
            Date d;
            string datestr;
            string entrystatus;
            string entry;
            cout << "Options:" << endl;
            cout << "1. Future Log" << endl;
            cout << "2. Monthly Log" << endl;
            cout << "3. Daily Log" << endl;
            cout << "Enter a collection number: ";
            cin >> ch;
            cout << "Enter the date that the entry is for(dd/mm/yyyy): ";
            cin >> datestr;
            cout << "Enter the status(task, completed, migrated, scheduled, event, note or deleted): ";
            getline(cin, entrystatus);
            cout << "Type your new entry: ";
            cin.ignore();
            getline(cin, entry);

            JournalEntry newentry;
            newentry.SetDate(datestr);
            newentry.SetStatus(entrystatus);
            newentry.SetEntry(entry);

            if(ch == '1') mybulletjournal.SetFutureLogEntry(newentry);
            if(ch == '2') mybulletjournal.SetMonthlyLogEntry(newentry);
            if(ch == '3') mybulletjournal.SetDailyLogEntry(newentry);
        }

        if(ch == '6'){
            cout << "Future Log: a year at a glance This is where events occurring in future months are shown." << endl;
            cout << "Monthly Log: a month at a glance. This minimal calendar is designed to provide a birdseye view of the month." << endl;
            cout << "Daily Log: designed for day-to-day use. This is where your Tasks, Events, and Notes for the day are shown." << endl;
        }

        if(ch == '7'){
            cout << "Key:" << endl;
            cout << "• Task - Precedes any Task you write down." << endl;
            cout << "X Task completed - Once you’ve completed a Task, mark it with a X" << endl;
            cout << "> Migrated - If you didn’t complete a Task, it Migrates to another Collection." << endl;
            cout << "< Scheduled - Tasks with specific dates in the future. These can be added to the Future Log." << endl;
            cout << "o Event - These are date-specific. You would add them to the according Collections: Future Log, Monthly Log, and Daily Log." << endl;
            cout << "- Note - Facts, ideas, thoughts, and observations. They're used to capture information or data you don't want to forget." << endl;
            cout << "# Task deleted" << endl;
        }

        if(ch == '8'){
            break;
        }
    }

    return 0;
}