#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Dictionary{
//atributos
private:
    vector <string> m_listofwords;

//metodos
private:
    void Initialize();

public:
    //load a dictionary file
    bool LoadDictionary(string path);

    //get the number of words in a loaded dictionary
    size_t GetSize() const {return m_listofwords.size(); };

    //include new word
    void SetWord(string word) {m_listofwords.push_back(word); };

    //return an specific word with idnex i
    string GetWord(size_t index);

    //remove an word with indec i
    bool RemoveWord(size_t index);
    bool RemoveWord(size_t indexbegin, size_t indexend);
};

#endif