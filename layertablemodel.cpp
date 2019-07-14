#include "layertablemodel.h"
LayerTableModel::LayerTableModel(vector<Layer*> *layerlist):layerlist(layerlist){}
LayerTableModel::~LayerTableModel(){}
QVariant LayerTableModel::data(const QModelIndex &index,int role) const
{
    if (!index.isValid())
        return QVariant();
    int column = index.column();
    if (column == 0){//col1: visibility
        if (role == Qt::CheckStateRole){
            return (*layerlist)[index.row()]->get_visibility() ?
                    Qt::Checked :
                    Qt::Unchecked;
        }
        if (role == Qt::SizeHintRole) return QSize(20,20);
    }
    else if (column == 1){//col2: visionType
        if (role == Qt::CheckStateRole){
            return (*layerlist)[index.row()]->get_visionType() ?
                    Qt::Checked :
                    Qt::Unchecked;
        }
        if (role == Qt::SizeHintRole) return QSize(20,20);
    }
    else {
        if (role == Qt::EditRole)
        {
            return QVariant(QString::fromStdString((*layerlist)[index.row()]->get_name()));
        }
        if (role == Qt::DisplayRole)
        {
            return QVariant(QString::fromStdString((*layerlist)[index.row()]->get_name()));
        }
        if (role == Qt::DecorationRole)
        {
            return (*layerlist)[index.row()]->getThumbNail(40,40);
        }
        if (role ==Qt::SizeHintRole)
        {
            return QSize(200,50);
        }
        if (role ==Qt::TextAlignmentRole)
        {
            return  int(Qt::AlignCenter);
        }
    }
    return QVariant();
}
QVariant LayerTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole){
        if (orientation==Qt::Orientation::Horizontal)
            return header_name[section];
        else return QString::number(section);
    }
    return QAbstractItemModel::headerData(section, orientation, role);
}
Qt::ItemFlags LayerTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) return 0;
    if (index.column()==0||index.column() == 1)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsUserCheckable;
    }
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable|Qt::ItemIsEditable;
}
bool LayerTableModel::setData(const QModelIndex &index,const QVariant &value,int role)
{
    if (!index.isValid()) return false;
    if (role == Qt::CheckStateRole && value.type()==QVariant::Bool)
    {
        if (index.column()==0) (*layerlist)[index.row()]->set_visibility(value.toBool());
        else (*layerlist)[index.row()]->set_visionType((Transparency)value.toInt());
        emit(dataChanged(index,index));
        return true;
    }
    else if (role == Qt::EditRole && value.type()==QVariant::String)
    {
        (*layerlist)[index.row()]->set_name(value.toString().toStdString());
        emit(dataChanged(index,index));
        return true;
    }
    return false;
}
void LayerTableModel::changeLayerVisibility(const QModelIndex &index)
{
    if (index.isValid()&&index.column()==0) setData(index,!((*layerlist)[index.row()]->get_visibility()),Qt::CheckStateRole);
}

void LayerTableModel::changeLayerVisionType(const QModelIndex &index)
{
    if (index.isValid()&&index.column()==1) setData(index,!((*layerlist)[index.row()]->get_visionType()),Qt::CheckStateRole);
}
void LayerTableModel::refreshModel(){
    beginResetModel();
    endResetModel();
}
QModelIndex LayerTableModel::selecttedIndex(int row)
{
    return this->createIndex(row, 1);
}

void LayerTableModel::setSelecttedRow(int row)
{
    selectedRow = row;
}

int LayerTableModel::getSelecttedRow() const
{
    return selectedRow;
}



int LayerTableModel::rowCount(const QModelIndex &parent) const
{
    return (parent.isValid() && parent.column() != 0) ? 0 : layerlist->size();
}
int LayerTableModel::rowCount() const
{
    return layerlist->size();
}

int LayerTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}
void LayerTableModel::deleteItem(int index){}
void LayerTableModel::addItem(){}
