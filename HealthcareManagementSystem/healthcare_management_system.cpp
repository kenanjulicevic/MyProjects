#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;
string unesiString();
long long unesiCijeliBroj();
long long unesiRealniBroj();
//------------------------------------KLASE--------------------------------------------------
class Osoba {
protected:
    long long jmbg;
    string ime;
    string prezime;
public:
    Osoba() = default;

    Osoba(const string &i, const string &p, long long j) {
        ime = i;
        prezime = p;
        jmbg = j;
    }

    string getIme() const { return ime; }
    string getPrezime() const { return prezime; }
    long long getJMBG() const { return jmbg; }

    void setIme(const string &i) { ime = i; }
    void setPrezime(const string &p) { prezime = p; }

    void prikazi() const {
        cout << "Ime: " << ime << endl;
        cout << "Prezime: " << prezime << endl;
        cout << "JMBG: " << jmbg << endl;
    }
};

class ZdravstveniKarton {
private:
    int godinaRodjenja;
    string dijagnoza;
    vector<string> alergeni;

public:
    ZdravstveniKarton() {}

    ZdravstveniKarton(int god, const string &diag, const vector<string> &alerg) {
        godinaRodjenja = god;
        dijagnoza = diag;
        alergeni = alerg;
    }

    int getGodinaRodjenja() const { return godinaRodjenja; }
    string getDijagnoza() const { return dijagnoza; }
    vector<string> getAlergeni() const { return alergeni; }

    void setGodinaRodjenja(int g) { godinaRodjenja = g; }
    void setDijagnoza(const string &d) { dijagnoza = d; }
    void setAlergene(const vector<string> &a) { alergeni = a; }

    void prikazi() const {
        cout << "Godina rodjenja: " << godinaRodjenja << endl;
        cout << "Dijagnoza: " << dijagnoza << endl;
        cout << "Alergeni: ";
        for (const auto &a : alergeni) cout << a << " ";
        cout << endl;
    }
};

class Pacijent : public Osoba {
protected:
    string brojZK;
    ZdravstveniKarton karton;
public:
    Pacijent() = default;

    Pacijent(const string &i, const string &p, long long j, const string &br, const ZdravstveniKarton &k)
        : Osoba(i, p, j)
    {
        brojZK = br;
        karton = k;
    }

    void prikazi() const {
        cout << "Pacijent: " << ime << " " << prezime << endl;
        cout << "JMBG: " << jmbg << endl;
        cout << "ZK broj: " << brojZK << endl;
        karton.prikazi();
        cout << "------------------------" << endl;
    }

    string getBrojZK() const { return brojZK; }
    void setBrojZK(const string &zk) { brojZK = zk; }

    ZdravstveniKarton getKarton() const { return karton; }
    void setKarton(const ZdravstveniKarton &k) { karton = k; }
};

class Radnici : public Osoba{
protected:
  int plata;
public:
  Radnici() = default;
  Radnici(const string &i, const string &p, long long j, int pl)
   :Osoba(i,p,j)
  {
    plata=pl;
  }
   // GET
    int getPlata() const { return plata; }

    // SET
    void setPlata(int pl) { plata = pl; }

    void prikazi() const {
        cout << "Radnik: " << ime << " " << prezime << endl;
        cout << "JMBG: " << jmbg << endl;
        cout << "Plata: " << plata << endl;
        cout << "------------------------" << endl;
    }
};

class Doktori : public Osoba{
protected:
  int plata;
public:
  Doktori() = default;
  Doktori(const string &i, const string &p, long long j, int pl)
   :Osoba(i,p,j)
  {
    plata=pl;
  }
   // GET
    int getPlata() const { return plata; }

    // SET
    void setPlata(int pl) { plata = pl; }

    void prikazi() const {
        cout << "Medicinar: " << ime << " " << prezime << endl;
        cout << "JMBG: " << jmbg << endl;
        cout << "Plata: " << plata << endl;
        cout << "------------------------" << endl;
    }
};

class Usluge{
protected:
  string naziv;
  float cijena;
public:
  Usluge()=default;
  Usluge(const string &n, float c){
    naziv = n;
    cijena = c;
  }

