#ifndef MAP_H
#define MAP_H

#include <QAbstractListModel>
#include <QObject>
#include <vector>
#include <utility>
#include <QVector>

enum class TYPE {BOT,BLOCK,CRASH_BLOCK,CORRIDOR,BOMB,EXPLOSION};




class Board : public QAbstractListModel
{
    Q_OBJECT
    //Q_PROPERTY()
public:

    static constexpr size_t defaultBordSize{49};

    Board( const size_t bordSize = defaultBordSize, QObject* parent = nullptr );

    struct Piece{
        Piece(const char& sumbolG,const TYPE &typeG):sumbol_(sumbolG),type_(typeG){};
        char sumbol_{};
        TYPE type_{};
        bool operator ==(const TYPE otherType){
            return type_ == otherType;
        }
    };

    int rowCount(const QModelIndex &parent = QModelIndex{})const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    void fillBoard();
    bool ispositionValid(const size_t position)const;

    std::vector<Piece> m_boardMap;
    const size_t m_boardSize;
};

#endif // MAP_H
