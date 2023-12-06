typedef void Objet;
typedef int  booleen;

#ifndef ARBRE_H_INCLUEDED
#define ARBRE_H_INCLUEDED
#include <stdio.h>
#include <stdlib.h>
#define faux 0 
#define vrai 1 

typedef struct Noeud
{
	Objet* reference;
	struct noeud* gauche;
	struct noeud* droite;
} Noeud;

typedef struct{
	Noeud* racine;
	char* (*afficher) (Objet*);
	int (*comparer) (Objet*, Objet*);
} Arbre;

typedef struct element{
	Objet* reference;
	struct element* suivant;
}Element;

typedef struct {
	Element* premier;
	Element* dernier;
	Element* courant;
	int nbElt;
	int type;
	char* (*afficher)(Objet*);
	int (*comparer)(Objet*,Objet*);
}Liste;



void     initListe              (Liste* li, int type, char* (*afficher) (Objet*), int (*comparer) (Objet*, Objet*) );
Liste* creerListe(int type, char*(*afficher)(Objet*),int (*comparer)(Objet*,Objet*));
booleen listeVide(Liste*li);
void insererEnTeteDeListe(Liste* li , Objet* objet);
void insererEnFinDeListe(Liste * li, Objet * objet);
static void insererApres(Liste* li,Element* precedent,Objet* objet);
static Element* creeElement();
Objet* extraireEnTeteDeListe(Liste* li);
Noeud* cNd (Objet* objet, Noeud* gauche, Noeud* droite);
Noeud* cf(Objet* objet);
void initArbre(Arbre* arbre, Noeud* racine,char*(*afficher)(Objet*),int(*comparer)(Objet*,Objet*));
Arbre* creerArbre(Noeud* racine, char*(*afficher)(Objet*),int(*comparer)(Objet*,Objet*));
Arbre* creerArbreGene ();
char* afficher(Objet* objet);
void prefixe(Noeud* racine, char* (*afficher)(Objet*));
void infixe (Noeud* racine, char*(*afficher)(Objet*));
void postfixe(Noeud* racine, char*(*afficher)(Objet*));
Noeud* trouverNoeud(Noeud* racine,Objet* objet, int(*comparer)(Objet*,Objet*));
void enLargeur (Noeud* racine, char* (*afficher)(Objet*));
int taille(Noeud* racine);
int hauteur (Noeud* racine);


#endif
