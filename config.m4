PHP_ARG_ENABLE(alinq,
    [Whether to enable the "alinq" extension],
    [  enable-alinq        Enable "alinq" extension support])

if test $PHP_ALINQ != "no"; then
    PHP_SUBST(ALINQ_SHARED_LIBADD)
    PHP_NEW_EXTENSION(alinq, alinq.c, $ext_shared)
fi
 