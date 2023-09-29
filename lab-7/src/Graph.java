import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Graph {
    private final List<Pair<Integer, Integer>> edges;
    private final List<Set<Integer>> list;

    Graph() {
        this.edges = new ArrayList<>();
        this.list = new ArrayList<>();
    }

    void addEdge(int u, int v) {
        this.edges.add(new Pair<>(u, v));
    }

    List<Pair<Integer, Integer>> getAllEdges() {
        return this.edges;
    }

    List<Set<Integer>> generateAdjacencyList() {
        int countNodes = countNodes();
        for (int i = 0; i < countNodes; i++) {
            list.add(new HashSet<>());
        }
        for (Pair<Integer, Integer> edge : this.edges) {
            list.get(edge.first).add(edge.second);
            list.get(edge.second).add(edge.first);
        }
        return this.list;
    }

    private int countNodes() {
        Set<Integer> set = new HashSet<>();
        for (Pair<Integer, Integer> edge : this.edges) {
            set.add(edge.first);
            set.add(edge.second);
        }
        return set.size();
    }
}
