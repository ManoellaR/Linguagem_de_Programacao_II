#include "dictionary.hpp"

Dictionary::Dictionary(){
    cout << "Hello, I'm a constructor method" << endl;
    m_path = " ";
}

Dictionary::~Dictionary(){
    cout << "Hello I'm a destructor method" << endl;
    m_listofwords.clear();
}

void Dictionary::Initialize()
{
    m_listofwords.clear();
}

bool Dictionary::LoadDictionary(string path)
{
    Initialize();    
    ifstream filereader;
    filereader.open(path);
    
    if(filereader.is_open() == false) return false;
    
    //reading list of words
    string tmp;
    while(getline(filereader, tmp))
    {
        m_listofwords.push_back(tmp);
    }        
    m_listofwords.erase(m_listofwords.begin()+0);     
    filereader.close();

    m_path = path;
   
    return true;
}

string Dictionary::GetWord(size_t index)
{
    string str;
    if(index >= m_listofwords.size())
    {
        return str;
    }
    str = m_listofwords.at(index);    
    return str;
}

bool Dictionary::RemoveWord(size_t index)
{
    if(index >= m_listofwords.size())
    {
        return false;
    }
    m_listofwords.erase(m_listofwords.begin()+index);
    return true;
}

bool Dictionary::RemoveWord(size_t index1, size_t index2)
{
    if(index1 > index2) return false;
    if(index1 < 0) return false;
    
    if(index2 >= m_listofwords.size())
    {
        return false;
    }
    
    m_listofwords.erase(m_listofwords.begin()+index1, m_listofwords.begin()+index2+1);
    return true;
}
