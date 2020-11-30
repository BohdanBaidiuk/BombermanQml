#include "bombermanmodel.h"
#include <QQmlEngine>
#include <QTimer>
#include <algorithm>

namespace  {
QString grass = "image/grass.jpg";
QString brick_wall ="image/brick_wall.jpg";
QString unitGif = "image/avatar/avatar.gif";
QString space = "";
QString bomb = "image/bomb.png";
QString wall = "image/wall.jpg";
int currIndex = 10;
int currIndexBomb{};
bool stateBomb = false;
}

BombermanModel::BombermanModel()
{
    QTimer *timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(onAutoRefreshModel()));
    connect(timerBomb,SIGNAL(timeout()),this,SLOT(onBombBlast()));
    timer->start(600);
    timerBomb->start(1000);
    timerBomb->stop();
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

void BombermanModel::onAutoRefreshModel()
{
    resetModel();
}

void BombermanModel::onBombBlast()
{
   auto &bomb= m_map.at(currIndexBomb);
   bomb.second.imagePiece = space;
   bomb.second.typePiece = TYPE_PIECE::EMPTY;
   currIndexBomb = -1;
   timerBomb->stop();
   stateBomb = false;
}

void BombermanModel::moveUnit(int step)
{
    timerBomb->stop();
    auto &unit = m_map.at(currIndex);
    int stepPosition = currIndex + step;
    if(stepPosition > -1 && stepPosition < 81){
        auto &stepUnit = m_map.at(stepPosition);
        if(stepUnit.second.typePiece == TYPE_PIECE::EMPTY && stepUnit.first.getTypeMap() == TYPE_MAP::CORRIDOR) {
            std::swap(unit.second,stepUnit.second);
            currIndex = stepPosition;
            if(stateBomb && currIndexBomb != currIndex){
                auto &stepBomb= m_map.at(currIndexBomb);
                stepBomb.second.imagePiece = bomb;
                stepBomb.second.typePiece = TYPE_PIECE::BOMB;
                timerBomb->start();
            }
            resetModel();
        }
    }
}

void BombermanModel::setBomb()
{
    if(!stateBomb){
        currIndexBomb = currIndex;
        stateBomb = true;
    }
}

void BombermanModel::fillMap()
{
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{unitGif,TYPE_PIECE::USER});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::CORRIDOR,grass},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
    m_map.emplace_back(Map{TYPE_MAP::WALL,wall},Piece{space,TYPE_PIECE::EMPTY});
}


