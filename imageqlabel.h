#ifndef IMAGEQLABEL_H
#define IMAGEQLABEL_H
#include<QLabel>
#include<QMouseEvent>
#include<QKeyEvent>
class ImageQLabel:public QLabel
{
    Q_OBJECT
private:
    QPixmap preview_;
    qreal zoom_level_=1.0;
    QPoint clicked_pos;
    QPoint move_pos;
signals:
    void dragged(QPoint,QPoint);
    void moved(QPoint,QPoint);
public:
    ImageQLabel();
    ImageQLabel(QWidget *parent);
    void SetPreview(const QPixmap &new_preview);
    void SetZoomLevel(qreal delta_level);
    void ResetZoom();
    void RefreshView();
    qreal GetZoomLevel()const;
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
};

#endif // IMAGEQLABEL_H
