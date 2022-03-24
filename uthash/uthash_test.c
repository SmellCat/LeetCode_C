#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

struct my_struct
{
    int ikey;
    char value[10];
    UT_hash_handle hh;
};
struct my_struct *g_users = NULL;

struct my_struct *find_user(int ikey)
{
    struct my_struct *s;
    HASH_FIND_INT(g_users, &ikey, s);

    return s;
}

void add_user(int ikey, char *value_buf)
{
    struct my_struct *s;
    // 插入前线查看key值是否已经在hash表g_users里
    // 由于uthash需要键(key)必须唯一，而uthash内部未对key值的唯一性进行很好的处理，
    // 因此它要求外部在插入操作时要确保其key值不在当前的hash表中
    // 这就需要，在插入操作时，先查找hash表看其值是否已经存在，不存在时再进行插入操作
    HASH_FIND_INT(g_users, &ikey, s);

    if (s == NULL)
    {
        s = (struct my_struct *)malloc(sizeof(struct my_struct));
        s->ikey = ikey;
        HASH_ADD_INT(g_users, ikey, s);
    }
    strcpy(s->value, value_buf);
}

void delete_user_by_ikey(int ikey)
{
    struct my_struct *s = NULL;
    HASH_FIND_INT(g_users, &ikey, s);
    if (s != NULL)
    {
        HASH_DEL(g_users, s);
        free(s);
    }
}

void delete_user(struct my_struct *user)
{
    HASH_DEL(g_users, user);
    free(user);
}
/*
    清空hash表
*/
void delete_all()
{
    struct my_struct *current_user, *tmp;

    HASH_ITER(hh, g_users, current_user, tmp)
    {
        HASH_DEL(g_users, current_user);
        free(current_user);
    }
}

void print_users()
{
    struct my_struct *s;

    for (s = g_users; s != NULL; s = (struct my_struct *)(s->hh.next))
    {
        printf("user ikey %d: value %s\n", s->ikey, s->value);
    }
}

int name_sort(struct my_struct *a, struct my_struct *b)
{
    return strcmp(a->value, b->value);
}

int id_sort(struct my_struct *a, struct my_struct *b)
{
    return (a->ikey - b->ikey);
}

void sort_by_name()
{
    HASH_SORT(g_users, name_sort);
}

void sort_by_id()
{
    HASH_SORT(g_users, id_sort);
}

int main(void)
{
    char in[10];
    int ikey = 1, running = 1;
    struct my_struct *s;
    unsigned num_users;

    while (running)
    {
        printf(" 1. add user\n");
        printf(" 2. add/rename user bu id\n");
        printf(" 3. find user\n");
        printf(" 4. delete user\n");
        printf(" 5. delete all users\n");
        printf(" 6. sort items by name\n");
        printf(" 7. sort items by id\n");
        printf(" 8. print users\n");
        printf(" 9. count users\n");
        printf(" 10. quit\n");
        gets(in);
        switch (atoi(in))
        {
        case 1:
            printf("name?\n");
            add_user(ikey++, gets(in));
            break;
        case 2:
            printf("id?\n");
            gets(in);
            ikey = atoi(in);
            printf("name?\n");
            add_user(ikey, gets(in));
            break;
        case 3:
            printf("id?\n");
            s = find_user(atoi(gets(in)));
            printf("user: %s\n", s ? s->value: "inknown");
            break;
        case 4:
            printf("id?\n");
            s = find_user(atoi(gets(in)));
            if (s) delete_user(s);
            else printf("id unknown\n");
            break;
        case 5:
            delete_all();
            break;
        case 6:
            sort_by_name();
            break;
        case 7:
            sort_by_id();
            break;
        case 8:
            print_users();
            break;
        case 9:
            num_users = HASH_COUNT(g_users);
            printf("there are %u users\n", num_users);
            break;
        case 10:
            running = 0;
            break;
        default:
            break;
        }
    }

    delete_all();
    return 0;
}
