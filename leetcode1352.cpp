#include<vector>
using namespace std;
class ProductOfNumbers {
    typedef struct a {
        int products;
        int zeros;
    } Node;
    vector<Node> temp;
    int size = 0;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        Node* node = new Node();
        if (size == 0){   
            node->products = num;
            node->zeros = 0;
        } else{
            if (temp[size - 1].products == 0){
                node->products = num;
                node->zeros = temp[size - 1].zeros + 1;
            } else {
                node->products = temp[size - 1].products * num;
                node->zeros = temp[size - 1].zeros;
            }
        }
        temp.push_back(*node);
        size++;
       // cout<<"w"<<endl;
    }
    
    int getProduct(int k) {
        Node last = temp[size - 1];
        if (size == 1)
            return temp[size - 1].products;
        if (size == k){
            if (temp[size - 1].zeros != 0)
                return 0;
            return temp[size - 1].products;
        }
        Node prev = temp[size - k - 1];
        //cout<<1<<endl;
        if (last.zeros - prev.zeros > 1)
            return 0;
        if (last.zeros != prev.zeros && prev.products != 0)
            return 0;
        if (last.zeros != prev.zeros){
            //cout<<last.products<<endl;
            return last.products;
        }
       //cout<<last.products / prev.products<<endl;
        return last.products / prev.products;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */