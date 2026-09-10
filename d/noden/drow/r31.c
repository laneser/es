#include "iigima.h"

inherit ROOM;


int stone = 1;
void create()
{

        ::create();
        set_short( "snake temple","大蛇神殿");
        set_long(

@C_LONG
哇～穿過引道竟然有這麼大的神殿，咦？怎麼所有的石像，毀損
的毀損，破裂的破裂，東倒西歪的石像隨意地置放著，四周隨時傳來
刺耳的怪叫聲，不知道是什麼生物的聲音，一陣寒意由你心頭竄來，
剛剛的勇氣似乎已經被恐懼所淹沒了，滿地都是駭骨以及噁心的蛇皮
，你的勇氣已經受到考驗！
C_LONG
        );

        set( "light",0 );
        set( "exits", ([
                     "west": DROW"r30",
        ]) );
        set("objects", ([
                "snake": DRO"s8",      
        ]) );
        set( "search_desc", ([ "skin" : "@@search_skin" ]) );
        reset();
}
string search_skin()
{
        object obj;
        if( !stone || present("stone", this_object()) ) return
                "你把乾扁蛇皮一張張翻來找去，但沒有發現任何東西。\n";
   if( present("eight tail snake",this_object()) )
   return "八岐大蛇正在攻擊你! 你手忙腳亂無法搜尋!\n";
        obj = new( OBJ "stone" );
        obj->move( this_object() );
        stone = 0;
        return "你在蛇皮當中發現了一顆閃爍著藍光的石頭。\n";
}
