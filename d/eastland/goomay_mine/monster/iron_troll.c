#include "../zeus.h"

inherit MONSTER;

void create()
{       int wine; 
	object ob1, ob2;

	::create();
	set_level(20);
	set_name( "steely troll", "鋼鐵巨人" );
	add( "id", ({ "troll" }) );
	set_short( "a steely troll", "鋼鐵巨人" );
	set_long(@LONG
你彷佛看見一座山矗立在你面前，他的全身佈滿了鋼甲．他是段家特地
聘來看守儲藏室的．他曾經到過少林寺學武，擅長般若掌，目前沒有人
知道他的缺點．可是他對所有來這裡的人都用一種敵視的眼光，連段家
的人也不例外，事情似乎不太尋常，找人問問看吧！
LONG
);
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "kar", 30 );
	set_perm_stat( "int", 30 );
	set_skill( "unarmed", 100);
	set_skill( "parry", 100);     
	set_natural_armor( 120, 60 );
	set_natural_weapon( 70, 30, 70 );
	set( "time_to_heal", 6 );
          set("attack_skill","monk/general/bolo_fist");
          set("monk_gonfu/bolo-fist",25);
	set( "max_hp", 1500 );
	set( "max_fp",600);
	set( "force_effect",2);
	set( "force_points",600);
	set( "hit_points", 1500 );
	set( "gender", "male" );
	set( "alignment",-500 );
	set( "wealth/gold", 100 );
	set( "wine",0);
}  
int accept_item(object me,object item)
{       int wine; 
        if ((string)item->query("name")!="da chu"){
	tell_object(me,
	"巨人道：想賄酪我嗎？．．．．可是我不喜歡這東西，換點新花樣吧！\n\n"
	"說著巨人就把東西丟下了．\n",
	);
        command("drop all");
        return 1;
        }
        if(query("wine"))
        {
        tell_room(environment(this_object()),
        "巨人拿起酒來如灌水般將酒倒進嘴裡，道一聲：好酒！！\n"
        "然後腳步蹣跚地走到河邊，噗！一聲！倒了下去．\n\n"
        "你看見一把藥丸從巨人的口袋中掉出來，滾啊滾到河裡去了．\n\n"
                  );
        item->remove();
        set_short("醉倒的巨人");
        set_name("troll","酒醉的巨人");
        set_natural_armor(100,40);
        set("monk_gonfu/bolo-fist",20);
        return 1;
        }else{ 
        tell_room(environment(this_object()),
	"巨人拿起酒來如巨鯨吸水般將所有的酒吸乾，然後擦擦嘴巴意猶未盡\n\n"
	"道：還有沒有呢？快拿來孝敬大哥吧！\n\n"
	);
	item->remove();
        set("wine",1);
      	return 1;
               }
}
void die()
{       object killer,obj;
        int wine;
 	if (query("wine")){
 	killer=query("last_attacker");
 	killer->set_temp("get_magnetite",1);
 	tell_room(environment(this_object()),
 	"巨人以懺悔的聲音道：四處找找吧，我已經把你要的東西．藏起來了！\n",
 	this_object());
 	set("exp_reward",36000);
 	::die(1);
 	}else{
 	tell_room(environment(this_object()),
 		"巨人大叫道：你想打敗我嗎？別傻了孩子！\n"
 		"突然巨人從口袋裡抓出一把藥丸往嘴裡一塞．\n\n"
 		"又一個生龍活虎的鋼鐵巨人．\n",
 		this_object());
 	set ("exp_reward",10); 
 	set ("alt_corpse",ZMOB"/iron_troll.c");
 	::die(1);
 	}
 	}