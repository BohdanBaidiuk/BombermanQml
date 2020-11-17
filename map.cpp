#include "map.h"
#include <algorithm>
#include <QDebug>

Map::Map(const size_t bordSize, QObject *parent):QAbstractListModel(parent), m_boardSize(bordSize)
{
    m_boardMap;
    m_boardMap.resize(m_boardSize);
    fillBoard();
}

int Map::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_boardMap.size();
}

QVariant Map::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole){
        return {};
    }
    const int rowIndex{index.row()};

    if(!ispositionValid(rowIndex)){
        return {};
    }
    qDebug()<<rowIndex;
    return QVariant::fromValue(m_boardMap[rowIndex].sumbol_);
}

void Map::fillBoard()
{
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});

}

bool Map::ispositionValid(const size_t position) const
{
    return position < m_boardSize;
}
