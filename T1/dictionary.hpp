#include <iostream>
#include <fstream> 
#include <vector>

#define NDEBUG 0 // dev = 1 release = 0

using namespace std;

bool LoadDictionary(string path, vector< string > &wordlist);
vector< string > SearchSubstrings(const vector < vector < string > > &wordlist, string query);
bool RemoveSubstring(string removequery, vector < vector<string> >  &listOfDicts);