// bandage.c
// Rewritten by Annihilator to fit the new recover system (09-21-94)
// add exp gain for healers by indra 11.30.94
#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
#include <compress_obj.h>
	set_name( "bandage", "繃帶" );
	set_short("繃帶" );
	set_long(
		"繃帶是一種常見的、用來使受傷的人加快恢復速度的醫藥用品，如果\n"
		"你學過傷口包紮的技能，就可以用 bandage 指令替自己或別人包紮。\n"
	);
	set( "unit", "條" );
	set( "weight", 5 );
	set( "value", ({ 15, "silver" }) );
}

void init()
{
	add_action("do_bandage", "bandage");
	add_action("do_remove", "remove" );
}

int do_bandage(string arg)
{
	object dest;
	int skill, pie;
	mixed *cond; 

	// The player must carry the bandage before he can bandage.
	if( environment()!=this_player() ) return 0;

	if( query("in_use") ) return notify_fail("這卷繃帶已經在使用中了。\n");
				
	if( !arg || arg=="me" || arg=="myself" ) dest = this_player();
	else dest = present( arg, environment(this_player()) );
	if( !dest )
		return notify_fail("你要包紮誰？\n");

	if( (int)dest->query_temp("bandaged") >= time()) {
		write("如果你要重新包紮，請先除去(remove)原來的繃帶。\n");
		return 1;
	}

	if( dest->query("hit_points")==dest->query("max_hp") ) {
		write("繃帶只能用來包紮受傷的人。\n");
		return 1;
	}
	
	// Ok, now do the bandage stuff.
	if( dest==this_player()) {
		write("你細心地為自己的傷口包上繃帶。\n");
		tell_room( environment(this_player()), 
			sprintf("%s用繃帶包紮自己的傷口。\n",this_player()->query("c_name")),
			this_player() );
	} else {
		write(sprintf("你細心地用繃帶替%s包紮傷口。\n",dest->query("c_name")));
		tell_object( dest,
			sprintf("%s用繃帶替你包紮傷口。\n",this_player()->query("c_name")));
		tell_room( environment(this_player()), 
			sprintf("%s用繃帶替%s包紮傷口。\n",this_player()->query("c_name"),dest->query("c_name")),
			({ dest, this_player() }) );
		move(dest);
	}
	
	skill = this_player()->query_skill("bandage");
	pie = dest->query_stat("pie");
	cond = dest->query("conditions/herb_apply");
	if( cond && sizeof(cond) ) {
		// speed up 減 0% 到 80%, when skill 0 到 100, by Kyoko/Annihilator.
		cond[0] -= cond[0] * skill * 8 / 1000;
		if( cond[0] < 1 ) cond[0] = 1;
		dest->set("conditions/herb_apply", cond);
	}
	BANDAGED->apply_effect(dest, 12-skill*84/1000);
	dest->set_temp("bandaged",time()+50+skill+3*pie);
	set( "in_use", 1 );
	set( "prevent_drop", 1 );
	set( "prevent_insert", 1 );
	set_short( "繃帶 (使用中)" );

        // add this part to exp gain for healers
        if((string)this_player()->query("class")=="healer")
             this_player()->gain_experience(skill/5) ;

	// The bandage falls down takes a longer time than its effect.
	call_out("expire", 50+skill+3*pie);
	return 1;
}

int do_remove(string arg)
{
	object ob;
	
	ob = environment(this_object());	
	// for fix the bug of user quit or suicide.
	if( ob && living(ob) ) {
		if( !id(arg) || !query("in_use") ) return 0;
		tell_object(ob,"你將繃帶拆下來丟掉。\n");
		ob->delete_temp("bandaged");
		BANDAGED->remove_effect(ob);
		// remove the herb apply effect.
//		if( ob->query("conditions/herb_apply") )
//			HERB_APPLY->remove_effect(ob);
	}
	remove_call_out("expire");
	remove();
	return 1;
}

void expire()
{
	object ob;
	
	ob = environment();
	if( !ob || !living(ob) ) {
		remove();
		return;
	}
	tell_object(ob,"你的繃帶被鮮血浸透了。\n");
	do_remove("bandage");
	return;
}
