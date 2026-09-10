#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("偏殿");
    set_long(@LONG
這兒是偏殿，也是阿重霞公主的寢宮。來到此處，只聞滿室清香，四處
整理的一塵不染；不過，令你驚訝的是，在此處看不到任何的女工，反倒是
刀、劍，或刀譜、劍譜之類的東西分別放在你的左右，你對阿重霞公主有何
種的印象呢？
LONG
             );
    set("exits",([
        "south":CITY"inhouse2"]) );
    set("light",1);
    set("objects",([
        "aiga":TMOB"aiga"]) );
    reset();
}

void init()
{
    add_action("prevent_quit","quit");
}

int prevent_quit()
{
   object who;
   who = this_player();
   
   if( !who->query_temp("luoky_killer") ) return 0; 
    tell_object(who,"阿重霞奸笑道：殺了人家的寵物，想逃到那去？\n");
    tell_room( environment(who),
    who->query("c_name")+" 居然想畏罪潛逃，但被阿重霞阻止了！！\n"
    ,who );
    return 1;
}
