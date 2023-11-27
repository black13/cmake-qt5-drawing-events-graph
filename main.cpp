#include <QApplication>
#include <QGraphicsView>
#include "GraphicsScene.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create the graphics view and scene
    QGraphicsView view;
    GraphicsScene scene;

    view.setScene(&scene);
    view.setSceneRect(0, 0, 800, 600); // Set scene size as needed
    view.show();

    // Add a large graph to the scene
    // int nodeCount = 2; // Example node count
    // int edgesPerNode = 1; // Example edges per node
    scene.addLargeGraph(5, 2);

    // Add two vertices
    //Vertex v1 = scene.addVertex(QPointF(100, 100));
    //Vertex v2 = scene.addVertex(QPointF(300, 300));

    // Add an edge between the vertices
    //scene.addEdge(v1, v2);
    
    return app.exec();
}
