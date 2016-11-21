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

	void setListMaitre(const list<T*>& maitre);

	list<S*> getListCompagnon() const;

	void setListCompagnon(const list<S*>& compagnon);

	void ajouterMaitre(const T& maitre);

	void ajouterCompagnon(const S& compagnon);

	void supprimer(const T& maitre);

	void supprimer(const S& compagnon);

	//ne pas oublier de creer un iterateur pour find!!
	//faire un foncteur pour supprimer maitre

	template<class PredicatUnaire>
	void supprimerMaitre(PredicatUnaire foncteur);

	template<class PredicatUnaire>
	void supprimerCompagnon(PredicatUnaire foncteur);

	void vider();

	MondeMagique//op+=
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
void MondeMagique<T, S>::setListMaitre(const list<T*>& listMaitre)		//vraiment pas sur ici si cest bon
{
	listMaitre_ = listMaitre;
}


template<typename T, typename S>
list<S*> MondeMagique<T, S>::getListCompagnon() const
{
	return listCompagnon_;
}


template<typename T, typename S>
void MondeMagique<T, S>::setListCompagnon(const list<S*>& listCompagnon)
{
	listCompagnon_ = listCompagnon;
}


template<typename T, typename S>
void MondeMagique<T, S>::ajouterMaitre(const T& maitre)
{
	listMaitre_.push_back(maitre);
}


template<typename T, typename S>
void MondeMagique<T, S>::ajouterCompagnon(const S& compagnon)
{
	listCompagnon_.push_back(compagnon);
}


template<typename T, typename S>
void MondeMagique<T, S>::supprimer(const T& maitre)
{
	auto positionM = find(listMaitre_.begin(), listMaitre_.end(), &maitre);
	if (positionM != listMaitre_.end())
	{
		listMaitre_.erase(positionM);
	}
}



template<typename T, typename S>
void MondeMagique<T, S>::supprimer(const S& compagnon)
{
	auto positionC = find(listCompagnon_.begin(), listCompagnon_.end(), &compagnon);
	if (positionC != listCompagnon_.end())
	{
		listCompagnon_.erase(positionC);
	}
}


template<typename T, typename S>
template<class PredicatUnaire>
void MondeMagique<T, S>::supprimerMaitre(PredicatUnaire foncteur)
{
	listMaitre_.remove_if(listMaitre_.begin(), listMaitre_.end(), foncteur);
}

template<typename T, typename S>
template<class PredicatUnaire>
void MondeMagique<T, S>::supprimerCompagnon(PredicatUnaire foncteur)
{
	listCompagnon_.remove_if(listCompagnon_.begin(), listCompagnon_.end(), foncteur);
}


template <typename T, typename S>
void MondeMagique<T, S>::vider()
{
	listMaitre_.clear();
	listCompagnon_.clear();
}



#endif