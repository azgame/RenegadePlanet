// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"
#include "ItemDispatcher.h"
#include "Templates/UniquePtr.h"
#include "UObject/UObjectBase.h"

AInventory::AInventory()
{

}

AInventory::~AInventory()
{
}

void AInventory::Initialize(int maxSize_, AActor* owner_)
{
	maxSize = maxSize_;
	owner = owner_;
	itemCount = 0;
	items = inventory_type{};
}

AInventory::inventory_type AInventory::getContents()
{
	return items;
}

AItem* AInventory::getItem(FString itemID_)
{
	if (items.Contains(itemID_))
	{
		return items.Find(itemID_)->Key;
	}
	return nullptr;
}

AItem* AInventory::takeItem(FString itemID_, int & stackSize_, int amount_)
{
	if (items.Contains(itemID_))
	{
		AItem* itemRet = items.Find(itemID_)->Key;
		stackSize_ = items.Find(itemID_)->Value;
		if (items.Find(itemID_)->Value >= amount_)
		{
			items.Find(itemID_)->Value -= amount_;
			stackSize_ = amount_;
			itemCount -= amount_;
		}
		else
		{
			stackSize_ = items.Find(itemID_)->Value;
			itemCount -= items.Find(itemID_)->Value;
			items.Find(itemID_)->Value = 0;
		}
		return itemRet;
	}

	return nullptr;
}

void AInventory::addItem(FString itemID_)
{
	if (!isFull())
	{
		if (items.Contains(itemID_))
		{
			if (items.Find(itemID_)->Key->stackable())
			{
				items.Find(itemID_)->Value += 1;
				itemCount++;
			}
		}
	}
}

void AInventory::emplaceItem(FString itemID_, AItem* item_)
{
	if (!isFull())
	{
		if (!items.Contains(itemID_))
		{
			items.Add(itemID_, TPair<AItem*, int> { item_, 1 } );
			itemCount++;
		}
		else
		{
			this->addItem(itemID_);
		}
	}
}

void AInventory::useItem(FString itemID_, AActor* user_)
{
	TPair<AItem*, int>* itemPair = items.Find(itemID_);

	if (itemPair != nullptr)
	{
		ItemDispatcher dispatcher { user_ };

		auto& item = itemPair->Key;

		if (item->equippable())
		{
			dispatcher.setTarget(owner);
			if (item->isEquipped())
			{
				item->setEquip(false);
				item->use(dispatcher);
			}
			else
			{
				item->setEquip(true);
				item->use(dispatcher);
			}
			return;
		}
		else
		{
			dispatcher.setTarget(user_);
			item->use(dispatcher);
		}

		if (!item->reusable())
		{
			if (!item->stackable())
				removeItem(itemID_);
			else
			{
				if (itemPair->Value > 1) itemPair->Value -= 1;
				else removeItem(itemID_);
			}
			itemCount--;
		}
	}
}

void AInventory::removeItem(FString itemID_)
{
	TPair<AItem*, int>* item_ = items.Find(itemID_);

	if (item_->Key != nullptr)
	{
		if (item_->Key->stackable())
		{
			item_->Value -= 1;
			if (item_->Value == 0)
				items.Remove(itemID_);
		}
		else
		{
			items.Remove(itemID_);
		}

		itemCount--;
	}
}

int AInventory::getMaxSize()
{
	return maxSize;
}

void AInventory::merge(AInventory* other_)
{
	if (mergeFits(other_))
	{
		/*for (auto elem : other_->getContents())
		{
			this->items.Add(elem.Key, elem.Value);
		}*/

		other_->clear();
	}
}

bool AInventory::mergeFits(AInventory* other_)
{
	return !(isFull() || other_->getCount() + this->getCount() > this->getMaxSize());
}

void AInventory::transfer(AInventory* other_, FString itemID_, int amount_)
{
	if (!other_->isFull())
	{
		other_->getContents().Add(itemID_, *items.Find(itemID_));

		this->removeItem(itemID_);
		itemCount--;
	}
}

bool AInventory::isEmpty()
{
	return itemCount == 0;
}

bool AInventory::isFull()
{
	return itemCount == maxSize;
}

void AInventory::setInventoryOwner(AActor* owner_)
{
	owner = owner_;
}

AActor* AInventory::getInventoryOwner()
{
	return owner;
}

bool AInventory::contains(FString itemID_)
{
	return items.Contains(itemID_);
}

int AInventory::getItemCount(FString itemID_)
{
	if (contains(itemID_))
		return items.Find(itemID_)->Value;

	return -1;
}

int AInventory::getCount()
{
	return itemCount;
}

void AInventory::clear()
{
	items.Empty();
	itemCount = 0;
}
