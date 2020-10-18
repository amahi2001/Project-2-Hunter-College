using namespace std;
template <typename ItemType>
ArrayBag<ItemType>::ArrayBag() : item_count_{0}
{
}

template <typename ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return item_count_;
}

template <typename ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

template <typename ItemType>
bool ArrayBag<ItemType>::add(const ItemType &new_entry)
{
    bool can_Add_Item = (item_count_ < DEFAULT_CAPACITY);
    if (can_Add_Item)
    {
        items_[item_count_] = new_entry;
        item_count_++;
    }
    return can_Add_Item;
}

template <typename ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &an_entry)
{
    int index_ = getIndexOf(an_entry);
    bool can_Remove_Item = !isEmpty() && (index_ > -1);
    if (can_Remove_Item)
    {
        item_count_--;
        items_[index_] = items_[item_count_];
    }
    return can_Remove_Item;
}

template <typename ItemType>
void ArrayBag<ItemType>::clear()
{
    item_count_ = 0;
}

template <typename ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &an_entry) const
{
    return getIndexOf(an_entry) > -1;
}

template <typename ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &an_entry) const
{
    int counter_ = 0;
    int current_Index = 0; //array index currently being inspected

    while (current_Index < item_count_)
    {
        if (items_[current_Index] == an_entry)
        {
            counter_++;
        }
        current_Index++; // increment to the next entry regardless of counter increase or decrease
    }
    return counter_;
}

template <typename ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const
{
    bool found_ = false;
    int result_ = -1;
    int index_ = 0;
    //If bag is empty item_count_ is zero loop is skipped
    while (!found_ && (index_ < item_count_))
    {
        if (items_[index_] == target)
        {
            found_ = true;
            result_ = index_;
        }
        else
        {
            index_++;
        }
    }
    return result_;
}

template <typename ItemType> // +=
void ArrayBag<ItemType>::operator+=(const ArrayBag<ItemType> &a_bag)
{
    if (a_bag.item_count_ + this->item_count_ <= DEFAULT_CAPACITY)
    {
        for (int i = 0; i < a_bag.item_count_; i++)
        {
            if (contains(a_bag.items_[i]) == false)
            {
                this->add(a_bag.items_[i]);
            }
        }
    }
}

template <typename ItemType> // -=
void ArrayBag<ItemType>::operator-=(const ArrayBag<ItemType> &a_bag)
{
    //looping through the items in a_bag
    for (int i = 0; i < a_bag.item_count_; i++)
    {
        bool flag = true;
        if (contains(a_bag.items_[i]) == flag) //if this contains the item
        {
            this->remove(a_bag.items_[i]); //remove the item from this
        }
        break;
    }
}

template <typename ItemType> // /=
void ArrayBag<ItemType>::operator/=(const ArrayBag<ItemType> &a_bag)
{
    //looping through a_bag
    for (int i = 0; i < a_bag.item_count_; i++)
    {
        bool flag = false;
        if (a_bag.contains(items_[i]) == flag) //if the items are not in a_bag
        {
            this->remove(items_[i]); //remove the itrems from this
        }
    }
}

template <typename ItemType> // ==
bool ArrayBag<ItemType>::operator==(const ArrayBag<ItemType> &a_bag)
{
    int this_size = this->item_count_;
    int a_size = a_bag.item_count_;

    if ((this->isEmpty()) && (a_bag.isEmpty())) // if both sets are empty
    {
        return true; // they are equal
    }
    if (this_size == a_size) // if they have the same size
    {
        for (int i = 0; i < this_size; i++) //looping through this
        {
            for (int j = 0; j < this_size; j++)
            {
                if (this->items_[i] != a_bag.items_[j]) //comparing each item in this to a_bag
                {
                    return false; //false if atleast one of the elements are different
                }
                return true; //tru otherwise
            }
        }
    }
    return false; //false otherwise
}

template <typename ItemType> // !=
bool ArrayBag<ItemType>::operator!=(const ArrayBag<ItemType> &a_bag)
{
    int this_size = this->item_count_;
    int a_size = a_bag.item_count_;

    if ((this->isEmpty()) && (a_bag.isEmpty())) //if both sets are empty 
    {
        return false; //they are equal: false 
    }
    if (this_size != a_size) // if they are not the same size
    {
        return true; //return true
    }
    else
    {
        for (int i = 0; i < this_size; i++) //loop through the this 
        {
            for (int j = 0; j < this_size; j++)
            {
                if (this->items_[i] != a_bag.items_[j]) //compare the items in this and a_bag
                {
                    return true; // true if atleast one element is different 
                }
                return false; // false otherwise
            }
        }
    }
}
