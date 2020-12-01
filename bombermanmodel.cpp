#include "bombermanmodel.h"
#include <QQmlEngine>
#include <QTimer>
#include <algorithm>

namespace  {
QString grass = "image/grass.jpg";
QString brick_wall ="image/brick_wall.jpg";
QString unitGif = "image/avatar/avatar.gif";
QString space = "";
QString bomb = "image/bomb.gif";
QString wall = "image/wall.jpg";
QString blastBomb = "image/blast.png";

int currIndex = 10;
int currIndexBomb{};
bool stateBomb = false;
}

BombermanModel::BombermanModel()
{
    QTimer *timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(onAutoRefreshModel()));
    connect(timerBomb,SIGNAL(timeout()),this,SLOT(onBombBlast()));
    connect(timerFierBlast,SIGNAL(timeout()),this,SLOT(onStopFierBlast()));
    timer->start(600);
    timerBomb->setInterval(1000);
    timerFierBlast->setInterval(500);

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

void BombermanModel::setBlast(int stepBlast)
{
    auto &blast= m_map.at(stepBlast);
    if(blast.second.typePiece == TYPE_PIECE::BRICK_WALL || blast.second.typePiece == TYPE_PIECE::BOT
            || blast.second.typePiece == TYPE_PIECE::EMPTY ||blast.second.typePiece == TYPE_PIECE::BOMB){
        if(blast.first.getTypeMap() == TYPE_MAP::CORRIDOR){
            blast.second.imagePiece = blastBomb;
            blast.second.typePiece = TYPE_PIECE::BLAST;
            timerFierBlast->start();
        }
    }
}

void BombermanModel::setStopFierBlast(int stepBlast)
{
    auto &stopFier= m_map.at(stepBlast);
    if(stopFier.second.typePiece == TYPE_PIECE::BLAST){
        stopFier.second.imagePiece = grass;
        stopFier.second.typePiece = TYPE_PIECE::EMPTY;
    }
}

void BombermanModel::onAutoRefreshModel()
{
    resetModel();
}

void BombermanModel::onBombBlast()
{
    setBlast(currIndexBomb);
    setBlast(currIndexBomb - 1);
    setBlast(currIndexBomb + 1);
    setBlast(currIndexBomb - 9);
    setBlast(currIndexBomb + 9);
    timerBomb->stop();
}

void BombermanModel::onStopFierBlast()
{
    setStopFierBlast(currIndexBomb);
    setStopFierBlast(currIndexBomb + 1);
    setStopFierBlast(currIndexBomb - 1);
    setStopFierBlast(currIndexBomb + 9);
    setStopFierBlast(currIndexBomb - 9);
    timerFierBlast->stop();
    currIndexBomb = -1;
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


