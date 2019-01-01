#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <vector>
#include <ostream>
#include <algorithm>

template<typename T>
class BinaryHeap{
      static const unsigned TOP = 0;
   public:
      BinaryHeap() : vec() {}

      int lastIndex() const {return vec.size() - 1;}
      int getSize() const {return vec.size();}
      void push(const T& data) {
         vec.push_back(data);
         siftUp(lastIndex());
      }
      void pop(){
         std::swap(vec[TOP], vec[lastIndex()]);
         vec.pop_back();
         siftDown(TOP);
      }
      T peek() const {return vec[TOP];}
      bool isEmpty() const {return vec.empty();}

      void vecify(const std::vector<T> elements){
         vec.assign(elements.begin(), elements.end());
         int current = getParent(vec.size());
         while (current >= 0){
            siftDown(current);
            --current;
         }
      }

      void vecsort(std::vector<T>& elements){
         vecify(elements);
         elements.clear();
         while (!vec.empty()){
            T first = peek(); pop();
            elements.push_back(first);
         }
      }
      typename std::vector<T>::iterator begin() {return vec.begin();}
      typename std::vector<T>::iterator end() {return vec.end();}
   private:
      std::vector<T> vec;

      void siftUp(int index);
      void siftDown(int index);
      static int getParent(int index) {return (index - 1) / 2;}
      static int leftChild(int index) {return 2 * index + 1;}
      static int rightChild(int index) {return 2 *(index + 1);}
};

template<typename T>
std::ostream& operator<<(std::ostream& out, BinaryHeap<T> binvec){
   if (binvec.isEmpty()){
      out << "[]\n";
      return out;
   }
   typename std::vector<T>::const_iterator iter = binvec.begin();
   out << "[";
   for (;iter != binvec.end() - 1; ++iter){
      out << *iter << ", ";
   }
   out << *(binvec.end() - 1) << "]\n";
   return out;
}

template<typename T>
void BinaryHeap<T>::siftUp(int index){
   int current = index;
   int parent = getParent(current);
   while (current >= TOP && vec[current] > vec[parent]){
      std::swap(vec[current], vec[parent]);
      current = parent;
      parent = getParent(current);
   }

}

template<typename T>
void BinaryHeap<T>::siftDown(int index){  //not 100 % sure about this but I think it's OK
   int current = index;
   int left = leftChild(current), right = rightChild(current);

   while ((left <= lastIndex() && vec[current] < vec[left]) ||
          (right <= lastIndex() && vec[current] < vec[right])){
      if (left <= lastIndex() && right <= lastIndex()){
         if (vec[left] < vec[right]){
            std::swap(vec[current], vec[right]);
            current = right;
            left = leftChild(current); right = rightChild(current);
         }
         else {
            std::swap(vec[current], vec[left]);
            current = left;
            left = leftChild(current); right = rightChild(current);
         }
      }
      else if (left <= lastIndex()){
         std::swap(vec[current], vec[left]);
         current = left;
         left = leftChild(current); right = rightChild(current);
      }
      else if (right <= lastIndex()){
         std::swap(vec[current], vec[right]);
         current = right;
         left = leftChild(current); right = rightChild(current);
      }
   }
}


#endif // HEAP_H_INCLUDED
