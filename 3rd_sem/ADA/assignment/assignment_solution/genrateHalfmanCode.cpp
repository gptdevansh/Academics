#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for the Huffman Tree
struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency; // Min-Heap based on frequency
    }
};

// Function to generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code; // Store code for leaf nodes
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    char characters[n];
    int frequencies[n];

    cout << "Enter the characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> characters[i] >> frequencies[i];
    }

    // Priority queue (Min-Heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters into the min-heap
    for (int i = 0; i < n; i++) {
        pq.push(new Node(characters[i], frequencies[i]));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* combined = new Node('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;

        pq.push(combined);
    }

    // The root of the Huffman Tree
    Node* root = pq.top();

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Output Huffman Codes
    cout << "\nHuffman Codes:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
