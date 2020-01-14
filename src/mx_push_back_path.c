#include "pathfinder.h"

void mx_push_back_path(t_allpaths **paths, int c, int *route, int *d) {
    t_allpaths *tmp;
    t_allpaths *p;

    if (!paths || !c || !route || !d)
        return;
    tmp = mx_create_path(c, route, d);
    if (!tmp)
        return;
    p = *paths;
    if (*paths == NULL) {
        *paths = tmp;
        return;
    }
    else {
        while (p->next != NULL)
            p = p->next;
        p->next = tmp;
    }

}
