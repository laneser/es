//butterfly's workroom

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        ::create() ;
        set("short", HIG "百花園" NOR);
        set("long", 

"這裡是"+BLINK HIM"蝴蝶"NOR"的工作室。你還沒有走進花園，花香就
已經撲面而來了。在花園擺放著各種各樣正在盛開的鮮
花，花園的正中長著一棵汁液茂盛而你叫不上名字的大
樹(tree)。在樹下襬放著一對石桌和石凳，石桌上放了
一朵"+HIR"玫瑰花"+NOR"(rose)和一個"+HIW"賀卡"+NOR"(letter)。\n"
  NOR
  );

        set("light",1);
        set("virtual_server",1);
        set("no_cast",1);
        set("no_enhant",1);
 
        set("exits", ([
                "thi" : "/d/thief/hall/thief_guild",
                "mon": "/d/monk/guild/monk_guild",
                "kni": "/d/knight/fortress/knight_guild",
                "mag": "/d/mage/tower/mage_guild",
                "hea": "/d/healer/building/healer_guild",   
                "guild" : "/d/wiz/wiz_hall",
                "sch": "/d/scholar/scholar/scholar_guild",
        ]));
        set( "objects", ([
                "zhu": "/u/b/bfly/butterfly"
        ]) );
 
set("item_desc", ([
                "rose" : HIR "這是一朵情人互贈很普通的紅玫瑰花。\n" NOR,
                "letter" : HIG "偷看別人的信不太好吧！\n" NOR,
                "tree" : CYN "不知道你能不能爬(climb)上去。\n" NOR
        ]));

        reset();

}

void init()
{
        add_action( "climb_tree", "climb" );
        add_action( "break_rose", "break" );
        add_action("to_search", "search");
}
int climb_tree( string arg )
{
        if( !arg || arg!="tree" )
                return notify_fail( "爬什麼？\n" );
                
        this_player()->move_player( "/u/b/bfly/tree", "SNEAK" );
 write( "你爬到樹上。\n");

        tell_room( this_object(), 
                this_player()->query("c_name") + "爬到樹上。\n",
                this_player() );
        return 1;
}
int break_rose( string arg )
{
       object rose;
        rose = new(__DIR__"rose");
        if( !arg || arg!= "rose" )
                return notify_fail( "你想幹什麼？\n" );
           rose->move(this_player());
  write(              
"你從花園中摘下一朵"+HIR"紅玫瑰"NOR"。\n");
       tell_room( this_object(), 
  this_player()->query("c_name") + "從花園中摘下一朵"+HIR"紅玫瑰"NOR"。\n",
                this_player() );
        return 1;

}
int to_search(string arg)
{
    object o;

    write("突然你發現在花叢有一個"+HIY"手絹"NOR"！\n");
    o = new("/u/b/bfly/paper");
    o->move(this_object());
    return 1;
}
