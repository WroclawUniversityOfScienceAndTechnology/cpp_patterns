#pragma once

#include "pimpl.h"

class Foo
{
  class impl;
  pimpl<impl> p_impl;

  public:
    void greet();
    Foo();
};


