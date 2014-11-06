clinq
=====

a php extension implement of linq using C language.

##Examples
*	The use of this extension: 			
	下面给出例子:
```
 	dl('alinq.so');

 	$timestamp = time();
    $item = array(
            'key_0' => array(
                'int' => 0,
                'date' => new \DateTime(date('Y-m-d H:i:s', $timestamp+(0))),
                'string' => 'val_0',
                'bool' => true
            ),
            'key_1' => array(
                'int' => 1,
                'date' => new \DateTime(date('Y-m-d H:i:s', $timestamp+(432000))),
                'string' => 'val_1',
                'bool' => true
            ),
            'key_2' => array(
                'int' => 2,
                'date' => new \DateTime(date('Y-m-d H:i:s', strtotime('2014-06-11')+(0))),
                'string' => 'val_2',
                'bool' => true
            ),
        );
    $alinq = Alinq::Instance($item);
    //get the third element
    $result = $alinq->ElementAt(3);

    //group by sub key 'date'
    $result = $alinq->GroupBy(function ($k, $v) {
                    return (date('Y-m',$v['date']->getTimeStamp()));
                })->ToArray();

    //At least have a value that bigger than 10 ,it will return true.Otherwise it will return false.
    $boolValue = $alinq->Any(function($k, $v){ return $v['int']>10; })

```
## Alinq methods that will return object:

* `Instance()`
* `getArrayItem()`
* `Single()`
* `SelectMany()`
* `Select()`
* `All()`
* `Any()`
* `Skip()`
* `Average()`
* `Concat()`
* `GroupBy()`
* `ElementAt()`


## Requirements

* PHP 5.3 or higher -- because of it  depends on the new feature closures in PHP 5.3

##Running tests
install phpunit
```bash
wget https://phar.phpunit.de/phpunit.phar
chmod +x phpunit.phar
sudo mv phpunit.phar /usr/local/bin/phpunit
```
run phpunit
```bash
phpunit --verbose test/AlinqTest.php
```

