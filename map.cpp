#include "map.h"
#include <algorithm>
#include <QDebug>

QString grass = "image/grass.jpg";
QString brick_wall ="image/brick_wall.jpg";
QString unit = "image/avatar.png";
QString space = "";

Map::Map(const size_t bordSize, QObject *parent):QAbstractListModel(parent), m_boardSize(bordSize)
{
    fillBoard();
}




int Map::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_boardMap.size();
}

QVariant Map::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return {};
    }
    const int rowIndex{index.row()};

    if(!ispositionValid(rowIndex)){
        return {};
    }

    switch (role) {
    case Qt::DisplayRole:
        return QVariant(QString(m_boardMap[rowIndex].sumbol));
    case ImageRole:
        return QVariant(m_boardMap[rowIndex].imageMap);
    case ImageUnitRole:
        return QVariant(m_boardMap[rowIndex].imageUnit);
    }


    return QVariant();
}

QHash<int, QByteArray> Map::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[Qt::DisplayRole] = "display";
    roles[ImageRole] = "image";
    roles[ImageUnitRole] = "unit";
    return roles;

}

Map::Position Map::getRowCol(size_t index) const
{
    size_t row = index / 7;
    size_t col = index % 7;


    return std::make_pair(row,col);

}

bool Map::moveAvatar(int step)
{
    int stepPosition = curentIndexUtin + step;
    //qDebug()<<stepPosition;
    if(stepPosition < 49 && stepPosition > -1){
        // qDebug()<<curentIndexUtin;
        m_boardMap[curentIndexUtin].imageUnit = space;
        m_boardMap[stepPosition].imageUnit = unit;
        curentIndexUtin = curentIndexUtin + step;
        return true;
    }
    return false;
}

void Map::fillBoard()
{

    m_boardMap.emplace_back(Piece{' ',grass,unit});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{'#',brick_wall,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});
    m_boardMap.emplace_back(Piece{' ',grass,space});

}

bool Map::ispositionValid(const size_t position) const
{
    return position < m_boardSize;
}
