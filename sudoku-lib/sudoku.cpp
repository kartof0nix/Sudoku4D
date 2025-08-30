#include "sudoku.hpp"

bool subgroup::set(uint index, uint value, bool dry_run) {
    if (index >= size()) throw out_of_range("Index out of range");
    if (value > size()) throw out_of_range("Value out of range");
    if (used[value]) return false; // Value already used
    if (dry_run)
        return true; // If dry_run
    used [ (*this)[index] ] = false; // Mark old value as unused
    (*this)[index] = value;
    used[value] = true;
    return true;
} 

uint subgroup::get(uint index) const {
    if (index >= size()) throw out_of_range("Index out of range");
    return (*this)[index];
}


sudokuGame::sudokuGame(const uint &Base) : base(Base), size(Base * Base), rows(size, subgroup(size)), cols(size, subgroup(size)), squares(size, subgroup(size)){
    board.resize(size, vector<uint>(size, 0));
}

bool sudokuGame::set(uint row, uint col, uint value) {
    if (row >= size ||  col >= size) throw out_of_range("Row or column out of range");
    if (value > size) throw out_of_range("Value out of range");
    uint squareGroup = getSquareGroup(row, col), squareIndex = getSquareIndex(row, col);
    
    subgroup *groups[3] = {&rows[row], &cols[col], &squares[squareGroup]};
    uint id[3] = {col, row, squareIndex};
    
    for (int i = 0; i < 3; ++i) {
        auto group = groups[i];
        if (!group->set(id[i], value, true)) {
            return false; // Value already exists in the group
        }
    }
    for (int i = 0; i < 3; ++i) {
        auto group = groups[i];
        if (!group->set(id[i], value, false)) {
            throw runtime_error("Subgroup agreed to set value but failed to do so");
        }
    }
    
    board[row][col] = value;
    return true; // Successfully set the value
}
