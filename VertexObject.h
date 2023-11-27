#ifndef VERTEXOBJECT_H
#define VERTEXOBJECT_H

#include <QGraphicsObject>
#include <QUuid>
#include <boost/graph/adjacency_list.hpp>

typedef boost::graph_traits<boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>>::vertex_descriptor Vertex;

class VertexObject : public QGraphicsObject {
    Q_OBJECT

public:
    VertexObject(const QRectF &rect, const QUuid& uuid, const Vertex& vertex, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    const QUuid& uuid() const { return uuid_; }
    const Vertex& vertex() const { return vertex_; }

signals:
    void positionChanged();

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    QRectF rect_;
    QUuid uuid_;
    Vertex vertex_;
};

#endif // VERTEXOBJECT_H
