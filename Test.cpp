#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>

using namespace ariel;
using namespace std;


TEST_CASE("Empty Container"){

    MagicalContainer container;

    CHECK(container.size() == 0);
    // CHECK_THROWS_AS(container.get(1), std::out_of_range);
    CHECK_NOTHROW(container.removeElement(1));

    bool flag = false;

    MagicalContainer::AscendingIterator ascIter(container);
    for (auto itr = ascIter.begin(); itr != ascIter.end(); ++itr) {
        flag = true;
    }

    MagicalContainer::SideCrossIterator crsIter(container);
    for (auto itr = crsIter.begin(); itr != crsIter.end(); ++itr) {
        flag = true;
    }
    
    MagicalContainer::PrimeIterator prmIter(container);
    for (auto itr = prmIter.begin(); itr != prmIter.end(); ++itr) {
        flag = true;
    }

    CHECK(flag == false);
    
}

TEST_CASE("Single Element Container"){

    MagicalContainer container;
    container.addElement(176);

    MagicalContainer::AscendingIterator ascIterator(container);
    MagicalContainer::PrimeIterator prmIterator(container);
    MagicalContainer::SideCrossIterator crsIterator(container);

    CHECK(*ascIterator.begin() == 176);
    CHECK(*prmIterator.begin() == 176);
    CHECK(*crsIterator.begin() == 176);

    CHECK(*ascIterator.begin() == *ascIterator.end());
    CHECK(*prmIterator.begin() == *prmIterator.end());
    CHECK(*crsIterator.begin() == *crsIterator.end());
    
}

    TEST_CASE("Adding and Removing Elements") {

        MagicalContainer container;

        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        CHECK(container.size() == 5);

        container.removeElement(2);

        CHECK(container.size() == 4);

        container.removeElement(10); // Removing non-existent element

        CHECK(container.size() == 4);
    }

TEST_CASE("Iterators Test") {

    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Ascending Iterator") {

        MagicalContainer:: AscendingIterator ascIter(container);

        CHECK(*ascIter == 1);

        ++ascIter;
        CHECK(*ascIter == 2);
        CHECK(*ascIter != *ascIter.end());

        ++ascIter;
        CHECK(*ascIter == 4);

        ++ascIter;
        CHECK(*ascIter == 5);

        ++ascIter;
        CHECK(*ascIter == 14);

        ++ascIter;
        CHECK(ascIter == ascIter.end());
    }

    SUBCASE("SideCross Iterator") {

        MagicalContainer:: SideCrossIterator crossIter(container);

        CHECK(*crossIter == 1);

        ++crossIter;
        CHECK(*crossIter == 14);

        ++crossIter;
        CHECK(*crossIter == 2);

        ++crossIter;
        CHECK(*crossIter == 5);

        ++crossIter;
        CHECK(*crossIter == 4);

        ++crossIter;
        CHECK(crossIter == crossIter.end());
    }

    SUBCASE("Prime Iterator") {

        MagicalContainer:: PrimeIterator primeIter(container);

        CHECK(*primeIter == 2);

        ++primeIter;
        CHECK(*primeIter == 5);

        ++primeIter;
        CHECK(primeIter == primeIter.end());
    }
}


