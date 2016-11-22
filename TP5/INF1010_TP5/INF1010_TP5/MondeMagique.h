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

	void ajouterMaitre(T& maitre);

	void ajouterCompagnon(S& compagnon);

	void supprimer(const T& maitre);

	void supprimer(const S& compagnon);

	template<class PredicatUnaire>
	void supprimerMaitre(PredicatUnaire foncteur);

	template<class PredicatUnaire>
	void supprimerCompagnon(PredicatUnaire foncteur);

	void vider();

	MondeMagique& operator+=(T& maitre);
	MondeMagique& operator+=(S& compagnon);

	MondeMagique& operator-=(const T& maitre);
	MondeMagique& operator-=(const S& compagnon);

protected:
	std::list<S*> listCompagnon_;
	std::list<T*> listMaitre_;


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
void MondeMagique<T, S>::setListMaitre(const list<T*>& listMaitre)
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


/**
* La fonction ajouterMaitre ajoute un dreseur � la liste de dresseurs.
* \param[IN] maitre Ce param�tre repr�sente le dresseur a ajouter dans la liste.
*/
template<typename T, typename S>
void MondeMagique<T, S>::ajouterMaitre(T& maitre)
{
	listMaitre_.push_back(&maitre);
}


/**
* La fonction ajouterCompagnon ajoute une cr�ature � la liste de cr�atures.
* \param[IN] compagnon Ce param�tre repr�sente la cr�ature � ajouter dans la liste.
*/
template<typename T, typename S>
void MondeMagique<T, S>::ajouterCompagnon(S& compagnon)
{
	listCompagnon_.push_back(&compagnon);
}



/**
* La fonction supprimer retire un dreseur de la liste de dresseurs.
* \param[IN] maitre Ce param�tre repr�sente le dresseur � retirer de la liste.
*/
template<typename T, typename S>
void MondeMagique<T, S>::supprimer(const T& maitre)
{
	auto positionM = find(listMaitre_.begin(), listMaitre_.end(), &maitre);
	if (positionM != listMaitre_.end())
	{
		listMaitre_.erase(positionM);
	}
}



/**
* La fonction supprimer retire une cr�ature de la liste de cr�atures.
* \param[IN] compagnon Ce param�tre repr�sente la cr�ature � retirer de la liste.
*/
template<typename T, typename S>
void MondeMagique<T, S>::supprimer(const S& compagnon)
{
	auto positionC = find(listCompagnon_.begin(), listCompagnon_.end(), &compagnon);
	if (positionC != listCompagnon_.end())
	{
		listCompagnon_.erase(positionC);
	}
}


/**
* La fonction supprimerMaitre retire les dresseurs ne correspondant pas au pr�dicat.
* \param[IN] foncteur Ce param�tre repr�sente le pr�dicat servant � s�lectionner les dreseurs � supprimer.
*/
template<typename T, typename S>
template<class PredicatUnaire>
void MondeMagique<T, S>::supprimerMaitre(PredicatUnaire foncteur)
{
	listMaitre_.remove_if(foncteur);
}


/**
* La fonction supprimerCompagnon retire les cr�atures ne correspondant pas au pr�dicat.
* \param[IN] foncteur Ce param�tre repr�sente le pr�dicat servant � s�lectionner les dreseurs � supprimer.
*/
template<typename T, typename S>
template<class PredicatUnaire>
void MondeMagique<T, S>::supprimerCompagnon(PredicatUnaire foncteur)
{
	listCompagnon_.remove_if(foncteur);
}


/**
* La fonction vider tous les �l�ments des deux listes.
*/
template <typename T, typename S>
void MondeMagique<T, S>::vider()
{
	listMaitre_.clear();
	listCompagnon_.clear();
}



/**
* L'op�rateur += ajoute un dreseur � la liste de dresseurs.
* \param[IN] maitre Ce param�tre repr�sente le dresseur � ajouter dans la liste.
* \return La fonction retourne un monde magique.
*/
template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator+=(T& maitre)
{
	this->ajouterMaitre(maitre);
	return *this;
}


/**
* L'op�rateur += ajoute un compagnon � la liste de cr�atures.
* \param[IN] compagnon Ce param�tre repr�sente la cr�ature � ajouter dans la liste.
* \return La fonction retourne un monde magique.
*/
template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator+=(S& compagnon)
{
	this->ajouterCompagnon(compagnon);
	return *this;
}


/**
* L'op�rateur -= retire un dreseur de la liste de dresseurs.
* \param[IN] maitre Ce param�tre repr�sente le dresseur � retirer de la liste.
* \return La fonction retounre un monde magique.
*/
template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator-=(const T& maitre)
{
	this->supprimer(maitre);
	return *this;
}


/**
* L'op�rateur -= retire une cr�ature de la liste de cr�atures.
* \param[IN] compagnon Ce param�tre repr�sente la cr�ature � retirer de la liste.
* \return La fonction retounre un monde magique.
*/
template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator-=(const S& compagnon)
{
	this->supprimer(compagnon);
	return *this;
}
#endif