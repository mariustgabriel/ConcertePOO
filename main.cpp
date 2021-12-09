#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*Proiectul ConcertePOO, ca Organizator de Concerte, implica implementarea informatiilor privind
 * concertele organizate la o anumita data si ora, intr-o anumita locatie.
 * Concertele reprezinta un fenomen care se intampla cu regularitate, intr-un ritm controlat,
 * organizat cu un scop specific, acela de divertisment.
 * Se identifica prin clasele artist,eveniment si statistica.
 * Artistii pot fi unul sau mai multi la un eveniment si au o data de participare si cate o ora la care incepe si se termina cantarea.
 * Au nume, data, ora inceput, ora sfarsit, evenimentul la care concerteaza, locatie si constructori/destructori specifici
 * Evenimentele se desfasoara pe mai multe zile.
 * Au data inceput, data sfarsit, locatie, lista de artisti per eveniment si constructori/destructori specifici
 * Statisticile listeaza cantarile artistilor in functie de eveniment si au constructori/destructori specifici
 * In algoritm ne folosim de doua clase helper(data si ora)
 */
//const std::string locatie; //poate fi folosit ca variabila globala

class data{
    int zi;
    int luna;
    int an;
public:
    data(int zi, int luna, int an) : zi(zi), luna(luna), an(an) {}
    ~data() = default;

    bool operator==(const data &rhs) const {
        return zi == rhs.zi &&
               luna == rhs.luna &&
               an == rhs.an;
    }

    bool operator<(const data &rhs) const {
        if (zi < rhs.zi)
            return true;
        if (rhs.zi < zi)
            return false;
        if (luna < rhs.luna)
            return true;
        if (rhs.luna < luna)
            return false;
        return an < rhs.an;
    }

    friend std::ostream &operator<<(std::ostream &os, const data &data) {
        os << "zi: " << data.zi << " luna: " << data.luna << " an: " << data.an;
        return os;
    }
};
class ora_minut{
    int ora;
    int minut;
public:
    ora_minut(int ora, int minut) : ora(ora), minut(minut) {}
    ~ora_minut() = default;

    bool operator<(const ora_minut &rhs) const {
        if (ora < rhs.ora)
            return true;
        if (rhs.ora < ora)
            return false;
        return minut < rhs.minut;
    }

    bool operator==(const ora_minut &rhs) const {
        return ora == rhs.ora &&
               minut == rhs.minut;
    }

    friend std::ostream &operator<<(std::ostream &os, const ora_minut &minut) {
        os << "ora: " << minut.ora << " minut: " << minut.minut;
        return os;
    }
};
class eveniment;
class artist{
    std::string nume_artist;
    std::string nume_eveniment;
    data data_concertare_artist;
    ora_minut inceput;
    ora_minut sfarsit;
    std::string locatie;
public:
    artist(const std::string &nume_artist, const std::string &numeEveniment, const data &dataConcertareArtist,
           const ora_minut &inceput, const ora_minut &sfarsit, const std::string &locatie) : nume_artist(nume_artist),
                                                                                 nume_eveniment(numeEveniment),
                                                                                 data_concertare_artist(
                                                                                         dataConcertareArtist),
                                                                                 inceput(inceput), sfarsit(sfarsit),
                                                                                 locatie(locatie) {}
    ~artist() = default;

    friend std::ostream &operator<<(std::ostream &os, const artist &artist) {
        os << "nume_artist: " << artist.nume_artist << " nume_eveniment: " << artist.nume_eveniment
           << " data_concertare_artist: " << artist.data_concertare_artist << " inceput: " << artist.inceput
           << " sfarsit: " << artist.sfarsit << " locatie: " << artist.locatie;
        return os;
    }
    artist(const artist &copie)
    :nume_artist(copie.nume_artist),nume_eveniment(copie.nume_eveniment), data_concertare_artist(copie.data_concertare_artist)
    , inceput(copie.inceput), sfarsit(copie.sfarsit),locatie(copie.locatie){
        std::cout<<"CC artist\n";
    }
    artist& operator=(const artist& copie) {
        std::cout<<"OP= artist\n";
        if(this!= &copie){
            this->nume_artist = copie.nume_artist;
            this->nume_eveniment = copie.nume_eveniment;
            this->data_concertare_artist = copie.data_concertare_artist;
            this->inceput = copie.inceput;
            this->sfarsit = copie.sfarsit;
            this->locatie = copie.locatie;
        }
            return *this;
    }

