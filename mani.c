#include <stdio.h>
#include <stdlib.h>

#include "contato.h"
#include "lista_contatos.h"

int main()
{
lista_contatos amigos;
inicializar(&amigos, 3);

contato a = {"neil tyson", "+1(699)193265", 1958,10,5};
contato b = {"serena williams", "+1(369)654963", 1981,9,26};
contato c = {"edson nascimento", "+55 (11) 35693696", 1940,10,23};
contato d = {"miguel sapateiro", "+49 (0151) 9876589", 1969,1,3};

inserir(&amigos, a);
inserir(&amigos, b);
inserir(&amigos, c);
inserir(&amigos, d);

print_lista(&amigos);

destruir(&amigos);

return 0;
}