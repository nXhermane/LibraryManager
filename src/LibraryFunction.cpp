#include "LibraryFunction.h"
#include "Livre.h"
#include <iostream>
#include <limits>
#include <cstring>

Livre creerUnLivre()
{
    Livre livre;
    const int maxChar = 200;
    livre.titre = new char[maxChar];
    livre.auteur = new char[maxChar];
    livre.genre = new char[maxChar];
    std::cin.ignore();
    std::cout << "Entrez le titre : ";
    std::cin.getline(livre.titre, maxChar);
    std::cout << "Entrez l'auteur : ";
    std::cin.getline(livre.auteur, maxChar);
    std::cout << "Entrez le genre : ";
    std::cin.getline(livre.genre, maxChar);

    while (true)
    {
        std::cout << "Entrez l'annee de publication : ";
        std::cin >> livre.publicationWeek;
        if (std::cin.fail())
        {
            std::cout << "Veillez entrer un nombre entier." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }

    return livre;
}

void afficherUnLivre(const Livre &livre)
{
    std::cout << "Titre                : " << livre.titre << std::endl;
    std::cout << "Auteur               : " << livre.auteur << std::endl;
    std::cout << "Genre                : " << livre.genre << std::endl;
    std::cout << "Annee de Publication : " << livre.publicationWeek << std::endl;
}

Livre *ajouterUnLivre(const Livre &livre, Livre *livres, int &livresLength)
{
    Livre *newLivresList = new Livre[livresLength + 1];

    for (int i = 0; i < livresLength; i++)
        newLivresList[i] = livres[i];

    newLivresList[livresLength] = livre;

    livresLength++;

    delete[] livres;
    return newLivresList;
}

Livre *supprimerUnLivre(const char *titre, Livre *livres, int &livresLength)
{
    ResultatDeRecherche res = rechercherUnLivreParTitre(titre, livres, livresLength);
    if (res.livre == nullptr)
    {
        std::cout << "ERROR: Le livre que vous voulez supprimer n'existe pas dans votre library." << std::endl;
        return livres;
    }

    Livre *newLivreList = new Livre[livresLength - 1];

    for (int i = 0, countNewLivre = 0; i < livresLength; i++)
    {
        if (res.index == i)
            continue;
        newLivreList[countNewLivre++] = livres[i];
    }
    
    delete[] livres;
    livresLength--;
    return newLivreList;
}

ResultatDeRecherche rechercherUnLivreParTitre(const char *titre, Livre *livres, int &livresLength)
{
    ResultatDeRecherche resultat;
    resultat.livre = nullptr;
    resultat.index = 0;
    for (int i = 0; i < livresLength; i++)
    {
        Livre livre = livres[i];
        if (strstr(titre, livre.titre) != nullptr)
        {
            resultat.livre = &livres[i];
            resultat.index = i;
        }
    }
    return resultat;
}

void rechercherUnLivre(const char *titre, Livre *livres, int &livresLength)
{
    ResultatDeRecherche resultat = rechercherUnLivreParTitre(titre, livres, livresLength);
    if (resultat.livre == nullptr)
    {
        std::cout << "ERROR: Le livre que vous recherchez n'existe pas." << std::endl;
        return;
    }
    std::cout << "====== Voici le livre ======" << std::endl;
    afficherUnLivre(*resultat.livre);
}

bool confirmationFunction(const char *prompt)
{
    std::cout << prompt << " ";
    char confirmChar;
    std::cin >> confirmChar;
    if (confirmChar == 'y')
        return true;
    else
        return false;
}