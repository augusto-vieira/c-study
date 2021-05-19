#ifndef ANIMAL_H_
#define ANIMAL_H_

struct animal
{
    // torna vtable_ um ponteiro para que eles possam ser compartilhados entre as instâncias
    // use _ para marcar membros privados
    const struct animal_vtable_ *vtable_;
    const char *name;
};

struct animal_vtable_
{
    const char *(*sound)(void);
};

// wrapper function - função destinada a chamar uma ou mais funções
static inline const char *animal_sound(struct animal *animal)
{
    return animal->vtable_->sound();
}

// faça os arrays vtables para que possam ser usados como ponteiros
extern const struct animal_vtable_ CAT[], DOG[];

#endif