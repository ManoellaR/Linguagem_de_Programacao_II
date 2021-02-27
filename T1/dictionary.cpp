#include "dictionary.hpp"

bool LoadDictionary(string path, vector< string > &wordlist){
    ifstream filereader;
    filereader.open(path);
    
    if(filereader.is_open() == false)
        return false;
    
    string tmp;
    while(getline(filereader, tmp)){
        wordlist.push_back(tmp);
    }
        
    wordlist.erase(wordlist.begin()+0);
    
    return true;
}

vector< string > SearchSubstrings(const vector < vector < string > > &wordlist, string query){
    vector< string > substrlist;
    for(size_t i=0; i < wordlist.size(); i++){
        for (size_t j = 0; j < wordlist.at(i).size(); j++){
            size_t pos = wordlist.at(i).at(j).find(query);

            if(pos < wordlist.at(i).at(j).length()){
                substrlist.push_back(wordlist.at(i).at(j));
            }
        }
    }
    return substrlist;
}

bool RemoveSubstring(string query, vector < vector<string> >  &listOfDicts){
    for(size_t i=0; i<listOfDicts.size(); i++){
        size_t j = 0;
        while(j < listOfDicts.at(i).size()){
            size_t pos = listOfDicts.at(i).at(j).find(query);
            if(pos < listOfDicts.at(i).at(j).length()){
                listOfDicts.at(i).erase(listOfDicts.at(i).begin() + j);
            }
            else{
                j++;
            }
        }
    }
    return true;
}