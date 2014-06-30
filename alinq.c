//alinq.c
#include "php_alinq.h"
zend_class_entry *alinq_class_ce;


//zend class method[
//首先，定义这个函数的C语言部分，不过这一次我们使用的是ZEND_METHOD
ZEND_METHOD( alinq_class , getArrayItem )
{
    zval *data_array;
    zval *copy_array;
    char *name;
    int name_len;
    zval **fooval;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "as",&data_array,  &name, &name_len) == FAILURE) {
        RETURN_NULL();
    }

    if(zend_hash_find(HASH_OF(data_array),name,name_len,(void**)&fooval) == SUCCESS ){
        RETVAL_ZVAL(*fooval, 1, 0); 
    }else{
        RETVAL_STRING("index_not_found", 1);
    }
    return;
}
 
ZEND_METHOD( alinq_class , __construct )
{
    zval * data_array; 
    zend_class_entry *ce;

    ce = Z_OBJCE_P(getThis());
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a",&data_array) == FAILURE) {
        RETURN_NULL();
    }

    zend_update_property(alinq_class_ce, getThis(), "dataSource", sizeof("dataSource")-1, data_array TSRMLS_CC);

} 

//静态方法的返回值
ZEND_METHOD( alinq_class , Instance )
{
    //实例化类
    // zval *obj;
    // MAKE_STD_ZVAL(obj);
    // object_init_ex(obj, alinq_class_ce);
    // zval * obj; 
    zval * data_array; 
    zval * retval_ptr;
    // zval * function_name;
    // zval        *argv[3];
    // MAKE_STD_ZVAL(argv[0]);



    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a",&data_array) == FAILURE) {
        RETURN_NULL();
    }


    object_init_ex(return_value, alinq_class_ce);
    // zend_call_method_with_1_params(&return_value, NULL, NULL, "__construct",
    //         &retval, data_array);

    // MAKE_STD_ZVAL(function_name);
    // ZVAL_STRINGL(function_name,"__construct",sizeof("__construct")-1,1);
    // ZVAL_STRING(function_name,"__construct",0);
    // argv[0] = data_array;
    // call_user_function(NULL,&return_value,function_name,retval_ptr,1,&data_array TSRMLS_DC);
    walu_call_user_function(&retval_ptr, return_value, "__construct", "z", data_array);

    // call_php();
    // zval_ptr_dtor(&data_array);
    // zval_ptr_dtor(&function_name);
    return;
}

ZEND_METHOD( alinq_class , Single )
{
    zend_fcall_info fci;
    zend_fcall_info_cache fci_cache;
    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());
    zval * reVal;

 
    char aReturnType;
    int aReturnTypeLen; 

    // aReturnType = 'bool';

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "f", &fci, &fci_cache) == FAILURE) {
        return;
    }     
    // zval *arrayValues;
    zval *ALINQ_CLOSURE_RETURN_TYPE_BOOL;

    ALINQ_CLOSURE_RETURN_TYPE_BOOL = zend_read_static_property(ce, "ALINQ_CLOSURE_RETURN_TYPE_BOOL", sizeof("ALINQ_CLOSURE_RETURN_TYPE_BOOL")-1, 0 TSRMLS_DC);
    // walu_call_user_function(&arrayValues, getThis(), "GetApplicables", "fl", fci,1);
    reVal = GetApplicables(getThis(),fci,fci_cache,1,Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL),sizeof(Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL)));
    RETURN_ZVAL(reVal,1,1);
    // php_printf("fine");  
    // RETURN_ZVAL(arrayValues,1,1);
    // walu_call_anony_function(&arrayValues, NULL, fci, "sz", key, keylen,tmpcopy);

}
ZEND_METHOD( alinq_class , SelectMany )
{
    zend_fcall_info fci;
    zend_fcall_info_cache fci_cache;
    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());
    zval * reVal;

 
    char aReturnType;
    int aReturnTypeLen; 

    // aReturnType = 'bool';

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "f", &fci, &fci_cache) == FAILURE) {
        return;
    }     
    zval *ALINQ_CLOSURE_RETURN_TYPE_BOOL;

    ALINQ_CLOSURE_RETURN_TYPE_BOOL = zend_read_static_property(ce, "ALINQ_CLOSURE_RETURN_TYPE_BOOL", sizeof("ALINQ_CLOSURE_RETURN_TYPE_BOOL")-1, 0 TSRMLS_DC);
    reVal = GetApplicables(getThis(),fci,fci_cache,0,Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL),sizeof(Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL)));
    RETURN_ZVAL(reVal,1,1);

}

