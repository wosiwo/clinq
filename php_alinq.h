//php_alinq.h
#ifndef alinq_H
#define alinq_H
 
//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"
#define phpext_alinq_ptr &alinq_module_entry
extern zend_module_entry alinq_module_entry;
 
#endif

// #include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "Zend/zend_list.h"
#include "Zend/zend_interfaces.h" 
int walu_call_user_function(zval** retval, zval* obj, char* function_name, char* paras, ...){        //用于接收参数  
     short int  paras_count = 0;  
     zval***    parameters  = NULL;  
     long       long_tmp;  
     char       *string_tmp;  
     zval       *zval_tmp;  
     double     dou_tmp;  
     int        i;         //仅与调用有关的变量  
     int        fun_re, retval_is_null = 0;  
     HashTable  *function_table;         //接收参数 

    paras_count = strlen(paras);  
    if(paras_count > 0)        {  
        parameters = (zval***)emalloc(sizeof(zval**) * paras_count);  
        va_list ap;  
        va_start(ap,paras);  
        for(i=0; i<paras_count; i++)                {  
            parameters[i] = (zval**)emalloc(sizeof(zval*));  
            switch(paras[i])                        {  
                case 's':  
                    MAKE_STD_ZVAL(*parameters[i]);  
                    string_tmp = va_arg(ap, char*);  
                    long_tmp   = va_arg(ap, long);    
                    ZVAL_STRINGL(*parameters[i], string_tmp, long_tmp, 1);  
                    break;  
                case 'l':    
                    MAKE_STD_ZVAL(*parameters[i]);  
                    long_tmp = va_arg(ap, long);  
                    ZVAL_LONG(*parameters[i], long_tmp);    
                    break;                                 
                case 'd':    
                    MAKE_STD_ZVAL(*parameters[i]);  
                    dou_tmp = va_arg(ap, double);  
                    ZVAL_DOUBLE(*parameters[i], dou_tmp);  
                    break;  
                case 'n':  
                    MAKE_STD_ZVAL(*parameters[i]);  
                    ZVAL_NULL(*parameters[i]);  
                    break;  
                 case 'z':  
                    zval_tmp = va_arg(ap, zval*);  
                    *parameters[i] = zval_tmp;  
                    break;  
                 case 'b':    
                    MAKE_STD_ZVAL(*parameters[i]);    
                    ZVAL_BOOL(*parameters[i], (int)va_arg(ap, int));  
                    break;  
               default:  
                    zend_error(E_ERROR, "Unsupported type:%c in walu_call_user_function", paras[i]);                                        
                    return 0;  
            }  
        }  
        va_end(ap);  
    }         //构造参数执行call_user_function_ex    
    zval *_function_name;  
    MAKE_STD_ZVAL(_function_name);  
    ZVAL_STRINGL(_function_name, function_name, strlen(function_name), 1);  
    if(retval == NULL)        {  
        retval_is_null = 1;  
        retval = (zval**)emalloc(sizeof(zval*));  
    }         //开始函数调用  
    if(obj) {  
        function_table = &Z_OBJCE_P(obj)->function_table;  
    } else {  
        function_table = (CG(function_table));  
    }  
    zend_fcall_info fci;  
    fci.size            = sizeof(fci);  
    fci.function_table  = function_table;  
    fci.object_ptr      = obj ? obj : NULL;  
    fci.function_name   = _function_name;  
    fci.retval_ptr_ptr  = retval;  
    fci.param_count     = paras_count;  
    fci.params          = parameters;  
    fci.no_separation   = 1;  
    fci.symbol_table    = NULL;  
    fun_re = zend_call_function(&fci, NULL TSRMLS_CC);         //函数调用结束。  
    if(retval_is_null == 1)        {  
        zval_ptr_dtor(retval);  
        efree(retval);  
    }  
    zval_ptr_dtor(&_function_name);         //free掉parameter及其里面的每个元素zval**，及每个元素zval**对应的zval*        //对于传进来的zval，不进行free，由参数调用者自行free  
    if(paras_count > 0)        {  
        for(i=0; i<paras_count; i++)                {  
            if(paras[i] != 'z')                        {  
                    zval_ptr_dtor(parameters[i]);  
            }  
            efree(parameters[i]);  
        }  
        efree(parameters);  
    }  
    return fun_re;  
}  