  //GET
  string getNaziv() const {return naziv;}
  float getCijena() const {return cijena;}
  //SET
  void setNaziv(const string &n) {naziv=n;}
  void setCijena(float c) {cijena=c;}
};

class Termini{
public:
  string brojZK_pacijenta;
  string vrijeme;

  Termini()=default;
  Termini(const string &brZK, const string &v){
    brojZK_pacijenta = brZK;
    vrijeme = v;
  }
  //get
  string getBrojZK() const {return brojZK_pacijenta;}
  string getVrijeme() const {return vrijeme;}
  //set
  void setBrojZK(const string &brZK) {brojZK_pacijenta=brZK;}
  void setVrijeme(const string &v) {vrijeme=v;}
};
//------------------------------------------------------------------KLASE--------------------------------------------------
Pacijent unosPacijenta() {
    string ime, prezime, zk, dijagnoza;
    long long jmbg;
    int godinaRodjenja, nAlergena;
    vector<string> alergeni;

    cout << "Unesi ime: ";
    ime = unesiString();
    cout << "Unesi prezime: ";
    prezime = unesiString();
    cout << "Unesi JMBG (13 cifara): ";
    jmbg = unesiCijeliBroj();
    cout << "Unesi broj zdravstvenog kartona: ";
    zk = unesiString();
    cout << "Unesi godinu rodjenja: ";
    godinaRodjenja = unesiCijeliBroj();
    cout << "Unesi dijagnozu: ";
    dijagnoza = unesiString();
    cout << "Koliko alergena: ";
    nAlergena = unesiCijeliBroj();
    alergeni.resize(nAlergena);
    for(int i = 0; i < nAlergena; i++) {
        cout << "Alergen " << i+1 << ": ";
        alergeni[i] = unesiString();
    }
    ZdravstveniKarton karton(godinaRodjenja, dijagnoza, alergeni);
    Pacijent p(ime, prezime, jmbg, zk, karton);
    return p;
}

Pacijent editPacijenta(Pacijent p) {
    cout << "Pacijent pronadjen, unesite nove podatke!" << endl;

    string novoIme, novoPrezime;
    cout << "Novo ime: ";
    novoIme = unesiString();
    cout << "Novo prezime: ";
    novoPrezime = unesiString();
    p.setIme(novoIme);
    p.setPrezime(novoPrezime);

    int novaGodina;
    string novaDijagnoza;
    int nAlergena;
    vector<string> noviAlergeni;

    cout << "Nova godina rodjenja: ";
    novaGodina = unesiCijeliBroj();
    cout << "Nova dijagnoza: ";
    novaDijagnoza = unesiString();
    cout << "Koliko alergena: ";
    nAlergena = unesiCijeliBroj();
    noviAlergeni.resize(nAlergena);
    for(int i = 0; i < nAlergena; i++) {
        cout << "Alergen " << i+1 << ": ";
        noviAlergeni[i] = unesiString();
    }

    ZdravstveniKarton noviKarton(novaGodina, novaDijagnoza, noviAlergeni);
    p.setKarton(noviKarton);

    cout << "Podaci uspjesno izmijenjeni!\n";
    return p;
}

Radnici unosRadnika(){
    string ime, prezime;
    long long jmbg;
    float plata;

    cout << "Unesi ime: ";
    ime = unesiString();
    cout << "Unesi prezime: ";
    prezime = unesiString();
    cout << "Unesi JMBG (13 cifri): ";
    jmbg = unesiCijeliBroj();
    cout << "Unesi platu: ";
    plata = unesiRealniBroj();

    Radnici r(ime, prezime, jmbg, plata);
    return r;
}

Doktori unosDoktora(){
    string ime, prezime;
    long long jmbg;
    float plata;

    cout << "Unesi ime: ";
    ime = unesiString();
    cout << "Unesi prezime: ";
    prezime = unesiString();
    cout << "Unesi JMBG (13 cifri): ";
    jmbg = unesiCijeliBroj();
    cout << "Unesi platu: ";
    plata = unesiRealniBroj();

    Doktori d(ime, prezime, jmbg, plata);
    return d;
}