ZEND_METHOD( alinq_class , Select )
{
    zend_fcall_info fci;
    zend_fcall_info_cache fci_cache;
    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());
    zval * reVal;

 
    char aReturnType;
    int aReturnTypeLen; 

    // aReturnType = 'bool';

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "f", &fci, &fci_cache) == FAILURE) {
        return;
    }     
    zval *ALINQ_CLOSURE_RETURN_TYPE_OBJECT;

    ALINQ_CLOSURE_RETURN_TYPE_OBJECT = zend_read_static_property(ce, "ALINQ_CLOSURE_RETURN_TYPE_OBJECT", sizeof("ALINQ_CLOSURE_RETURN_TYPE_OBJECT")-1, 0 TSRMLS_DC);
    reVal = GetApplicables(getThis(),fci,fci_cache,0,Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_OBJECT),sizeof(Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_OBJECT)));
    RETURN_ZVAL(reVal,1,1);

}

ZEND_METHOD( alinq_class , Where )
{
    zend_fcall_info fci;
    zend_fcall_info_cache fci_cache;
    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());
    zval * reVal;

 
    char aReturnType;
    int aReturnTypeLen; 

    // aReturnType = 'bool';

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "f", &fci, &fci_cache) == FAILURE) {
        return;
    }     
    zval *ALINQ_CLOSURE_RETURN_TYPE_BOOL;

    ALINQ_CLOSURE_RETURN_TYPE_BOOL = zend_read_static_property(ce, "ALINQ_CLOSURE_RETURN_TYPE_BOOL", sizeof("ALINQ_CLOSURE_RETURN_TYPE_BOOL")-1, 0 TSRMLS_DC);
    reVal = GetApplicables(getThis(),fci,fci_cache,0,Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL),sizeof(Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL)));
    RETURN_ZVAL(reVal,1,1);

}
ZEND_METHOD( alinq_class , All )
{
    zend_fcall_info fci;
    zend_fcall_info_cache fci_cache;
    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());
    zval *dataSource, *reObj, *reZvalCount,*new_dataSource;

    HashTable *arrht;
    HashTable *rearrht;

    char aReturnType;
    int aReturnTypeLen; 

    int count,reCount;

    // aReturnType = 'bool';

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "f", &fci, &fci_cache) == FAILURE) {
        return;
    }     
    zval *ALINQ_CLOSURE_RETURN_TYPE_BOOL;

    ALINQ_CLOSURE_RETURN_TYPE_BOOL = zend_read_static_property(ce, "ALINQ_CLOSURE_RETURN_TYPE_BOOL", sizeof("ALINQ_CLOSURE_RETURN_TYPE_BOOL")-1, 0 TSRMLS_DC);
    reObj = GetApplicables(getThis(),fci,fci_cache,0,Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL),sizeof(Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL)));
    // RETURN_ZVAL(reArr,1,1);
    //过滤后的元素个数
    new_dataSource = zend_read_property(NULL, reObj, "dataSource", sizeof("dataSource")-1, 0 TSRMLS_DC);
    // walu_call_user_function(&reZvalCount, NULL, "count", "z", reArr);
    // reCount = Z_LVAL_P(reZvalCount);
    rearrht = Z_ARRVAL_P(new_dataSource);
    reCount = rearrht->nNumOfElements;


    //原数组的元素个数
    dataSource = zend_read_property(ce, getThis(), "dataSource", sizeof("dataSource")-1, 0 TSRMLS_DC);
    arrht = Z_ARRVAL_P(dataSource);
    count = arrht->nNumOfElements;

    if(count==reCount){
        RETURN_BOOL(1);
    }
    RETURN_BOOL(0);

}
ZEND_METHOD( alinq_class , Any )
{
    zend_fcall_info fci;
    zend_fcall_info_cache fci_cache;
    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());
    zval *dataSource, *reObj, *reZvalCount,*new_dataSource;

    HashTable *arrht;
    HashTable *rearrht;

    char aReturnType;
    int aReturnTypeLen; 

    int count,reCount;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "f", &fci, &fci_cache) == FAILURE) {
        return;
    }     
    // zval *arrayValues;
    zval *ALINQ_CLOSURE_RETURN_TYPE_BOOL;

    ALINQ_CLOSURE_RETURN_TYPE_BOOL = zend_read_static_property(ce, "ALINQ_CLOSURE_RETURN_TYPE_BOOL", sizeof("ALINQ_CLOSURE_RETURN_TYPE_BOOL")-1, 0 TSRMLS_DC);
    // walu_call_user_function(&arrayValues, getThis(), "GetApplicables", "fl", fci,1);
    reObj = GetApplicables(getThis(),fci,fci_cache,1,Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL),sizeof(Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL)));

    //过滤后的元素个数
    new_dataSource = zend_read_property(NULL, reObj, "dataSource", sizeof("dataSource")-1, 0 TSRMLS_DC);
    // walu_call_user_function(&reZvalCount, NULL, "count", "z", reArr);
    // reCount = Z_LVAL_P(reZvalCount);
    rearrht = Z_ARRVAL_P(new_dataSource);
    reCount = rearrht->nNumOfElements;




    if(reCount>0){
        RETURN_BOOL(1);
    }
    RETURN_BOOL(0);

}

