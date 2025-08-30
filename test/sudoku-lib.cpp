#include "sudoku.hpp"
#include "gtest/gtest.h"

TEST(SudokuLib, Base2) {
    sudokuGame game(2);
    EXPECT_EQ(game.getBase(), 2);
    EXPECT_EQ(game.getSize(), 4);

    EXPECT_TRUE(game.set(0, 0, 1));
    EXPECT_TRUE(game.set(0, 1, 2));

    EXPECT_FALSE(game.set(0, 2, 2)); // Duplicate in row
    EXPECT_TRUE(game.set(0, 2, 3));
    EXPECT_TRUE(game.set(0, 3, 4));
    /*
    1 2  3 4
    - -  - -

    - -  - -
    - -  - -*/
    EXPECT_FALSE(game.set(1, 0, 1)); // Duplicate in column
    EXPECT_TRUE(game.set(1, 0, 3));
    /*
    1 2  3 4
    3 -  - -

    - -  - -
    - -  - -*/
    EXPECT_FALSE(game.set(1, 1, 1)); // Duplicate in square
    EXPECT_TRUE(game.set(1, 1, 4));

    /*
    1 2  3 4
    3 4  - -

    - -  - -
    - -  - -*/
    
    EXPECT_FALSE(game.set(2, 2, 3)); // Collision
    EXPECT_TRUE(game.set(0, 2, 0)); // ERASE
    /*
    1 2  - 4
    3 4  - -

    - -  - -
    - -  - -*/
    EXPECT_TRUE(game.set(2, 2, 3)); // Duplicate erased

}

TEST(SudokuLib, Base3) {
    sudokuGame game(3);
    EXPECT_EQ(game.getBase(), 3);
    EXPECT_EQ(game.getSize(), 9);

    EXPECT_TRUE(game.set(0, 0, 1));
    EXPECT_TRUE(game.set(0, 1, 2));
    EXPECT_TRUE(game.set(0, 2, 3));

    EXPECT_FALSE(game.set(0, 3, 1)); // Duplicate in row
    EXPECT_TRUE(game.set(0, 3, 4));
    
    EXPECT_FALSE(game.set(1, 0, 1)); // Duplicate in column
    EXPECT_TRUE(game.set(1, 0, 5));

    EXPECT_FALSE(game.set(2, 2, 2));
    EXPECT_TRUE(game.set(2, 2, 6));
}