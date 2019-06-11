# VUOP5

## Kaip paleisti:
+ Susikompiliuoti naudojant makefile t.y parasius komanda `make` i komandine eilute. (Veikia tik su mac ir unix OS)
+ Paleisti programa parasius komanda `./test`.

## 1 uzduotis

**Panaudoti asociatyvus konteriai:**

```C++
std::map< string, std::pair<std::set<int>,int> > word;
std::set<string> link;
```

Kadangi map gali "pavezti" tik 2 elementus, teko panaudoti `std::pair`. Kadangi reikia saugoti 3 duomenis apie zodi. T.y pati zodi, kokiose eilutese jis pasikartojo, na ir zinoma kiek kartu tas zodis pasikartojo.
Linkam uzteko tiesiog panaudoti set, kadangi apie juos tokios detalios informacijos saugoti - nereikejo.

Taip pat zodziai gali prasideti is didziosios tiek is mazosios raides ar buti nuskaityti kartu su simboliu. Todel reikejo padaryti kazkoki filtra, tam kad tas ivairias zodziu variacijas paverstu i 1 konkrecia.

**Filtras:**
```C++
string wordFix (string word){

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

    return word;
}
```

## 2 uzduotis

Zodziu, pasikartojimu skaiciu ir eiluciu kuriose jie buvo pamineti spausdinimas atrodo taip:

```C++
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
```

## 3 uzduotis

Linku paieska buvo atlikta naudojant `std::regex`

```C++
std::regex url("^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w \\.-]*)*\\/?$");
```
Iskart nuskaicius zodi, jis tikrinamas ar tai buvo linkas paprasto if pagalba.

```C++
if (std::regex_match(tempWord, url)) // Ziuri ar nuskaitytas zodis nera linkas
                link.insert(tempWord); // Itraukia linka
```

Jeigu tas zodis yra linkas, jo niekur netraukia, jeigu ne - tas zodis apdorjamas ir atliekamos visos kitos manipuliacijos uzduoties salygai patenkinti.

Na ir zinoma realizuotas linku spausdinimas.

```C++
void printLinks (std::set<string> link){
    cout << "Links: " << endl;
    for (auto i = link.begin() ; i!=link.end() ; i++)
        cout << *i << endl;
}
```

