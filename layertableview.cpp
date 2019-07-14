#include "layertableview.h"

LayerTableView::LayerTableView(vector<Layer *> *layerlist,QWidget *parent)
    : QTableView(parent)
{
    delegate = new LayerDelegate();
    model = new LayerTableModel(layerlist);

    this->setContentsMargins(0, 0, 0, 0);
    this->setModel(model);
    this->setItemDelegate(delegate);
    this->horizontalHeader()->setStretchLastSection(true);
    this->horizontalHeader()->setHighlightSections(false);
    this->setFrameShape(QFrame::NoFrame);
    this->setColumnWidth(0, 30);
    this->setColumnWidth(1, 170);
    this->verticalHeader()->setVisible(true);
    this->horizontalHeader()->setVisible(true);
    this->resizeColumnsToContents();
    this->resizeRowsToContents();
    /*this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);*/
    this->setMouseTracking(true);//important

    //When click on the checkbox it will emit signal twice.Click on the cell emit only once.
    connect(this, SIGNAL(clicked(const QModelIndex&)), this, SLOT(itemClicked(const QModelIndex&)));
    connect(model,SIGNAL(dataChanged(const QModelIndex&,const QModelIndex&,const QVector<int> &)),this,SLOT(modelDataChanged(const QModelIndex&,const QModelIndex&,const QVector<int> &)));
}

LayerTableView::~LayerTableView()
{

}

void LayerTableView::mouseMoveEvent(QMouseEvent * event)
{

}



void LayerTableView::contextMenuEvent(QContextMenuEvent * event)
{

    QMenu *pMenu = new QMenu(this);
    int row_index = event->pos().y()/rowHeight(0);
    if (row_index>=model->rowCount())
    {
        pMenu->addAction(tr("New Layer"),this,SLOT(createLayer()));
        pMenu->popup(mapToGlobal(event->pos()));
    }
    else
    {
        model->setSelecttedRow(row_index);
        emit currentLayerChanged(row_index);
        pMenu->addAction(tr("Delete Layer"),this,SLOT(deleteLayer()));
        pMenu->addAction(tr("Move Up Layer"),this,SLOT(layerUp()));
        pMenu->addAction(tr("Move Down Layer"),this,SLOT(layerDown()));
        pMenu->popup(mapToGlobal(event->pos()));
    }

}

void LayerTableView::addNewLayer(int layer_id)
{
    model->addItem();
    model->refreshModel();
    this->resizeRowsToContents();
}

void LayerTableView::itemClicked(const QModelIndex& index)
{
    if (index.isValid() )
    {
        //When click in column 0, 1.
        if (index.column() == 0 || index.column() ==1)
        {
            if (index.column()==0) model->changeLayerVisibility(index);
            else model->changeLayerVisionType(index);
            QModelIndex tmp = model->selecttedIndex(model->getSelecttedRow());
            this->selectionModel()->select(tmp, QItemSelectionModel::Select);
        }
        //When click in column 2.
        else if (index.column() == 2)
        {
            model->setSelecttedRow(index.row());
            emit currentLayerChanged(index.row());
        }
    }
}

void LayerTableView::deleteLayer()
{
    emit tableDeleteLayer(model->getSelecttedRow());
    model->refreshModel();
    this->resizeRowsToContents();
    QModelIndex tmp = model->selecttedIndex(0);
    this->selectionModel()->select(tmp, QItemSelectionModel::Select);
}
void LayerTableView::layerDown()
{
    int row_index = model->getSelecttedRow();
    if(row_index == 0) return ;
    emit tableLayerResorted(row_index,row_index-1);
    model->setSelecttedRow(model->getSelecttedRow()-1);
    model->refreshModel();
}
void LayerTableView::layerUp()
{
    int row_index = model->getSelecttedRow();
    if(row_index+1 >= model->rowCount()) return ;
    emit tableLayerResorted(row_index,row_index+1);
    model->setSelecttedRow(model->getSelecttedRow()+1);
    model->refreshModel();
}
void LayerTableView::createLayer()
{
    emit tableLayerCreated();
}

void LayerTableView::modelDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles){
    emit tableDataChanged();
}
void LayerTableView::RefreshTable(){
    model->refreshModel();
}
