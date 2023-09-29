import java.util.*;

class HuffmanCoding {
    private record Letter(char character, int freq) {
        public String toString() {
            return "(" + this.character + ", " + this.freq + ")";
        }
    }

    private record Node(String symbol, int value, Node left, Node right) {
        @Override
        public String toString() {
            return this.value + "";
        }
    }

    static LinkedHashMap<Character, Integer> sorted(LinkedHashMap<Character, Integer> m) {
        LinkedHashMap<Character, Integer> newMap = new LinkedHashMap<>();
        List<Integer> list = new LinkedList<>();

        for (Map.Entry<Character, Integer> e : m.entrySet()) {
            list.add(e.getValue());
        }
        Collections.sort(list);

        for (Integer i : list) {
            for (Map.Entry<Character, Integer> e : m.entrySet()) {
                if (e.getValue().equals(i)) {
                    newMap.put(e.getKey(), i);
                }
            }
        }
        return newMap;
    }

    public static void main(String[] args) {
        String s = "aabbccccd";
        LinkedHashMap<Character, Integer> m = new LinkedHashMap<>();
        for (char c : s.toCharArray()) {
            m.merge(c, 1, Integer::sum);
        }
        m = sorted(m);
        List<Letter> input = new LinkedList<>();

        for (Map.Entry<Character, Integer> entry : m.entrySet()) {
            input.add(new Letter(entry.getKey(), entry.getValue()));
        }

        System.out.println(input);

        List<Node> nodes = new LinkedList<>();
        for (Letter letter : input) {
            nodes.add(new Node(letter.character + "", letter.freq, null, null));
        }

        while (!nodes.isEmpty()) {
            nodes.sort(Comparator.comparingInt(node -> node.value));
            if (nodes.size() == 1) {
                break;
            }
            Node left = nodes.remove(0);
            Node right = nodes.remove(0);
            Node node = new Node(left.symbol + right.symbol, left.value + right.value, left, right);
            nodes.add(node);
        }

        Node root = nodes.remove(0);
    }
}