TEST_CASE("Iterators Test With Comparisons") {

    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Ascending Iterator") {

        MagicalContainer::AscendingIterator ascIter1(container);
        MagicalContainer::AscendingIterator ascIter2(container);

        CHECK(*ascIter1 == 1);
        CHECK(*ascIter2 == 1);
        CHECK(ascIter1 == ascIter2);
        CHECK(!(ascIter1 < ascIter2));
        CHECK(!(ascIter1 > ascIter2));

        ++ascIter1;
        CHECK(*ascIter1 == 2);
        CHECK(*ascIter2 == 1);
        CHECK(ascIter1 != ascIter2);
        CHECK(!(ascIter1 < ascIter2));
        CHECK(ascIter1 > ascIter2);

        ++ascIter2;
        CHECK(*ascIter2 == 2);
        CHECK(ascIter1 == ascIter2);
        CHECK(!(ascIter2 < ascIter1));
        CHECK(!(ascIter2 > ascIter1));

        ++ascIter1;
        CHECK(*ascIter1 == 4);
        CHECK(*ascIter2 == 2);
        CHECK(ascIter1 != ascIter2);
        CHECK(!(ascIter1 < ascIter2));
        CHECK(ascIter1 > ascIter2);

        ++ascIter2;
        CHECK(*ascIter2 == 4);
        CHECK(ascIter1 == ascIter2);
        CHECK(!(ascIter2 < ascIter1));
        CHECK(!(ascIter2 > ascIter1));

        ++ascIter1;
        CHECK(*ascIter1 == 5);
        CHECK(*ascIter2 == 4);
        CHECK(ascIter1 != ascIter2);
        CHECK(!(ascIter1 < ascIter2));
        CHECK(ascIter1 > ascIter2);

        ++ascIter2;
        CHECK(*ascIter2 == 5);
        CHECK(ascIter1 == ascIter2);
        CHECK(!(ascIter2 < ascIter1));
        CHECK(!(ascIter2 > ascIter1));

        ++ascIter1;
        CHECK(*ascIter1 == 14);
        CHECK(*ascIter2 == 5);
        CHECK(ascIter1 != ascIter2);
        CHECK(!(ascIter1 < ascIter2));
        CHECK(ascIter1 > ascIter2);

        ++ascIter2;
        CHECK(*ascIter2 == 14);
        CHECK(ascIter1 == ascIter2);
        CHECK(!(ascIter2 < ascIter1));
        CHECK(!(ascIter2 > ascIter1));

        CHECK(ascIter1 == ascIter1.end());
        CHECK(ascIter2 == ascIter2.end());
    }

    SUBCASE("SideCross Iterator") {

        MagicalContainer::SideCrossIterator crossIter1(container);
        MagicalContainer::SideCrossIterator crossIter2(container);

        CHECK(*crossIter1 == 1);
        CHECK(*crossIter2 == 1);
        CHECK(crossIter1 == crossIter2);
        CHECK(!(crossIter1 < crossIter2));
        CHECK(!(crossIter1 > crossIter2));

        ++crossIter1;
        CHECK(*crossIter1 == 14);
        CHECK(*crossIter2 == 1);
        CHECK(crossIter1 != crossIter2);
        CHECK(!(crossIter1 < crossIter2));
        CHECK(crossIter1 > crossIter2);

        ++crossIter2;
        CHECK(*crossIter2 == 14);
        CHECK(crossIter1 == crossIter2);
        CHECK(!(crossIter2 < crossIter1));
        CHECK(!(crossIter2 > crossIter1));

        ++crossIter1;
        CHECK(*crossIter1 == 2);
        CHECK(*crossIter2 == 14);
        CHECK(crossIter1 != crossIter2);
        CHECK(crossIter1 < crossIter2);
        CHECK(!(crossIter1 > crossIter2));

        ++crossIter2;
        CHECK(*crossIter2 == 2);
        CHECK(crossIter1 == crossIter2);
        CHECK(!(crossIter2 < crossIter1));
        CHECK(!(crossIter2 > crossIter1));

        ++crossIter1;
        CHECK(*crossIter1 == 5);
        CHECK(*crossIter2 == 2);
        CHECK(crossIter1 != crossIter2);
        CHECK(!(crossIter1 < crossIter2));
        CHECK(crossIter1 > crossIter2);

        ++crossIter2;
        CHECK(*crossIter2 == 5);
        CHECK(crossIter1 == crossIter2);
        CHECK(!(crossIter2 < crossIter1));
        CHECK(!(crossIter2 > crossIter1));

        ++crossIter1;
        CHECK(*crossIter1 == 4);
        CHECK(*crossIter2 == 5);
        CHECK(crossIter1 != crossIter2);
        CHECK(crossIter1 < crossIter2);
        CHECK(!(crossIter1 > crossIter2));

        ++crossIter2;
        CHECK(*crossIter2 == 4);
        CHECK(crossIter1 == crossIter2);
        CHECK(!(crossIter2 < crossIter1));
        CHECK(!(crossIter2 > crossIter1));

        CHECK(crossIter1 == crossIter1.end());
        CHECK(crossIter2 == crossIter2.end());
    }

    SUBCASE("Prime Iterator") {

        MagicalContainer::PrimeIterator primeIter1(container);
        MagicalContainer::PrimeIterator primeIter2(container);

        CHECK(*primeIter1 == 2);
        CHECK(*primeIter2 == 2);
        CHECK(primeIter1 == primeIter2);
        CHECK(!(primeIter1 < primeIter2));
        CHECK(!(primeIter1 > primeIter2));

        ++primeIter1;
        CHECK(*primeIter1 == 5);
        CHECK(*primeIter2 == 2);
        CHECK(primeIter1 != primeIter2);
        CHECK(!(primeIter1 < primeIter2));
        CHECK(primeIter1 > primeIter2);

        ++primeIter2;
        CHECK(*primeIter2 == 5);
        CHECK(primeIter1 == primeIter2);
        CHECK(!(primeIter2 < primeIter1));
        CHECK(!(primeIter2 > primeIter1));

        CHECK(primeIter1 == primeIter1.end());
        CHECK(primeIter2 == primeIter2.end());
    }
}




