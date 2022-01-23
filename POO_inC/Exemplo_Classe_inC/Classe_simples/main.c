#include <stdio.h>
#include <string.h>

#include "caneta.h"

int main() {

 Caneta caneta;
 caneta_new(&caneta,"Bic", "Verde", 0.22);
 caneta_status(caneta);

 return 0;
}

