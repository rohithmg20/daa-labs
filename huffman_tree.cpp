#include <iostream>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;
};

// Create node
Node* createNode(char data, int freq) {
    Node* temp = new Node();
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Find two minimum nodes
void findMin(Node* nodes[], int n, int &min1, int &min2) {
    min1 = min2 = -1;

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            if (min1 == -1 || nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            }
            else if (min2 == -1 || nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }
    }
}

// Print Huffman Codes
void printCodes(Node* root, string code) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char data[100];
    int freq[100];
    Node* nodes[100];

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    // Create nodes
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(data[i], freq[i]);
    }

    int size = n;

    // Build Huffman Tree
    while (true) {
        int min1, min2;
        findMin(nodes, size, min1, min2);

        if (min2 == -1)
            break;

        Node* newNode = createNode('$',
            nodes[min1]->freq + nodes[min2]->freq);

        newNode->left = nodes[min1];
        newNode->right = nodes[min2];

        nodes[min1] = newNode;
        nodes[min2] = NULL;
    }

    // Find root
    Node* root = NULL;
    for (int i = 0; i < size; i++) {
        if (nodes[i] != NULL) {
            root = nodes[i];
        }
    }

    // Output
    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}