//调用匿名函数
int walu_call_anony_function(zval** retval, zval* obj, zend_fcall_info fci, char* paras, ...){        //用于接收参数  
     short int  paras_count = 0;  
     zval***    parameters  = NULL;  
     long       long_tmp;  
     char       *string_tmp;  
     zval       *zval_tmp;  
     double     dou_tmp;  
     int        i;         //仅与调用有关的变量  
     int        fun_re, retval_is_null = 0;  
     HashTable  *function_table;         //接收参数 

    paras_count = strlen(paras);  
    if(paras_count > 0)        {  
        parameters = (zval***)emalloc(sizeof(zval**) * paras_count);  
        va_list ap;  
        va_start(ap,paras);  
        for(i=0; i<paras_count; i++)                {  
            parameters[i] = (zval**)emalloc(sizeof(zval*));  
            switch(paras[i])                        {  
                case 's':  
                    MAKE_STD_ZVAL(*parameters[i]);  
                    string_tmp = va_arg(ap, char*);  
                    long_tmp   = va_arg(ap, long);    
                    ZVAL_STRINGL(*parameters[i], string_tmp, long_tmp, 1);  
                    break;  
                case 'l':    
                    MAKE_STD_ZVAL(*parameters[i]);  
                    long_tmp = va_arg(ap, long);  
                    ZVAL_LONG(*parameters[i], long_tmp);    
                    break;                                 
                case 'd':    
                    MAKE_STD_ZVAL(*parameters[i]);  
                    dou_tmp = va_arg(ap, double);  
                    ZVAL_DOUBLE(*parameters[i], dou_tmp);  
                    break;  
                case 'n':  
                    MAKE_STD_ZVAL(*parameters[i]);  
                    ZVAL_NULL(*parameters[i]);  
                    break;  
                 case 'z':  
                    zval_tmp = va_arg(ap, zval*);  
                    *parameters[i] = zval_tmp;  
                    break;  
                 case 'b':    
                    MAKE_STD_ZVAL(*parameters[i]);    
                    ZVAL_BOOL(*parameters[i], (int)va_arg(ap, int));  
                    break;  
               default:  
                    zend_error(E_ERROR, "Unsupported type:%c in walu_call_user_function", paras[i]);                                        
                    return 0;  
            }
        }  
        va_end(ap);  
    }         //构造参数执行call_user_function_ex    
    // zval *_function_name;  
    // MAKE_STD_ZVAL(_function_name);  
    // ZVAL_STRINGL(_function_name, function_name, strlen(function_name), 1);  
    // if(retval == NULL)        {  
    //     retval_is_null = 1;  
    //     retval = (zval**)emalloc(sizeof(zval*));  
    // }         //开始函数调用  
    // if(obj) {  
    //     function_table = &Z_OBJCE_P(obj)->function_table;  
    // } else {  
    //     function_table = (CG(function_table));  
    // }  
    // zend_fcall_info fci;  
    fci.size            = sizeof(fci);  
    // fci.function_table  = function_table;  
    // fci.object_ptr      = obj ? obj : NULL;  
    // fci.function_name   = _function_name;  
    fci.retval_ptr_ptr  = retval;  
    fci.param_count     = paras_count;  
    fci.params          = parameters;  
    fci.no_separation   = 1;  
    fci.symbol_table    = NULL;  
    fun_re = zend_call_function(&fci, NULL TSRMLS_CC);         //函数调用结束。  
    if(retval_is_null == 1)        {  
        zval_ptr_dtor(retval);  
        efree(retval);  
    }  
    // zval_ptr_dtor(&_function_name);         //free掉parameter及其里面的每个元素zval**，及每个元素zval**对应的zval*        //对于传进来的zval，不进行free，由参数调用者自行free  
    if(paras_count > 0)        {  
        for(i=0; i<paras_count; i++)                {  
            if(paras[i] != 'z')                        {  
                    zval_ptr_dtor(parameters[i]);  
            }  
            efree(parameters[i]);  
        }  
        efree(parameters);  
    }  
    return fun_re;  
}  


