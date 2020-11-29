#ifndef MAP_H
#define MAP_H

#include <QAbstractListModel>
#include <QObject>
#include <vector>
#include <utility>
#include <QVector>

enum class TYPE_MAP {WALL,CORRIDOR,EMPTY};



Q_DECLARE_METATYPE(TYPE_MAP)

class Map
{
public:
    Map() = default;
    //using Position = std::pair<size_t,size_t>;
    //static constexpr size_t defaultBordSize{49};

    Map(const TYPE_MAP &type, QString image);

    TYPE_MAP getTypeMap() const;
    QString getImageMap() const;
    QString getPieceImage() const;
    void setCurrentIdnex(int index);
    int getCurrentIndex() const;


private:
    TYPE_MAP typeMap{};
    QString imageMap{};
};

#endif // MAP_H
