
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("鳥人祭壇");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
這裡是鳥人族最重要的聖地，高高的矗立在天空之城的最頂點。你往下
一望，只看到無窮無盡的綠色薄霧，虛無飄緲的感覺讓你不禁有點腳軟。
LONG_DESCRIPTION
        );
        set( "jumped",0);
        set( "exits", ([
                "northwest" : HAWK"room3-7",
                     ]) );
        set( "objects",([
                "prayer" : MOB"god1" ]) );
	reset();
}//end of creat

void init()
{
        add_action("to_jump","jump");
}

int to_jump()
{
	int alig,lev;
        lev = (int)this_player()->query_level();
        alig = (int)this_player()->query("alignment");

	if (!present("valor amulet",this_player() ))
        {
                tell_object(this_player(),@LONG
一陣帶有濃厚血腥味的大風從祭壇邊吹起，頓時讓你打消了往下跳的念頭。
LONG
                );
                return 1;
        }

        if (lev < 17)
        {
                tell_object(this_player(),
                        "年紀輕輕不要太沖動，乖，不要亂跳嘛。\n" );
                return 1;
        }

	if (alig > 0)
	{
		this_player()->move_player(HAWK"square1","SNEAK");
		return 1;
	}
        else
        {
                this_player()->receive_damage(70);
                this_player()->move_player(HAWK"room1-18","SNEAK");
                return 1;
        }
        return 1;
}
