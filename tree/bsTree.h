#ifndef _BS_TREE_H
#define _BS_TREE_H
#include <exception>
#include <stdexcept>
#include <queue>
using namespace std;
template<typename K, typename V>
class BSTree{
private:
    class Node{
    public:
        Node(K key, V value){
            this->key = key;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
        ~Node(){
            left = nullptr;
            right = nullptr;
        };

        K key;
        V value;
        Node *left;
        Node *right;
    };
    
public:
    BSTree(){
        root = nullptr;
        count = 0;
    };
    ~BSTree(){
        if(nullptr != root){
            cout << "destory" << endl;
            destory(root);            
        }
    };

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(K key, V value);
    void insert_1(K key, V value);
    bool contain(K key);
    V get(K key);

    void travelFront(); //前序遍历
    void travelFront(Node* node);

    void travelMiddle(); //中序遍历
    void travelMiddle(Node* node);

    void travelEnd(); //后序遍历
    void travelEnd(Node* node);

    void travelLevel(); //广度优先遍历

    K getMin();
    K getMin(Node *node);
    K getMax();
    K getMax(Node *node);

    void removeMin();
    Node* removeMin(Node *node){
        if(node->left == nullptr){
            Node *nodeRight = node->right;
            delete node;
            count--;
            return nodeRight;
        }

        node->left = removeMin(node->left);
        return node;
    }

    void removeMax();
    Node* removeMax(Node *node){
        if(node->right == nullptr){
            Node *nodeLeft = node->left;
            delete node;
            count--;
            return nodeLeft;
        }

        node->right = removeMax(node->right);
        return node;
    }


private:
    V get(Node *node, K key);
    bool contain(Node *node, K key);
    void destory(Node *node);

    Node* insert(Node *node, K key, V value){
        if(node == nullptr){
            count++;
            return new Node(key, value);
        }
        if(key == node->key){
            node->value = value;
        }else if (key < node->key){
            node->left = insert(node->left, key, value);
        }else{
            node->right = insert(node->right, key, value);
        }

        return node;
    }

private:
    int count;
    Node *root;
};

template<typename K, typename V>
void BSTree<K,V>::destory(Node *node){
    if(node->left != nullptr){
        destory(node->left);
    }
    if(node->right != nullptr){
        destory(node->right);
    }

    delete node;
    count--;
    // cout << "count:" << count << endl;
}

template<typename K, typename V>
void BSTree<K,V>::insert(K key, V value){
    root = insert(root, key, value);
}

template<typename K, typename V>
void BSTree<K,V>::insert_1(K key, V value){
    if(root == nullptr){
        root = new Node(key, value);
    }

    Node* node = root;
    while(node != nullptr){
        if(key == node.key){
            node.key = key;
            break;
        }else if (key < node.key){
            if(node.left != nullptr)
            {
                node = node.left;                    
            }else{
                node.left = new Node(key, value);
                break;
            }
        }else{
            if(node.right != nullptr){
                node = node.right;
            }else{
                node.left = new Node(key, value);
                break;
            }
        }
    }
}

template<typename K, typename V>
bool BSTree<K,V>::contain(K key){
    return contain(root, key);
}

template<typename K, typename V>
bool BSTree<K,V>::contain(Node *node, K key){
    if(node == nullptr){
        return false;
    }
    if(key == node->key){
        return true;
    }else if (key < node->key){
        return contain(node->left, key);
    }else{
        return contain(node->right, key);
    }
}

template<typename K, typename V>
V BSTree<K,V>::get(K key){
    if(root == nullptr){
        throw std::runtime_error("key not exist");
    }else{
        try{
            return get(root, key);
        }catch(...){
            throw;
        }
    }
}

template<typename K, typename V>
V BSTree<K,V>::get(Node *node, K key){
    if(node == nullptr){
        throw std::runtime_error("key not exist");
    }
    if(key == node->key){
        return node->value;
    }else if (key < node->key){
        return get(node->left, key);
    }else{
        return get(node->right, key);
    }
}

template<typename K, typename V>
void BSTree<K,V>::travelFront(){
    travelFront(root);
}

template<typename K, typename V>
void BSTree<K,V>::travelFront(Node* node){
    if(node == nullptr){
        return;
    }
    cout << "key: " << node->key << "  value: " << node->value << endl;
    if(node->left != nullptr){
        travelFront(node->left);
    }
    
    if(node->right != nullptr){
        travelFront(node->right);
    }
}

template<typename K, typename V>
void BSTree<K,V>::travelMiddle(){
    travelMiddle(root);
}

template<typename K, typename V>
void BSTree<K,V>::travelMiddle(Node* node){
    if(node == nullptr){
        return;
    }
    if(node->left != nullptr){
        travelMiddle(node->left);
    }

    cout << "key: " << node->key << "  value: " << node->value << endl;
    
    if(node->right != nullptr){
        travelMiddle(node->right);
    }
}

template<typename K, typename V>
void BSTree<K,V>::travelEnd(){
    travelEnd(root);
}

template<typename K, typename V>
void BSTree<K,V>::travelEnd(Node* node){
    if(node == nullptr){
        return;
    }
    if(node->left != nullptr){
        travelEnd(node->left);
    }
    
    if(node->right != nullptr){
        travelEnd(node->right);
    }

    cout << "key: " << node->key << "  value: " << node->value << endl;
}

template<typename K, typename V>
void BSTree<K,V>::travelLevel(){
    queue<Node*> q;
    if(root != nullptr){
        q.push(root);
    }

    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        cout << "key:  " << node->key << "  value:  " << node->value << endl;
        if(node->left != nullptr){
            q.push(node->left);
        }
        if(node->right != nullptr){
            q.push(node->right);
        }
    }

    cout << "travelLevel over" << endl;
}

template<typename K, typename V>
K BSTree<K,V>::getMin(){
    if(root!= nullptr){
        return getMin(root);
    }
    return 0;
}

template<typename K, typename V>
K BSTree<K,V>::getMin(Node *node){
    if(node->left != nullptr){
        return getMin(node->left);
    }else{
        return node->key;
    }
}

template<typename K, typename V>
K BSTree<K,V>::getMax(){
    if(root!= nullptr){
        return getMax(root);
    }
    return 0;
}

template<typename K, typename V>
K BSTree<K,V>::getMax(Node *node){
    if(node->right != nullptr){
        return getMax(node->right);
    }else{
        return node->key;
    }
}

template<typename K, typename V>
void BSTree<K,V>::removeMin(){
    if(root != nullptr){
        root = removeMin(root);
    }
}

template<typename K, typename V>
void BSTree<K,V>::removeMax(){
    if(root != nullptr){
        root = removeMax(root);
    }
}

#endif