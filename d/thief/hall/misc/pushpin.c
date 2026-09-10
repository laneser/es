// Created by Aquarius@EasternStory
#include "mudlib.h"
#define TIME 120 	// 120 秒後消失
inherit OBJECT;
int droped = 0;		// 是否已被灑在地上
int xx = 0;		// 這這.. 總之, 必要的 flag
int life=0;		// 這枚圖釘的有效期限
int dam=0;		// 所造成的傷害 , dam = skill/5;
object tricker;		// 放圖釘的人

void create()
{
     set_name("pushpin","圖釘");
     set_short("圖釘");
     set_long(@LONG
一把圖釘, 看起來不太起眼, 若是灑(spread)在地上, 不小心踩到的人
一定會痛的哇哇叫。
LONG
      );
     set( "unit", "把");
     set("weight",5);
     set("value", ({ 50, "silver" }));
}

void init()
{
    object who,mount_ob,*obs,env;
    int i;
    mapping exits;
    string dir,*dirs;

	// 正在對某人(騎馬)作用中, 另一個同時進這個房間的人不會被刺到 .
    if ( xx ) return ;

    if ( ! droped ) {
        add_action("do_spread","spread");
	return;
    }

    if ( life < time() ) {
	this_object()->remove();
	return ;
    }


    who = previous_object();
    env = environment(who);
    
    if( ! who || ! living(who) || who->query_temp("flying") ) 
	return ;

    if ( who == tricker && dam > random(23) ) {
	tell_object(who,"你小心的避開自己灑的圖釘。\n");
	return ;
    }


    if ( random(dam) > 18 ) 
	return ;

    if ( (mount_ob = who->query_temp("mounting")) ){
	xx=1;
    	tell_object(who,
		set_color("你的座騎突然一陣鳴嘶,人立起來,把你摔到地上!!\n","HIR",who));
	tell_room( environment(who),
		who->query("c_name") + "的座騎突然慘叫一聲, 把"+who->query("c_name")+"摔在地上.\n",who);
	who->block_attack(6);
	who->set_temp("msg_stop_attack","( 你被摔的痛死了, 爬不起來, 無法攻擊 )" );
//	call_other("/adm/daemons/mount","dismount",mount_ob,who);
	"/adm/daemons/mount"->dismount(mount_ob,who);
	// 笨比 .. 害我寫不出來 ...
//	mount_ob->set("moving",1);
//	mount_ob->set("speed",40);
	this_object()->remove();
    } else {
	xx = 1;
    	tell_object(who,
		set_color("你腳下一痛, 好像被什麼刺到了!!\n","HIR",who));
    	who->set_temp("msg_stop_attack","( 你的腳被釘住了, 動彈不得 )\n");
    	who->block_attack(4);
    	who->add("hit_points",-dam);
    	this_object()->remove();
    }
    return ;
}

int do_spread(string arg)
{
	object env,*inv;
	int skill,i,num;
	if ( ! arg || arg == "" || ! id(arg) )
		return 0;
	if ( (int)this_player()->query_skill("trick") < 5) {
		tell_object(this_player(),"你笨手笨腳的, 不小心刺到自己, 痛死了!!\n");
		this_player()->add("hit_points",-10);
		return 1;
	}
	env = environment(this_player());
	inv = all_inventory(env);
	for(num = 0,i=sizeof(inv)-1;i>=0;i--)
		if ( (string) inv[i]->query("name") == "pushpin" )
			num++;

	if ( num > 2 ) {
		tell_object(this_player(),"這裡滿地都是圖釘, 就別再灑啦。\n");
		return 1;
	}

	tell_object(this_player(),
		"你抓起一把圖釘, 偷偷的灑在地上。\n");
	if( (int) this_player()->query_temp("hide_score") < 100  &&
	    this_player()->query("player_invisible") != 1 )
		tell_room(environment(this_player()),
	          sprintf("%s有點鬼鬼祟祟的,不知道在做什麼。\n",this_player()->query("c_name")), this_player() );
	life = time()+TIME;
	this_object()->set("prevent_get",1);
	this_object()->set("player_invisible",1);
	this_object()->move(env);
	tricker=this_player();
	dam = (int) this_player()->query_skill("trick")/5;
	droped = 1;
   	remove_action("do_spread","spread");
	return 1;	
}

