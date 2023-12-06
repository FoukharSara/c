#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbre.h"


Noeud* cNd (Objet* objet, Noeud* gauche, Noeud* droite)
{
	Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
	nouveau->reference = objet;
	nouveau->gauche=gauche;
	nouveau->droite = droite;
return nouveau;
}
Noeud* cf(Objet* objet)
{
	return cNd(objet, NULL, NULL);
}

char*afficher(Objet* objet){
	char* N=(char*)objet;
	return N;
}

void initListe(Liste* li, int type, char* (*afficher) (Objet*),int(*comparer)(Objet*,Objet*)){
	li->premier=NULL;
	li->dernier=NULL;
	li->courant=NULL;
	li->nbElt=0;
	li->type=type;
	li->afficher=afficher;
	li->comparer=comparer;
}

Liste* creerListe(int type, char*(*afficher)(Objet*),int (*comparer)(Objet*,Objet*)){
	Liste* li=(Liste*)malloc(sizeof(Liste));
	initListe(li,type,afficher,NULL);
	return li;
}
booleen listeVide(Liste*li){
	return li->nbElt==0;
}

void insererEnTeteDeListe(Liste* li , Objet* objet){
	Element* nouveau =creeElement();
	nouveau->reference=objet;
	nouveau->suivant=li->premier;
	li->premier=nouveau;
	if(li->dernier==NULL)li->dernier = nouveau;
	li->nbElt++;
}
void insererEnFinDeListe(Liste * li, Objet * objet){
	insererApres(li,li->dernier,objet);
}

static void insererApres(Liste* li,Element* precedent,Objet* objet){
	if(precedent == NULL){
		insererEnTeteDeListe(li,objet);
	}else{
		Element* nouveau = creeElement();
		/*!!!!!!!!!!!!!!!!dont forget this line below!!!!!!!!!!!!!!!!!!*/
		nouveau->reference=objet;
		nouveau->suivant=precedent->suivant;
		precedent->suivant=nouveau;
		/*!!!!!!!!!!!!!!!!why not use the function!!!!!!!!!!!!!!!!!!*/
		if(precedent == li->dernier) li->dernier=nouveau;
		li->nbElt++;
	}
}
static Element* creeElement(){
	return (Element*) malloc(sizeof(Element));
}

Objet* extraireEnTeteDeListe(Liste* li){
	Element* extrait = li->premier;
	if(!listeVide(li)){
		li->premier=li->premier->suivant;
		if(li->premier==NULL)li->dernier=NULL;
		li->nbElt--;
	}
	return extrait != NULL ? extrait->reference : NULL;
}

void initArbre(Arbre* arbre, Noeud* racine,char*(*afficher)(Objet*),int(*comparer)(Objet*,Objet*))
{
	arbre->racine = racine;
	arbre->afficher=afficher;
	arbre->comparer=comparer;
}
Arbre* creerArbre(Noeud* racine, char*(*afficher)(Objet*),int(*comparer)(Objet*,Objet*))
{
	Arbre* arbre = (Arbre*)malloc(sizeof(Arbre));
	initArbre(arbre,racine,afficher,comparer);
	return arbre;
}

Arbre* creerArbreGene () {
	Noeud* racine = 
	cNd ( "Samir",
		cNd ( "Kamal",
			cNd ( "Yassine",
				NULL,
					cNd("HIND",NULL,cf ("Yasmine")) 
					),
					cNd("Sarh",cf ("Karim"),NULL) 
					),
				NULL
			);
return creerArbre (racine,afficher,NULL);
}

void prefixe(Noeud* racine, char* (*afficher)(Objet*))
{
	if(racine != NULL)
	{
		
		printf("%s",afficher(racine->reference));
		prefixe(racine->gauche,afficher);
		prefixe(racine->droite,afficher);
	}
}

void infixe (Noeud* racine, char*(*afficher)(Objet*))
{
	if(racine!=NULL)
	{
		infixe(racine->gauche,afficher);
		printf("%s",afficher(racine->reference));
		infixe(racine->droite,afficher);
	}
}

void postfixe(Noeud* racine, char*(*afficher)(Objet*))
{
	if(racine!=NULL)
	{
		postfixe(racine->gauche,afficher);
		postfixe(racine->droite,afficher);
		printf("%s ",afficher(racine->reference));
	}
}

Noeud* trouverNoeud(Noeud* racine,Objet* objet, int(*comparer)(Objet*,Objet*))
{
	Noeud* pNom;
	if(racine == NULL)
	{
		pNom = NULL;
	}else if(comparer(racine->reference,objet)==0)
	{
		pNom = racine;
	}
	else{
		pNom=trouverNoeud(racine->gauche,objet,comparer);
		if(pNom == NULL) pNom=trouverNoeud(racine->droite,objet,comparer);
	}
	return pNom;
}

void enLargeur (Noeud* racine, char* (*afficher)(Objet*))
{
	Liste* li= creerListe(0,afficher,NULL);
	insererEnFinDeListe(li,racine);
	while(!listeVide(li)){
		Noeud* extrait=(Noeud*) extraireEnTeteDeListe(li);
		printf("%s",afficher(extrait->reference));
		if(extrait->gauche!=NULL)insererEnFinDeListe(li,extrait->gauche);
		if(extrait->droite!=NULL)insererEnFinDeListe(li,extrait->droite);
	}
}

int taille(Noeud* racine)
{
	if(racine == NULL)
	{
		return 0;
	}else{
		return 1+taille(racine->gauche)+taille(racine->droite);
	}
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int hauteur (Noeud* racine)
{
	if(racine == NULL)
	{
		return 0;
	}
	else 
	{
		return 1+max(hauteur (racine->gauche),hauteur(racine->droite));
	}
}










