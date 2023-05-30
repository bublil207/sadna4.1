#include "List.h"
#include <iostream>

//  class Link implementation
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}

List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}