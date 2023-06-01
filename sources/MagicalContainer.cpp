# include "MagicalContainer.hpp"
# include <iostream>

using namespace std;
using namespace ariel;


void MagicalContainer::addElement(int element){}

void MagicalContainer::removeElement(int element){}


/**
 * AscendingIterator:
*/

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container): container(container) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other): container(other.container) {}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other)
{
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator &other) const
{
    return false;
}

int MagicalContainer::AscendingIterator::operator*() const
{
    return 0;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    return this[++currentIndex];
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return this[0];
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    return this[container.size() - 1];
}

/**
 * SideCrossIterator:
*/

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &other) : container(other.container) {}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other)
{
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const
{
    return false;
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    return 0;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    return this[++currentIndex];
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return this[0];
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
   return *this;
}


/**
 * PrimeIterator:
*/

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container) {}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other) : container(other.container) {}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other)
{
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &other) const
{
    return false;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    return 0;
}


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    // if (this->container == nullptr)
    // {
    //     /* code */
    // }
    
    return this[0];
}


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    return *this;
}