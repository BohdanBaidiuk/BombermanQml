#ifndef MAP_H
#define MAP_H

#include <QAbstractListModel>
#include <QObject>
#include <vector>
#include <utility>
#include <QVector>

enum class TYPE_MAP {BLOCK,CORRIDOR,EMPTY};
enum class TYPE_PIECE {USER,BOT,BRICK_WALL};

class Map
{
public:
    Map() = default;
    //using Position = std::pair<size_t,size_t>;
    //static constexpr size_t defaultBordSize{49};
    struct Piece{
        Piece() = default;
        Piece(QString image, TYPE_PIECE type):imagePiece(image),typePiece(type){};
        QString imagePiece;
        TYPE_PIECE typePiece;
    };
    Map(const TYPE_MAP &type, QString image, Piece pieceInMap);

//    void resetModel();
//    void setModel();
   // Position getRowCol(size_t index)const;
    TYPE_MAP getTypeMap() const;
    QString getImageMap() const;
    Piece getPiece() const;

//public slots:
//    bool moveAvatar(int step);

private:
  TYPE_MAP typeMap{};
  QString imageMap{};
  Piece piece{};

};

#endif // MAP_H
