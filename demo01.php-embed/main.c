#include "sapi/embed/php_embed.h"

int main(int argc, char **argv) {
    zend_file_handle file_handle;

    php_embed_init(argc, argv);
    file_handle.type = ZEND_HANDLE_FILENAME;
    file_handle.filename = "call.php";

    php_execute_script(&file_handle);

    php_embed_shutdown();

    return 0;
}

/*
gcc \
-I /usr/local/include/php/ \
-I /usr/local/include/php/main \
-I /usr/local/include/php/sapi \
-I /usr/local/include/php/TSRM \
-I /usr/local/include/php/Zend \
-lphp7 -Wl,-rpath=/usr/local/src/php-src-php-7.0.12/libs \
-o main main.c
*/