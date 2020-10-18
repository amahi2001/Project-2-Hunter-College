/****************************************************************************************************************************
Title        : ShoppingCart.cpp
Auhors       : Nursima Donuk & Nigel Ferrer
Description  : implementation file of a ShoppingCart class which inherits from the ArrayBag class
Dependencies : ArrayBag.hpp, Grocery.hpp, ShoppingCart.hpp, <iomanip>
****************************************************************************************************************************/

#include <iomanip>
#include "ShoppingCart.hpp"

/* Default Constructor */
ShoppingCart::ShoppingCart() : ArrayBag()
{
}

/* Destructor */
ShoppingCart::~ShoppingCart()
{
    curr_contents_weight_ = 0;
}

/* adds new_entry to caller */
bool ShoppingCart::add(Grocery *new_entry)
{
    if (new_entry->getUnitWeight() + curr_contents_weight_ <= CARRYING_CAP)
    {
        if (contains(new_entry))
        {
            int found_index = getIndexOf(new_entry);
            items_[found_index]->incrementQuantity();
            curr_contents_weight_ += new_entry->getUnitWeight();
        }
        else
        {
            ArrayBag::add(new_entry);
            curr_contents_weight_ += new_entry->getUnitWeight();
        }
        return true;
    }
    return false;
}

/* remove an_item from caller */
bool ShoppingCart::remove(Grocery *an_item)
{
    bool already_contains = contains(an_item);
    if (already_contains)
    {
        int found_index = getIndexOf(an_item);
        items_[found_index]->decrementQuantity();
        curr_contents_weight_ -= an_item->getUnitWeight();
        garbageClear();
        return true;
    }
    return false;
}

/* clears shopping cart of items with quantity_ == 0*/
void ShoppingCart::garbageClear()
{
    for (size_t i = 0; i < item_count_; i++)
    {
        if (items_[i]->getQuantity() == 0)
        {
            ArrayBag::remove(items_[i]);
        }
    }
}

Grocery **ShoppingCart::getItems()
{
    return items_;
}

/* formatted display */
double ShoppingCart::checkout()
{
    if (item_count_ == 0)
    {
        std::cout << "Your cart is empty!" << std::endl;
        return 0;
    }

    double total = 0;
    for (size_t i = 0; i < item_count_; i++)
    {
        std::cout << "\n"
                  << std::setw(10) << std::left << items_[i]->getName() << "\t" << items_[i]->getQuantity() << "\t" << std::fixed << std::setprecision(2) << items_[i]->getTotalPrice();
        total += items_[i]->getTotalPrice();
    }
    std::cout << std::setfill('-') << std::setw(40) << "\n"
              << std::endl
              << "Total:                  " << total << std::endl
              << std::endl;

    clear();
    return total;
}

/* Accessor: curr_contents_weight_ */
double ShoppingCart::getCurrentWeight()
{
    return curr_contents_weight_;
}

bool ShoppingCart::operator>(ShoppingCart a_cart)
{
    double a_total=0;   //setting this total and a_carts total to 0
    double thisTotal=0;
    
    for (int i = 0; i < a_cart.item_count_; i++) //looping through a_cart
    {
        a_total += a_cart.items_[i]->getTotalPrice(); //adding the price of all items together
    }

    for (int i = 0; i < this->item_count_; i++) //looping through this cart
    {
        thisTotal += this->items_[i]->getTotalPrice(); //adding the price of all items together 
    }

    if (thisTotal > a_total) //if this cart is more expensive 
    {
        return true; //true if true
    }
    else // if a_cart is more expensive
    {
        return false; 
    }
}

bool ShoppingCart::operator<(ShoppingCart a_cart)
{
    double a_total =0; //setting this total and a_carts total to 0
    double thisTotal=0;
    
    for (int i = 0; i < a_cart.item_count_; i++)//looping through a_cart
    {
        a_total += a_cart.items_[i]->getTotalPrice();//adding the price of all items together
    }

    for (int i = 0; i < this->item_count_; i++)//looping through this cart
    {
        thisTotal += this->items_[i]->getTotalPrice();//adding the price of all items together
    }

    if (thisTotal < a_total) //if this cart is less expensive
    {
        return true; //true if true
    }
    else
    {
        return false; //false if false
    }
}