ZEND_METHOD( alinq_class , Skip )
{
    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());
    zval * reVal;

    int count;
    long *skip_num;
    zval *dataSource,*resultArray;
    HashTable *arrht;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &skip_num) == FAILURE) {
        return;
    }     
    dataSource = zend_read_property(ce, getThis(), "dataSource", sizeof("dataSource")-1, 0 TSRMLS_DC);

    arrht = Z_ARRVAL_P(dataSource);
    count = arrht->nNumOfElements;

    walu_call_user_function(&resultArray, NULL, "array_slice", "zll", dataSource,skip_num,count);

    walu_call_user_function(&reVal, getThis(), "Instance", "z", resultArray);
    RETURN_ZVAL(reVal,1,1);

}


//平均数
ZEND_METHOD( alinq_class , Average )
{
    zend_fcall_info fci;
    zend_fcall_info_cache fci_cache;
    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());
    zval * reArrVal;
    MAKE_STD_ZVAL(reArrVal);
    array_init(reArrVal);
    zval *dataSource, **tmpns;
    ALLOC_INIT_ZVAL(reArrVal);      //持久化分配内存

    zval *retval_ptr = NULL;
    long resulTotal = 0,averagable=0;
    float averNum;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "f", &fci, &fci_cache) == FAILURE) {
        return;
    }     
    dataSource = zend_read_property(ce, getThis(), "dataSource", sizeof("dataSource")-1, 0 TSRMLS_DC);

    while (zend_hash_get_current_data(Z_ARRVAL_P(dataSource), (void **)&tmpns) == SUCCESS) {
        char *key;
        uint keylen;
        ulong idx;
        int type;
        zval **ppzval, *tmpcopy;
        MAKE_STD_ZVAL(tmpcopy);

        type = zend_hash_get_current_key_ex(Z_ARRVAL_P(dataSource), &key, &keylen,&idx, 0, NULL);

        //重新copy一个zval，防止破坏原数据
        tmpcopy = *tmpns;
        zval_copy_ctor(tmpcopy);
        // INIT_PZVAL(tmpcopy);
        walu_call_anony_function(&retval_ptr, NULL, fci, "sz", key, keylen,&tmpcopy);

        resulTotal = resulTotal + Z_LVAL_P(retval_ptr);
        averagable++;
        // php_printf("value: %d\n", Z_LVAL_P(retval_ptr));

        zend_hash_move_forward(Z_ARRVAL_P(dataSource));
    } 
    // php_printf("resulTotal: %d\n", resulTotal);
    // php_printf("averagable: %d\n", averagable);
   
    if(averagable > 0){
        averNum = (float)resulTotal/(float)averagable;
        // php_printf("averagable: %f\n", averNum);
        RETURN_DOUBLE(averNum);
    }   
    RETURN_DOUBLE(0);

    RETURN_ZVAL(reArrVal,1,1);

}

