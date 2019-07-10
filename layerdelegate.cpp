#include "layerdelegate.h"

LayerDelegate::LayerDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

LayerDelegate::~LayerDelegate()
{

}



void LayerDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{


    if (index.column() == 2) // value column
    {
        if (option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, option.palette.highlight());

        QImage image = qvariant_cast<QImage>(index.data(Qt::DecorationRole));
        QRect rect = option.rect;
        int x = rect.x() + 10;
        int y = rect.y() + 5;

        QBrush brush;
        painter->drawImage(x, y, image);

        QRect textRect(rect.x() + 60, rect.y(), rect.width() - 60, rect.height());

        QString layerName = index.model()->data(index, Qt::DisplayRole).toString();
        QTextOption textOption = Qt::AlignLeft | Qt::AlignVCenter;
        painter->drawText(textRect, layerName, textOption);

    }
    else
    {
        QStyledItemDelegate::paint(painter, option, index);
    }
}


bool LayerDelegate::editorEvent(QEvent * event,
    QAbstractItemModel * model,
    const QStyleOptionViewItem & option,
    const QModelIndex & index)
{
    return false;
}

QWidget *LayerDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &option,
    const QModelIndex &index) const
{
    qDebug() << "createEditor";
    if (index.column() == 2) // value column
    {
        QLineEdit* edit = new QLineEdit(parent);
        edit->setFixedHeight(33);
        edit->setContentsMargins(48, 15, 50, 0);
        return edit;
    }
    else return 0;  // no editor attached
}

void LayerDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();

    QLineEdit *edit = static_cast<QLineEdit*>(editor);
    edit->setText(value);
    //qDebug() << "setEditorData";
}

void LayerDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex & index ) const
{
    editor->setGeometry(option.rect);
}

void LayerDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
    const QModelIndex &index) const
{
    //qDebug() << "setModelData";
    QLineEdit *edit = static_cast<QLineEdit*>(editor);
    model->setData(index, edit->text(), Qt::EditRole);
}

