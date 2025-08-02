#ifndef SHAPE_INTERFACE_H_
#define SHAPE_INTERFACE_H_


typedef struct 
{
    void(*draw)(void);
} Shape_t;


#endif /* SHAPE_INTERFACE_H_ */