Termini unosTermina(vector<Termini> &listaTermina){
  string brojZK_pacijenta;
  string vrijeme;
  bool slobodno;

  cout<<"Unesite broj kartona pacijenta: "<<endl;
  brojZK_pacijenta = unesiString();
  do{
  slobodno = true;
  cout<<"Unesite vrijeme željenog termina (format sati:minute): "<<endl;
  vrijeme = unesiString();
  for(auto &d : listaTermina){
    if(d.vrijeme==vrijeme){
      slobodno = false;
      cout<<"Termin "<<vrijeme<<" je zauzet!"<<endl;
      break;
    }
  }
  }while(!slobodno);
  return Termini(brojZK_pacijenta, vrijeme);
}

Usluge unosUsluge() {
    string naziv;
    float cijena;

    cout << "Unesi naziv usluge: ";
    naziv = unesiString();

    cout << "Unesi cijenu usluge: ";
    cijena = unesiRealniBroj();

    return Usluge(naziv, cijena);
}

void prikaziDoktore(const vector<Doktori> &listaDoktora) {
    if (listaDoktora.empty()) {
        cout << "Nema registrovanih doktora.\n";
        return;
    }

    cout << "\n=== Lista doktora ===\n";
    for (const auto &d : listaDoktora) {
        d.prikazi();
    }
}

void prikaziRadnika(const vector<Radnici> &listaRadnika) {
    if (listaRadnika.empty()) {
        cout << "Nema registrovanih radnika!\n";
        return;
    }

    cout << "\n=== Lista radnika ===\n";
    for (const auto &d : listaRadnika) {
        d.prikazi();
    }
}

void prikaziUsluge(const vector<Usluge> &listaUsluga) {
    if (listaUsluga.empty()) {
        cout << "Nema usluga u sistemu.\n";
        return;
    }

    cout << "\n=== Lista usluga ===\n";
    for (const auto &u : listaUsluga) {
        cout << "Naziv: " << u.getNaziv() << " | Cijena: " << u.getCijena() << " KM\n";
    }
}

void prikaziTermine(const vector<Termini> &listaTermina) {
    if (listaTermina.empty()) {
        cout << "Nema zakazanih termina!\n";
        return;
    }

    cout << "\n===== LISTA ZAKAZANIH TERMINA =====\n";
    for (const auto &t : listaTermina) {
        cout << "Broj kartona: " << t.getBrojZK()
             << " | Vrijeme: " << t.getVrijeme() << endl;
    }
    cout << "===================================\n";
}

