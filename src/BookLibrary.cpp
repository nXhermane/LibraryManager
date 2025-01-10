#include "BookLibrary.h"
#include "Livre.h"
#include "LibraryFunction.h"
#include <iostream>
#include <limits>

BookLibraryManager::BookLibraryManager()
{
    bookSize = 0;
    libraryBooks = nullptr;
    init();
}
BookLibraryManager::BookLibraryManager(const int bookLength, Livre *livres) : bookSize(bookLength), libraryBooks(livres)
{
    init();
}
BookLibraryManager::~BookLibraryManager()
{
    for (int i = 0; i < bookSize; i++)
    {
        delete[] libraryBooks[i].auteur;
        delete[] libraryBooks[i].titre;
        delete[] libraryBooks[i].genre;
    }
    delete[] libraryBooks;
}

void BookLibraryManager::init()
{
    bool condition = true;
    std::cout << "Bienvenue dans la bibliotheque" << std::endl;
    while (condition)
    {
        showMenu();
        int choice;
        while (true)
        {
            std::cout << "Votre choix : ";
            std::cin >> choice;
            if (std::cin.fail())
            {
                std::cout << "Entrer un nombre entier parmis ceux du menu" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
                break;
        }

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            showAllBook();
            break;
        case 3:
            searchBookByTitle();
            break;
        case 4:
            deleteByTitle();
            break;
        case 5:
        {
            if (confirmationFunction("Voulez-vous vraiment quitter la library ? (y/n) default(n) "))
                condition = false;
            else
                continue;
        };
        break;

        default:
            std::cout << "ERROR: Unknow choice " << choice << std::endl;
        }
    }
}
void BookLibraryManager::showMenu()
{
    std::cout << "___Menu___" << std::endl;
    std::cout << "1. Ajouter un livre" << std::endl;
    std::cout << "2. Afficher tous les livres" << std::endl;
    std::cout << "3. Rechercher un livre par titre" << std::endl;
    std::cout << "4. Supprimer un livre par titre" << std::endl;
    std::cout << "5. Quitter" << std::endl;
}
void BookLibraryManager::addBook()
{
    Livre livre = creerUnLivre();
    std::cout << "Voici le livre que vous souhaitez ajouter." << std::endl;
    afficherUnLivre(livre);
    if (confirmationFunction("Voulez-vous l'ajouter(y) ou annuler(n) ? default(n) : "))
    {
        libraryBooks = ajouterUnLivre(livre, libraryBooks, bookSize);
        std::cout << "Livre ajoute avec success." << std::endl;
    }
    else
        std::cout << "Ajout annule avec success." << std::endl;
}

void BookLibraryManager::showAllBook()
{
    if (bookSize == 0)
    {
        std::cout << "Aucun livre n'est disponible dans la bibliotheque ." << std::endl;
        return;
    }
    for (int i = 0; i < bookSize; i++)
    {
        const Livre book = libraryBooks[i];
        std::cout << "Livre n ̊  " << i << std::endl;
        afficherUnLivre(book);
    }
}

void BookLibraryManager::searchBookByTitle()
{
    std::cin.ignore();
    char *bookTitle = new char[maxChar];
    std::cout << "Entrez le titre du livre que vous recherchez : ";
    std::cin.getline(bookTitle, maxChar);
    rechercherUnLivre(bookTitle, libraryBooks, bookSize);
    delete[] bookTitle;
}

void BookLibraryManager::deleteByTitle()
{
    std::cin.ignore();
    char *bookTitle = new char[maxChar];
    std::cout << "Entrez le titre du livre que vous voulez supprimer : ";
    std::cin.getline(bookTitle, maxChar);
    libraryBooks = supprimerUnLivre(bookTitle, libraryBooks, bookSize);
    delete[] bookTitle;
}