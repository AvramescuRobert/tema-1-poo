#include <iostream>

using namespace std;

class Polinom{

private:
    int power;
    double *coeficient;
protected:

public:

    Polinom(){};

    Polinom(Polinom &p);

    ~Polinom();

    friend istream &operator>>(istream &in, Polinom &p);

    friend ostream &operator<<(ostream &out, const Polinom &p);

    Polinom operator=(const Polinom &p);

    Polinom operator+(const Polinom &p);

    Polinom operator-(const Polinom &p);

    Polinom operator*(const Polinom &p);

    double valoarePunct(double valoare);
};

//CONSTRUCORI

Polinom::Polinom(Polinom &p){
    power = p.power;
    coeficient = new double[power+1];
    for(int i = 0; i <= power; i++)
        coeficient[i] = p.coeficient[i];

}

/*Polinom::Polinom(int p, double *coefficent){
    while(p < 1){
        cout << "Puterea a fost data gresit. Introdu o putere mai mare sau egala cu 1";
        cin >> p;
    }
Hytale
    power = p;
    this->coeficient = new double[power+1];
    for(int i = 0; i <= power; i++)
        coeficient[i] = coefficent[i];
}*/
// DESTRUCTOR

Polinom::~Polinom(){
    power = 0;
    delete[] coeficient;
}


//OPERATORI CITIRE SI AFISARE
istream &operator>>(istream &in, Polinom &p){
    cout << "Introdu gradul polinomului: ";
    in >> p.power;
    while(p.power < 0){
        cout << "Introdu o putere mai mare sau egala cu 0: ";
        in >> p.power;
    }
    p.coeficient = new double[p.power+1];
    for(int i = 0; i <= p.power; i++){
        cout << "Coeficientul lui x^["<<i<<"]: ";
        in >> p.coeficient[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const Polinom &p){
    cout << "Polinomul este: ";
    for(int i = 0; i < p.power; i++)
        cout << p.coeficient[i]<< "*" << "x^["<<i<<"] + ";
    cout << p.coeficient[p.power]<< "*" << "x^["<<p.power<<"]";
    cout << "\n";
    return out;
}

//OPERATORI OPERATII
Polinom Polinom::operator=(const Polinom &p){
    power = p.power;
    delete[] coeficient;
    coeficient = new double[power+1];
    for(int i = 0; i <= power; i++)
        coeficient[i] = p.coeficient[i];

}

Polinom Polinom::operator+(const Polinom &p){
    Polinom rez;
    if(power < p.power)
        rez.power = p.power;
    else rez.power = power;
    rez.coeficient = new double[rez.power+1];
    for(int i = 0; i <= rez.power; i++){
        if(i <= power)
            if(i <= p.power)
                rez.coeficient[i] = p.coeficient[i] + coeficient[i];
            else rez.coeficient[i] = coeficient[i];
        else rez.coeficient[i] = p.coeficient[i];
    }
    return rez;
}

Polinom Polinom::operator-(const Polinom &p){
    Polinom rez;
    if(power < p.power)
        rez.power = p.power;
    else rez.power = power;
    rez.coeficient = new double[rez.power+1];
    for(int i = 0; i <= rez.power; i++){
        if(i <= power)
            if(i <= p.power)
                rez.coeficient[i] = coeficient[i] - p.coeficient[i];
            else rez.coeficient[i] = coeficient[i];
        else rez.coeficient[i] = -p.coeficient[i];
    }
    return rez;
}

Polinom Polinom::operator*(const Polinom &p){
    Polinom rez;
    rez.power = power + p.power;
    rez.coeficient = new double[rez.power+1];
    for(int i = 0; i <= rez.power; i++)
        rez.coeficient[i] = 0;
    for(int i = 0; i <= power; i++)
        for(int j = 0; j <= p.power; j++)
            rez.coeficient[i+j] = rez.coeficient[i+j] + coeficient[i] * p.coeficient[j];
    return rez;
}

double Polinom::valoarePunct(double n){
    double result = 0, x;
    for(int i = 0; i <= power; i++){
        x = 1;
        for(int j = 1; j <= i; j++)
            x = x * n;
        result = result + coeficient[i] * x;
    }
    cout << "Valoarea este " << result << "\n";
    return result;
}

void afisareMeniu(){
    cout << "Meniu \n";
    cout << " 1) Introdu primul polinom \n";
    cout << " 2) Introdu al doilea polinom \n";
    cout << " 3) Polinom1 + Polinom2 \n";
    cout << " 4) Polinom1 - Polinom2 \n";
    cout << " 5) Polinom1 * Polinom2 \n";
    cout << " 6) Calcul Polinom1 in punctul x \n";
    cout << " 7) Afiseaza polinoamele \n";
    cout << " 0) Exit \n";
    cout << "Introdu varianta: ";
}

int main(){
    char meniuChoice = 'c';
    bool polinom1In = false;
    bool polinom2In = false;
    Polinom p1, p2;
    while(meniuChoice != '0'){
        afisareMeniu();
        cin >> meniuChoice;
        // AICI AM MENIU
        switch(meniuChoice){
            case '1':
                cin >> p1;
                polinom1In = true;
                break;

                case '2':
                cin >> p2;
                polinom2In = true;
                break;

                case '3':
                if(polinom1In == true)
                    if(polinom2In == true)
                        cout << p1 + p2;
                    else cout << "Trebuie sa introduci polinomul 2 \n";
                else cout << "Trebuie sa introduci polinomul 1 \n";
                break;

                case '4':
                if(polinom1In == true)
                    if(polinom2In == true)
                        cout << p1 - p2;
                    else cout << "Trebuie sa introduci polinomul 2 \n";
                else cout << "Trebuie sa introduci polinomul 1 \n";
                break;

                case '5':
                if(polinom1In == true)
                    if(polinom2In == true)
                        cout << p1 * p2;
                    else cout << "Trebuie sa introduci polinomul 2 \n";
                else cout << "Trebuie sa introduci polinomul 1 \n";
                break;

                case '6':
                if(polinom1In == true)
                    if(polinom2In == true){
                        double x;
                        cout << "Introdu punctul: ";
                        cin >> x;
                        cout << p1.valoarePunct(x);
                    }
                    else cout << "Trebuie sa introduci polinomul 2 \n";
                else cout << "Trebuie sa introduci polinomul 1 \n";
                break;

                case '7':
                if(polinom1In == true)
                    cout << p1;
                else cout << "Trebuie sa introduci polinomul 1 \n";
                if(polinom2In == true)
                    cout << p2;
                else cout << "Trebuie sa introduci polinomul 2 \n";

                break;

            default:
                cout <<"Introdu un caracter valid \n";
        }
    }
    return 0;
}
