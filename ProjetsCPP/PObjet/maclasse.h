#ifndef MACLASSE_H
#define MACLASSE_H


class MaClasse
{
public:
    MaClasse();
    MaClasse(const MaClasse &a);

int membre;
int* pm;

void AfficheMembre();
void AfficheContenuPointeur();
};

#endif // MACLASSE_H
