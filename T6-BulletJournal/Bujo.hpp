#ifndef BUJO_HPP
#define BUJO_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

vector < string > split(const string& s, char delimiter);

enum Status {none, task, completed, migrated, scheduled, event, note, deleted};

class Date{
private:
    string m_day, m_month, m_year;
public:
    Date() : m_day(" "), m_month(" "), m_year(" ") {};
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
    JournalEntry() : m_entry(" "), m_status(none), m_date() {};
    JournalEntry(Date date, Status type, string entry) : m_date(date), m_status(type), m_entry(entry) {};
    void SetDate(string d, string m, string y);
    void SetDate(string date);
    void SetStatus(Status status){m_status = status; };
    void SetStatus(string status);
    void SetEntry(string entry){ m_entry = entry; };
    Date GetDate() const { return m_date; };
    Status GetStatus() const { return m_status; };
    string GetEntry() const { return m_entry; };
    string ShowDate();
    string ShowEntry();
};

class BulletJournal : public JournalEntry{
private:
    vector < JournalEntry > m_futurelog;
    vector < JournalEntry > m_monthlylog;
    vector < JournalEntry > m_dailylog;
public:
    void SetFutureLogEntry(JournalEntry entry){ m_futurelog.push_back(entry); };
    void SetMonthlyLogEntry(JournalEntry entry){ m_monthlylog.push_back(entry); };
    void SetDailyLogEntry(JournalEntry entry){ m_dailylog.push_back(entry); };
    void SetFutureLogStatus(size_t i, string status){m_futurelog[i].SetStatus(status); };
    void SetMonthlyLogStatus(size_t i, string status){m_monthlylog[i].SetStatus(status); };
    void SetDailyLogStatus(size_t i, string status){m_dailylog[i].SetStatus(status); };
    void GetFutureLog();
    void GetMonthlyLog();
    void GetDailylog();
    void SortFutureLog();
    void SortMonthlyLog();
    void SortDailyLog();
    bool LoadBulletJournal();
    bool SaveBulletJournal();
    void operator < (JournalEntry newentry){ SetFutureLogEntry(newentry); };
    void operator > (JournalEntry newentry){ SetMonthlyLogEntry(newentry); };
    void operator - (JournalEntry newentry){ SetDailyLogEntry(newentry); };    
};

#endif