// ZEND_METHOD( alinq_class , GetApplicables )
// void GetApplicables();

zval* GetApplicables(zval * obj,zend_fcall_info fci,zend_fcall_info_cache fci_cache,long count,char *aReturnType,long aReturnTypeLen)
{
 
    zend_class_entry *ce;
    zval * dataSource;
    zval * ALINQ_CLOSURE_RETURN_TYPE_BOOL;
    zval * ALINQ_CLOSURE_RETURN_TYPE_OBJECT;
    zval * resultArray,*returnObj;             //
    MAKE_STD_ZVAL(resultArray);
    array_init(resultArray);

    ce = Z_OBJCE_P(obj);

    zval *retval_ptr = NULL;
    // zend_fcall_info fci;
    // zend_fcall_info_cache fci_cache;

    // long count;

    HashTable *arrht;

    // char *aReturnType;
    // int aReturnTypeLen;

    // if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "fl|s", &fci, &fci_cache, &count,&aReturnType,&aReturnTypeLen) == FAILURE) {
    //     return;
    // }

    //取得数组
    dataSource = zend_read_property(ce, obj, "dataSource", sizeof("dataSource")-1, 0 TSRMLS_DC);
    ALINQ_CLOSURE_RETURN_TYPE_BOOL = zend_read_static_property(ce, "ALINQ_CLOSURE_RETURN_TYPE_BOOL", sizeof("ALINQ_CLOSURE_RETURN_TYPE_BOOL")-1, 0 TSRMLS_DC);
    ALINQ_CLOSURE_RETURN_TYPE_OBJECT = zend_read_static_property(ce, "ALINQ_CLOSURE_RETURN_TYPE_OBJECT", sizeof("ALINQ_CLOSURE_RETURN_TYPE_OBJECT")-1, 0 TSRMLS_DC);


    //循环数组元素

    arrht = Z_ARRVAL_P(dataSource);

    zval **tmpns;
    int i;
    i=0;
    while (zend_hash_get_current_data(Z_ARRVAL_P(dataSource), (void **)&tmpns) == SUCCESS) {
        char *key;
        uint keylen;
        ulong idx;
        int type;
        zval **ppzval, tmpcopy;
        if(count>0 && i>=count){        //只循环count次
            break;
        }
        type = zend_hash_get_current_key_ex(Z_ARRVAL_P(dataSource), &key, &keylen,&idx, 0, NULL);

        //重新copy一个zval，防止破坏原数据
        tmpcopy = **tmpns;
        zval_copy_ctor(&tmpcopy);
        INIT_PZVAL(&tmpcopy);
         // convert_to_string(&tmpcopy);
                
        if( !strcmp(aReturnType,Z_STRVAL_P(ALINQ_CLOSURE_RETURN_TYPE_BOOL))  || NULL==aReturnType){
            walu_call_anony_function(&retval_ptr, NULL, fci, "sz", key, keylen,&tmpcopy);
            
            if(Z_BVAL_P(retval_ptr)){   //匿名函数返回ture则保存数据，即通过匿名函数来筛选数据
                //  php_printf("\nssss");
                // PHPWRITE(Z_STRVAL(tmpcopy), sizeof(Z_STRVAL(tmpcopy)));

                add_assoc_zval(resultArray, key, *tmpns);
            }else{
                // php_printf("\nxxxx");
            }
        }else{

            walu_call_anony_function(&retval_ptr, NULL, fci, "sz", key, keylen,&tmpcopy);
            // if(Z_BVAL_P(retval_ptr)){
            //     php_printf("\nbad1"); 
            // }    
            add_assoc_zval(resultArray, key, retval_ptr);  
        }
        

        /* Toss out old copy */
        zval_dtor(&tmpcopy);



        zend_hash_move_forward(Z_ARRVAL_P(dataSource));
        i++;
    }
    walu_call_user_function(&returnObj, obj, "Instance", "z", resultArray);

    // RETVAL_ZVAL(returnObj,1,0);
    return returnObj;

}   

//===========================================================================================================
//===========================================================================================================
//===========================================================================================================
//===========================================================================================================
//===========================================================================================================
//===========================================================================================================

