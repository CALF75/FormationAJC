#ifndef HEURE_H
#define HEURE_H


class heure
{
public:
    heure();
    heure(int, int, int);
    int h;
    int m;
    int s;
    void affiche();
    heure operator+(heure);
};

#endif // HEURE_H
