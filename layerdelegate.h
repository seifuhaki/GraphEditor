#ifndef LAYERDELEGATE_H
#define LAYERDELEGATE_H

#include <QStyledItemDelegate>
#include <QLineEdit>
#include <QDebug>
#include <QPainter>

class LayerDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    LayerDelegate(QObject *parent=nullptr);
    ~LayerDelegate();


    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;
    bool editorEvent(QEvent * event,
        QAbstractItemModel * model,
        const QStyleOptionViewItem & option,
        const QModelIndex & index);
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

#endif // LAYERDELEGATE_H
