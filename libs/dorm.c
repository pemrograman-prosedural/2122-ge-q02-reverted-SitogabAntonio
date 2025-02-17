#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender){
    struct dorm_t d;
    strcpy(d.name, _name);
    d.capacity = _capacity;
    d.gender = _gender;
    d.residents_num = 0;
    return d;
}

void print_dorm(struct dorm_t *_dorm, int count){
    for (int i = 0; i < count; i++)
    {
        if (_dorm[i].gender==GENDER_MALE){
            printf("%s|", _dorm[i].name);
            printf("%d|",_dorm[i].capacity);
            printf("male|");
            printf("%d\n",_dorm[i].residents_num);
        } else if(_dorm[i].gender==GENDER_FEMALE){
            printf("%s|", _dorm[i].name);
            printf("%d|",_dorm[i].capacity);
            printf("female|");
            printf("%d\n",_dorm[i].residents_num);
        }
    }   
}