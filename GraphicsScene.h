#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QMap>
#include <QUuid>
#include <boost/graph/adjacency_list.hpp>// Define a simple undirected graph type
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;

// Forward declaration of the VertexObject class
class VertexObject;

class GraphicsScene : public QGraphicsScene {
    Q_OBJECT

public:
    GraphicsScene(QObject *parent = nullptr);

    // Method to add a vertex at a specified position
    Vertex addVertex(const QPointF& position);

    // Method to add an edge between two vertices
    void addEdge(Vertex v1, Vertex v2);

    void addLargeGraph(int nodeCount, int edgesPerNode);
private slots:
    // Slot to update edge positions when vertices move
    void updateEdges();

private:
    Graph graph_;
    QMap<Vertex, VertexObject*> vertexItems_;
    QMap<Edge, QGraphicsLineItem*> edgeItems_;
    QMap<QGraphicsItem*, QUuid> itemUuids_;
};

#endif // GRAPHICSSCENE_H
