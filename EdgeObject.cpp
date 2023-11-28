#include <QGraphicsSceneHoverEvent>
#include <QDebug>
#include <QPainter>
#include "EdgeObject.h"

#include "debug.h"
EdgeObject::EdgeObject(const QLineF &line, const QUuid& uuid, const Edge& edge, QGraphicsItem *parent)
    : QGraphicsLineItem(line, parent), uuid_(uuid), edge_(edge), pen_(Qt::black) {
    setAcceptHoverEvents(true);
    pen_.setWidth(3); // Set the pen width to make the line thicker
    pen_.setColor(Qt::black); // You can also set the default color here
    setPen(pen_);
    DEBUG_LOG("");
}

void EdgeObject::updatePosition(const QPointF& sourcePos, const QPointF& targetPos) {
    setLine(QLineF(sourcePos, targetPos));
}

const QUuid& EdgeObject::uuid() const {
    return uuid_;
}

const Edge& EdgeObject::edge() const {
    return edge_;
}

void EdgeObject::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    pen_.setColor(Qt::red);  // Change color to red on hover
    setPen(pen_);
    DEBUG_LOG("");
}

void EdgeObject::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    pen_.setColor(Qt::black);  // Revert color back to black when hover ends
    setPen(pen_);
    DEBUG_LOG("");
}
void EdgeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)

    // Dynamic adjustment of the pen (if needed)
    QPen dynamicPen = pen_;
    dynamicPen.setWidth(3); // Adjust width dynamically
    painter->setPen(dynamicPen);

    painter->drawLine(this->line());
}
