clinq
=====

a php implement of php linq.

##Examples
*	The use of this extension: 			
	下面给出例子:
```
 	dl('alinq.so');

 	$a = array(
            'a'=>'b',
            'c'=>'d',
            'cc'=>'dd'
        );

 	$obj = alinq::Instance($a);
```
## Alinq methods that will return object:

* `GroupBy()`
* `Concat()`
* `SelectMany()`
* `Select()`
* `Where()`
* `Skip()`

## Requirements

* PHP 5.3 or higher -- because of it  depends on the new feature closures in PHP 5.3