void pretragaDoktora(const vector<Doktori> &listaDoktora) {
    if (listaDoktora.empty()) {
        cout << "Nema doktora u sistemu!\n";
        return;
    }

    cout << "Unesite JMBG doktora kojeg trazite: ";
    long long j = unesiCijeliBroj();

    bool found = false;
    for (const auto &d : listaDoktora) {
        if (d.getJMBG() == j) {
            cout << "\nDoktor pronadjen:\n";
            d.prikazi();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Doktor sa tim JMBG nije pronadjen!\n";
    }
}

void pretragaRadnika(const vector<Radnici> &listaRadnika) {
    if (listaRadnika.empty()) {
        cout << "Nema radnika u sistemu!\n";
        return;
    }

    cout << "Unesite JMBG radnika kojeg trazite: ";
    long long j = unesiCijeliBroj();

    bool found = false;
    for (const auto &d : listaRadnika) {
        if (d.getJMBG() == j) {
            cout << "\nRadnik pronadjen:\n";
            d.prikazi();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Radnik sa tim JMBG nije pronadjen!\n";
    }
}

void editTermin(vector<Termini> &listaTermina) {
    if (listaTermina.empty()) {
        cout << "Nema termina za uređivanje!\n";
        return;
    }

    string trazenoVrijeme;
    cout << "Unesite vrijeme termina koji želite urediti (format sati:minute): ";
    trazenoVrijeme = unesiString();

    bool found = false;
    for (auto &t : listaTermina) {
        if (t.getVrijeme() == trazenoVrijeme) {
            found = true;

            cout << "Termin pronađen!\n";
            cout << "Broj kartona: " << t.getBrojZK() << endl;
            cout << "Vrijeme: " << t.getVrijeme() << endl;

            string novoVrijeme;
            string noviZK;
            bool slobodno;

            cout << "Unesite novi broj kartona: ";
            noviZK = unesiString();

            do {
                slobodno = true;
                cout << "Unesite novo vrijeme termina: ";
                novoVrijeme = unesiString();

                for (auto &x : listaTermina) {
                    if (x.getVrijeme() == novoVrijeme && &x != &t) {
                        cout << "Termin " << novoVrijeme << " je već zauzet!\n";
                        slobodno = false;
                        break;
                    }
                }
            } while (!slobodno);

            // -------- PRIMJENA PROMJENA --------
            t.setBrojZK(noviZK);
            t.setVrijeme(novoVrijeme);

            cout << "Termin uspješno uređen!\n";
            return;
        }
    }

    if (!found) {
        cout << "Termin sa tim vremenom nije pronađen!\n";
    }
}


void editDoktora(vector<Doktori> &listaDoktora) {
    if (listaDoktora.empty()) {
        cout << "Nema doktora za uređivanje.\n";
        return;
    }

    long long j;
    cout << "Unesite JMBG doktora kojeg zelite urediti: ";
    j = unesiCijeliBroj();

    bool found = false;
    for (auto &d : listaDoktora) {
        if (d.getJMBG() == j) {
            string ime, prezime;
            int plata;

            cout << "Novo ime: ";
            ime = unesiString();
            cout << "Novo prezime: ";
            prezime = unesiString();
            cout << "Nova plata: ";
            plata = unesiCijeliBroj();

            d.setIme(ime);
            d.setPrezime(prezime);
            d.setPlata(plata);

            found = true;
            cout << "Podaci doktora uspjesno izmijenjeni!\n";
            break;
        }
    }

    if (!found) {
        cout << "Doktor nije pronadjen!\n";
    }
}

void editRadnika(vector<Radnici> &listaRadnika) {
    if (listaRadnika.empty()) {
        cout << "Nema radnika za uređivanje!\n";
        return;
    }

    long long j;
    cout << "Unesite JMBG radnika kojeg zelite urediti: ";
    j = unesiCijeliBroj();

    bool found = false;
    for (auto &d : listaRadnika) {
        if (d.getJMBG() == j) {
            string ime, prezime;
            int plata;

            cout << "Novo ime: ";
            ime = unesiString();
            cout << "Novo prezime: ";
            prezime = unesiString();
            cout << "Nova plata: ";
            plata = unesiCijeliBroj();

            d.setIme(ime);
            d.setPrezime(prezime);
            d.setPlata(plata);

            found = true;
            cout << "Podaci radnika uspjesno izmijenjeni!\n";
            break;
        }
    }

    if (!found) {
        cout << "Radnik nije pronadjen!\n";
    }
}

void editUslugu(vector<Usluge> &listaUsluga) {
    if (listaUsluga.empty()) {
        cout << "Nema usluga za uređivanje.\n";
        return;
    }

    string trazeniNaziv;
    cout << "Unesi naziv usluge za uređivanje: ";
    trazeniNaziv = unesiString();

    for (auto &u : listaUsluga) {
        if (u.getNaziv() == trazeniNaziv) {
            string noviNaziv;
            float novaCijena;

            cout << "Unesi novi naziv: ";
            noviNaziv = unesiString();
            cout << "Unesi novu cijenu: ";
            novaCijena = unesiRealniBroj();

            u.setNaziv(noviNaziv);
            u.setCijena(novaCijena);

            cout << "Usluga uspješno uređena!\n";
            return;
        }
    }

    cout << "Usluga s tim nazivom nije pronađena!\n";
}

void obrisiDoktora(vector<Doktori> &listaDoktora) {
    if (listaDoktora.empty()) {
        cout << "Nema doktora za brisanje.\n";
        return;
    }

    cout << "Unesite JMBG doktora kojeg zelite obrisati: ";
    long long j = unesiCijeliBroj();

    for (auto it = listaDoktora.begin(); it != listaDoktora.end(); ++it) {
        if (it->getJMBG() == j) {
            listaDoktora.erase(it);
            cout << "Doktor uspjesno obrisan!\n";
            return;
        }
    }

    cout << "Doktor nije pronadjen!\n";
}

void obrisiRadnika(vector<Radnici> &listaRadnika) {
    if (listaRadnika.empty()) {
        cout << "Nema radnika za brisanje!\n";
        return;
    }


    cout << "Unesite JMBG radnika kojeg zelite obrisati: ";
    long long j = unesiCijeliBroj();

    for (auto it = listaRadnika.begin(); it != listaRadnika.end(); ++it) {
        if (it->getJMBG() == j) {
            listaRadnika.erase(it);
            cout << "Radnik uspjesno obrisan!\n";
            return;
        }
    }

    cout << "Radnik nije pronadjen!\n";
}

void obrisiUslugu(vector<Usluge> &listaUsluga) {
    if (listaUsluga.empty()) {
        cout << "Nema usluga za brisanje.\n";
        return;
    }

    string trazeniNaziv;
    cout << "Unesi naziv usluge za brisanje: ";
    trazeniNaziv = unesiString();

    for (auto it = listaUsluga.begin(); it != listaUsluga.end(); ++it) {
        if (it->getNaziv() == trazeniNaziv) {
            listaUsluga.erase(it);
            cout << "Usluga uspješno obrisana!\n";
            return;
        }
    }

    cout << "Usluga nije pronadjena!\n"<<endl;
}

void brisanjePacijenata(vector<Pacijent> &listaPacijenata) {
    if(listaPacijenata.empty()) {
        cout << "Nema trazenog pacijenta" << endl;
        return;
    }
    cout << "Unesite broj zdravstvenog kartona pacijenta kojeg zelite obrisati: ";
    string trazeniZK = unesiString();
    bool found = false;
    for(auto it = listaPacijenata.begin(); it != listaPacijenata.end(); ++it) {
        if(it->getBrojZK() == trazeniZK) {
            listaPacijenata.erase(it);
            cout << "Pacijent uspjesno obrisan!\n";
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "Pacijent sa tim brojem kartona nije pronadjen!\n";
    }
}

void obrisiTermin(vector<Termini> &listaTermina) {
    if (listaTermina.empty()) {
        cout << "Nema termina za brisanje!\n";
        return;
    }

    string trazenoVrijeme;
    cout << "Unesite vrijeme termina koji želite obrisati (format sati:minute): ";
    trazenoVrijeme = unesiString();

    for (auto it = listaTermina.begin(); it != listaTermina.end(); ++it) {
        if (it->getVrijeme() == trazenoVrijeme) {
            listaTermina.erase(it);
            cout << "Termin uspješno obrisan!\n";
            return;
        }
    }

    cout << "Termin sa tim vremenom nije pronađen!\n";
}

void pretragaPacijenata(const vector<Pacijent> &listaPacijenata) {
    if(listaPacijenata.empty()) {
        cout << "Nema pacijenata u sistemu\n";
        return;
    }

    string trazeniZK;
    cout << "Unesite broj kartona trazenog pacijenta: ";
    trazeniZK = unesiString();

    bool found = false;
    for(const auto &p : listaPacijenata) {
        if(p.getBrojZK() == trazeniZK) {
            cout << "Pacijent pronadjen:\n";
            p.prikazi();
            found = true;
        }
    }

    if(!found) {
        cout << "Nema pacijenta sa tim brojem kartona\n";
    }
}

void pregledPacijentaPoJMBG(const vector<Pacijent> &listaPacijenata){
    if(listaPacijenata.empty()){
        cout<<"Nema pacijenata!"<<endl;
        return;
    }

    long long trazeniJMBG;
    cout<<"Unesite JMBG trazenog pacijenta!"<<endl;
    trazeniJMBG = unesiCijeliBroj();

    bool found = false;
    for(const auto &p : listaPacijenata) {
        if(p.getJMBG() == trazeniJMBG) {
            cout << "\n*** Podaci pacijenta ***\n";
            p.prikazi();
            found = true;
            break;
        }
    }

    if(!found){
        cout<<"Nije pronadjen ni jedan pacijent sa ovim JMBG!"<<endl;
    }
}

string Login(){
  cout<<"=========ADMIN LOGIN========="<<endl;
  cout<<"USERNAME: ADMINADMIN"<<endl;
  cout<<"Unesite password: "<<endl;
  string password = unesiString();
  return password;
}

void adminMeni(){
  cout<<"======DOBRODOSLI ADMIN======="<<endl;
  cout<<"1. Dodaj radnika"<<endl;
  cout<<"2. Dodaj medicinara"<<endl;
  cout<<"3. Dodaj uslugu"<<endl;
  cout<<"4. Uredi medicinara"<<endl;
  cout<<"5. Uredi radnika"<<endl;
  cout<<"6. Uredi uslugu"<<endl;
  cout<<"7. Obrisi radnika"<<endl;
  cout<<"8. Obrisi medicinara"<<endl;
  cout<<"9. Obrisi uslugu"<<endl;
  cout<<"10. Pregled radnika"<<endl;
  cout<<"11. Pregled medicirana"<<endl;
  cout<<"12. Pregled Usluga"<<endl;
  cout<<"13. Izlaz"<<endl;
  cout<<"-----------------------------"<<endl;
  cout<<"Odaberite opciju: "<<endl;
}

int main() {
    vector<Pacijent> listaPacijenata;
    vector<Doktori> listaDoktora;
    vector<Radnici> listaRadnika;
    vector<Usluge> listaUsluga;
    vector<Termini> listaTermina;

    while(true) {
        int slucaj = 0;

        cout << "========MENI=============" << endl;
        cout << "1. Pacijent" << endl;
        cout << "2. Medicinsko osoblje" << endl;
        cout << "3. Administrator" << endl;
        cout << "4. Izlaz iz programa"<<endl;
        cout << "=========================" << endl;
        cout << "Izaberite vas status: ";
        slucaj = unesiCijeliBroj();

        switch(slucaj) {
            case 1:{
                int opcija1;
                do{
                    cout<<"====Dobrodosli pacijente!===="<<endl;
                    cout<<"1. Pregled svog zdravstvenog kartona"<<endl;
                    cout<<"2. Pregled usluga"<<endl;
                    cout<<"3. Izlaz"<<endl;
                    cout<<"=============================="<<endl;
                    cout<<"Izaberite opciju: ";
                    opcija1 = unesiCijeliBroj();

                    switch(opcija1){
                        case 1:
                            pregledPacijentaPoJMBG(listaPacijenata);
                            break;
                        case 2:
                            prikaziUsluge(listaUsluga);
                            break;
                        case 3:
                            cout<<"Izlaz iz pacijentskog menija!"<<endl;
                            break;
                        default:
                            cout<<"Nevalidan unos!"<<endl;
                            break;
                    }
                }while(opcija1!=3);
                break;
            }

            case 2: {
                int opcija = 0;
                do {
                    cout << "====Dobrodosli doktore!=======" << endl;
                    cout << "1. Dodaj pacijenta" << endl;
                    cout << "2. Edituj pacijenta" << endl;
                    cout << "3. Pretrazi pacijenta" << endl;
                    cout << "4. Obrisi pacijenta" << endl;
                    cout << "5. Termini" << endl;
                    cout << "6. Izlaz" << endl;
                    cout << "==============================" << endl;
                    cout << "Izaberite opciju: ";
                    opcija = unesiCijeliBroj();

                    switch(opcija) {
                        case 1: {
                            Pacijent p = unosPacijenta();
                            listaPacijenata.push_back(p);
                            cout << "Pacijent uspjesno dodan!\n";
                            break;
                        }
                        case 2: {
                            if(listaPacijenata.empty()) {
                                cout << "Nema pacijenata za editovanje.\n";
                                break;
                            }


                            cout << "Unesite broj kartona pacijenta za edit: ";
                            string trazeniZK = unesiString();

                            bool found = false;
                            for(int i = 0; i < listaPacijenata.size(); i++) {
                                if(listaPacijenata[i].getBrojZK() == trazeniZK) {
                                    listaPacijenata[i] = editPacijenta(listaPacijenata[i]);
                                    found = true;
                                    break;
                                }
                            }

                            if(!found) cout << "Pacijent nije pronadjen!\n";
                            break;
                        }
                        case 3:
                            pretragaPacijenata(listaPacijenata);
                            break;

                        case 4:
                            brisanjePacijenata(listaPacijenata);
                            break;
                        case 5:{
                            int opcija2 = 0;
                            do{
                              cout << "======UPRAVLJANJE TERMINA=======" << endl;
                              cout << "1. Dodaj termin" << endl;
                              cout << "2. Edituj termin" << endl;
                              cout << "3. Prikaz svih termina" << endl;
                              cout << "4. Obrisi termin" << endl;
                              cout << "5. Izlaz" << endl;
                              cout << "================================" << endl;
                              cout << "Izaberite opciju: ";
                              opcija2 = unesiCijeliBroj();

                              switch(opcija2){
                                case 1:{
                                  Termini pi = unosTermina(listaTermina);
                                  listaTermina.push_back(pi);
                                  cout << "Termin uspjesno zakazan!\n";
                                  }
                                  break;
                                case 2:
                                  editTermin(listaTermina);
                                  break;
                                case 3:
                                  prikaziTermine(listaTermina);
                                  break;
                                case 4:
                                  obrisiTermin(listaTermina);
                                  break;
                                case 5:
                                  cout<<"Izlaz iz menija.."<<endl;
                                  break;
                                default:
                                  cout<<"Nevalidan unos!"<<endl;
                                  break;
                              }

                            }while(opcija2!=5);
                            break;
                        }
                        case 6:
                            cout << "Izlaz iz doktorskog menija!\n";
                            break;

                        default:
                            cout << "Nevalidan unos!\n";
                            system("cls");
                            system("pause");
                            return 0;
                    }

                } while(opcija != 6);

                break;
            }

            case 3:{
                int opcija = 0;
                do {
                    string passwd = Login();
                    if(passwd == "********"){ // the password is 8 asterisks
                        adminMeni();
                        opcija = unesiCijeliBroj();
                        switch(opcija){
                            case 1:{
                                Radnici r = unosRadnika();
                                listaRadnika.push_back(r);
                                cout<<"Radnik uspjesno dodan!"<<endl;
                                break;
                            }
                            case 2:{
                                Doktori d = unosDoktora();
                                listaDoktora.push_back(d);
                                cout<<"Medicinar uspjesno dodan!"<<endl;
                                break;
                            }
                            case 3:{
                                Usluge u = unosUsluge();
                                listaUsluga.push_back(u);
                                cout << "Usluga uspjesno dodana!" << endl;
                                break;
                            }
                            case 4:
                                editDoktora(listaDoktora);
                                break;
                            case 5:
                                editRadnika(listaRadnika);
                                break;
                            case 6:
                                editUslugu(listaUsluga);
                                break;
                            case 7:
                                obrisiRadnika(listaRadnika);
                                break;
                            case 8:
                                obrisiDoktora(listaDoktora);
                                break;
                            case 9:
                                obrisiUslugu(listaUsluga);
                                break;
                            case 10:
                                prikaziRadnika(listaRadnika);
                                break;
                            case 11:
                                prikaziDoktore(listaDoktora);
                                break;
                            case 12:
                                prikaziUsluge(listaUsluga);
                                break;
                            case 13:
                                cout<<"Izlaz iz menija..."<<endl;
                                break;
                            default:
                                cout<<"Nevalidan unos!"<<endl;
                                system("cls");
                                system("pause");
                                return 0;
                        }
                    } else {
                        cout<<"Pogresan password!"<<endl;
                        cout<<"PRISTUP ZABRANJEN!"<<endl;
                        opcija = 13; // izlaz iz menija
                    }
                } while(opcija!=13);
                break;
            }

            case 4:
                cout << "Izlaz iz programa..." << endl;
                system("cls");
                system("pause");
                return 0;

            default:
                cout << "Pogresan unos!" << endl;
        }

        cout << "\nPritisnite enter za povratak u glavni meni...";
        cin.get();
        system("cls");
        system("pause");
    }

    return 0;
}
string unesiString() {
    string s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // počisti ostatak linije nakon cin >>
    getline(cin, s);

    while (s.empty()) {
        cout << "Nevalidan unos. Pokusajte ponovo: ";
        getline(cin, s);
    }
    return s;
}
long long unesiCijeliBroj() {
    long long x;
    while (true) {
        if (cin >> x) return x;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nevalidan unos. Pokusajte ponovo: ";
    }
}
long long unesiRealniBroj() {
    long long x;
    while (true) {
        if (cin >> x) return x;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nevalidan unos. Pokusajte ponovo: ";
    }
}
