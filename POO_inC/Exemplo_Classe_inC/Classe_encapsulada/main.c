#include <stdio.h>
#include <string.h>

#include "caneta.h"

int main() {

 Caneta *pen = caneta_new("Bic", "Verde", 0.22);
 caneta_status(pen);
 
 return 0;
}

