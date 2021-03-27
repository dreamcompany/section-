#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#include "section_node.h"
#include <bitset>

using namespace::std;
using namespace::J;
using namespace::J::basic;

struct Testmachine {
    string head;
    int num;
} testmachine;

template<typename... Types>
void _t(bool, const Types&... args);


int main() {
    cout << "Start test section vessel" << endl;
    cout << "-------------------------" << endl;

    testmachine.head = "J.1.";
    testmachine.num = 0;

    _Section_node_base section_node_base;
    _t(nullptr == section_node_base._parent, "Define object _Section_node_base, with default constructor, get its parent: ", section_node_base._parent, "expected nullptr.");

    _t(true, "Call function of _Section_node_base declared in section_node.h but defined in range_node.cc, with its output: ", section_node_base.print());
    
    _Section_leaf_node_base section_leaf_node_base;
    _t(section_leaf_node_base._parent == nullptr, "Define object _Section_leaf_node_base, with default constructor, get its parent: ", section_leaf_node_base._parent, ", expected nullptr");

    _t(section_leaf_node_base._next == nullptr && section_leaf_node_base._prev == nullptr, "Checkout whether section_leaf_node_base._next is nullptr: ", section_leaf_node_base._next, " ,expected nullptr;", " Checkout whether section_leaf_node_base._prev is nullptr: ", section_leaf_node_base._prev, " ,expected nullptr;");

    section_node_base._parent = &section_leaf_node_base;
    _t(section_node_base._parent == &section_leaf_node_base, "Let section_node_base._parent -> section_leaf_node_base, see their memory address. section_node_base._parent: ", section_node_base._parent, ", &section_leaf_node_base: ", &section_leaf_node_base);

    _Section_node_base* section_node_base_ptr(&section_leaf_node_base);
    _t(section_node_base_ptr == &section_leaf_node_base, "Define _Section_node_base_ptr, point to section_leaf_node_base.");

    static_cast<_Section_leaf_node_base*>(section_node_base_ptr)->_next = &section_leaf_node_base;
    _t(section_node_base_ptr == section_leaf_node_base._next, "static_cast the father node to child, modify ._next variable which father not have.");

    _Section_tree_node_base section_tree_node_base;
    _Section_tree_node_base section_tree_node_base2(section_node_base_ptr, &section_tree_node_base, &section_tree_node_base);
    _t(section_tree_node_base2._parent == section_node_base_ptr && section_tree_node_base2._left == &section_tree_node_base && section_tree_node_base2._right == &section_tree_node_base, "New Section_tree_node_base, show its ._parent: ", section_tree_node_base2._parent, ", ._left: ", section_tree_node_base2._left,", ._right: ", section_tree_node_base2._right);
    
    {
        _Section_node_header section_node_header;
        auto& h = section_node_header;
        _t(h._parent == nullptr && h._next == &h && h._prev == &h, "New _Section_node_header, show its ._parent: ", h._parent, ", ._next: ", h._next, ", ._prev: ", h._prev);

        _t(h._node_count == 0 && h._size == 0, "Verify section_node_header's ._size: ", h._size, ", .node_count: ", h._node_count, ", both expected 0");

        _Section_node_header section_node_header2(std::move(section_node_header));
        auto& h2 = section_node_header2;
        _t(true, "New _Section_node_header section_node_header2 consturcted by section_node_header.");

        _t(h2._prev == &h2 && h2._next == &h2, "Checkout whether section_node_header2's ._prev: ", h2._prev, ", ._next: ", h2._next, ", this: ", &h2, ", expected equal.");

        // const _Section_node_header& section_node_header3 = _Section_node_header();
        // _Section_node_header section_node_header4(std::move(section_node_header3));
        _t(true, "New _Section_node_header section_node_header4 cannot consturcted by const section_node_header&.");

        _Section_node_header section_node_header5;
        auto& h5(section_node_header5);
        h5._next = h5._prev = &h;
        h._next = h._prev = &h5;
        _t(true, "New _Section_node_header section_node_header5 connected section_node_header forming a circle.");

        _Section_node_header section_node_header6(move(h5));
        _t(true, "New _Section_node_header section_node_header6 constructed by section_node_header5.");

        auto& h6(section_node_header6);
        _t(h6._next == &h && h6._prev == &h && h._next == &h6 && h._prev == &h6, "Check whether section_node_header and section_node_header6 forms a circle, section_node_header's this: ", &h, ", ._prev: ", h._prev, ", ._next: ", h._next, ", section_node_header6's this: ", &h6, ", ._prev: ", h6._prev, ", ._next: ", h6._next);

        _t(&h5 == h5._next && &h5 == h5._prev, "Check whether section_node_header5 is reconstructed by default. section_node_header5' this: ", &h5, ", ._prev: ", h5._prev, ", ._next: ", h5._next);
    }
    cout << "-----------------------" << endl;
    cout << "End test section vessel" << endl;
    return 0;
}

void print() {} // 递归终止条件。这是必需的。
 
template<typename Type, typename... Types>
void print(const Type& arg, const Types&... args)
{
  cout << arg;
  print(args...);
}

template<typename... Types>
void _t(bool judge, const Types&... args) {
    cout << testmachine.head << testmachine.num << "=" << judge << " ";
    print(args...);
    cout << endl;
    testmachine.num++;
}