//排序
zval* OrderFun(zval * obj,zend_fcall_info fci,zend_fcall_info_cache fci_cache,char *direction,long directionLen)
{
    reVal = GetApplicables(obj,fci,fci_cache,0,'object',sizeof('object'));

    int sortType = 1;   //ALINQ_ORDER_TYPE_NUMERIC
}    

//数组覆盖
ZEND_METHOD( alinq_class , Concat )
{
    zval *concat_array;
    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());
    zval * reArrVal;
    MAKE_STD_ZVAL(reArrVal);
    array_init(reArrVal);
    zval *dataSource, **tmpns;
    ALLOC_INIT_ZVAL(reArrVal);      //持久化分配内存

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &concat_array) == FAILURE) {
        return;
    }     
    dataSource = zend_read_property(ce, getThis(), "dataSource", sizeof("dataSource")-1, 0 TSRMLS_DC);
        //重新copy一个zval，防止破坏原数据
        reArrVal = dataSource;
        zval_copy_ctor(reArrVal);
        // INIT_PZVAL(reArrVal);
    while (zend_hash_get_current_data(Z_ARRVAL_P(concat_array), (void **)&tmpns) == SUCCESS) {
        char *key;
        uint keylen;
        ulong idx;
        int type;
        zval **ppzval, *tmpcopy;
        MAKE_STD_ZVAL(tmpcopy);

        type = zend_hash_get_current_key_ex(Z_ARRVAL_P(concat_array), &key, &keylen,&idx, 0, NULL);


        //重新copy一个zval，防止破坏原数据
        tmpcopy = *tmpns;
        zval_copy_ctor(tmpcopy);
        // INIT_PZVAL(tmpcopy);

        add_assoc_zval(reArrVal, key, tmpcopy); 
        // zval_dtor(&tmpcopy);
        // PHPWRITE(key,keylen);  
        // RETURN_ZVAL(reArrVal,1,1); 
        zend_hash_move_forward(Z_ARRVAL_P(concat_array));
    }    

    RETURN_ZVAL(reArrVal,1,1);

}

