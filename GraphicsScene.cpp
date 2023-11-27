#include <QRandomGenerator>
#include <QPainter>
#include <QRandomGenerator>
#include <QPointF>
#include <cmath>

#include <QGraphicsLineItem>
#include <QDebug>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "VertexObject.h"
#include "GraphicsScene.h"

GraphicsScene::GraphicsScene(QObject *parent) : QGraphicsScene(parent) {
    // Constructor implementation (if needed)
}

Vertex GraphicsScene::addVertex(const QPointF& position) {
    QUuid uuid = QUuid::createUuid();
    Vertex vertex = boost::add_vertex(graph_);
    
    // Create a rectangle for the vertex object
    QRectF rect(-5, -5, 10, 10); // Adjust the rectangle size as needed

    // Instantiate VertexObject
    VertexObject *vertexObject = new VertexObject(rect, uuid, vertex);
    
    // Set the position of the vertexObject
    vertexObject->setPos(position);

    // Add vertexObject to the scene
    addItem(vertexObject);

    // Connect the positionChanged signal to the updateEdges slot
    connect(vertexObject, &VertexObject::positionChanged, this, &GraphicsScene::updateEdges);

    // Insert the vertex and its object into the map
    vertexItems_[vertex] = vertexObject;
    itemUuids_[vertexObject] = uuid;

    // Debug output
    qDebug() << "Vertex added at position:" << vertexObject->pos();

    return vertex;
}


void GraphicsScene::addEdge(Vertex v1, Vertex v2) {
    if (!vertexItems_.contains(v1) || !vertexItems_.contains(v2)) {
        return; // Vertex not found
    }

    QPointF pos1 = vertexItems_.value(v1)->pos();
    QPointF pos2 = vertexItems_.value(v2)->pos();
    qDebug() << "pos1:" << pos1 << " pos2:" << pos2;

    QGraphicsLineItem *lineItem = new QGraphicsLineItem(QLineF(pos1, pos2));
    addItem(lineItem);
    Edge edge;
    bool added;
    boost::tie(edge, added) = boost::add_edge(v1, v2, graph_);
    if (added) {
        edgeItems_.insert(edge, lineItem);
    } else {
        delete lineItem; // Make sure lineItem is a pointer to QGraphicsLineItem
    }
}

void GraphicsScene::updateEdges() {
    for (auto it = edgeItems_.begin(); it != edgeItems_.end(); ++it) {
        Edge edge = it.key();
        QGraphicsLineItem *lineItem = it.value();

        Vertex source = boost::source(edge, graph_);
        Vertex target = boost::target(edge, graph_);

        lineItem->setLine(QLineF(vertexItems_.value(source)->pos(), vertexItems_.value(target)->pos()));
    }
}


void GraphicsScene::addLargeGraph(int nodeCount, int edgesPerNode) {
    if (nodeCount <= 0 || edgesPerNode <= 0) return;

    // Clear existing graph
    clear();
    graph_.clear();
    vertexItems_.clear();
    edgeItems_.clear();
    itemUuids_.clear();

    // Add vertices
    for (int i = 0; i < nodeCount; ++i) {
        qreal x = QRandomGenerator::global()->bounded(0, 800); // Assuming scene size
        qreal y = QRandomGenerator::global()->bounded(0, 600);
        addVertex(QPointF(x, y));
    }

    // Add edges
    for (Vertex v = 0; v < nodeCount; ++v) {
        for (int j = 0; j < edgesPerNode; ++j) {
            Vertex other = QRandomGenerator::global()->bounded(0, nodeCount);
            // Ensure no self-loop and no duplicate edge
            if (other != v && !boost::edge(v, other, graph_).second) {
                addEdge(v, other);
            }
        }
    }
}
