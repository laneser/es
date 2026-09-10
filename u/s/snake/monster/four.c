#include "../healer.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(13);
        set_name( "four", "四谷" );
        add( "id", ({ "four" }) );
        set_short( "四谷" );
        set_long(
         "他是一位神秘悉悉, 西裝筆挺的人, 從他緊鎖的眉宇, 冷冷的目光中\n"
         "好象你全身都給他看透了!\n"
        );
        seteuid(getuid());
        set( "alignment", -1000 );
        set( "race", "human" );
        set( "gender", "male" );
        set( "pursuing", 1 );
        set( "chat_chance", 40 );
        set("chat_output",({
             "四穀神秘悉悉地對你『嘿嘿嘿』地笑了笑。\n",
             "四穀神秘悉悉地靠過你的耳邊，悄聲說道：秘密。\n",
             "四谷一手把你手上的的酒給搶了過去“咕嚕咕嚕”地喝個清光。\n"
         }) );

}

