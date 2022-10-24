This table shows which access specifier will result in the derived class for
which combination of base class access specifier and member access specifier
in the base class.

|----------------------------------------------------------------|
|                  |            Member Access Level              |
|Base Class        |---------------------------------------------|
|Access Specifier  |   Private          Protected       Public   |
|----------------------------------------------------------------|
|                  |                                             |   
|Public            |   Inaccessible     Protected       Public   |
|                  |                                             |
|Protected         |   Inaccessible     Protected       Protected|
|                  |                                             |
|Private           |   Inaccessible     Private         Private  |   
|----------------------------------------------------------------|

The base class access specifier will affect how members are inherited by the
derived class.  For example, when using the proteted acces specifier when
inheriting the base class, the public members of the base class will become
protected members of the derived class.  Generally, we use the public
specifier. Notably, if no access specifier is provided the default is
private.