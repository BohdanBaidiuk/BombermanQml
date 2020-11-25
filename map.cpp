#include "map.h"
#include <algorithm>
#include <QDebug>

QString grass = "image/grass.jpg";
QString brick_wall ="image/brick_wall.jpg";
QString unit = "image/avatar.png";
QString space = "";


TYPE_MAP Map::getTypeMap() const
{
    return typeMap;
}

QString Map::getImageMap() const
{
    return imageMap;
}

Map::Piece Map::getPiece() const
{
    return piece;
}

Map::Map(const TYPE_MAP &type, QString image, Map::Piece pieceInMap):typeMap(type),imageMap(image), piece(pieceInMap)
{

}




//void Map::resetModel()
//{
//    beginResetModel();

//    endResetModel();
//}

//void Map::setModel()
//{


//}

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
