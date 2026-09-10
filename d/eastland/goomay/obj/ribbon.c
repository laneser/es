#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "pink ribbon", "粉紅色絲帶" );
	add( "id", ({ "ribbon","whip" }) );
	set_short( "粉紅色絲帶" );
	set_long(
		"這是一條粉紅色的長絲帶，看起來就像是一般女孩用來綁頭髮的絲帶。\n"
		 "但是卻充滿了一種奇特的魅力。\n"
	);
	set( "unit", "條" );
	set( "weight", 30 );
        set("nosecond",1);
	setup_weapon( "whip", 20, 9,18);
	set( "value", ({ 320, "silver" }) );
//        set( "hit_func", "charmed" );
	set( "wield_func","wield_ribbon");
        set_c_verbs(({"%s甩向%s","%s卷向%s","%s揮向%s"}));

}

void wield_ribbon()
{
object holder;
	holder=this_player();
		
       if ((string)holder->query("gender")!="female")
        {
        tell_room( environment(holder), 
         holder->query("c_name")+"想要學著女生扭扭捏捏地拿著粉紅色絲帶，真是笑死人。\n"
		, ({holder}) );
        tell_object( holder,
         "你想要學著女生用粉紅色絲帶，試了一陣以後，旁邊的人都笑的直不起腰來。\n");
	::unwield();
		return ;
	}
	else
	{
        tell_room( environment(holder), 
         holder->query("c_name")+"優雅地拿著粉紅色絲帶，顯得十分嬌媚。\n"
	, ({holder}) );
        tell_object( holder, 
         "你拿起粉紅色絲帶，覺得自己簡直是世界上最美麗的超級美女。\n");
		return;
	}
	return ;
}
int charmed(object victim)
{	
	object holder;
	holder=environment(this_object());
        if( random(holder->query_perm_stat("int")+
		   holder->query_perm_stat("str"))<25) return 0;
       if( victim->query("stop_attack") ) return 0;
	if ( (string)victim->query("gender")=="female" ) return 0; 

        tell_object( victim, 
          "粉紅絲帶散發出一種迷人的力量，你感到一陣暈眩 !!\n");
        tell_object( holder, 
          "\n你的粉紅絲帶散發出一種迷人的力量，敵人變的兩眼無神 !!\n\n");
        tell_room( environment(holder), 
          "\粉紅色絲帶的魅力，使" + victim->query("c_name") +"無法攻擊 !!\n\n"
	, ({ victim, this_object() }));
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack", 
          "( 你現在全身無力，沈醉在著片美麗的誘惑裡 ! )\n" 
        );
        return 1;

}
