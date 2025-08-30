#include <vector>
#include <stdexcept>
using namespace std;

class subgroup : protected vector<uint>
{
    vector<bool> used;
public:
    subgroup(uint n) : vector<uint>(n, 0), used(n+1, 0) {}
    subgroup(const subgroup &other) : vector<uint>(other), used(other.used) {}
    bool set(uint index, uint value, bool dry_run = false);
    uint get(uint index) const ;
    
};

class sudokuGame
{
    uint base;
    uint size; // Side length of the Sudoku board (base*base)

    //All subgroups index from 0 to size-1
    vector<subgroup> rows; 
    vector<subgroup> cols;
    vector<subgroup> squares;
    //Board rows/cols also indexed from 0 to size-1
    vector<vector<uint>> board;

public:
    // Initialize board with a given sub-square size n
    sudokuGame(const uint &Base);

    uint getBase() const{
        return base;
    }
    uint getSize() const {
        return size;
    }

    uint getSquareGroup(uint row, uint col) const {
        return base * (row / base) + (col / base);
    }
    uint getSquareIndex(uint row, uint col) const {
        return base * (row % base) + (col % base);
    }
    bool set(uint row, uint col, uint value);
};