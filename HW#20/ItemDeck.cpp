#include "ItemDeck.h"

#include "Item.h"
#include <algorithm> // This for std::random_shuffle

std::vector<Item*> ItemDeck::generateItems() const {
	std::vector<Item*> available = m_itemsDataBase;
	std::random_shuffle(available.begin(), available.end());
	return { available.front() };
}

ItemDeck::ItemDeck()
{
	//TODO: Move item's database to file in format:
	// type;name; params for the type
	//For example:
	//UndeadWeapon;"Holy Grenade";4		//should call UndeadWeapon("Holy Grenade", 4);

	//TODO: Setup more items of diferent types
	m_itemsDataBase =
	{ new Weapon{"The Sword of DOOM", 5},
	new UndeadWeapon{"Stinky knife", 2},
	new UndeadWeapon{"Holy grenade", 4},
	new HolySword(),
	new MagicWeapon{"HOLLY MOLLY", 4}};
}

ItemDeck::~ItemDeck()
{
	//TODO: FREE MEMORY
	for (auto item : m_itemsDataBase) {
		delete item;
	}
}

std::vector<Item*> ItemDeck::generateItems() const
{
	//TODO: PICK AT RANDOM SEVERAL ITEMS FROM DATABASE AS A PLAYER HAND
	return m_itemsDataBase;
} 