#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
    data(int an, int luna, int zi):an(an), luna(luna), zi(zi){}
};
class ora{
    int ora;
    int minut;
};

class artist{
    std::string nume;
    std::string nume_eveniment;
    data data_concertare_artist;
    ora inceput;
    ora sfarsit;
    std::string lct;// locatie
public:
 artist(const std::string &nume, const std::string &numeEveniment, const data &dataConcertareArtist, const ora &inceput,
        const ora &sfarsit, const std::string &lct) : nume(nume), nume_eveniment(numeEveniment),
                                                      data_concertare_artist(dataConcertareArtist), inceput(inceput),
                                                      sfarsit(sfarsit), lct(lct) {std::cout << "Constructor\n";}

    virtual ~artist() {

    }
};


class eveniment{
    std::string nume;
    data inceput;
    data sfarsit;
    //std::vector<nume> artisti_ev; //Pentru un eveniment folosim un vector de string-uri care sa reprezinte artistii,
    //artist artisti_ev;            // specific fiecarui eveniment in parte. Pentru acest lucru trebuie sa
                                    // apelam o functie prieten care foloseste date private (string nume) din clasa artist

    std::string lct; //locatia
public:
    eveniment(const std::string &nume, const data &inceput, const data &sfarsit, const std::string &lct) : nume(nume),
                                                                                                           inceput(inceput),
                                                                                                           sfarsit(sfarsit),
                                                                                                           lct(lct) {std::cout << "Constructor\n";}

    virtual ~eveniment() {

    }
};

class statistica{
    std::vector<artist> date;
public:
    statistica(){std::cout << "Constructor de initializare\n";}
    statistica(const statistica &){std::cout << "Constructor de copiere\n";}

    virtual ~statistica() {

    }
};

int main() {
    //artist TudorG1("Tudor Gheorghe", "Sarbatorile de iarna", {25,12,2021}, {18,0},{21,0}, "Sala Palatului");
    //artist Fuego1("Fuego", "Sarbatorile de iarna", {26,12,2021}, {18,0},{21,0}, "Sala Palatului");
    //artist Hrusca1("Stefan Hrusca", "Sarbatorile de iarna", {27,12,2021}, {18,0},{21,0}, "Sala Palatului");
    statistica S;
    return 0;
}
