#include "stdafx.h"
#include <unordered_map>
#include <list>

#include "Bag.h"
#include "IItem.h"


struct Bag::Impl
{
	unordered_map<ItemType, list<shared_ptr<Item>>> items;
//	unordered_map<ItemType, shared_ptr<Item>>::iterator it;
	int size = 0;
	list<shared_ptr<Item>> *curentList;
	shared_ptr<Item> currentItem;
};

Bag::Bag():impl(make_unique<Impl>())
{
}


Bag::~Bag()
{
}

auto Bag::getSize() -> int
{
	return impl->size;
}

auto Bag::push_back(shared_ptr<Item> item) -> void
{
	impl->items[item->getType()].push_back(move(item));
	impl->size++;
}

void Bag::forEach(function<BagItemDo(shared_ptr<Item>item)> func)
{
	for (auto &itList : impl->items) {		
		for (auto it : itList.second) {
			if ( !it) {
				itList.second.remove(it);
			}
			else {
				
				auto state = func(it);
				
				if (state == BagItemDo::stop)
					goto stop;
				else if (state == BagItemDo::select) {
					impl->curentList  = &itList.second;
					impl->currentItem = it;
				}
				else if(state == BagItemDo::eraseStop) {
					itList.second.remove(it);
					impl->size--;
					goto stop;
				}
			}
		}
	}
stop:
	return;
}



