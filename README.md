clinq
=====

a php implement of php linq.
##The Purpose of Branche
This branche of the libaray trying to implemente the same feature without using SPL RecursiveArrayIterator;<br/>
这个分支试图在不依赖SPL RecursiveArrayIterator 这个标准库的情况下,实现与原Plinq同样的功能

##Differences
*	This branche add a new method Instance to Instance the Alinq class without using "new" keyword.
	Sometimes it's usefull,like the libaray live on a framework.<br/>
	Here giving a example: 
	这个分支添加了一个新的方法：Instance,以传入的数组来实例化Alinq类，而不必使用new 关键字.<br/>
	这在某些情况下还是有点用的,比如在框架代码中调用这个类的时候。<br/>
	下面给出例子:
```
include('Alinq.php');

$alinq = new Alinq($array);
$otherAlinq = $alinq->Instance($newArray);
```
*	Another difference is that  some result of the this library are objects which could not used as array . 
	The result object should call it's ToArray method to get array result.<br/>
	另外一个不同之处在与类库返回的结果,这个分支返回的对象结果不能直接作为数组使用,对象结果可以通过调用自身的ToArray方法来的到数组结果。
	example:
```php
include('Alinq.php');

$alinq = new Alinq($array);
$result = $alinq->Select(function($k, $v){ return $v['int']; })->ToArray();
```
## Alinq methods that will return object:

* `GroupBy()`
* `Concat()`
* `SelectMany()`
* `Select()`
* `Where()`
* `Skip()`
* `Take()`
* `OrderBy()`
* `OrderByDescending()`
* `Distinct()`
* `Intersect()`
* `Diff()`

## Requirements

* PHP 5.3 or higher -- because of it  depends on the new feature closures in PHP 5.3



## Examples

```php
include('Alinq.php');

```
