#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct student_t create_student(char *_id, char *_name, char *_year,enum gender_t _gender){
    struct student_t s;
    strcpy(s.id, _id);
    strcpy(s.name, _name);
    strcpy(s.year, _year);
    s.gender = _gender;
    s.dorm = malloc (sizeof(struct dorm_t));
    s.dorm = NULL;
    return s;
}
void print_student(struct student_t *_student, int count){
    for (int i = 0; i < count; i++)
    {
        if (_student[i].gender==GENDER_MALE){
            printf("%s|", _student[i].id);
            printf("%s|", _student[i].name);
            printf("%s|male", _student[i].year);
        } else if (_student[i].gender==GENDER_FEMALE){
            printf("%s|", _student[i].id);
            printf("%s|", _student[i].name);
            printf("%s|female", _student[i].year);
        }
    }
}
void print_student_detail(struct student_t *_student, int count){
    for (int i = 0; i < count; i++)
    {
        if (_student[i].dorm == NULL){
            if (_student[i].gender==GENDER_MALE){
                printf("%s|", _student[i].id);
                printf("%s|",_student[i].name);
                printf("%s|male|unassign\n", _student[i].year);
            } else if (_student[i].gender==GENDER_FEMALE){
                printf("%s|", _student[i].id);
                printf("%s|",_student[i].name);
                printf("%s|female|unassign\n", _student[i].year);
            }
        } else {
            if (_student[i].gender==GENDER_MALE){
                printf("%s|", _student[i].id);
                printf("%s|",_student[i].name);
                printf("%s|",_student[i].year);
                printf("%s|male|", _student[i].year);
                printf("%s\n", _student[i].dorm->name);
            } else if (_student[i].gender==GENDER_FEMALE){
                printf("%s|", _student[i].id);
                printf("%s|",_student[i].name);
                printf("%s|",_student[i].year);
                printf("%s|female|", _student[i].year);
                printf("%s\n", _student[i].dorm->name);
            }
        }
    }
}
void assign_student(struct student_t *_student,struct dorm_t *_dorm, char *id, char *dorm_name){
    if (_dorm->residents_num < _dorm->capacity){
        if (_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_num++;
        }
    }
}
void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name){
    if (_dorm->residents_num < _dorm->capacity){
        if (_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_num++;
            old_dorm->residents_num--;
        }
    }
}

void unassign_student(struct student_t *_student, struct dorm_t *_dorm){
    _student->dorm = NULL;
    _dorm->residents_num--;
}
