/*
 * Copyright 2009 Patrick Hogan
 * Cleaned up by Joshua Rubin <jrubin@zvelo.com> 20050410
 *
 * A lightweight signals and slots implementation using fast delegates
 * https://github.com/pbhogan/Signals
 *
 * Signals.h is released under the MIT License: http://www.opensource.org/licenses/mit-license.php
 * Delegates.h is released into the public domain by the author and may be used for any purpose.
 */

#ifndef SIGNAL_H_
#define SIGNAL_H_

#include <set>
#include "./Delegates.h"

namespace zvelo {
namespace signals {

template< class Param0 = void >
class Signal0 {
  public:
    typedef Delegate0< void > _Delegate;

    Signal0()
    : delegateList() {}

  private:
    typedef std::set<_Delegate> DelegateList;
    typedef typename DelegateList::const_iterator DelegateIterator;
    DelegateList delegateList;

  public:
    void Connect(_Delegate delegate) {
      delegateList.insert(delegate);
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)()) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)() const) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    void Disconnect(_Delegate delegate) {
      delegateList.erase(delegate);
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)()) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)() const) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    void Clear() {
      delegateList.clear();
    }

    void Emit() const {
      DelegateList dl = delegateList;
      for (DelegateIterator i = dl.begin(); i != dl.end(); ++i)
      {
        (*i)();
      }
    }

    void operator() () const {
      Emit();
    }

    bool Empty() const {
      return delegateList.empty();
    }
};

template< class Param1 >
class Signal1 {
  public:
    typedef Delegate1< Param1 > _Delegate;

    Signal1()
    : delegateList() {}

  private:
    typedef std::set<_Delegate> DelegateList;
    typedef typename DelegateList::const_iterator DelegateIterator;
    DelegateList delegateList;

  public:
    void Connect(_Delegate delegate) {
      delegateList.insert(delegate);
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1)) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1) const) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    void Disconnect(_Delegate delegate) {
      delegateList.erase(delegate);
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1)) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1) const) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    void Clear() {
      delegateList.clear();
    }

    void Emit(Param1 p1) const {
      DelegateList dl = delegateList;
      for (DelegateIterator i = dl.begin(); i != dl.end(); ++i)
      {
        (*i)(p1);
      }
    }

    void operator() (Param1 p1) const {
      Emit(p1);
    }

    bool Empty() const {
      return delegateList.empty();
    }
};

template< class Param1, class Param2 >
class Signal2 {
  public:
    typedef Delegate2< Param1, Param2 > _Delegate;

    Signal2()
    : delegateList() {}

  private:
    typedef std::set<_Delegate> DelegateList;
    typedef typename DelegateList::const_iterator DelegateIterator;
    DelegateList delegateList;

  public:
    void Connect(_Delegate delegate) {
      delegateList.insert(delegate);
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2)) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2) const) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    void Disconnect(_Delegate delegate) {
      delegateList.erase(delegate);
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2)) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2) const) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    void Clear() {
      delegateList.clear();
    }

    void Emit(Param1 p1, Param2 p2) const {
      DelegateList dl = delegateList;
      for (DelegateIterator i = dl.begin(); i != dl.end(); ++i)
      {
        (*i)(p1, p2);
      }
    }

    void operator() (Param1 p1, Param2 p2) const {
      Emit(p1, p2);
    }

    bool Empty() const {
      return delegateList.empty();
    }
};

template< class Param1, class Param2, class Param3 >
class Signal3 {
  public:
    typedef Delegate3< Param1, Param2, Param3 > _Delegate;

    Signal3()
    : delegateList() {}

  private:
    typedef std::set<_Delegate> DelegateList;
    typedef typename DelegateList::const_iterator DelegateIterator;
    DelegateList delegateList;

  public:
    void Connect(_Delegate delegate) {
      delegateList.insert(delegate);
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3)) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3) const) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    void Disconnect(_Delegate delegate) {
      delegateList.erase(delegate);
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3)) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3) const) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    void Clear() {
      delegateList.clear();
    }

    void Emit(Param1 p1, Param2 p2, Param3 p3) const {
      DelegateList dl = delegateList;
      for (DelegateIterator i = dl.begin(); i != dl.end(); ++i)
      {
        (*i)(p1, p2, p3);
      }
    }

    void operator() (Param1 p1, Param2 p2, Param3 p3) const {
      Emit(p1, p2, p3);
    }

    bool Empty() const {
      return delegateList.empty();
    }
};

template< class Param1, class Param2, class Param3, class Param4 >
class Signal4 {
  public:
    typedef Delegate4< Param1, Param2, Param3, Param4 > _Delegate;

    Signal4()
    : delegateList() {}

  private:
    typedef std::set<_Delegate> DelegateList;
    typedef typename DelegateList::const_iterator DelegateIterator;
    DelegateList delegateList;

