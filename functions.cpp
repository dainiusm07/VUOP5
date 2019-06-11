#include "header.h"

string wordFix (string word){

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

    return word;
}

bool fileExists (const string name) { //Tikrina ar failas egzistuoja
    std::ifstream f(name.c_str());
    return f.good();
}

void printWords (std::map<string, std::pair< std::set<int>, int >> word) {
    for (auto i = word.begin() ; i!=word.end() ; i++) {
        string mapWord = i->first;
        if ( word[ mapWord ].second > 1){
            cout << mapWord << " - pasikartojo " << word[ mapWord ].second << " kartus(-u), eilutese:";
            for (auto j = word[ mapWord ].first.begin(); j!=word[ mapWord ].first.end() ; j++)
                cout << " " << *j;
            cout << endl;
        }
    }
    cout << endl;
}

void printLinks (std::set<string> link){
    cout << "Links: " << endl;
    for (auto i = link.begin() ; i!=link.end() ; i++)
        cout << *i << endl;
}