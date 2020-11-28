#include "bombermanmodel.h"
#include <QQmlEngine>
#include <algorithm>

namespace  {
QString grass = "image/grass.jpg";
QString brick_wall ="image/brick_wall.jpg";
QString unit = "image/avatar.png";
QString space = "";
QString bomb = "image/bomb.png";
int currIndex{};
int currIndexBomb{};
}


BombermanModel::BombermanModel()
{
    fillMap();

}

void BombermanModel::registerMe(const std::string &moduleName)
{
    qmlRegisterType<BombermanModel>(moduleName.c_str(), 1, 0, "BombermanModel");
}

QHash<int, QByteArray> BombermanModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[BombermanRole::TypeMap] = "typeMap";
    roles[BombermanRole::ImageMap] = "imageMap";
    roles[BombermanRole::PieceInMap] = "piece";
    return roles;
}

int BombermanModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(m_map.size());
}

QVariant BombermanModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()|| index.row() > rowCount(index)){
        return {};
    }
    const auto &map = m_map.at(index.row());

    switch (role) {
    case BombermanRole::TypeMap:
        return QVariant::fromValue(map.first.getTypeMap());
    case BombermanRole::ImageMap:
        return QVariant::fromValue(map.first.getImageMap());
    case BombermanRole::PieceInMap:
        return QVariant::fromValue(map.second.imagePiece);
    }

    return QVariant();
}

void BombermanModel::resetModel()
{
    beginResetModel();
    endResetModel();
}

void BombermanModel::moveUnit(int step)
{

    auto &unit = m_map.at(currIndex);
    int stepPosition = currIndex + step;
    if(stepPosition > -1 && stepPosition < 49){
        auto &stepUnit = m_map.at(stepPosition);
        if(stepUnit.second.typePiece == TYPE_PIECE::EMPTY){
            std::swap(unit.second,stepUnit.second);
            currIndex = stepPosition;
        }
       resetModel();
    }

}

void BombermanModel::setBomb()
{




}


void BombermanModel::fillMap()
{
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{unit,TYPE_PIECE::USER});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});

}


