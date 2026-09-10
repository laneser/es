#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat_me" );
}

void create()
{
        
	set_name("Bear Palm","『清蒸熊掌』");
	add( "id" , ({ "palm","bear palm" }) );
        set_short(set_color("『清蒸熊掌』","CYN"));
        set_long(@C_LONG
難得一見的佳餚，讓你不禁垂涎欲滴，食指大動(eat_me palm)。
C_LONG
	);
   	set("unit","盤");
   	set("weight", 50);
   	set("value",({ 800, "gold" }) );
}

int eat_food(string arg)
{
        
    if( !arg || ( arg != "palm") )
        return notify_fail("你要吃啥東東?\n");
    this_player()->add_temp("drink_nest_times",1);
    if( this_player()->query_temp("drink_nest_times")>5 ) {
       tell_object(this_player(),
         "喲呀，你吃下了這一隻"+set_color("『清蒸熊掌』","CYN")+"之後居然開始"+
         set_color("流鼻血","HIR")+"，看來是補過頭了～～\n");
       tell_room( environment(this_player()),"喲呀，"+
         this_player()->query("c_name")+
         "吃下一隻"+set_color("『清蒸熊掌』","CYN")+"之後居然開始"+set_color("流鼻血","HIR")+
         "，看來是補過頭了～～\n",
         this_player());
       this_player()->delete_temp("drink_nest_times");
       BLEEDING->apply_effect(this_player(),20,1);    
       remove();
       return 1;
    }
    tell_room( environment(this_player()),"你站在旁邊流口水地看著"+
        this_player()->query("c_name")+"吃下一隻"+set_color("『清蒸熊掌』","CYN")+"～～\n", 
         this_player());
    tell_object( this_player(),
        "你滿足地吃下一隻"+set_color("『清蒸熊掌』","CYN")+"。嗯，好吃～～\n");
    this_player()->set("hit_points",this_player()->query("max_hp") );
    this_player()->set("force_points",this_player()->query("max_fp") );
    remove();
    return 1;
}
