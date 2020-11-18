#include "map.h"
#include <algorithm>
#include <QDebug>

QString grass = "image/grass.jpg";
QString brick_wall ="image/brick_wall.jpg";

Map::Map(const size_t bordSize, QObject *parent):QAbstractListModel(parent), m_boardSize(bordSize)
{
    //m_boardMap.resize(4);
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
        return QVariant(m_boardMap[rowIndex].image);
    }


    return QVariant();
}

QHash<int, QByteArray> Map::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[Qt::DisplayRole] = "display";
    roles[ImageRole] = "image";
    return roles;

}

void Map::fillBoard()
{

    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{' ',grass});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});
    m_boardMap.emplace_back(Piece{'#',brick_wall});

}

bool Map::ispositionValid(const size_t position) const
{
    return position < m_boardSize;
}
