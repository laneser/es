#include <mumar.h>
inherit ROOM;
 
int daoist = 1;
void create()
{
        ::create();
        set_short("牧馬關南城門");
        set_long( @C_LONG_DESCRIPTION
你現在來到一座雄偉的關門口，城門上刻著三個雄偉的大字「牧馬關」。這裡
是東方大國防守北方的重要據點，因此派駐了重兵防守，所有來自關外的旅客都要
在這裡接受盤查才能通過。城門口兩尊巨大的武神雕像威風凜凜地守護著這座大城
。城門外的荒野中埋著不少古時候戰死的枯骨，據說在晚上常常有人聽到殺伐聲與
戰鼓聲。
C_LONG_DESCRIPTION
        );
 
        set_outside( "eastland" );
        set( "exits", ([
                "north" : MUMAR"road1",
                "south" : "/d/eastland/12,1.east" ]) );
set( "search_desc", ([ "here" : "@@search_here" ]) );
        reset();
}
string search_here()
{
        object obj;
        if( !daoist || present("daoist", this_object()) ) return
                "你幾乎把這兒的地給翻過來了，但沒有發現任何東西。\n";
        obj = new( MOB"daoist" );
        obj->move( this_object() );
        daoist = 0;
        return "你在四周的草叢中找著找著，忽然被一隻腳絆了一跤...\n"; }
