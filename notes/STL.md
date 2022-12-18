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
Double ended queue. 
- #### `queue`
A FIFO queue. 