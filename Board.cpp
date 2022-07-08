#include "Board.hpp"
#include <iostream>

Board::Board() {
    m_w = 32;
}
Board::~Board() {}

int Board::GetCellSize() {
    return m_w;
}