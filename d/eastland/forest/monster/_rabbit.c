#include "../forest.h"

void create (object ob)
{
		if ( !ob ) return ;
       ob->set_level(1);
       ob->set_name( "rabbit", "兔子" );
       ob->set_short("兔子");
       ob->set("unit","只");
       ob->set_long(@C_LONG
你看見一隻可愛的動物，正在草原上輕快的跳躍著，他有著一雙
長長的耳朵及兩隻突出的門牙，此刻它正望著你，無辜的表情好像是
俏皮的精靈般地令人又疼又愛。
C_LONG
                        );
       ob->set_perm_stat("dex", 3);
       ob->set_natural_weapon(3,0,0);
       ob->set_natural_armor(5,0);
       ob->set_c_verbs(({"%s用它的後腿向%s踢去"}));
       ob->set_c_limbs(({"身體","耳朵","腳部","頭部"}));
}
