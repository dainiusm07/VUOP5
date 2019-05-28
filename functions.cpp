#include "header.h"

string wordFix (string word){

    for (int i=0 ; i<word.size() ; i++)
        if (!(word[i] >= 'a' && word[i]<='z'))
            word[i] = tolower(word[i]);

    for (int i=0 ; i<word.size() ; i++)
        if (!(word[i] >= 'a' && word[i]<='z'))
            word = word.substr(0,i) + word.substr(i+1);

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