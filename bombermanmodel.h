#ifndef BOMBERMANMODEL_H
#define BOMBERMANMODEL_H

#include "map.h"
#include "piece.h"
#include <QAbstractListModel>
#include <QObject>
#include <vector>
#include <utility>

class BombermanModel: public QAbstractListModel
{
    Q_OBJECT
public:
    BombermanModel();
    static void registerMe(const std::string& moduleName);
    virtual QHash<int,QByteArray>roleNames()const override;
    int rowCount(const QModelIndex &parent = QModelIndex{})const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void resetModel();
    void autoRefreshModel();

public slots:
    void moveUnit(int step);
    void setBomb();

signals:
   void refreshModel();

private:
    std::vector<std::pair<Map,Piece>> m_map;
    enum BombermanRole{
        TypeMap = Qt::UserRole + 1,
        ImageMap,
        PieceInMap
    };

    void fillMap();
};

#endif // BOMBERMANMODEL_H
