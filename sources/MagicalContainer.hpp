#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>

namespace ariel {}

class MagicalContainer {

private:

    std::vector<int> elements;

public:

    void add(int element);

    void remove(int element);

    int size() const;

    class AscendingIterator {

    private:

        MagicalContainer& container;
        int currentIndex;

    public:

        // Default constructor
        AscendingIterator();

        // Copy constructor
        AscendingIterator(AscendingIterator &other);

        // Destructor
        ~AscendingIterator();

        // Assignment operator
        AscendingIterator& operator=(const AscendingIterator& other);

        // Equality comparison (operator==)
        bool operator==(const AscendingIterator& other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const AscendingIterator& other) const;

        // Comparison operator (operator>)
        bool operator>(const AscendingIterator& other) const;

        // Comparison operator (operator<)
        bool operator<(const AscendingIterator& other) const;

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        AscendingIterator& operator++();

        // begin(type)
        AscendingIterator begin(const MagicalContainer& container);

        // end(type)
        AscendingIterator end(const MagicalContainer& container);

    };

    class SideCrossIterator {

    private:

        MagicalContainer& container;
        int currentIndex;

    public:

        // Default constructor
        SideCrossIterator();

        // Copy constructor
        SideCrossIterator(SideCrossIterator &other);

        // Destructor
        ~SideCrossIterator();

        // Assignment operator
        SideCrossIterator& operator=(const SideCrossIterator& other);

        // Equality comparison (operator==)
        bool operator==(const SideCrossIterator& other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const SideCrossIterator& other) const;

        // Comparison operator (operator>)
        bool operator>(const SideCrossIterator& other) const;

        // Comparison operator (operator<)
        bool operator<(const SideCrossIterator& other) const;

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        SideCrossIterator& operator++();

        // begin(type)
        SideCrossIterator begin(const MagicalContainer& container);

        // end(type)
        SideCrossIterator end(const MagicalContainer& container);
    };

    class PrimeIterator {
    private:

        MagicalContainer& container;
        int currentIndex;

    public:

        // Default constructor
        PrimeIterator();

        // Copy constructor
        PrimeIterator(PrimeIterator &other);

        // Destructor
        ~PrimeIterator();

        // Assignment operator
        PrimeIterator& operator=(const PrimeIterator& other);

        // Equality comparison (operator==)
        bool operator==(const PrimeIterator& other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const PrimeIterator& other) const;

        // Comparison operator (operator>)
        bool operator>(const PrimeIterator& other) const;

        // Comparison operator (operator<)
        bool operator<(const PrimeIterator& other) const;

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        PrimeIterator& operator++();

        // begin(type)
        PrimeIterator begin(const MagicalContainer& container);

        // end(type)
        PrimeIterator end(const MagicalContainer& container);
    };


};

/**

operations for each iterator:
• Default constructor
• Copy constructor
• Destructor
• Assignment operator
• Equality comparison (operator==)
• Inequality comparison (operator!=)
• GT, LT comparison (operator>, operator<) all comparison operators only valid for iterators of the same type of order
  and should compare the location of the iterator in the container and not the element inside. Example bellow.
  Using operators on iterators of different type or different containers should throw an examtion.
• Dereference operator (operator*)
• Pre-increment operator (operator++)
• begin(type): Returns the appropriate iterator (ascending, cross, or prime) pointing to the first element
  of the container based on the specified type.
• end(type): Returns the appropriate iterator (ascending, cross, or prime) pointing one position past the last element
  of the container based on the specified type.

 Example: say our container contains the numbers 1,2,4,5,14 the iterators will return the elements
 in the following order:
• Ascending: 1,2,4,5,14. operator> should return true on 5>2, 14>1
• prime: 2,5. operator> should return true on 5>2
• cross: 1,14,2,5,4 (one from the start then one from the end). operator> should return true on 5>14, 2>1, 4>14

All iterators should work in O(1) in both memory and time complexity.
Iterators should NOT be detached from the main container.
If one adds an element to a container after an iterator is created,
the iterator should know the element return it should its turn will come.

 */

#endif
