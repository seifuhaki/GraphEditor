#ifndef LAYERTABLEMODEL_H
#define LAYERTABLEMODEL_H
#include"layer.h"
#include<QAbstractTableModel>
#include<QObject>
#include<QList>

class LayerTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    int rowCount(const QModelIndex &parent) const;
    int rowCount() const;
    int columnCount(const QModelIndex &parent) const;
    LayerTableModel(vector<Layer*> *layerlist = nullptr);
    ~LayerTableModel();
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);
    void deleteItem(int index);
    void addItem();
    void refreshModel();
    QModelIndex selecttedIndex(int row);

    void setSelecttedRow(int row);
    int getSelecttedRow() const;


public slots:
    void changeLayerVisibility(const QModelIndex&);
    void changeLayerVisionType(const QModelIndex&);

private:
    vector<Layer*> *layerlist;
    int selectedRow;
    const QStringList header_name={tr("Visibility"),tr("Opacity"),tr("Layer Name")};
};

#endif // LayerTableModel_H
