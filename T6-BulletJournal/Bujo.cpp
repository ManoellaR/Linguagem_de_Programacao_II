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

struct monthcomp{
    inline bool operator()(const JournalEntry &e1, const JournalEntry &e2){
        Date a, b;
        a = e1.GetDate();
        b = e2.GetDate();

        return a.GetMonth() < b.GetMonth();
    }
};

struct daycomp{
    inline bool operator()(const JournalEntry &e1, const JournalEntry &e2){
        Date a, b;
        a = e1.GetDate();
        b = e2.GetDate();

        return a.GetDay() < b.GetDay();
    }
};

//JOURNAL ENTRY CLASS METHODS
void JournalEntry::SetDate(string date){
    vector < string > str;
    str = split(date, '/');
    m_date.SetDay(str[0]);
    m_date.SetMonth(str[1]);
    m_date.SetYear(str[2]);
}

void JournalEntry::SetStatus(string status){
    if(status == "none") m_status = none;
    if(status == "task") m_status = task;
    if(status == "completed") m_status = completed;
    if(status == "migrated") m_status = migrated;
    if(status == "scheduled") m_status = scheduled;
    if(status == "event") m_status = event;
    if(status == "note") m_status = note;
    if(status == "deleted") m_status = deleted;
}

string JournalEntry::ShowDate(){
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

//BULLET JOURNAL CLASS METHODS
void BulletJournal::GetFutureLog(){
    for(size_t i=0; i<m_futurelog.size(); i++){
        cout << "[" << i << "]  " << m_futurelog[i].ShowDate() << " " << m_futurelog[i].ShowEntry() << endl;
    }
}

void BulletJournal::GetMonthlyLog(){
    for(size_t i=0; i<m_monthlylog.size(); i++){
        cout << "[" << i << "]  " << m_futurelog[i].ShowDate() << " " << m_monthlylog[i].ShowEntry() << endl;
    }
}

void BulletJournal::GetDailylog(){
    for(size_t i=0; i<m_dailylog.size(); i++){
        cout << "[" << i << "]  " << m_dailylog[i].ShowEntry() << endl;
    }
}

void BulletJournal::SortFutureLog(){
    sort(m_futurelog.begin(), m_futurelog.end(), monthcomp());
}

void BulletJournal::SortMonthlyLog(){
    sort(m_futurelog.begin(), m_futurelog.end(), daycomp());
}

bool BulletJournal::LoadBulletJournal(){
    ifstream fileReader("database.dat");
    
    if(!fileReader.is_open()){
        cout << "Failed to open file while loading" << endl;
        return false;
    }

    string tmp;
    JournalEntry entry;
    while(getline(fileReader, tmp)){
        if(tmp == "F"){
            getline(fileReader, tmp);
            entry.SetDate(tmp);
            getline(fileReader, tmp);
            entry.SetStatus(tmp);
            getline(fileReader, tmp);
            entry.SetEntry(tmp);
            m_futurelog.push_back(entry);
        }
        if(tmp == "M"){
            getline(fileReader,tmp);
            entry.SetDate(tmp);
            getline(fileReader, tmp);
            entry.SetStatus(tmp);
            getline(fileReader, tmp);
            entry.SetEntry(tmp);
            m_monthlylog.push_back(entry);
        }
        if(tmp == "D"){
            getline(fileReader,tmp);
            entry.SetDate(tmp);
            getline(fileReader, tmp);
            entry.SetStatus(tmp);
            getline(fileReader, tmp);
            entry.SetEntry(tmp);
            m_dailylog.push_back(entry);
        }
    }
    return true;
}

bool BulletJournal::SaveBulletJournal(){
    ofstream fileWriter("database.dat");

    if(!fileWriter.is_open()){
        cout << "Failed to open file while saving" << endl;
        return false;
    }
    
    SortFutureLog();
    SortMonthlyLog();

    for(size_t i=0; i<m_futurelog.size(); i++){
        fileWriter << "F" << endl;
        fileWriter << m_futurelog[i].ShowDate() << endl;
        fileWriter << m_futurelog[i].GetStatus() << endl;
        fileWriter << m_futurelog[i].GetEntry() << endl;
    }
    for(size_t i=0; i<m_monthlylog.size(); i++){
        fileWriter << "M" << endl;
        fileWriter << m_monthlylog[i].ShowDate() << endl;
        fileWriter << m_futurelog[i].GetStatus() << endl;
        fileWriter << m_monthlylog[i].GetEntry() << endl;
    }
    for(size_t i=0; i<m_dailylog.size(); i++){
        fileWriter << "D" << endl;
        fileWriter << m_dailylog[i].ShowDate() << endl;
        fileWriter << m_futurelog[i].GetStatus() << endl;
        fileWriter << m_dailylog[i].GetEntry() << endl;
    }
    fileWriter.close();
    return true;
}