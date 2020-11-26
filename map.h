#ifndef MAP_H
#define MAP_H

#include <QAbstractListModel>
#include <QObject>
#include <vector>
#include <utility>
#include <QVector>

enum class TYPE_MAP {BLOCK,CORRIDOR,EMPTY};
enum class TYPE_PIECE {USER,BOT,BRICK_WALL,EMPTY};


Q_DECLARE_METATYPE(TYPE_MAP)
Q_DECLARE_METATYPE(TYPE_PIECE)
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
        int currentIndex = 0;
    };
    Map(const TYPE_MAP &type, QString image, Piece pieceInMap);

    //    void resetModel();
    //    void setModel();
    // Position getRowCol(size_t index)const;
    TYPE_MAP getTypeMap() const;
    QString getImageMap() const;
    QString getPieceImage() const;
    void setCurrentIdnex(int index);
    int getCurrentIndex() const;
    Piece getPiece();
    void swapPiece(Map &mapPiece);


private:
    TYPE_MAP typeMap{};
    QString imageMap{};
    Piece piece{};

};

Q_DECLARE_METATYPE(Map::Piece)
#endif // MAP_H
