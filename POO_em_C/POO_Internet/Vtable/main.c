#include <stdio.h>

// http://cecilsunkure.blogspot.com/2012/08/object-oriented-c-virtual-table-vtable.html#:~:text=A%20vtable%20is%20simply%20a%20pointer%20to%20a%20collection%20of%20function%20pointers.&text=Luckily%20the%20murkiness%20of%20member,an%20array%20of%20function%20pointers.

/*

Essa estrutura requer espaço de memória para cada local. Isso é desnecessário e um pouco incômodo
de lidar durante a inicialização e pode levar a uma impressão de tipos incômoda em vários locais.

typedef struct _GameObj
{
  int HP;
  Vector2D_ position;
  GAME_OBJ_TYPE ID;
  Image_ *image;
  void (*Construct)( GameObj_ *self ); 
  void (*Init)( GameObj_ *self );  
  void (*Update)( GameObj_ *self );  
  void (*Draw)( GameObj_ *self );  
  void (*Destroy)( GameObj_ *self );
} GameObj_;

*/

// Esta é a aparência do novo objeto se introduzirmos uma vtable,
// Isso reduz o tamanho da memória necessária para as funções virtuais
// para este objeto específico por um fator de 5

typedef struct _GameObj
{
  int HP;
  Vector2D_ position;
  GAME_OBJ_TYPE ID;
  Image_ *image;
  const _GAMEOBJECT_VTABLE *vtable;
} GameObj_;

 // Aqui está como a definição da vtable pode ser:

 typedef struct _GAMEOBJECT_VTABLE
{
  void (*Construct)( struct _GAMEOBJECT *self );
  void (*Init)     ( struct _GAMEOBJECT *self );
  void (*set)      ( struct _GAMEOBJECT *self );
  void (*Update)   ( struct _GAMEOBJECT *self );
  void (*Draw)     ( struct _GAMEOBJECT *self );
  void (*Destroy)  ( struct _GAMEOBJECT *self );
} _GAMEOBJECT_VTABLE;

// Aqui está um pequeno exemplo de algum código de inicialização para inicializar o membro de dados vtable:

const _SOME_OTHER_VTABLE SOME_OTHER_VTABLE = {
  SomeOtherConstruct,
  SomeOtherInit,
  SomeOtherSet,
  SomeOtherUpdate,
  SomeOtherDraw,
  SomeOtherDestroy
};

((GAMEOBJECT *)object)->vtable_ =
  (const _GAMEOBJECT_VTABLE *)(&SOME_OTHER_VTABLE);

// Example invocation of an object's vtable's function
object->vtable->Destroy( object );
((SOME_OTHER_VTABLE *) objeto-> vtable) -> SomeOtherUpdate (outros parâmetros);