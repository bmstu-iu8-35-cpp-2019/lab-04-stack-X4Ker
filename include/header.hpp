// Copyright 2020 Paul Nolan pasha230899@gmail.com

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <any>

template <typename T>
class Element {
 public:
  T value;
  std::any nextEl;

 public:
  Element() = default;
  Element(const T& val, Element<T> next) {
    this->value = val;
    this->nextEl = next;
  }

  void reset(Element<T> El) {
    this->value = El.value;
    this->nextEl = El.nextEl;
  }

  const T& getValue() const { return this->value; }

  auto getNext() { return std::any_cast<Element<T>>(this->nextEl); }

  ~Element() = default;
};

template <typename T>
class Stack {
 private:
  size_t size;
  Element<T> head_value;

 public:
  Stack();
  ~Stack() = default;
  void push(T&& value) noexcept;
  void push(const T& value);
  void pop();
  const T& head() const;
};

template <typename T>
Stack<T>::Stack() {
  this->size = 0;
}

template <typename T>
void Stack<T>::push(T&& value) noexcept {
  Element<T> element(value, head_value);
  size++;
  this->head_value.reset(element);
}

template <typename T>
void Stack<T>::push(const T& value) {
  Element<T> element(value, head_value);
  size++;
  this->head_value.reset(element);
}

template <typename T>
void Stack<T>::pop() {
  this->head_value.reset(head_value.getNext());
}

template <typename T>
const T& Stack<T>::head() const {
  return this->head_value.getValue();
}

#endif  // INCLUDE_HEADER_HPP_
