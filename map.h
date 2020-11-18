#ifndef MAP_H
#define MAP_H

#include <QAbstractListModel>
#include <QObject>
#include <vector>
#include <utility>
#include <QVector>

enum class TYPE {BOT,brick_wall,CRASH_BLOCK,CORRIDOR,BOMB,EXPLOSION};

class Map : public QAbstractListModel
{
    Q_OBJECT
    //Q_PROPERTY()
public:

    enum{
        ImageRole = 1,
    };


    static constexpr size_t defaultBordSize{49};

    Map( const size_t bordSize = defaultBordSize, QObject* parent = nullptr );

    struct Piece{
        Piece(){};
        Piece(char sumbol, QString image):sumbol(sumbol),image(image){};
        char sumbol;
        QString image;
        //        bool operator ==(const TYPE otherType){
        //            return type_ == otherType;
        //        }
    };

    int rowCount(const QModelIndex &parent = QModelIndex{})const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int,QByteArray>roleNames()const override;
private:
    void fillBoard();
    bool ispositionValid(const size_t position)const;

    std::vector<Piece> m_boardMap;
    const size_t m_boardSize;
};

#endif // MAP_H
