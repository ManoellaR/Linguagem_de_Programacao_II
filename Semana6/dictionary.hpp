#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#define NDEBUG 1 // dev=1 release=0

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Dictionary{
//atributos
private:
    vector <string> m_listofwords;
    string m_name;

//metodos
private:
    void Initialize();

public:
    //load a dictionary file
    bool LoadDictionary(string path);

    //get the number of words in a loaded dictionary
    size_t GetSize() const {return m_listofwords.size(); };
    
    //get name of dictionary
    void GetName(string name);

    //return an specific word with idnex i
    string GetWord(size_t index);

    //include new word
    void SetWord(string word) {m_listofwords.push_back(word); };

    //remove an word with indec i
    bool RemoveWord(size_t index);
    bool RemoveWord(size_t indexbegin, size_t indexend);

};

//search for a substring
bool SearchSubstring(const vector < Dictionary > &dictlist, string query);

#endif