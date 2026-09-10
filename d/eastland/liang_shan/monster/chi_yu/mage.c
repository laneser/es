#include <mudlib.h>

inherit "/d/eastland/liang_shan/monster/chi_yu_group";

void create()
{
	object ob1, ob2;

	::create();
	set_level(16);
	set_name( "snaky Magician", "蛇人法師" );
	add( "id", ({ "magician" }) );
	set_short( "蛇人法師" );
	set_long(@C_LONG
蛇人其實可以說是沒有腳的蜥蜴人，雖沒有蜥蜴人那麼強壯
但是卻有遠高於他們的智慧。因此蛇人常常也是有力的施法
者，而蛇人法師更是其中的佼佼者。	
C_LONG	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -800 );
	set( "hit_points", 350 );
	set( "max_hp", 350 );
        set("stun_difficulty",33) ;
        set("aim_difficulty",
        ([ "critical":40, "vascular":10, "weakest":25, "ganglion":3 ]));
	
	set_natural_armor(20,24);
	set_natural_weapon(10,10,15);
	set( "wealth/silver", 600 );
	set( "tactic_func", "my_tactic" );
	set("chi_yu_group",1);
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 28 );
	set("guild_levels/black-magic",40) ;
	set("guild_levels/guild",40);
	set_skill("target",100);
	set_skill("black-magic",100);
	set_skill("concentrate",100);
	set_skill( "wand", 80 );
	set_skill( "dodge", 90 );
	set("magic_delay",2);
	set("spells/flare",1);
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"[1m蛇人法師大叫: 你們這些愚蠢無知的卑微生物，通通給我下地獄去吧！[0m\n",
		"[1m蛇人法師對你說道: 先回去叫你的同伴幫你準備後事再進來吧！[0m\n",
		"[1m蛇人法師高舉手中的蛇眼石之杖，似乎正在吸取天地間遊離的能量...[0m\n"
	}) );
        wield_weapon( "/d/noden/drow/obj/wand" );
//        equip_armor( "/d/noden/drow/arm/a10" );
//        equip_armor( "/d/noden/drow/arm/a14" );
        equip_armor( "/d/noden/drow/arm/ring" );
}

int my_tactic()
{
	object victim;
	string name;
        
        if ( (int)this_object()->query("spell_points")< 100 )
        this_object()->add("spell_points",200);
        
        if ( !victim = query_attacker()) return 0;
	
	if( random(20)<4 ) {
        name=victim->query("name");
        command("cast flare on "+name);
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
         "蛇人法師(magician)說道: 敵人已經逃走了，快來幫我治療吧.....\n",this_object());
         return ;
         }        



}        