//代码参考
ZEND_METHOD( alinq_class , ElementAt1 )
{
    zval * function_name;
    zval * dataSource1;
    zval * arrayValues1;
    zend_class_entry *ce;
    zval * data_array;
    zval * item;
    zval    **args[1];
    char *lcase_fname;
    char funame[] = "array_values";
    zend_function *fe;



    ce = Z_OBJCE_P(getThis());

    long at;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "la",&at,&data_array) == FAILURE) {
        RETURN_NULL();
    }


    //读取类变量
    // MAKE_STD_ZVAL(dataSource1);
    dataSource1 = zend_read_property(ce, getThis(), "dataSource", sizeof("dataSource")-1, 0 TSRMLS_DC);
  


    zval *val;
    walu_call_user_function(&val, NULL, "array_keys1", "ss", ",", 1, "1,3,4", sizeof("1,3,4")-1);
    RETVAL_ZVAL(val,1,1);
    // php_var_dump(&val); 

    return;
     // RETVAL_STRING("index_not_found", 1);
    // array_init(args);
    // add_index_zval(args, 0, dataSource1);
    args[0] = &dataSource1;

    // lcase_fname = estrndup(funame, sizeof(funame));
    // zend_str_tolower(lcase_fname, sizeof(funame));
    


    // if (zend_hash_find(CG(function_table),lcase_fname, sizeof(funame) + 1, (void **)&fe) == SUCCESS)
    // {
    //     php_printf("发现\n");
    // }

    MAKE_STD_ZVAL(function_name);
    ZVAL_STRINGL(function_name,"array_keys1",sizeof("array_keys1")-1,1);
   
    // zval *params = { dataSource1 };
    // TSRMLS_FETCH();
    
    // if(FAILURE == call_user_function(CG(function_table), NULL, function_name, arrayValues1,1,&dataSource1 TSRMLS_DC))
    
    // HashTable *fun_arg_table;
    // ZEND_SET_SYMBOL( fun_arg_table ,  "a" , dataSource1);
    // zval **dataSource2;
    // dataSource2 = &dataSource1;
    // ZEND_SET_SYMBOL( &EG(symbol_table) ,  "a" , dataSource1);
    // php_printf("发现\n");
    // if(FAILURE == call_user_function_ex(CG(function_table), NULL,
    //         function_name, &arrayValues1, 1, &dataSource2, 1, NULL TSRMLS_CC))
    // {
    //     zend_error(E_ERROR, "Function call failed");
    // }
    call_user_function(CG(function_table), NULL,function_name,arrayValues1,1,&data_array TSRMLS_DC);
    // call_php();
    php_printf("bbb\n");
    // item = &arrayValues[at];
    RETVAL_ZVAL(arrayValues1,1,1);

    zval_ptr_dtor(&function_name);
    // zval_ptr_dtor(&arrayValues1);
    return;
}    

ZEND_METHOD( alinq_class , GetApplicables1 )
{
    zval *retval_ptr = NULL;
    zval *_function_name;  
    MAKE_STD_ZVAL(_function_name);  
    ZVAL_STRINGL(_function_name, "echo", strlen("echo"), 1);  
    short int paras_count = 1;
    char count = 'A';
    HashTable  *function_table;         //接收参数 
    zval***    parameters  = NULL;  
    int        fun_re;

    function_table = (CG(function_table));  

    //参数
    parameters = (zval***)emalloc(sizeof(zval**) * paras_count); 
    parameters[1] = (zval**)emalloc(sizeof(zval*));  
    MAKE_STD_ZVAL(*parameters[1]);  
    // ZVAL_STRINGL(*parameters[0], count,1,1);  
    ZVAL_STRINGL(*parameters[1],"a",sizeof("a")-1,1);


    zend_fcall_info fci;  
    fci.size            = sizeof(fci);  
    fci.function_table  = function_table;  
    fci.object_ptr      = NULL;  
    fci.function_name   = _function_name;  
    fci.retval_ptr_ptr  = &retval_ptr;  
    fci.param_count     = paras_count;  
    fci.params          = parameters;  
    fci.no_separation   = 1;  
    fci.symbol_table    = NULL;  
    fun_re = zend_call_function(&fci, NULL TSRMLS_CC);         //函数调用结束。  


    return;

} 

