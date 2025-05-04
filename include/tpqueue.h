// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>
template<typename T>
class TPQueue {
    private:
        struct Node {
            T data;
            Node* next;
        };
    
        Node* head_;
    
    public:
        TPQueue() : head_(nullptr) {}
        ~TPQueue() {
            while (head_ != nullptr) {
                Node* temp = head_;
                head_ = head_->next;
                delete temp;
            }
        }
        void enqueue(const T& item) {
            Node* new_node = new Node{item, nullptr};
            Node* prev = nullptr;
            Node* current = head_;
            while (current != nullptr && current->data.prior >= item.prior) {
                prev = current;
                current = current->next;
            }
            new_node->next = current;
            if (prev == nullptr) {
                head_ = new_node;
            } else {
                prev->next = new_node;
            }
        }
        T dequeue() {
            if (head_ == nullptr) {
                throw std::runtime_error("Dequeue on empty queue");
            }
    
            Node* to_remove = head_;
            T result = to_remove->data;
            head_ = head_->next;
    
            delete to_remove;
            return result;
        }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
