#include <mudlib.h>
#define MAXHEAL 300
#define NAME(x) (string)x->query("name")
#define LEADER(x) (string)x->query_temp("leader")
#define CNAME(x) (string)x->query("c_name")

inherit OBJECT;

void create()
{
        set_name("life ball", "兜率彌陀珠");
        add("id", ({ "ball" }) );        
        set_short(set_color("兜率彌陀珠","HIY"));
        set_long( @LONG
相傳這是紫清玉府太虛宮中，乾靈燈上所結的燈花，被幾位謫降的天仙，帶臨
凡世，仗以御邪防身。先後共七朵，威力大小均不同。那些謫降的仙人大概也
沒想到其中一顆乾靈神□居然造就出莽牯朱蛤這毒物。
LONG
        );
        set( "light",3); 
        set( "times_left",5);
        set( "unit", "顆" );
        set( "weight", 10 );
}

void init()
{
  add_action("do_heal_all", "use_lifeball");
}

int who_in_party(object obj, string me)
{
     if( !living(obj) ) return 0;
     if( LEADER(obj)!= me ) return 0;
     return 1;
}

int do_heal_all()
{
    int i, times;
    object *part, me;
    
    me = this_player();
    if (this_object()->query("times_left")<1) {
      tell_object(me,"兜率彌陀珠的光澤慢慢黯了下來並且消失了。\n");
      this_object()->remove();   
      return 1;
    }
    tell_object(me,@LONG

你高捧著兜率彌陀珠對天祈求......

一片五色祥雲由遠方飄來, 雲際金光四射, 罩住了你
LONG); 
    tell_room(environment(me),sprintf(
        "\n一片五色祥雲由遠方飄來, 雲際金光四射, 罩住了%s...\n",me->query("c_name")),me);
    if (!LEADER(me)||LEADER(me)!=NAME(me)) {
      tell_object(me,
        set_color("你覺得神清氣爽, 渾身無一處不暢快！\n","HIB"));
      this_player()->receive_healing(MAXHEAL);    
      this_object()->add("times_left",-1);        
      return 1;
    }
    part=filter_array(all_inventory(environment(this_player())),
                       "who_in_party",this_object(),NAME(this_player()));
    i=sizeof(part);
    while(i--) {
      tell_object(part[i],
        set_color("你覺得神清氣爽, 渾身無一處不暢快！\n","HIB"));    
      part[i]->receive_healing(MAXHEAL);
    } 
    this_object()->add("times_left",-1);                  
    return 1;
}