  public:
    void Connect(_Delegate delegate) {
      delegateList.insert(delegate);
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4)) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4) const) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    void Disconnect(_Delegate delegate) {
      delegateList.erase(delegate);
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4)) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4) const) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    void Clear() {
      delegateList.clear();
    }

    void Emit(Param1 p1, Param2 p2, Param3 p3, Param4 p4) const {
      DelegateList dl = delegateList;
      for (DelegateIterator i = dl.begin(); i != dl.end(); ++i)
      {
        (*i)(p1, p2, p3, p4);
      }
    }

    void operator() (Param1 p1, Param2 p2, Param3 p3, Param4 p4) const {
      Emit(p1, p2, p3, p4);
    }

    bool Empty() const {
      return delegateList.empty();
    }
};

template< class Param1, class Param2, class Param3, class Param4, class Param5 >
class Signal5 {
  public:
    Signal5()
    : delegateList() {}
    typedef Delegate5< Param1, Param2, Param3, Param4, Param5 > _Delegate;

  private:
    typedef std::set<_Delegate> DelegateList;
    typedef typename DelegateList::const_iterator DelegateIterator;
    DelegateList delegateList;

  public:
    void Connect(_Delegate delegate) {
      delegateList.insert(delegate);
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5) const) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    void Disconnect(_Delegate delegate) {
      delegateList.erase(delegate);
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5) const) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    void Clear() {
      delegateList.clear();
    }

    void Emit(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5) const {
      DelegateList dl = delegateList;
      for (DelegateIterator i = dl.begin(); i != dl.end(); ++i)
      {
        (*i)(p1, p2, p3, p4, p5);
      }
    }

    void operator() (Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5) const {
      Emit(p1, p2, p3, p4, p5);
    }

    bool Empty() const {
      return delegateList.empty();
    }
};

template< class Param1, class Param2, class Param3, class Param4, class Param5, class Param6 >
class Signal6 {
  public:
    typedef Delegate6< Param1, Param2, Param3, Param4, Param5, Param6 > _Delegate;

    Signal6()
    : delegateList() {}

  private:
    typedef std::set<_Delegate> DelegateList;
    typedef typename DelegateList::const_iterator DelegateIterator;
    DelegateList delegateList;

  public:
    void Connect(_Delegate delegate) {
      delegateList.insert(delegate);
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6) const) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    void Disconnect(_Delegate delegate) {
      delegateList.erase(delegate);
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6) const) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    void Clear() {
      delegateList.clear();
    }

    void Emit(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6) const {
      DelegateList dl = delegateList;
      for (DelegateIterator i = dl.begin(); i != dl.end(); ++i)
      {
        (*i)(p1, p2, p3, p4, p5, p6);
      }
    }

    void operator() (Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6) const {
      Emit(p1, p2, p3, p4, p5, p6);
    }

    bool Empty() const {
      return delegateList.empty();
    }
};

template< class Param1, class Param2, class Param3, class Param4, class Param5, class Param6, class Param7 >
class Signal7 {
  public:
    typedef Delegate7< Param1, Param2, Param3, Param4, Param5, Param6, Param7 > _Delegate;

    Signal7()
    : delegateList() {}

  private:
    typedef std::set<_Delegate> DelegateList;
    typedef typename DelegateList::const_iterator DelegateIterator;
    DelegateList delegateList;

  public:
    void Connect(_Delegate delegate) {
      delegateList.insert(delegate);
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7)) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7) const) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    void Disconnect(_Delegate delegate) {
      delegateList.erase(delegate);
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7)) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7) const) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    void Clear() {
      delegateList.clear();
    }

    void Emit(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7) const {
      DelegateList dl = delegateList;
      for (DelegateIterator i = dl.begin(); i != dl.end(); ++i)
      {
        (*i)(p1, p2, p3, p4, p5, p6, p7);
      }
    }

    void operator() (Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7) const {
      Emit(p1, p2, p3, p4, p5, p6, p7);
    }

    bool Empty() const {
      return delegateList.empty();
    }
};

template< class Param1, class Param2, class Param3, class Param4, class Param5, class Param6, class Param7, class Param8 >
class Signal8 {
  public:
    typedef Delegate8< Param1, Param2, Param3, Param4, Param5, Param6, Param7, Param8 > _Delegate;

    Signal8()
    : delegateList() {}

  private:
    typedef std::set<_Delegate> DelegateList;
    typedef typename DelegateList::const_iterator DelegateIterator;
    DelegateList delegateList;

  public:
    void Connect(_Delegate delegate) {
      delegateList.insert(delegate);
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8)) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Connect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8) const) {
      delegateList.insert(MakeDelegate(obj, func));
    }

    void Disconnect(_Delegate delegate) {
      delegateList.erase(delegate);
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8)) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    template< class X, class Y >
    void Disconnect(Y * obj, void (X::*func)(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8) const) {
      delegateList.erase(MakeDelegate(obj, func));
    }

    void Clear() {
      delegateList.clear();
    }

    void Emit(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8) const {
      DelegateList dl = delegateList;
      for (DelegateIterator i = dl.begin(); i != dl.end(); ++i)
      {
        (*i)(p1, p2, p3, p4, p5, p6, p7, p8);
      }
    }

    void operator() (Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6, Param7 p7, Param8 p8) const {
      Emit(p1, p2, p3, p4, p5, p6, p7, p8);
    }

    bool Empty() const {
      return delegateList.empty();
    }
};

}  // namespace signals
}  // namespace zvelo

#endif  // SIGNAL_H_
