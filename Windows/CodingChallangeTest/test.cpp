#include "pch.h"
#include "../CodingChallange/graph.cpp"
#include "../CodingChallange/vertex.cpp"

TEST(TestAddVertex, Subset_1) {
  int a = 10;
  Graph graph(a);
}

TEST(TestAddEdge, Subset_1) {
  // Arrange
  Graph graph(10);
  vector<Vertex*> control;

  // Add node 0
  graph.addEdge(0, 1, 3);
  graph.addEdge(0, 4, 8);
  graph.addEdge(0, 3, 7);

  control.push_back(new Vertex(0));
  control.at(0)->getDestinations()->push_back(make_pair(1, 3));
  control.at(0)->getDestinations()->push_back(make_pair(4, 8));
  control.at(0)->getDestinations()->push_back(make_pair(3, 7));

  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(graph.getList().at(0)->getDestinations()->at(i).first,
              control.at(0)->getDestinations()->at(i).first);
    EXPECT_EQ(graph.getList().at(0)->getDestinations()->at(i).second,
              control.at(0)->getDestinations()->at(i).second);
  }

  // Add node 1
  graph.addEdge(1, 3, 4);
  graph.addEdge(1, 1, 2);

  control.push_back(new Vertex(1));
  control.at(1)->getDestinations()->push_back(make_pair(3, 4));
  control.at(1)->getDestinations()->push_back(make_pair(1, 2));

  for (int i = 0; i < 2; i++) {
    EXPECT_EQ(graph.getList().at(1)->getDestinations()->at(i).first,
              control.at(1)->getDestinations()->at(i).first);
    EXPECT_EQ(graph.getList().at(1)->getDestinations()->at(i).second,
              control.at(1)->getDestinations()->at(i).second);
  }

  // Add node 2
  control.push_back(new Vertex(2));

  // Add node 3
  graph.addEdge(3, 2, 2);

  control.push_back(new Vertex(3));
  control.at(3)->getDestinations()->push_back(make_pair(2, 2));

  EXPECT_EQ(graph.getList().at(3)->getDestinations()->at(0).first,
            control.at(3)->getDestinations()->at(0).first);
  EXPECT_EQ(graph.getList().at(3)->getDestinations()->at(0).second,
            control.at(3)->getDestinations()->at(0).second);

  // Add node 4
  graph.addEdge(4, 3, 3);

  control.push_back(new Vertex(4));
  control.at(4)->getDestinations()->push_back(make_pair(3, 3));

  EXPECT_EQ(graph.getList().at(4)->getDestinations()->at(0).first,
            control.at(4)->getDestinations()->at(0).first);
  EXPECT_EQ(graph.getList().at(4)->getDestinations()->at(0).second,
            control.at(4)->getDestinations()->at(0).second);
}

TEST(TestDeleteEdge, subset_1) {
  // Arrange
  Graph graph(10);
  vector<Vertex*> control;

  // Add node 0 and 1
  graph.addEdge(0, 1, 3);
  graph.addEdge(0, 4, 8);
  graph.addEdge(0, 3, 7);
  graph.addEdge(1, 3, 4);
  graph.addEdge(1, 1, 2);

  // Delete node 0
  EXPECT_EQ(graph.getList().at(0)->getDestinations()->size(), 3);
  EXPECT_EQ(graph.getList().at(1)->getDestinations()->size(), 2);
  graph.deleteEdge(0);
  EXPECT_EQ(graph.getList().at(0)->getDestinations()->size(), 0);
  EXPECT_EQ(graph.getList().at(1)->getDestinations()->size(), 2);
}

TEST(TestShortestPath, subset_1) {
  // Arrange
  Graph graph(5);
  vector<int> control;

  graph.addEdge(0, 1, 3);
  graph.addEdge(0, 4, 8);
  graph.addEdge(0, 3, 7);
  graph.addEdge(1, 3, 4);
  graph.addEdge(1, 1, 2);
  graph.addEdge(3, 2, 2);
  graph.addEdge(4, 3, 3);

  control.push_back(0);
  control.push_back(3);
  control.push_back(9);
  control.push_back(7);
  control.push_back(8);

  EXPECT_EQ(graph.shortestPath(0), control);
}

TEST(TestACyclic, subset_1) {
  // Arrange
  Graph graph(5);
  vector<int> control;

  graph.addEdge(0, 1, 3);
  graph.addEdge(0, 4, 8);
  graph.addEdge(0, 3, 7);
  graph.addEdge(1, 3, 4);
  graph.addEdge(1, 1, 2);
  graph.addEdge(3, 2, 2);
  graph.addEdge(4, 3, 3);

  EXPECT_EQ(graph.isACyclic(), true);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
};
