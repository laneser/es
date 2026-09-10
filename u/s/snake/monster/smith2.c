#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 3 );
        set_name( "smith", "鐵匠" );
        set_short( "老鐵匠" );
        set( "gender", "male" );
        set( "race", "dwarf" );
        set_natural_weapon( 4, 2, 2 );
        set_natural_armor( 30, 10 );
}


int accept_item(object who,object item)
{
     tell_room( environment(), 
            sprintf("老鐵匠向%s(%s)點頭微笑，說道: 謝謝！\n",
                who->query("c_name"),who->query("name") )
                ,who );
        tell_object( who,"老鐵匠向你點頭微笑，說道: 謝謝！\n");
                tell_object( who, 
                        "[你完成了 Smith 任務，得到 1000 點經驗]\n"
                        );
                who->gain_experience(10000);
                }


