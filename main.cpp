#include "header.h"

int main () {
    std::regex url("^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w \\.-]*)*\\/?$");

    if(!fileExists(filename)) throw std::runtime_error("Nepavyko rasti failo!");
    
    std::ifstream fromFile (filename);
    string tempLine;
    int lineNumber = 0;

    std::map< string, std::pair<std::set<int>,int> > word;
    std::set<string> link;

    while (std::getline(fromFile,tempLine)){ // Nuskaito eilute
        lineNumber++;
        std::istringstream fromLine (tempLine);
        string tempWord;
        while(fromLine >> tempWord){ // Skaito eilute, kol joje yra zodziu
            if (std::regex_match(tempWord, url)) // Ziuri ar nuskaitytas zodis nera linkas
                link.insert(tempWord); // Itraukia linka
            else{
                tempWord = wordFix(tempWord); // Sutvarko zodi t.y istrina simbolius, pavarcia visas raides i mazasias
                if (word[tempWord].first.count(lineNumber) == 0) // Cia kad i set neitrauktu tu paciu eiluciu nr
                    word[tempWord].first.insert(lineNumber); // Itraukia nauja eilute

                word[tempWord].second++; // Kadangi zodis gali buti 1 eilute daugiau nei 1 karta, tai skaiciuoju atskirai
            }
        }
    }

    printWords(word);
    printLinks(link);

    return 0;
}