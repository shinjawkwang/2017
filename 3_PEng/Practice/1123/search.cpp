#include <iostream>
#include <list>

using namespace std;

class TreeNode{
private:
    int value;
    int no_children = 0;
    TreeNode *children[5] = {0,};
public:
    TreeNode(int v): value(v){}
    TreeNode(int v, int cv[], int size): value(v){
        if(size > 5)
            size = 5;
        for(int i=0; i<size; i++)
            children[i] = new TreeNode(cv[i]);
        no_children = size;
    }
    TreeNode(int v, TreeNode *c[], int size): value(v){
        if(size > 5)
            size = 5;
        for(int i=0; i<size; i++)
            children[i] = c[i];
        no_children = size;
    }
    void add_child(TreeNode *c);
    void add_children(TreeNode *c[], int size);
    void add_children(list<TreeNode*> *c);
    int get_value();
    void set_value(int v);
    TreeNode *get_child(int index);
    TreeNode **get_children();
    int get_no_children();
};

void make_children_from_string(string str,  list<TreeNode*> *children);
TreeNode *make_node_from_string(string str);

void TreeNode::add_child(TreeNode *c){
    if(no_children < 5){
        children[no_children] = c;
        no_children++;
    }
}

void TreeNode::add_children(TreeNode *c[], int size){
    if(no_children + size > 5){
        size = 5 - no_children;
    }
    for(int i=no_children; i<no_children+size; i++)
        children[i] = c[i];
    no_children = no_children + size;
}

void TreeNode::add_children(list<TreeNode*> *c){
    unsigned long size = c->size();
    if(no_children + size > 5){
        size = 5 - no_children;
    }
    for(int i=no_children; i<no_children+size; i++){
        children[i] = c->front();
        c->pop_front();
    }
    no_children += size;
}

int TreeNode::get_value(){
    return value;
}

void TreeNode::set_value(int v){
    value = v;
}

TreeNode *TreeNode::get_child(int index){
    return children[index];
}

TreeNode **TreeNode::get_children(){
    return children;
}

int TreeNode::get_no_children(){
    return no_children;
}

void make_children_from_string(string str, list<TreeNode*> *children){
    unsigned long len = str.length();
    int bgn=0;
    int count = 0;
    for(int i=0; i<len; i++){
        TreeNode *node = NULL;
        switch(str[i]){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                break;
            case '[':
                count++;
                break;
            case ']':
                count--;
                break;
            case ' ':
                if(count == 0){
                    node = make_node_from_string(str.substr(bgn, i-bgn));
                    bgn = i+1;
                    children->push_back(node);
                }
                break;
            default:
                break;
        }
    }
    children->push_back(make_node_from_string(str.substr(bgn, len-bgn)));
}

TreeNode *make_node_from_string(string str){
    unsigned long len = str.length();
    TreeNode *node = NULL;
    int val = 0;
    bool minus = false;
    for(int i=0; i<len; i++){
        switch(str[i]){
            case '-':
                minus = true;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                val *= 10;
                val += str[i]-'0';
                break;
            case '[':
                val *= (minus)? -1:1;
                node = new TreeNode(val);
                val = 0;
                minus = false;
            {
                int j;
                int count=0;
                for(j=1; i+j<len; j++){
                    if(str[i+j] == '[')
                        count++;
                    else if(str[i+j] == ']')
                        count--;

                    if(count<0)
                        break;
                }

                list<TreeNode*> children;
                make_children_from_string(
                                          str.substr(i+1, j-1),
                                          &children);
                node->add_children(&children);
                i+=j;
            }
            case ']':
                break;
            default:
                break;
        }
    }
    if(val != 0){
        val *= (minus)? -1:1;
        node = new TreeNode(val);
        val = 0;
        minus = false;
    }
    return node;
}

namespace DFS {
    void add_to_list(std::list<TreeNode*> *l, TreeNode* children[], int size){
        for(int i=size-1; i>=0; i--){
            l->push_front(children[i]);
        }
    }
    TreeNode *get_next(std::list<TreeNode*> *l){
        if(l->empty())
            return NULL;
        TreeNode *temp = l->front();
        l->pop_front();
        return temp;
    }
    TreeNode *search(TreeNode* root, int target, list<TreeNode*> *path){
        list<TreeNode*> l;
        /* Fill here. */
        /*Iteration Version*/
        TreeNode *push;
        path->push_back(root);
        int num = root->get_no_children();
        if(num){
          add_to_list(&l, root->get_children(), num);
        }
        while(true){
          push = get_next(&l);
          path->push_back(push);
          if(push->get_value() == target) break;
          num = push->get_no_children();
          if(num){
            add_to_list(&l, push->get_children(), num);
          }
        }
        return NULL;
        /*  Recursion Version
        path->push_back(root);
        if(root->get_value() == target){
          return root;
        }
        if(root->get_no_children())
          DFS::add_to_list(&l, root->get_children(), root->get_no_children());
        while(!l.empty()){
          if(!search(get_next(&l), target, path)){
            continue;
          }
          else{
            cout << "DFS Complete\n";
            return root;
          }
        }
        cout << "NULL!\n";
        return NULL;
        */
    }
}

namespace BFS {
    void add_to_list(std::list<TreeNode*> *l, TreeNode* children[], int size){
        for(int i=0; i<size; i++){
            l->push_back(children[i]);
        }
    }
    TreeNode *get_next(std::list<TreeNode*> *l){
        if(l->empty())
            return NULL;
        TreeNode *temp = l->front();
        l->pop_front();
        return temp;
    }
    TreeNode *search(TreeNode* root, int target, list<TreeNode*> *path){
        list<TreeNode*> l;
        /* Fill here. */
        TreeNode *enqueue;
        path->push_back(root);
        int num = root->get_no_children();
        if(num){
          add_to_list(&l, root->get_children(), num);
        }
        while(true){
          enqueue = get_next(&l);
          path->push_back(enqueue);
          if(enqueue->get_value() == target)  break;
          num = enqueue->get_no_children();
          if(num){
            add_to_list(&l, enqueue->get_children(), num);
          }
        }
        return NULL;
    }
}

void print_tree(TreeNode *root){
    cout << root->get_value();
    if(int N = root->get_no_children()){
        cout << "[";
        for(int i=0; i<N; i++){
            print_tree(root->get_child(i));
            if(i<N-1)
                cout << " ";
        }
        cout << "]";
    }
}

void print_path(list<TreeNode*> path){
    for(list<TreeNode*>::iterator it = path.begin();
        it != path.end();
        it++){
        cout << (*it)->get_value() << " ";
    }
    cout << endl;
}

int main(){
    int target;
    char c;
    string s;

    cin >> target;
    cin.get(c);
    getline(cin, s);

    TreeNode *root = make_node_from_string(s);

    list<TreeNode*> dfs_path;
    DFS::search(root, target, &dfs_path);
    //cout << "<----DFS Result---->\n";
    print_path(dfs_path);

    //cout << "DFS Successfully Ended.\n";
    list<TreeNode*> bfs_path;
    BFS::search(root, target, &bfs_path);
    //cout << "<----BFS Result---->\n";
    print_path(bfs_path);
}
