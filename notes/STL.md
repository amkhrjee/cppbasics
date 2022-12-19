# Standard Template Library Notes
## Templates
When functions are defined with templates, they are synthesised _inline_ making them blazingly fast.

When there is both template and non-template versions of a function, the non-template version is always preferred by the compiler. 

## Composition
The STL comprises of four parts - containers, iterators, algorithms and functtions. 

### Containers
There are two types of containers - sequence containers and associative containers.

Sequence containers comprises of `vector`, `deque` and `list`.

Associative containers comprises of `set`, `multiset`, `map`, `multimap`, `hash_set`, `hash_map`, `hash_multiset` and `hash_multimap`. 

There is another fundamental associative container called `pair`.

- #### `pair`
This comprised of a 2-tuple of "first" and "second" value. The array of objects in a `map` or a `hash_map` are of type `pair`, where all the 'first' elements are the unique keys and the 'second; values are the object values.

> ### Sequence Containers

- #### `vector`
This is a dynamic array, like a C array which enables _random-access_.

>Inserting at the back of vector = _O(1)_ [amortized]
>
>Deleting at the back of vector = _O(1)_
>
>Insert/delete at beginning/middle = _O(n)_

- #### `list`
A doubly linked list.
- #### `slist`
A singly linked list.
- #### `deque`
Double ended queue. This supports insertion/deletion from all combinations of back and front. Thus, it can be used to implement both `LIFO` and `FIFO` data structures(_i.e._, stack and queue).
- #### `queue`
A FIFO queue. 
- #### `priority_queue`
Basically a heap.
- #### `Stack`
A LIFO stack.

> ### Associative  Containers

- #### `set`
A mathematical set; inserting/erasing elements in a set does not invalidate iterators pointing in the set. Provides set operations union, intersection, difference, symmetric difference and test of inclusion. Type of data must implement comparison operator `<` or custom comparator function must be specified; such comparison operator or comparator function must guarantee strict weak ordering, otherwise behavior is undefined. Typically implemented using a self-balancing binary search tree.

- #### `multiset`
A set that allows duplicate elements.

- #### `map`
Type of key must implement comparison operator < or custom comparator function must be specified; such comparison operator or comparator function must guarantee strict weak ordering, otherwise behavior is undefined. Typically implemented using a self-balancing binary search tree.

- #### `multimap`
A map that allows duplicate elements.

- #### `hash_*`
similar to a set, multiset, map, or multimap, respectively, but implemented using a hash table; keys are not ordered, but a hash function must exist for the key type. These types were left out of the C++ standard; similar containers were standardized in C++11, but with different names (`unordered_set` and `unordered_map`).

> ### Other types

- #### `bitset`
stores series of bits similar to a fixed-sized vector of bools. Implements bitwise operations and lacks iterators. Not a sequence. Provides random access.

- #### `valarray`
intended for numerical use

## Some things to be aware of
STL containers are **not** intended to be used as base classes (their destructors are deliberately non-virtual); deriving from a container is a common mistake.
