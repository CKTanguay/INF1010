#ifndef MONDE_MAGIQUE_H
#define MONDE_MAGIQUE_H

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

template<typename T, typename S, class PredicatUnaire>

class MondeMagique
{
public:
	MondeMagique();
	~MondeMagique();

	list<T*> getListMaitre() const;

	void setListMaitre(const T& maitre);

	list<S*> getListCompagnon() const;

	void setListCompagnon(const S& compagnon);

	void ajouter(const T& maitre);

	void ajouter(const S& compagnon);


	void supprimer(const T& maitre);

	void supprimer(const S& compagnon);

	//ne pas oublier de creer un iterateur pour find!!
	//faire un foncteur pour supprimer maitre

	void supprimerMaitre(PredicatUnaire foncteur);

	void supprimerCompagnon(PredicatUnaire foncteur);

private:
	list<T*> listMaitre_;
	list<S*> listCompagnon_;

};


template<typename T, typename S, class PredicatUnaire>
MondeMagique<T, S, PredicatUnaire>::MondeMagique()
{

}

template<typename T, typename S, class PredicatUnaire>
void MondeMagique<T, S, PredicatUnaire>::supprimerMaitre(PredicatUnaire foncteur)
{
	remove_if(listMaitre_.begin(), listMaitre_.end(), foncteur);
}



#endif

