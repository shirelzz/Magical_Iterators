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

    // test iters begin end
    
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

TEST_SUITE("Iterators Test") {

    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    TEST_CASE("AscendingIterator") {

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

    TEST_CASE("SideCrossIterator") {

        MagicalContainer:: SideCrossIterator crossIterator = SideCrossIterator::begin(container);
        MagicalContainer:: SideCrossIterator crossEndIterator = SideCrossIterator::end(container);

        CHECK(*crossIterator == 1);
        CHECK(*crossEndIterator == 14);

        ++crossIterator;
        CHECK(*crossIterator == 14);
        CHECK(crossIterator != crossEndIterator);

        ++crossIterator;
        CHECK(*crossIterator == 2);

        ++crossIterator;
        CHECK(*crossIterator == 5);

        ++crossIterator;
        CHECK(*crossIterator == 4);

        ++crossIterator;
        CHECK(crossIterator == crossEndIterator);
    }

    TEST_CASE("PrimeIterator") {

        MagicalContainer:: PrimeIterator primeIterator = PrimeIterator::begin(container);
        MagicalContainer:: PrimeIterator primeEndIterator = PrimeIterator::end(container);

        CHECK(*primeIterator == 2);
        CHECK(*primeEndIterator == 5);

        ++primeIterator;
        CHECK(*primeIterator == 5);
        CHECK(primeIterator != primeEndIterator);

        ++primeIterator;
        CHECK(primeIterator == primeEndIterator);
    }
}



