import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

class HuffmanCoding {
    private record Letter(char character, int freq) {}

    private record Node(String symbol, int value, Node left, Node right) {
        @Override
        public String toString() {
            return this.value + "";
        }
    }

    private static void bfs(Node root) {
        if (root == null) {
            return;
        }
        List<Node> list = new LinkedList<>();
        list.add(root);

        while (!list.isEmpty()) {
            Node node = list.remove(0);
            System.out.print(node + " ");
            if (node.left != null) {
                list.add(node.left);
            }
            if (node.right != null) {
                list.add(node.right);
            }
        }
    }

    public static void main(String[] args) {
        Letter[] input = {
            new Letter('a', 5),
            new Letter('b', 1),
            new Letter('c', 6),
            new Letter('d', 3),
        };

        List<Node> nodes = new LinkedList<>();
        for (Letter letter : input) {
            nodes.add(new Node(letter.character + "", letter.freq, null, null));
        }

        while (!nodes.isEmpty()) {
            nodes.sort(Comparator.comparingInt(node -> node.value));
            System.out.println(nodes);
            if (nodes.size() == 1) {
                break;
            }
            Node left = nodes.remove(0);
            Node right = nodes.remove(0);
            Node node = new Node(left.symbol + right.symbol, left.value + right.value, left, right);
            nodes.add(node);
        }

        Node root = nodes.remove(0);
        bfs(root);
    }
}
