#ifndef MODGRAPHICSVIEW_H
#define MODGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>

class ModGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ModGraphicsView(QWidget *parent = nullptr);
};

#endif // MODGRAPHICSVIEW_H
