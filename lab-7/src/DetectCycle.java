public class DetectCycle {
    public static void main(String[] args) {
        // assuming that there are no negative valued nodes
        Graph graph = new Graph();
        graph.addEdge(1, 0);
        graph.addEdge(0, 2);
        graph.addEdge(2, 1);
        graph.addEdge(0, 3);
        graph.addEdge(3, 4);
        System.out.println(graph.getAllEdges());
        System.out.println(graph.generateAdjacencyList());
    }
}
