#include "Bujo.hpp"

//FUNCTIONS
vector<string> split(const string& s, char delimiter){
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter)){
      tokens.push_back(token);
   }
   return tokens;
}

void ShowOptions(){
    cout << endl << "Options:" << endl;
    cout << "1. Edit a entry status" << endl;
    cout << "2. Add an entry" << endl;
    cout << "3. Go back to menu" << endl;
    cout << "Enter an option: ";
}

//JOURNAL ENTRY CLASS METHODS
void JournalEntry::SetDate(vector < string > array){
    m_date.SetDay(array[0]);
    m_date.SetMonth(array[1]);
    m_date.SetYear(array[2]);
}

string JournalEntry::GetDate(){
    stringstream sst;
    sst << m_date.GetDay() << "/" << m_date.GetMonth() << "/" << m_date.GetYear();
    return sst.str();
}

string JournalEntry::ShowEntry(){
    stringstream sst;
    if(m_status == none) sst << "NULL";
    if(m_status == task) sst << "• " << m_entry;
    if(m_status == completed) sst << "X " << m_entry;
    if(m_status == migrated) sst << "> " << m_entry;
    if(m_status == scheduled) sst << "< " << m_entry;
    if(m_status == event) sst << "o " << m_entry;
    if(m_status == note) sst << "- " << m_entry;
    if(m_status == deleted) sst << "#" << m_entry;

    return sst.str();
}

void JournalEntry::EditEntryStatus(JournalEntry entry, string newstatus){
    if(newstatus == ""){
        //TERMINAR!!!
    }
}

//BULLET JOURNAL CLASS METHODS
bool BulletJournal::LoadBulletJournal(){
    ifstream fileReader("database.dat");
    
    if(!fileReader.is_open()){
        cout << "Failed to open file while loading" << endl;
        return false;
    }

    string tmp;
    JournalEntry entry;
    vector < string > tempvec;
    while(getline(fileReader, tmp)){
        if(tmp == "FutureLog"){
            getline(fileReader, tmp);
            tempvec = split(tmp, '/');
            entry.SetDate(tempvec);
            getline(fileReader, tmp);
            entry.SetStatus(tmp);
            getline(fileReader, tmp);
            entry.SetEntry(tmp);
            //TERMINAR!!!
        }
        if(tmp == "MonthlyLog"){
            //TERMINAR!!!
        }
        if(tmp == "DailyLog"){
            //TERMINAR!!!
        }
    }
    
    return true;
}

bool BulletJournal::SaveBulletjournal(){
    ofstream fileWriter("database.dat");

    if(!fileWriter.is_open()){
        cout << "Failed to open file while saving" << endl;
        return false;
    }
    //ORGANIZAR O FUTURELOG POR MÊS E O MONTHLYLOG POR DIA
    fileWriter << "FutureLog" << endl;
    for(size_t i=0; i<m_futurelog.size(); i++){
        fileWriter << m_futurelog[i].GetDate() << endl << m_futurelog[i].GetStatus() <<endl << m_futurelog[i].GetEntry() << endl;
    }
    fileWriter << "MonthlyLog" << endl;
    for(size_t i=0; i<m_monthlylog.size(); i++){
        fileWriter << m_monthlylog[i].GetDate() << endl << m_futurelog[i].GetStatus() <<endl << m_monthlylog[i].GetEntry() << endl;
    }
    fileWriter << "DailyLog" << endl;
    for(size_t i=0; i<m_dailylog.size(); i++){
        fileWriter << m_dailylog[i].GetDate() << endl << m_futurelog[i].GetStatus() <<endl << m_dailylog[i].GetEntry() << endl;
    }
    fileWriter.close();
    return true;
}