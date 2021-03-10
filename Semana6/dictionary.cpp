#include "dictionary.hpp"

void Dictionary::Initialize(){
    m_listofwords.clear();
}

bool Dictionary::LoadDictionary(string path){
    Initialize();

    ifstream filereader;
    filereader.open(path);
    if(filereader.is_open() == false){
        return false;
    }

    string tmp;
    while(getline(filereader, tmp)){
        m_listofwords.push_back(tmp);
    }

    m_listofwords.erase(m_listofwords.begin()+0);

    filereader.close();
    
    return true;
}

string Dictionary::GetWord(size_t index){
    string str;
    if(index  >= m_listofwords.size()){
        return str;
    }
    str = m_listofwords.at(index);
    return str;
}

bool Dictionary::RemoveWord(size_t index){
    if(index >= m_listofwords.size()){
        cout << "Out of range" << endl;
        return false;
    }
    m_listofwords.erase(m_listofwords.begin()+index);

    return true;
}

bool Dictionary::RemoveWord(size_t indexbegin, size_t indexend){
    if(indexbegin > indexend){
        return false;
    }
    if((indexbegin < 0) || (indexend >= m_listofwords.size())){
        cout << "Out of range" << endl;
        return false;
    }
    m_listofwords.erase(m_listofwords.begin()+indexbegin, m_listofwords.begin()+indexend);
    return true;
}

void Dictionary::GetName(string name){
    m_name == name;
}

//ARRUAMR!!!!
bool SearchSubstring(const vector < Dictionary > &myListOfDicts, string query){
    for(size_t i=0; i < myListOfDicts.size(); i++){
        for (size_t j = 0; j < myListOfDicts.at(i).m_listofwords.size(); j++){
            size_t pos = myListOfDicts.at(i).m_listofwords.at(j).find(query);

            if(pos < myListOfDicts.at(i).m_listofwords.at(j).length()){
                cout << myListOfDicts.at(i).m_listofwords.at(j) << endl;
            }
        }
    }
    return true;
}