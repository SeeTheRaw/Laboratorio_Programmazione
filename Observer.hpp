#ifndef OBSERVER_H
#define OBSERVER_H
#include "Subject.hpp"
#include "Oggetto.hpp"


class Observer{

public:

    virtual ~Observer() {}

    virtual void update(const std::string &nomeLista, std::list<Oggetto> &oggetti) = 0;
    virtual void attach() = 0;
    virtual void detach() = 0;

};

#endif // OBSERVER_H