#include <iostream>
using namespace std;

class OrderedList {
    private:
        int *items, itemCount, size;
    
    public:
        OrderedList();
        ~OrderedList();
        int getItem(int index);
        int removeAt(int index);
        int removeItem(int itm);
        void addItem(int itm);
        void concat(OrderedList& olist);
        void print();
        void sort();
        int getSize();
        int getItemCount();
};

int OrderedList::getItem(int index) {
    if ((0 <= index) && (index < itemCount))
        return items[index];
    else
        return -99999;
}

int OrderedList::removeAt(int index) {
    int removeAt = items[index];
    
    if ((0 <= index) && (index < itemCount)) {
        for (int i=index; i<itemCount; i++)
            items[i] = items[i+1];
        itemCount--;
        //sort();
        
        return removeAt;
    } else {
        return -99999;
    }
}

int OrderedList::removeItem(int itm) {
    int removeItem;
    
    for (int i=0; i<itemCount; i++) {
        if (items[i] == itm) {
            removeItem = i;
            
            for (int j=i; j<itemCount; j++)
                items[j] = items[j+1];
            itemCount--;
            //sort();
            
            return removeItem;
        }
    }
    return -99999;
}

void OrderedList::addItem(int itm) {
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
    
    sort();
}

void OrderedList::concat(OrderedList &olist) {
    for (int i=0; i<olist.itemCount; i++)
        addItem(olist.items[i]);
    sort();
}

void OrderedList::print() {
    cout << "[";
    
    for (int i=0; i<itemCount; i++) {
        cout << items[i];
        
        if (i != itemCount - 1)
            cout << " ";
    }
    
    cout << "]" << endl;
}

void OrderedList::sort() {
    for (int pos=0; pos<itemCount; pos++) {
        for (int j=pos+1; j<itemCount; j++) {
            if (items[pos] > items[j]) {
                swap(items[pos], items[j]);
            }
        }
    }
}

int OrderedList::getSize() {
    return size;
}

int OrderedList::getItemCount() {
    return itemCount;
}
