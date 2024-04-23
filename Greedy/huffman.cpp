#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// A Huffman tree node
struct Node {
    char data;
    unsigned frequency;
    Node *left, *right;

    Node(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->frequency > r->frequency;
    }
};

// Traverse the Huffman tree and store codes in a map
void encode(Node* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) // If leaf node
        codes[root->data] = code;

    encode(root->left, code + "0", codes);
    encode(root->right, code + "1", codes);
}

// Build Huffman tree and return the root
Node* buildHuffmanTree(const unordered_map<char, unsigned>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // Merge nodes until only one node remains in the priority queue
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('$', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    return pq.top();
}

int main() {
    string text = "hello world";
    unordered_map<char, unsigned> freq;

    // Count frequency of each character in the text
    for (char c : text)
        freq[c]++;

    // Build Huffman tree
    Node* root = buildHuffmanTree(freq);

    // Traverse Huffman tree to get codes for each character
    unordered_map<char, string> codes;
    encode(root, "", codes);

    // Print Huffman codes
    cout << "Huffman Codes:" << endl;
    for (const auto& pair : codes)
        cout << pair.first << ": " << pair.second << endl;

    return 0;
}
/*
Sure, let's go through the code line by line:

```cpp
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
```

- This section includes the necessary header files for input/output, priority queue (used for building the Huffman tree), and unordered map (used for storing frequency counts and Huffman codes).

```cpp
// A Huffman tree node
struct Node {
    char data;
    unsigned frequency;
    Node *left, *right;

    Node(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};
```

- This defines the structure of a node in the Huffman tree. Each node stores a character (`data`), its frequency (`frequency`), and pointers to its left and right children (`left` and `right`). The constructor initializes these values.

```cpp
// Comparison function for priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->frequency > r->frequency;
    }
};
```

- This defines a custom comparison function `Compare` for the priority queue, used to order nodes based on their frequencies in ascending order.

```cpp
// Traverse the Huffman tree and store codes in a map
void encode(Node* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) // If leaf node
        codes[root->data] = code;

    encode(root->left, code + "0", codes);
    encode(root->right, code + "1", codes);
}
```

- This function recursively traverses the Huffman tree and assigns Huffman codes to each character. It starts from the root of the tree and traverses left branches with '0' and right branches with '1'. When it reaches a leaf node, it assigns the accumulated code to the corresponding character in the `codes` map.

```cpp
// Build Huffman tree and return the root
Node* buildHuffmanTree(const unordered_map<char, unsigned>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // Merge nodes until only one node remains in the priority queue
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('$', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    return pq.top();
}
```

- This function builds the Huffman tree based on the frequency of characters in the input text. It starts by creating leaf nodes for each character and their frequency, then repeatedly merges the two nodes with the lowest frequencies until only one node (the root of the Huffman tree) remains in the priority queue.

```cpp
int main() {
    string text = "hello world";
    unordered_map<char, unsigned> freq;

    // Count frequency of each character in the text
    for (char c : text)
        freq[c]++;

    // Build Huffman tree
    Node* root = buildHuffmanTree(freq);

    // Traverse Huffman tree to get codes for each character
    unordered_map<char, string> codes;
    encode(root, "", codes);

    // Print Huffman codes
    cout << "Huffman Codes:" << endl;
    for (const auto& pair : codes)
        cout << pair.first << ": " << pair.second << endl;

    return 0;
}
```

- In the `main` function:
  - We define an input text.
  - We create an unordered map `freq` to store the frequency of each character in the text.
  - We count the frequency of each character in the text and store it in the `freq` map.
  - We build the Huffman tree using the `buildHuffmanTree` function.
  - We traverse the Huffman tree to generate Huffman codes for each character using the `encode` function.
  - Finally, we print out the generated Huffman codes for each character.
*/