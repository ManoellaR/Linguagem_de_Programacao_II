#include "dictionary.hpp"

int main(){

    vector < vector < string > > listOfDicts;
    vector<string> listOfDictsNames;

    for(; ;){
        if(NDEBUG) cout << "DICTIONARY MANIPULATOR HACK" << endl;
        if(NDEBUG) cout << "Select an option:" << endl;
        if(NDEBUG) cout << "1. Open Dictionary…" << endl;
        if(NDEBUG) cout << "2. Search Substrings..." << endl;
        if(NDEBUG) cout << "3. Remove Words Containing Substring..." << endl;
        if(NDEBUG) cout << "4. Show Statistics" << endl;
        if(NDEBUG) cout << "5. Exit" << endl;
        if(NDEBUG) cout << "6. Show all dictionaries" << endl;

        if(NDEBUG) cout << "Option: ";
        char ch;
        cin >> ch;

        if(ch == '1'){
            if(NDEBUG) cout << "Enter a dictionary file: ";
            string dictname;
            cin >> dictname;
            vector< string > wordlist;
            if(!LoadDictionary(dictname, wordlist)){
                if(NDEBUG) cout << "Error, file not found" << endl;
            }
            else{
                listOfDicts.push_back(wordlist);
                listOfDictsNames.push_back(dictname);
            }

            continue;
        }
        if(ch == '2'){
            if(NDEBUG) cout << "Enter a substring to search: ";
            string query;
            cin >> query;
            vector <string> list = SearchSubstrings(listOfDicts, query);
            for(size_t i=0; i<list.size(); i++){
                cout << list.at(i) << endl;
            }

            continue;
        }
        if(ch == '3'){
            if(NDEBUG) cout << "Enter a substring to remove all occurrences: ";
            string removequery;
            cin >> removequery;
            RemoveSubstring(removequery, listOfDicts);
            
            continue;
        }
        if(ch == '4'){
            cout << "Statistics" << endl;
            for(size_t i=0; i<listOfDicts.size(); i++){
                cout << listOfDictsNames.at(i) << " -> " << listOfDicts.at(i).size() << " words" << endl;
            }
            
            continue;
        }
        if(ch == '5')
            break;
        
        if(ch == '6'){
            if (NDEBUG) cout << "Show all dictionaries" << endl;
            for(size_t i=0; i<listOfDicts.size(); i++){
                if (NDEBUG) cout << "Dict name: " << listOfDictsNames.at(i) << endl;
                for(size_t j=0; j<listOfDicts.at(i).size(); j++){
                    if(NDEBUG) cout << "  " << j << "  " << listOfDicts.at(i).at(j) << " -> " << listOfDicts.at(i).at(j).length() << endl;
                }
            }
        }
    }

    return 0;
}