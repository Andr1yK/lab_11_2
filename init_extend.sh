file_name="$1"
define=$(echo $file_name | tr '[:lower:]' '[:upper:]')

set -o noclobber

code="#pragma once\n
\n\
#ifndef _${define}_\n\
#define _${define}_\n\
// code here\n\
#endif"

echo $code > src/extends/$file_name.cpp