#include <SFML/System.hpp>

class Board {
    public:
        Board();
        ~Board();

        int GetCellSize();
    private:
        int m_w;
};