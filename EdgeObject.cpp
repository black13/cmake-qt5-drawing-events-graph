#include "EdgeObject.h"

EdgeObject::EdgeObject(const QLineF &line, const QUuid& uuid, const Edge& edge, QGraphicsItem *parent)
    : QGraphicsLineItem(line, parent), uuid_(uuid), edge_(edge) {
    // Set any necessary properties for the line item, like pen color, width, etc.
}

void EdgeObject::updatePosition(const QPointF& sourcePos, const QPointF& targetPos) {
    setLine(QLineF(sourcePos, targetPos));
}

// Additional methods can be implemented as needed.
