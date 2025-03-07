#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  PComparator comp;
  int m;
  std::vector<T> heap;

  // helper function for pop()
  void heapify(int idx);

};

// Add implementation of member functions here

// Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  this->m = m;
  this->comp = c;
}

// Destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
  
}

// Push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  // push the item to the end of the heap
  heap.push_back(item);
  int loc = heap.size()-1;
  int parent = (loc-1)/m;
  // bubble up until the heap is sorted
  while (loc > 0 && comp(heap[loc], heap[parent])){
    std::swap(heap[parent], heap[loc]);
    loc = parent;
    parent = (loc-1)/m;
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap[0];
}

// heapify helper function for the pop function
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx){
  // if the index is greater than the size of the heap or a leaf node then return
  if (idx >= int(heap.size()-1)){
    return;
  }
  // find the best child to swap with for the m ary heap
  int bestChild = idx;
  for (int i = 1; i <= m; i++){
    int child = m*idx+i;
    if (child < int(heap.size()) && comp(heap[child], heap[bestChild])){
      bestChild = child;
    }
  }
  // if the best child is better than the current index, swap them and call heapify on the best child
  if (comp(heap[bestChild], heap[idx])){
    std::swap(heap[bestChild], heap[idx]);
    heapify(bestChild);
  }
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // add the last element to the top of the heap and remove the last element
  heap[0] = heap[heap.size()-1];
  heap.pop_back();
  // call heapify to reorder the heap
  heapify(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  // return if the heap is empty
  return heap.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  // return the size of the heap
  return heap.size();
}

#endif

