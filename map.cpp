#include "map.h"
#include <algorithm>
#include <QDebug>

TYPE_MAP Map::getTypeMap() const
{
    return typeMap;
}

QString Map::getImageMap() const
{
    return imageMap;
}

QString Map::getPieceImage() const
{
    return piece.imagePiece;
}

void Map::setCurrentIdnex(int index)
{
    piece.currentIndex = index;
}

int Map::getCurrentIndex() const
{
    return piece.currentIndex;
}

Map::Piece Map::getPiece()
{
    return piece;
}

void Map::swapPiece(Map &mapPiece)
{
    auto tmpPiece = mapPiece.getPiece();
    std::swap(piece,tmpPiece);

}

Map::Map(const TYPE_MAP &type, QString image, Map::Piece pieceInMap):typeMap(type),imageMap(image), piece(pieceInMap)
{

}






//Map::Position Map::getRowCol(size_t index) const
//{
//    size_t row = index / 7;
//    size_t col = index % 7;


//    return std::make_pair(row,col);

//}

//bool Map::moveAvatar(int step)
//{
//    int stepPosition = curentIndexUtin + step;
//    if(stepPosition < 49 && stepPosition > -1){
//        m_boardMap[curentIndexUtin].imageUnit = space;
//        m_boardMap[stepPosition].imageUnit = unit;
//        curentIndexUtin = curentIndexUtin + step;
//        emit modelChanged();
//        return true;
//    }
//    return false;
//}

//Piece Map::getPiece() const
//{
//    return piece;
//}

//QString Map::getImageMap() const
//{
//    return imageMap;
//}

//TYPE_MAP Map::getTypeMap() const
//{
//    return typeMap;
//}

//void Map::fillBoard()
//{

//    m_boardMap.emplace_back(Piece{' ',grass,unit});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});
//    m_boardMap.emplace_back(Piece{' ',grass,space});

//}

//bool Map::ispositionValid(const size_t position) const
//{
//    return position < m_boardSize;
//}
