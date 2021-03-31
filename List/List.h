#include <iostream>
using namespace std;

class List {
    private:
        int *items, itemCount, size;
    
    public:
        List();
        ~List();
        int getItem(int index);
        int removeAt(int index);
        int removeItem(int itm);
        void addItem(int itm);
        void insertItem(int index, int itm);
        void concat(List& list);
        void print();
        int getSize();
        int getItemCount();
};

int List::getItem(int index) {
    if ((0 <= index) && (index < itemCount))
        return items[index];
    else
        return -99999;
}

int List::removeAt(int index) {
    int removeAt = items[index];
    
    if ((0 <= index) && (index < itemCount)) {
        for (int i=index; i<itemCount; i++)
            items[i] = items[i+1];
        itemCount--;
        
        return removeAt;
    } else {
        return -99999;
    }
}

int List::removeItem(int itm) {
    int removeItem;
    
    for (int i=0; i<itemCount; i++) {
        if (items[i] == itm) {
            removeItem = i;
            
            for (int j=i; j<itemCount; j++)
                items[j] = items[j+1];
            itemCount--;
            
            return removeItem;
        }
    }
    return -99999;
}

void List::addItem(int itm) {
    if (itemCount < size) {
        items[itemCount] = itm;
        itemCount++;
    } else {
        int *newItem = new int[size + 1];
        
        for (int i=0; i<size; i++)
            newItem[i] = items[i];
        
        newItem[size] = itm;
        itemCount++;
        
        delete [] items;
        items = newItem;
        size += 1;
    }
}

void List::insertItem(int index, int itm) {
    if (itemCount == size) {
        int *newItem = new int[size + 1];
        
        for (int i=0; i<size; i++)
            newItem[i] = items[i];
        
        delete [] items;
        items = newItem;
        size += 1;
    }
    
    if ((0 <= index) && (index < itemCount)) {
        for (int i=itemCount; i>index-1; i--)
            items[i+1] = items[i];
        
        items[index] = itm;
        itemCount++;
    }
}

void List::concat(List &list) {
    for (int i=0; i<list.itemCount; i++)
        addItem(list.items[i]);
}

void List::print() {
    cout << "[";
    
    for (int i=0; i<itemCount; i++) {
        cout << items[i];
        
        if (i != itemCount - 1)
            cout << " ";
    }
    
    cout << "]" << endl;
}

int List::getSize() {
    return size;
}

int List::getItemCount() {
    return itemCount;
}
