#include "map.h"
#include <algorithm>

Board::Board(const size_t bordSize, QObject *parent):QAbstractListModel(parent), m_boardSize(bordSize)
{
    m_boardMap.resize(m_boardSize);
    fillBoard();
}

int Board::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_boardMap.size();
}

QVariant Board::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole){
        return {};
    }
    const int rowIndex{index.row()};

    if(!ispositionValid(rowIndex)){
        return {};
    }
    return QVariant::fromValue(m_boardMap[rowIndex].sumbol_);
}

void Board::fillBoard()
{
//    m_boardMap.push_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{' ',TYPE::CORRIDOR});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});
//    m_boardMap.emplace_back(Piece{'#',TYPE::BLOCK});

}

bool Board::ispositionValid(const size_t position) const
{
 return position < m_boardSize;
}
