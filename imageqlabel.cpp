#include "imageqlabel.h"
#include <QDebug>
ImageQLabel::ImageQLabel()
{

}
ImageQLabel::ImageQLabel(QWidget *parent):QLabel(parent)
{

}
void ImageQLabel::SetPreview(const QPixmap &new_preview)
{
    preview_ = new_preview.copy();
    RefreshView();
}
void ImageQLabel::SetZoomLevel(qreal delta_level)
{
    zoom_level_+=delta_level;
    zoom_level_ = zoom_level_ > 0?(zoom_level_<1.0?zoom_level_:1.0):0.0;
    RefreshView();
}
void ImageQLabel::RefreshView(){
    if (preview_.isNull()) return ;
    resize(preview_.size()*zoom_level_);
    clear();
    setPixmap(preview_.scaled(preview_.size()*zoom_level_));
}
void ImageQLabel::mousePressEvent(QMouseEvent *event){
    clicked_pos=QPoint(event->x(),event->y());
    move_pos=clicked_pos;
}
void ImageQLabel::mouseReleaseEvent(QMouseEvent *event){
    QPoint endpoint=QPoint(event->x(),event->y());
    emit dragged(clicked_pos,endpoint);
}
void ImageQLabel::mouseMoveEvent(QMouseEvent *event){
    QPoint endpoint=QPoint(event->x(),event->y());
    emit moved(move_pos,endpoint);
    move_pos = endpoint;
}
void ImageQLabel::ResetZoom(){
    zoom_level_=1.0;
    RefreshView();
}


qreal ImageQLabel::GetZoomLevel()const{
    return zoom_level_;
}
