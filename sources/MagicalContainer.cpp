# include "MagicalContainer.hpp"
# include <iostream>

using namespace std;
using namespace ariel;


void MagicalContainer::addElement(int element){}

void MagicalContainer::removeElement(int element){}

bool MagicalContainer::isPrime(int num)
{
    return true;
}


/**
 * AscendingIterator:
*/

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
: container(container), currentIndex(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other)
: container(other.container), currentIndex(other.currentIndex) {}

// tidy
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer::AscendingIterator &&other) noexcept
: container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::AscendingIterator
&MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other)
{
    return *this;
}

// tidy
MagicalContainer::AscendingIterator
&MagicalContainer::AscendingIterator::operator=(MagicalContainer::AscendingIterator &&other) noexcept
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

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
: container(container), rightIndex(0), leftIndex(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &other)
: container(other.container), rightIndex(other.rightIndex), leftIndex(other.leftIndex) {}

// tidy
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer::SideCrossIterator &&other) noexcept
: container(other.container), rightIndex(other.rightIndex), leftIndex(other.leftIndex) {}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other)
{
    return *this;
}

// tidy
MagicalContainer::SideCrossIterator
&MagicalContainer::SideCrossIterator::operator=(MagicalContainer::SideCrossIterator &&other) noexcept
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
    return this[0];
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

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
: container(container), currentIndex(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other)
: container(other.container), currentIndex(other.currentIndex) {}

// tidy
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer::PrimeIterator &&other) noexcept
: container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other)
{
    return *this;
}

// tidy
MagicalContainer::PrimeIterator
&MagicalContainer::PrimeIterator::operator=(MagicalContainer::PrimeIterator &&other) noexcept
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
    return this[0];
}


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    return *this;
}