ZEND_METHOD( alinq_class , GroupBy )
{
    zend_fcall_info fci;
    zend_fcall_info_cache fci_cache;
    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());
    zval * reVal;
    zval * resultArray;
    MAKE_STD_ZVAL(resultArray);
    array_init(resultArray);
    zval *retval_ptr = NULL;
    zval *returnObj;  
    zval *dataSource, **tmpns;


    char aReturnType;
    int aReturnTypeLen; 

    // aReturnType = 'bool';
     //取得数组
    dataSource = zend_read_property(ce, getThis(), "dataSource", sizeof("dataSource")-1, 0 TSRMLS_DC);

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "f", &fci, &fci_cache) == FAILURE) {
        return;
    }     

    while (zend_hash_get_current_data(Z_ARRVAL_P(dataSource), (void **)&tmpns) == SUCCESS) {
        char *key;
        uint keylen;
        ulong idx;
        int type;
        zval **ppzval, tmpcopy;
        zval **item,*item1;
        MAKE_STD_ZVAL(item1);
        array_init(item1);
        item = &item1;
        php_printf("step-\n");
        // if(count>0 && i>=count){        //只循环count次
        //     break;
        // }

        type = zend_hash_get_current_key_ex(Z_ARRVAL_P(dataSource), &key, &keylen,&idx, 0, NULL);

        //重新copy一个zval，防止破坏原数据
        tmpcopy = **tmpns;
        zval_copy_ctor(&tmpcopy);
        INIT_PZVAL(&tmpcopy);
         // convert_to_string(&tmpcopy);
        

        walu_call_anony_function(&retval_ptr, NULL, fci, "sz", key, keylen,&tmpcopy); 

        if(zend_hash_find(Z_ARRVAL_P(resultArray), Z_STRVAL_P(retval_ptr),sizeof(Z_STRVAL_P(retval_ptr)), (void **)&item) == FAILURE && IS_STRING==Z_TYPE_P(retval_ptr)) {
            // php_printf("step0\n");
            // zend_error(E_ERROR, "element not found");
            // MAKE_STD_ZVAL(item);
            // array_init(item);
            add_assoc_zval(resultArray, Z_STRVAL_P(retval_ptr), *item); 
        }
        // PHPWRITE(Z_STRVAL_P(retval_ptr),strlen(Z_STRVAL_P(retval_ptr)));  
        // php_printf("step1\n");
        if( IS_ARRAY!=Z_TYPE_PP(item)){
            php_printf("not array\n");
            continue;
        }

        // add_assoc_zval(resultArray, retval_ptr, *tmpns);  
        add_next_index_zval(*item,*tmpns);
        // /* Toss out old copy */
        zval_dtor(&tmpcopy);



        zend_hash_move_forward(Z_ARRVAL_P(dataSource));
    }
    
    walu_call_user_function(&returnObj, getThis(), "Instance", "z", resultArray);
    RETURN_ZVAL(returnObj,1,1);    

    return; 

}
ZEND_METHOD( alinq_class , ElementAt )
{
    zend_class_entry *ce;
    zval * dataSource;
    zval ** item;

    ce = Z_OBJCE_P(getThis());

    long at;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l",&at) == FAILURE) {
        RETURN_NULL();
    }



    //读取类变量
    // MAKE_STD_ZVAL(dataSource);
    dataSource = zend_read_property(ce, getThis(), "dataSource", sizeof("dataSource")-1, 0 TSRMLS_DC);
  

    //调用array_values函数
    zval *arrayValues;
    walu_call_user_function(&arrayValues, NULL, "array_values", "z", dataSource);


    //根据下标返回数组元素
    // item = &arrayValues[at];
    if(zend_hash_index_find(Z_ARRVAL_P(arrayValues), at, (void **)&item) == FAILURE) {
        // php_printf("发现\n");
        // zend_error(E_ERROR, "element not found");
        RETURN_NULL();
    }
    RETVAL_ZVAL(*item,1,1);
    // php_var_dump(&val); 
    zval_ptr_dtor(&arrayValues);
    // zval_ptr_dtor(item);
    return;

}


//迭代函数
void php_alinq_iterator_key(HashTable *arrht)
{

    for(zend_hash_internal_pointer_reset(arrht);
        zend_hash_has_more_elements(arrht) == SUCCESS;
        zend_hash_move_forward(arrht))
    {
        if(zend_hash_has_more_elements(arrht) == SUCCESS){
            php_printf("aaaa");
        }else{
            php_printf("bbbb");
        }
       
    }
}




//]

//zend class{
 
