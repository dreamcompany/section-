#ifndef SECTION_TREE_NODE_H_INCLUDE
#define SECTION_TREE_NODE_H_INCLUDE
#include "section_node.h"
namespace J{
    namespace tree_node{
        template<typename _Key, typename _Tp>
            class _Section_tree_node : public _Section_tree_node_base {
            public:
            //     typedef bool _Child_exist;
            //     typedef std::pair<const _Key, _Tp>		value_type;
            //     typedef _Tp mapped_type;
            //     //typedef bool _Is_leaf; 

            //     //家福在这想想初始化_Is_leaf为什么比较好
            //     _Section_leaf_node() noexcept :  _Is_leaf(false), _M_Field(value_type()), {}

            //     //_Child_exist _Left_child;  //removed in F.0.2 
            //     //_Child_exist _Right_child; //removed in F.0.2
            // private:
            //     bool _Is_leaf; //mark if its child is leaf
            //     value_type _M_field;
            //     mapped_type _M_marked;
                _Key _mid_key;
                _Key _right_key;
                bool _has_mid;
                bool _Is_leaf;
                _Tp _sum;

                _Section_tree_node<_Key, _Tp>() noexcept : _mid_key(_Key()), _right_key(_Key()), _has_mid(false), _Is_leaf(false), _sum(_Tp()) {}
            };

    }
}
#endif