#include "minishell.h"

static void give_place(t_src *data)
{
    t_env *chek_place;
    t_env *grup;
    int len;
    int campeyer;

    data->env->place = 0;
    chek_place = data->env;
    grup = data->env;
    int i = 0;

    while (chek_place)
    {
        len = ft_strlen(chek_place->key);
        while (grup->next)
        {
            campeyer = ft_strncmp(chek_place->key, grup->key, len);
            if (campeyer >= 0)
                chek_place->place++;
            grup = grup->next;
        }
        grup = data->env;
        chek_place->flag_p = 0;
        // printf("%d\n",chek_place->place);
        chek_place = chek_place->next;
    }
}
void print_export(t_src *data)
{
    int go_on;
    t_env *grup;
    int big;
    char c;

    c = '"';
    big = 0;
    go_on = 1;

    give_place(data);
    grup = data->env;
    while (grup->next)
    {
        if (big < grup->place)
            big = grup->place;
        grup = grup->next;
    }
    grup = data->env;

    while (big >= 0)
    {
        grup = data->env;
        while (grup)
        {
            if (big <= grup->place && grup->flag_p == 0)
            {
                printf("%s=%c%s%c\n", grup->key, c, grup->value, c);
                grup->flag_p = 1;
                big--;
            }
            grup = grup->next;
        }
    }
}