    const std::string &getNumeArtist() const {
        return nume_artist;
    }
    const std::string &getNumeEveniment() const {
        return nume_eveniment;
    }
    const data &getDataConcertareArtist() const {
        return data_concertare_artist;
    }

    const ora_minut &getInceput() const {
        return inceput;
    }

    const ora_minut &getSfarsit() const {
        return sfarsit;
    }

    const std::string &getLocatie() const {
        return locatie;
    }

};


class eveniment{
    std::string nume;
    data inceput;
    data sfarsit;
    std::string locatie;
public:
    eveniment(const std::string &nume, const data &inceput, const data &sfarsit, const std::string &locatie) : nume(
            nume), inceput(inceput), sfarsit(sfarsit), locatie(locatie) {}
    ~eveniment() = default;
    friend std::ostream &operator<<(std::ostream &os, const eveniment &eveniment) {
        os << "nume: " << eveniment.nume << " inceput: " << eveniment.inceput << " sfarsit: " << eveniment.sfarsit
           << " locatie: " << eveniment.locatie;
        return os;
    }
};

bool comparator(const artist& a, const artist& b) {
    if (a.getNumeEveniment() == b.getNumeEveniment()) {
        if (a.getDataConcertareArtist() == b.getDataConcertareArtist()) {
            if(a.getInceput() == b.getSfarsit()) {
                if(a.getNumeArtist() == b.getNumeArtist())
                    return a.getNumeArtist() < b.getNumeArtist();
            }
            return a.getInceput() < a.getSfarsit();
        }
        return a.getDataConcertareArtist() < b.getDataConcertareArtist();
    }
    return a.getNumeEveniment() < b.getNumeEveniment();
}

void lista_implicita(std::vector<artist> artisti1){
    artisti1.reserve(1000);
    artist TudorG1("Tudor Gheorghe", "Sarbatorile de iarna 2021", {25,12,2021}, {18,0},{21,0}, "Sala Palatului");
    artisti1.emplace_back(TudorG1);
    artist Fuego1("Fuego", "Sarbatorile de iarna 2021", {26,12,2021}, {18,0},{21,0}, "Sala Palatului");
    artisti1.emplace_back(Fuego1);
    artist Hrusca1("Stefan Hrusca", "Sarbatorile de iarna 2021", {27,12,2021}, {18,0},{21,0}, "Sala Palatului");
    artisti1.emplace_back(Hrusca1);
    artist NicolaeB1("Nicolae Botgros si Orchestra Lautarii", "Serbarile Timisoreana 2021", {10,8,2021}, {18, 0}, {20, 0}, "Piata Daciei");
    artisti1.emplace_back(NicolaeB1);
    artist Adda1("Adda", "Serbarile Timisoreana 2021", {10,8,2021}, {20, 0},{22, 0}, "Piata Daciei");
    artisti1.emplace_back(Adda1);
    artist TudorG2("Tudor Gheorghe","Serbarile Timisoreana 2021", {11,8,2021}, {19, 0},{21, 30}, "Piata Daciei");
    std::sort(artisti1.begin(), artisti1.end(), &comparator);
}

class statistica{
    std::vector<artist> Artisti;
    static std::string Nume;
public:
    statistica(const std::vector<artist> &artisti) : Artisti(artisti) {}
    //statistica(const statistica &){std::cout << "Constructor de copiere Statistica\n";}
    //~statistica() = default;

    friend std::ostream &operator<<(std::ostream &os, const statistica &statistica) {
        os << "Artisti: \n";
        std::unordered_map<std::string, int> frecventa;
        for(const artist& artisti_ : statistica.Artisti)
        //    if(frecventa.contains(artisti_.getNumeArtist()))
        //for(const auto& artisti: statistica.Artisti)
        //    os << artisti;
        return os;
    }

};


int main() {
    std::vector<artist> artisti;
    lista_implicita((artisti));
    //statistica S;
    return 0;
}
