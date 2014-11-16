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

//调用用户空间函数
int walu_call_user_function(zval** retval, zval* obj, char* function_name, char* paras, ...);


//调用匿名函数
int walu_call_anony_function(zval** retval, zval* obj, zend_fcall_info fci, char* paras, ...);


//闭包执行函数
zval* GetApplicables(zval * obj,zend_fcall_info fci,zend_fcall_info_cache fci_cache,long count,char *aReturnType,long aReturnTypeLen);