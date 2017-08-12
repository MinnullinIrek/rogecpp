#include "stdafx.h"
#include <unordered_map>

#include "Unit.h"
#include "Mover.h"
#include "Characs.h"
#include "Value.h"
#include "Bag.h"
#include "Cell.h"

struct Unit::Impl
{
	Name name;
	unique_ptr<Mover> mover;
	unique_ptr<Characs> chars;
	shared_ptr<Bag> bag = make_shared<Bag>();

	unordered_map<wstring, shared_ptr<Item>> wearingItems;


};

wstring Unit::getName(Type t)
{
	return impl->name.name_descr[t];
}

void Unit::setName(wstring&& nm, Type t)
{
	impl->name.name_descr[t] = nm;
}

wchar_t Unit::getChar()
{
	return impl->name.ch;
}

void Unit::setMover(Mover* mover)
{
	impl->mover.reset(mover);
}

auto Unit::moveTo(crd row, crd col) -> void
{
	if (impl->mover)
		impl->mover->moveTo(Coords{ row, col });
}

auto Unit::directTo(crd row, crd col) -> void
{
	if (impl->mover)
		impl->mover->directTo(Coords{ row, col });
}

shared_ptr<Cell> Unit::currentCell()
{
	return impl->mover->getCurrentCell();
}

Coords Unit::getCoord()
{
	return impl->mover->getCoord();
}

Value & Unit::getParam(const wstring& param)
{
	return impl->chars->getChar(param);
}

void Unit::initParams()
{
	impl->chars.reset(new Characs());
}

void Unit::destroy()
{
	auto cell = impl->mover->getCurrentCell();
	auto bag = cell->getBag();

	 
	impl->bag->forEach([bag](shared_ptr<Item> item) { bag->push_back(item); });

	impl->mover->clear();

	this->impl->name.ch = 'Z';
}

auto Unit::getBag() -> shared_ptr<Bag>
{
	return impl->bag;
}

Unit::Unit(wchar_t ch) :impl(make_unique<Impl>())
{
	impl->name.ch = ch;
	cooperator = [](shared_ptr<Unit> attacker, shared_ptr<ISpaceObject> defender) {
		if (defender) {
			auto defUnit = dynamic_cast<Unit*>(defender.get());

			if (defUnit != nullptr) {
				auto & defValHp = defUnit->getParam(L"hp");
				auto &attValAt = attacker->getParam(L"attack");

				defValHp -= attValAt;
			}
		}		
	};
}


Unit::~Unit()
{
}

Unit::operator wchar_t()
{
	return getChar();
}
