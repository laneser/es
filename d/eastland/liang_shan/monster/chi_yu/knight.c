#include <mudlib.h>

inherit "/d/eastland/liang_shan/monster/chi_yu_group";

void create()
{

	::create();
	set_level(17);
	set_name( "snaky warrior", "蛇人戰士" );
	add( "id", ({ "warrior" }) );
	set_short( "蛇人戰士" );
	set_long(@C_LONG
蛇人其實可以說是沒有腳的蜥蜴人，雖沒有蜥蜴人那麼強壯
但是卻有遠高於他們的智慧。儘管如此，經過嚴格訓練的蛇
人還是可以成為勇猛的戰士，並且能夠自由使用許多不同的
戰術。
C_LONG	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -500 );
	set_natural_weapon(20,15,15);
	set_natural_armor(20,20);
	set( "special_defense", ([ "all": 20,"none":10 ]) );
        
        set("aim_difficulty",
        ([ "critical":25, "vascular":20, "weakest":35, "ganglion":5 ]));

	set("chi_yu_group",1);
	set( "wealth/silver", 250 );
	set_perm_stat( "str", 24 );
	set_perm_stat( "dex", 24 );
	set( "aiming_loc", "weakest" );
	set_skill( "anatomlogy",60 );
	set_skill( "longblade", 90 );
	set_skill( "parry", 80 );
	set_skill( "block",85 );
	set("tactic","berserk");
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"[1m蛇人戰士大叫: 蚩尤大王就快過來了，大家快把垃圾清乾淨！[0m\n",
		"[1m蛇人戰士說道: 丟下武器，不要做無謂的抵抗！[0m\n",
		"[1m蛇人戰士喝道: 黃鐘譭棄，瓦釜雷鳴，你們的英雄都到那去了！[0m\n"
	}) );

        wield_weapon( "/d/deathland/weapon/sword03" );
//        equip_armor( "/d/noden/drow/arm/a18" );
  //      equip_armor( "/d/noden/drow/arm/a10" );
    //    equip_armor( "/d/noden/drow/arm/a14" );
}

int my_tactic()
{
	object victim;
        
        if ( !victim = query_attacker()) return 0;
	
	if( random(20)<3 ) {
        tell_object(victim,set_color( "說時遲，那時快，蛇人戰士用他長長的尾巴向你下盤掃去，你一個\n"
        "不小心，被他打翻在地上。\n","HIM",victim));
        tell_room(environment(this_object()),set_color("說時遲，那時快，蛇人戰士用他長長的尾巴向"
        +victim->query("c_name")+"的下盤掃去，將他打倒在地。\n","HIM",victim),victim);
        victim->block_attack(3);
        victim->set_temp("msg_stop_attack", "\n（ 你現在摔倒在地無法動彈 ）\n\n");
        victim->receive_damage(5);
        return 1;
	} else return 0;
}

void relay_message(string class, string str)
{
        int i,hitp,hp1,hp2;
        string name,direction,tmp,guild;
        object victim,mob,env,*who,bandage;
        mixed bandaged,bleed;
        ::relay_message(class,str);
        
        
        if( !str || str == "" ) return;
        if( sscanf(str,"%s(%s)走了過來。", tmp,name)==2 ) {
        name = lower_case(name);
        victim = present(name, environment(this_object()));
        if( !victim || victim->query("npc") || victim->query("no_attack")) return ;
        
        if( victim->query_level() > 5 && !victim->query("ghost") && victim->query("alignment") >100 ) {  
        
        if( !pointerp(attackers) || member_array(victim, attackers)==-1 ) {
        
        tell_object(victim,query("c_name")+"叫道 : 通通去死吧，同時不懷好意的往你這裡衝過來....\n");
         kill_ob(victim);
         } } }
        if( sscanf(str,"%s往%s離開。", tmp,direction)==2) {
        if ( query_attacker() ) return ;
        hp1 = query("max_hp")/2;
        hitp = query("hit_points");
        if ( bleed = query("conditions/bleeding") || hitp < hp1  )        
        tell_room(environment(this_object()),
        "蛇人戰士(warrior)說道: 敵人已經逃走了，快來幫我治療吧.....\n",this_object());
        return ;
        }  
}        
 