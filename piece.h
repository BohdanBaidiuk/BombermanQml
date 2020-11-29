#ifndef PIECE_H
#define PIECE_H

#include <QString>
#include <QObject>

enum class TYPE_PIECE {USER,BOT,BRICK_WALL,BOMB,EMPTY};

Q_DECLARE_METATYPE(TYPE_PIECE);

struct Piece{
    Piece() = default;
    Piece(QString image, TYPE_PIECE type):imagePiece(image),typePiece(type){};
    QString imagePiece;
    TYPE_PIECE typePiece;

};
Q_DECLARE_METATYPE(Piece);

#endif // PIECE_H
