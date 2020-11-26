#include "bombermanmodel.h"
#include <QQmlEngine>

namespace  {
QString grass = "image/grass.jpg";
QString brick_wall ="image/brick_wall.jpg";
QString unit = "image/avatar.png";
QString space = "";
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
    const Map &map = m_map.at(index.row());

    switch (role) {
    case BombermanRole::TypeMap:
        return QVariant::fromValue(map.getTypeMap());
    case BombermanRole::ImageMap:
        return QVariant::fromValue(map.getImageMap());
    case BombermanRole::PieceInMap:
        return QVariant::fromValue(map.getPieceImage());
    }

    return QVariant();
}

void BombermanModel::moveUnit(int step)
{
    Map &unit = m_map.at(currentIndexUnit);
    qDebug()<<unit.getPieceImage();
    int stepPosition = unit.getCurrentIndex() + step;

    if(stepPosition < 49 && stepPosition > -1){
        Map &stepUnit = m_map.at(stepPosition);
        stepUnit.swapPiece(unit);
        unit.setCurrentIdnex(stepPosition);
        currentIndexUnit = stepPosition;

        beginResetModel();
        endResetModel();
    }
}


void BombermanModel::fillMap()
{
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{unit,TYPE_PIECE::USER});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{brick_wall,TYPE_PIECE::BRICK_WALL});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(TYPE_MAP::CORRIDOR,grass,Map::Piece{space,TYPE_PIECE::EMPTY});

}


