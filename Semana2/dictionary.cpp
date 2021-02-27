#include "dictionary.hpp"

bool LoadDictionary(string path, vector< string > &wordlist)
{
    //this is a ifstream instance to read our dictionary file
    ifstream filereader;
    filereader.open(path);
    
    if(filereader.is_open() == false)
        return false;
    
    //reading list of words
    string tmp;
    while(getline(filereader, tmp))
    {
        //cout << tmp << endl;
        wordlist.push_back(tmp);
    }
        
    wordlist.erase(wordlist.begin()+0);
    
    return true;
} 

bool SearchString(const vector< string > &wordlist, string query){
    for(size_t i=0; i<wordlist.size(); i++){
        string word = wordlist.at(i);
        if(word == query)
            return true;
    }
    return false;
}

vector< string > SearchSubstrings(const vector< string > &wordlist, string query){
    vector< string > substrlist;
    for(size_t i=0; i < wordlist.size(); i++){
        string word = wordlist.at(i);
        size_t pos = word.find(query);
        if(pos < word.length()){
            substrlist.push_back(word);
        }
    }
    return substrlist;
}