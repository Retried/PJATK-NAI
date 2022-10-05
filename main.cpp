#include <any>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using mojamapa_id = std::map<std::string, std::vector<double>>;
using mojafunkcja_id = std::function<std::double_t (std::vector<double>)>;

void wypisz(mojamapa_id mapa, mojafunkcja_id fun) {
    using namespace std;
    for (auto kv : mapa) {
        auto [k, v] = kv;
        cout << "wybrana funkcja: " << k << ", wynik " << fun(v) << endl;
    }
}

int main(int argc, char **argv) {
    using namespace std;
    map<string, mojafunkcja_id> formatery;
    formatery["sin"] = [](vector<double> x) { return sin(x[0]); };
    formatery["add"] = [](vector<double> x) { return x[0] + x[1]; };
    formatery["mod"] = [](vector<double> x) { return (int)x[0] % (int)x[1]; };

    try {
        vector<string> argumenty(argv, argv + argc);

        string klucz = argumenty[1];

        vector<double> wartosci;
        for (int i = 2; i < argc; i++) {
            wartosci.push_back(stod(argumenty[i]));
        }
        mojamapa_id mojamapa = {{klucz, wartosci}};
        wypisz(mojamapa, formatery[klucz]);

    } catch (exception &aor) {
        cout << "Program do obliczania sinusa, dodawania i modulo argumentow.\nCzytasz to poniewaz niepoprawnie uzyto funkcji :)";
        return 1;

    }
    return 0;
}

// POZDRAWIAM PODGLĄDACZY