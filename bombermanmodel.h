#ifndef BOMBERMANMODEL_H
#define BOMBERMANMODEL_H

#include "map.h"
#include <QAbstractListModel>
#include <QObject>
#include <vector>

class BombermanModel: public QAbstractListModel
{
    Q_OBJECT
public:
    BombermanModel();
    static void registerMe(const std::string& moduleName);
    virtual QHash<int,QByteArray>roleNames()const override;
    int rowCount(const QModelIndex &parent = QModelIndex{})const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


public slots:
    void moveUnit(int step);



private:
    std::vector<Map> m_map;
    int currentIndexUnit = 0;
    enum BombermanRole{
        TypeMap = Qt::UserRole + 1,
        ImageMap,
        PieceInMap
    };

    void fillMap();
};

#endif // BOMBERMANMODEL_H
