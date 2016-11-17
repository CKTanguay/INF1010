#ifndef MONDE_MAGIQUE_H
#define MONDE_MAGIQUE_H

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

template<typename T, typename S>

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

	template<class PredicatUnaire>
	void supprimerMaitre(PredicatUnaire foncteur);

	template<class PredicatUnaire>
	void supprimerCompagnon(PredicatUnaire foncteur);

	void vider();

	//operateur +=
	//operateur -=

protected:
	list<T*> listMaitre_;
	list<S*> listCompagnon_;

};


template<typename T, typename S>
MondeMagique<T, S>::MondeMagique() {}


template<typename T, typename S>
MondeMagique<T, S>::~MondeMagique() {}


template<typename T, typename S>
list<T*> MondeMagique<T, S>::getListMaitre() const
{
	return listMaitre_;
}


template<typename T, typename S>
void MondeMagique<T, S>::setListMaitre(const list<T*> listMaitre)	//attention a leperluette en haut
{

}



template<typename T, typename S>
list<S*> MondeMagique<T, S>::getListCompagnon() const
{
	return listCompagnon_;
}



template<typename T, typename S>
template<class PredicatUnaire>
void MondeMagique<T, S>::supprimerMaitre(PredicatUnaire foncteur)
{
	listMaitre_.remove_if(listMaitre_.begin(), listMaitre_.end(), foncteur);
}



#endif

