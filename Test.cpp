#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

TEST_CASE("Single Element Container"){

    MagicalContainer container;

    // test iters begin end
    
}


TEST_CASE("Empty Container"){

    MagicalContainer container;

    CHECK(container.size() == 0);
    // CHECK_THROWS_AS(container.get(1), std::out_of_range);
    CHECK_THROWS_AS(container.removeElement(1), std::out_of_range);

    // check iters
    
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

TEST_SUITE("MagicalContainer Test") {

    MagicalContainer container;

    TEST_CASE("Adding and Removing Elements") {

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

    TEST_CASE("Element Access") {

        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        // CHECK(container.get(0) == 1);
        // CHECK(container.get(1) == 2);
        // CHECK(container.get(2) == 4);
        // CHECK(container.get(3) == 5);
        // CHECK(container.get(4) == 14);

        // CHECK_THROWS_AS(container.get(5), std::out_of_range);
    }
}

TEST_CASE("Iterators Test") {

    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("AscendingIterator") {

        MagicalContainer:: AscendingIterator ascIterator(container);

        CHECK(*ascIterator == 1);

        ++ascIterator;
        CHECK(*ascIterator == 2);
        // CHECK(ascIterator != ascEndIterator);

        ++ascIterator;
        CHECK(*ascIterator == 4);

        ++ascIterator;
        CHECK(*ascIterator == 5);

        ++ascIterator;
        CHECK(*ascIterator == 14);

        ++ascIterator;
        // CHECK(ascIterator == ascEndIterator);
    }

    SUBCASE("SideCrossIterator") {

        MagicalContainer:: SideCrossIterator crossIterator(container);

        CHECK(*crossIterator == 1);

        ++crossIterator;
        CHECK(*crossIterator == 14);

        ++crossIterator;
        CHECK(*crossIterator == 2);

        ++crossIterator;
        CHECK(*crossIterator == 5);

        ++crossIterator;
        CHECK(*crossIterator == 4);

        ++crossIterator;
        // CHECK(crossIterator == crossEndIterator);
    }

    SUBCASE("PrimeIterator") {

        MagicalContainer:: PrimeIterator primeIterator(container);

        CHECK(*primeIterator == 2);

        ++primeIterator;
        CHECK(*primeIterator == 5);

        ++primeIterator;
        // CHECK(primeIterator == primeEndIterator);
    }
}



