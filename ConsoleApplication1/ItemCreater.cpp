#include "stdafx.h"
#include "ItemCreater.h"
#include "IItem.h"
#include "Value.h"
#include "unit.h"


ItemCreater::ItemCreater()
{
}


ItemCreater::~ItemCreater()
{
}

shared_ptr<Item> ItemCreater::createItem(wstring name)
{
	shared_ptr<Item> item = make_shared<Item>(ItemType::armour);

	item->setName(INameble::Type::name, name);

	return item;
}

shared_ptr<Item> ItemCreater::createWeapon(wstring name, double att)
{
	auto wp = make_shared<Item>();
	wp->setName(INameble::Type::name, name);
	wp->getParam(L"attack") = att;

	wp->setCooperator(L"attack", [wp](shared_ptr<Unit> attacker, shared_ptr<Unit> defender)
		{ 
			attacker->getParam(L"attack") * wp->getParam(L"attack"); 
			defender->getParam(L"hp") -= attacker->getParam(L"attack") * wp->getParam(L"attack");
		} );

	return wp;
}
