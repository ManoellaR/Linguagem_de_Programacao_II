#include "dictionary.hpp"

int main(){
    Dictionary mydict;
    vector < Dictionary > myListOfDicts;

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
            if(!mydict.LoadDictionary(dictname)){
                cout << "File not found" << endl;
                return 1;
            }
            else{
                mydict.GetName(dictname);
                myListOfDicts.push_back(mydict);
            }

            continue;
        }

        if(ch == '2'){
            if(NDEBUG) cout << "Enter a substring to search: ";
            string query;
            cin >> query;
            //SearchSubstring(myListOfDicts, query);

            continue;
        }

        if(ch == '3'){
            continue;
        }

        if(ch == '4'){
            continue;
        }

        if(ch == '5'){
            break;
        }
    }

    return 0;
}