#ifndef BUJO_HPP
#define BUJO_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector < string > split(const string& s, char delimiter);
void ShowOptions();

enum Status {none, task, completed, migrated, scheduled, event, note, deleted};

class Date{
private:
    string m_day, m_month, m_year;
public:
    Date() : m_day(0), m_month(0), m_year(0) {};
    Date(string d,string m,string y) : m_day(d), m_month(m), m_year(y) {};
    void SetDay(string d){ m_day = d; };
    void SetMonth(string m){ m_month = m; };
    void SetYear(string y){ m_year = y; };
    string GetDay() const { return m_day; };
    string GetMonth() const { return m_month; };
    string GetYear() const { return m_year; };
};

class JournalEntry{
private:
    Date m_date;
    Status m_status;
    string m_entry;
public:
    JournalEntry() : m_entry(" "), m_status(none), m_date(0,0,0) {};
    JournalEntry(Date date, Status type, string entry) : m_date(date), m_status(type), m_entry(entry) {};
    void SetDate(vector < string > array);
    void SetStatus(Status status){m_status = status; };
    void SetEntry(string entry){ m_entry = entry; };
    string GetDate();
    Status GetStatus() const { return m_status; };
    string GetEntry() const { return m_entry; };
    string ShowEntry();
    void EditEntryStatus(JournalEntry entry, string newstatus);
};

class BulletJournal : public JournalEntry{
private:
    vector < JournalEntry > m_futurelog;
    vector < JournalEntry > m_monthlylog;
    vector < JournalEntry > m_dailylog;
public:
    bool LoadBulletJournal();
    bool SaveBulletjournal();
};

#endif