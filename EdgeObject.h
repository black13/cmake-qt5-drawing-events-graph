#ifndef EDGEOBJECT_H
#define EDGEOBJECT_H

#include <QGraphicsLineItem>
#include <QUuid>
#include <boost/graph/adjacency_list.hpp>

typedef boost::graph_traits<boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>>::edge_descriptor Edge;

class EdgeObject : public QGraphicsLineItem {
public:
    EdgeObject(const QLineF &line, const QUuid& uuid, const Edge& edge, QGraphicsItem *parent = nullptr);

    void updatePosition(const QPointF& sourcePos, const QPointF& targetPos);
    const QUuid& uuid() const { return uuid_; }
    const Edge& edge() const { return edge_; }

private:
    QUuid uuid_;
    Edge edge_;
};

#endif // EDGEOBJECT_H
