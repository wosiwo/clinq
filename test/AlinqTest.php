<?php
// dl('alinq.so');

class AlinqTest extends PHPUnit_Framework_TestCase
{

    public function testGroupBy()
    {
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

        $result = $alinq->GroupBy(function ($k, $v) {
                        return (date('Y-m',$v['date']->getTimeStamp()));
                    })->ToArray();

        $this->assertTrue(
            array_key_exists("2014-06", $result)
        );
    }

    public function testElementAt()
    {
        $item = array(1,2,3,4,5,6);
        $alinq = Alinq::Instance($item);
        $this->assertEquals(
            4,
            $alinq->ElementAt(3)
        );
    }

    // public function testOrderBy()
    // {
    //     $item = array(1,2,3,4,5,6);
    //     $alinq = Alinq::Instance($item);
    //     $result = $alinq->OrderByDescending(function($k, $v){ return $v; })->ToArray(); 
    //     reset($result);
    //     $this->assertEquals(
    //         6,
    //         current($result)
    //     );
    // }
    public function testAny()
    {
        $item = array(1,2,3,4,5,6);
        $alinq = Alinq::Instance($item);
        $this->assertTrue(
            $alinq->Any(function($k, $v){ return $v>10; })
        );
    }
}