//然后，定义一个zend_function_entry
zend_function_entry alinq_class_method[]=
{
    ZEND_ME(alinq_class,    __construct,    NULL,   ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    ZEND_ME(alinq_class,    getArrayItem,  NULL,   ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    ZEND_ME(alinq_class,    Instance,  NULL,   ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    ZEND_ME(alinq_class,    ElementAt,  NULL,   ZEND_ACC_PUBLIC)
    ZEND_ME(alinq_class,    Single,  NULL,   ZEND_ACC_PUBLIC)
    ZEND_ME(alinq_class,    GroupBy,  NULL,   ZEND_ACC_PUBLIC)
    ZEND_ME(alinq_class,    Concat,  NULL,   ZEND_ACC_PUBLIC)
    ZEND_ME(alinq_class,    SelectMany,  NULL,   ZEND_ACC_PUBLIC)
    ZEND_ME(alinq_class,    Select,  NULL,   ZEND_ACC_PUBLIC)
    ZEND_ME(alinq_class,    Where,  NULL,   ZEND_ACC_PUBLIC)
    ZEND_ME(alinq_class,    Skip,  NULL,   ZEND_ACC_PUBLIC)
    ZEND_ME(alinq_class,    All,  NULL,   ZEND_ACC_PUBLIC)
    ZEND_ME(alinq_class,    Any,  NULL,   ZEND_ACC_PUBLIC)
    ZEND_ME(alinq_class,    Average,  NULL,   ZEND_ACC_PUBLIC)
    // ZEND_ME(alinq_class,    GetApplicables,  NULL,   ZEND_ACC_PUBLIC)
    {NULL,  NULL,   NULL}
};
 
ZEND_MINIT_FUNCTION(test)
{
    // zval *myarray;
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"alinq",alinq_class_method);
    alinq_class_ce = zend_register_internal_class(&ce TSRMLS_CC);

    //定义属性
    zend_declare_property_null(alinq_class_ce, "dataSource", strlen("dataSource"), ZEND_ACC_PUBLIC TSRMLS_CC);
    
    // MAKE_STD_ZVAL(myarray);

    // array_init(myarray);
    // zend_declare_property(alinq_class_ce, "dataSource", sizeof("dataSource"), myarray, ZEND_ACC_PUBLIC TSRMLS_DC); //会报错 PHP Fatal error:  Internal zval's can't be arrays, objects or resources in Unknown on line 0
    // add_property_zval(alinq_class_ce, "dataSource", sizeof("dataSource"), myarray)

    char *bool_type_bool    = "bool";
    char *bool_type_object  = "object";

    zend_declare_property_string(alinq_class_ce, "ALINQ_CLOSURE_RETURN_TYPE_BOOL", sizeof("ALINQ_CLOSURE_RETURN_TYPE_BOOL")-1,bool_type_bool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);
    zend_declare_property_string(alinq_class_ce, "ALINQ_CLOSURE_RETURN_TYPE_OBJECT", sizeof("ALINQ_CLOSURE_RETURN_TYPE_OBJECT")-1,bool_type_object, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);


    bool_type_bool = NULL;
    bool_type_object = NULL;

    return SUCCESS;
}
//}

 
ZEND_FUNCTION(sample_array)
{
    zval *subarray;
 
    array_init(return_value);
     
    /* Add some scalars */
    add_assoc_long(return_value, "life", 42);
    add_index_bool(return_value, 123, 1);
    add_next_index_double(return_value, 3.1415926535);
     
    /* Toss in a static string, dup'd by PHP */
    add_next_index_string(return_value, "Foo", 1);
     
    /* Now a manually dup'd string */
    add_next_index_string(return_value, estrdup("Bar"), 0);
 
    /* Create a subarray */
    MAKE_STD_ZVAL(subarray);
    array_init(subarray);
     
    /* Populate it with some numbers */
    add_next_index_long(subarray, 1);
    add_next_index_long(subarray, 20);
    add_next_index_long(subarray, 300);
     
    /* Place the subarray in the parent */
    add_index_zval(return_value, 444, subarray);
}


ZEND_FUNCTION(alinq_get_array_item)
{
    zval *data_array;
    zval *copy_array;
    char *name;
    int name_len;
    zval **fooval;
    // char str[] = "未找到该索引";

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "as",&data_array,  &name, &name_len) == FAILURE) {
        RETURN_NULL();
    }


    if(zend_hash_find(HASH_OF(data_array),name,name_len,(void**)&fooval) == SUCCESS ){
        RETVAL_ZVAL(*fooval, 1, 0); 
    }else{
        // RETVAL_STRING(&str, 1);
        RETVAL_STRING("index_not_found", 1);
    }
    // array_init(return_value);
    // add_index_zval(return_value, 444, data_array);
    // RETURN_ZVAL(data_array, 1, 0);          //返回复合类型变量
    return;

}    

 
static zend_function_entry alinq_functions[] = {
    ZEND_FE(sample_array,        NULL)
    ZEND_FE(alinq_get_array_item,        NULL)
    { NULL, NULL, NULL }
};
 
//module entry 
zend_module_entry alinq_module_entry = {
    #if ZEND_MODULE_API_NO >= 20010901
         STANDARD_MODULE_HEADER,
    #endif
        "alinq", //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
        alinq_functions, /* Functions */
        ZEND_MINIT(test), /* MINIT */
        NULL, /* MSHUTDOWN */
        NULL, /* RINIT */
        NULL, /* RSHUTDOWN */
        NULL, /* MINFO */
    #if ZEND_MODULE_API_NO >= 20010901
        "2.1", //这个地方是我们扩展的版本
    #endif
        STANDARD_MODULE_PROPERTIES
};
 
#ifdef COMPILE_DL_ALINQ
ZEND_GET_MODULE(alinq)
#endif
