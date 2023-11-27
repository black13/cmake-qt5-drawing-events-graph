#include "VertexObject.h"
#include <QPainter>

VertexObject::VertexObject(const QRectF &rect, const QUuid& uuid, const Vertex& vertex, QGraphicsItem *parent)
    : QGraphicsObject(parent), rect_(rect), uuid_(uuid), vertex_(vertex) {
    setFlags(ItemIsMovable | ItemSendsGeometryChanges);
}

QRectF VertexObject::boundingRect() const {
    return rect_;
}

void VertexObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(Qt::gray);
    painter->drawRect(rect_);
}

QVariant VertexObject::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionHasChanged) {
        emit positionChanged();
    }
    return QGraphicsObject::itemChange(change, value);
}
