#ifndef PIECE_H
#define PIECE_H

#include <utility>
enum class TYPE {BOT,BLOCK,CRASH_BLOCK,CORRIDOR,BOMB,EXPLOSION};

using FigurePoint = std::pair<int, int>;

class Piece {
public:
    Piece(TYPE type, char arg) :piece_type(type), paint(arg) {};
    Piece() {};
    TYPE get_type() {
        return piece_type;
    };
    char get_name() {
        return paint;
    };
    Piece get_special() {
        if (piece_type ==TYPE::BOT) {
            return Piece{ TYPE::BOMB ,'+' };
        }
        else if (piece_type == TYPE::CRASH_BLOCK) {
            return Piece{ TYPE::CORRIDOR ,' ' };
        }
        return {};
    };
    TYPE setType(TYPE type) {
        piece_type = type;
        return piece_type;
    }
    char setNeme(char name) {
        paint = name;
        return paint;
    }
private:
    TYPE piece_type{ TYPE::BLOCK };
    char paint = '#';
};

#endif // PIECE_H
