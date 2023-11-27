#include "VertexObject.h"
#include <QPainter>
#include <QGraphicsSceneHoverEvent>

VertexObject::VertexObject(const QRectF &rect, const QUuid& uuid, const Vertex& vertex, QGraphicsItem *parent)
    : QGraphicsObject(parent), rect_(rect), uuid_(uuid), vertex_(vertex), brush_(Qt::white) {
    setFlags(ItemIsMovable | ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}

QRectF VertexObject::boundingRect() const {
    return rect_;
}

void VertexObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(brush_);
    painter->drawRect(rect_);
}

void VertexObject::hoverEnterEvent(QGraphicsSceneHoverEvent* event) {
    brush_ = QBrush(Qt::red);  // Change color to red on hover
    update();
}

void VertexObject::hoverLeaveEvent(QGraphicsSceneHoverEvent* event) {
    brush_ = QBrush(Qt::white);  // Change color back to white when hover ends
    update();
}

QVariant VertexObject::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionHasChanged) {
        emit positionChanged();
    }
    return QGraphicsObject::itemChange(change, value);
}
