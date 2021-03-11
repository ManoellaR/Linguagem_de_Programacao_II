#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Dictionary
{
//atributos
private:
    vector<string> m_listofwords;
    
//methods
private:
    void Initialize();
    
public:
    //load a dictionary file
    bool LoadDictionary(string path);

    //get the number of words in a loaded dictionary
    size_t GetSize() const { return m_listofwords.size(); };
    
    //include new words
    void SetWord(string word) { m_listofwords.push_back(word); };
    
    //return a specific word with index i
    string GetWord(size_t index);
    
    //remove a word with index i
    bool RemoveWord(size_t index);
    bool RemoveWord(size_t indexbegin, size_t indexend);
};

#endif
