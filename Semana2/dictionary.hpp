#include <iostream>
#include <fstream> 
#include <vector>

using namespace std;

bool LoadDictionary(string path, vector< string > &wordlist);
bool SearchString(const vector< string > &wordlist, string query);
vector< string > SearchSubstrings(const vector< string > &wordlist, string query);
