#pragma once

#include <string>
#include <vector>
#include <mutex>
#include <algorithm>

using namespace std;

template <typename> struct Observer;

template <typename T>
struct SaferObservable
{
  std::vector<Observer<T>*> observers;
  typedef std::recursive_mutex mutex_t;
  mutex_t mtx;
public:
  void notify(T& source, const std::string& field_name)
  {
    std::lock_guard<mutex_t> lock{mtx};
    for (auto observer : observers)
      if (observer)
        observer->field_changed(source, field_name);
  }

  void subscribe(Observer<T>& observer)
  {
    std::lock_guard<mutex_t> lock{mtx};
    observers.push_back(&observer);
  }

  void unsubscribe(Observer<T>& observer)
  {
    auto it = std::find(begin(observers), end(observers), &observer);
    if (it != end(observers))
      *it = nullptr;
  }
};


