#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("禁地");
	set_long(@LONG
你來到了一處神秘的禁地，四周圍不時傳來一些細微的聲音，那聲音是你從來
沒聽過的語言，其發音古怪已極！禁地中，你還可以看到一些栩栩如生的雕像，雕
像的模像極其兇惡，令你感到畏懼，一陣陣的寒意由然而生！據說，這裡曾被施以
咒語，許多到過這裡探險的人，十之八九都遭遇到不測，不曉是否因為那咒語的關
系，所以，你還可以在地上看到許多骷髏頭，你想想還是快離開這裡吧，俗話說的
好：「寧可信其有不可信其無。」說不定，待會兒你的□體會在這裡被別人發現！
LONG
	);
        set( "exit_suppress", ({
            "nd","su"}) );
	set("exits", ([
              "southup" : SAREA"hole2",
            "northdown" : SAREA"spell2",
                   "su" : SAREA"hole2",
                   "nd" : SAREA"spell2"
        ]) );
	set("light",1);
	reset();
}
void init()
{
    int i;
    object player,*all;
    add_action("do_cant","get");
    add_action("do_cant","auction");
    player=this_player();
    if ( !player->query_temp("can_pass_spell") ) {
       write("\n這禁地的咒語，讓你感到天旋地轉一陣昏眩！\n\n");
       player->add("hit_points",-30);
       all=all_inventory(player);
       for (i=0;i<sizeof(all);i++) {
          if ( all[i]->query("max_load") ) all[i]->set("need_drop",1);
          else if ( all[i]->query("defense_bonus")||
                    all[i]->query("armor_class") ) all[i]->set("need_drop",1);
          else if ( all[i]->query("weapon_class") ) all[i]->set("need_drop",1);
          else if ( !(all[i]->query("prevent_get")||
                      all[i]->query("prevent_drop")) ) all[i]->set("need_drop",1);
          if ( all[i]->query("need_drop") ) {
             all[i]->move(SAREA"temp_room1");
             if (all[i]->query("name")!="magic cube") all[i]->remove();
          }
       }    
    }
}
int do_cant(string arg)
{
    write("正當你想要做這動作，忽然頭感到一陣劇痛，令你無法控制你的行動！！\n");
    return 1;
}