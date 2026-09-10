
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("長老室");
        set("light",1);
        set_long( @LONG_DESCRIPTION
這裡是鳥人族長老辦公休息的地方，牆上掛著許多稀奇古怪的東西，
都是鳥人長老年輕時在外遊歷所得到的戰利品。金色的光線把整個房間照
的有如白晝一般，但是你卻無法感覺出光線的來源究竟是哪兒。
LONG_DESCRIPTION
        );
        set( "objects", ([
                "elder" : MOB"small_elder",
                "guard1" : MOB"guard",
                "guard2" : MOB"guard",
                        ]) );

        set( "exits", ([
                "south" : HAWK"room3-1",
                     ]) );
        set("pre_exit_func",(["south" : "go_south" ]) ) ;
        reset();
}//end of creat

int go_south()
{
        object caster;
        int aa;

        caster = present("elder");
        if (!caster) return 0;
        aa = (int)caster->query_temp("no_way_out");

        if (aa)
        {
                write("四周冰雪遮住了你的視線讓你沒辦法離開這裡。\n");
                return 1;
        }
        return 0;
}
