// This is the combat controller daemon seperated from /std/body/attack.c
// Call report_combat to report an attack.
// By Annihilator 10/15/93

#include <daemons.h>
#include <martial.h>
#include <attack.h>

// The default database of verb messages

mapping c_dflt_verbs = ([
	"unarmed": ({
		"%s對準%s一記直拳", "%s猛踹%s一腿", "%s揮拳攻擊%s", "%s伸手抓向%s" }),
	"longblade": ({
		"用%s斜砍%s", "的%s刺向%s", "%s一揮，斬向%s", "揮動%s，往%s削去" }),
	"shortblade": ({
		"用%s斜砍%s", "的%s刺向%s", "倒握%s，順勢往%s一刺", "的%s對準%s，筆直刺出" }),
	"dagger": ({
		"緊握%s，往%s狠狠一戳", "倒握%s，順勢往%s一刺", "的%s對準%s，筆直刺出",
		"%s白光一閃，從近距離猛刺%s" }),
	"thrusting": ({
		"%s對準%s閃電般的一刺", "回過%s，直直戳向%s", "%s刺向%s",
		"用%s斜刺%s" }),
	"blunt": ({
		"舉起%s，瞄準%s當頭砸下", "的%s往%s揮去", "的%s重重地往%s　去", "的%s掃過%s" }),
	"axe": ({
		"的%s往%s猛劈", "揮舞%s，砍向%s", "的%s對準%s用力一劈", "的%s夾著一道勁風斬向%s",
		"高舉%s，往%s砍落" }),
	"polearm": ({
		"揮動%s，往%s掃過", "將%s對準%s往前直刺", "%s一揮，砍向%s", "雙手揮舞著%s，往%s橫掃過去" }),
	"wand": ({
		"舉起%s，揮向%s", "的%s往%s一揮", "用%s往%s一點", "的%s掃過%s" }),
	"chain": ({
		"甩動%s，擊向%s", "用%s往%s用力　去", "的%s掃過%s" }),
	"whip": ({
		"甩動%s，卷向%s", "舞動%s往%s一掃", "用%s直直地擊向%s" }),
	"jousting": ({
		"%s對準%s閃電般的一刺", "的%s直直戳向%s", "%s刺向%s",
		"用%s斜刺%s" }),
]);

// The default database of limb messages

string *c_dflt_limbs = ({
	"門面", "左臂", "右臂", "前胸", "左腿", "右腿", "左肩", "右肩",
	"後心", "小腹" });

// These parameter are used by many functions and are declared here to 
// save time on passing parameter.
string c_name, c_vname, c_weap_name,c_verb,c_limb;
int dam;

// These strings are handled by many functions, declared here to save time
// on passing parameter
string c_msg_attacker, c_msg_defender, c_msg_others;

// Ok, these are the message generators
 generate_action_message()
{
	c_msg_attacker	= sprintf("%s"+c_verb, "你", c_weap_name, c_vname + c_limb);
	c_msg_defender	= sprintf("%s"+c_verb, c_name, c_weap_name, "你" + c_limb);
	c_msg_others 	= sprintf("%s"+c_verb, c_name, c_weap_name, c_vname + c_limb);
}

 generate_miss_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是沒中.　\n";
		c_msg_defender	+= "，但是沒中.　\n";
		c_msg_others 	+= "，但是沒中.　\n";
	} else {
		c_msg_attacker	+= "沒打中.\n";
		c_msg_defender	+= "沒打中.　\n";
		c_msg_others 	+= "沒打中.　\n";
	}
}

 generate_parry_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是被對方格開了.　\n";
		c_msg_defender	+= "，但是被你格開了.　\n";
		c_msg_others 	+= "，但是被"+c_vname+"格開了.　\n";
	} else {
		c_msg_attacker	+= "被對方格開了.　\n";
		c_msg_defender	+= "被你格開了.　\n";
		c_msg_others 	+= "被"+c_vname+"格開了.　\n";
	}
}

 generate_unarmed_parry_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是被對方用手格開.　\n";
		c_msg_defender	+= "，但是被你用手格開.　\n";
		c_msg_others 	+= "，但是被"+c_vname+"用手格開.　\n";
	} else {
		c_msg_attacker	+= "被對方用手格開.　\n";
		c_msg_defender	+= "被你用手格開.　\n";
		c_msg_others 	+= "被"+c_vname+"用手格開.　\n";
	}
}

 generate_dodge_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是被對方躲開了.　\n";
		c_msg_defender	+= "，但是被你躲開了.　\n";
		c_msg_others 	+= "，但是被"+c_vname+"躲開了.　\n";
	} else {
		c_msg_attacker	+= "被對方躲開了.　\n";
		c_msg_defender	+= "被你躲開了.　\n";
		c_msg_others 	+= "被"+c_vname+"躲開了.　\n";
	}
}

 generate_block_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是被對方用盾擋開.　\n";
		c_msg_defender	+= "，但是被你用盾擋開.　\n";
		c_msg_others 	+= "，但是被"+c_vname+"用盾擋開.　\n";
	} else {
		c_msg_attacker	+= "被對方用盾擋開.　\n";
		c_msg_defender	+= "被你用盾擋開.　\n";
		c_msg_others 	+= "被"+c_vname+"用盾擋開.　\n";
	}
}

 generate_no_penetrate_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是沒有造成任何傷害.　\n";
		c_msg_defender	+= "，但是沒有造成任何傷害.　\n";
		c_msg_others	+= "，但是沒有造成任何傷害.　\n";
	} else {
		c_msg_attacker	+= "沒有造成任何的傷害.　\n";
		c_msg_defender	+= "沒有造成任何的傷害.　\n";
		c_msg_others	+= "沒有造成任何的傷害.　\n";
	}
}

 generate_hit_message(int defend)
{
	string c_dmsg;

	if( !defend ) c_dmsg = "，";
	else c_dmsg = "";
	if( dam < 3 ) {
		if( !defend ) c_dmsg += "但是只從旁邊擦過.　\n";
		else c_dmsg += "只是從旁邊擦過.　\n";
	} else if( dam < 6 ) {
		c_dmsg += "造成輕微的傷害.　\n";
	} else if( dam < 10 ) {
		c_dmsg += "造成一些傷害.　\n";
	} else if( dam < 15 ) {
		c_dmsg += "造成不少傷害.　\n";
	} else if( dam < 20 ) {
		c_dmsg += "造成嚴重的傷害.　\n";
	} else if( dam < 27 ) {
		c_dmsg += "造成頗為嚴重的傷害.　\n";
	} else if( dam < 35 ) {
		c_dmsg += "造成相當嚴重的傷害.　\n";
	} else if( dam < 45 ) {
		c_dmsg += "造成十分嚴重的傷害.　\n";
	} else if( dam < 60 ) {
		c_dmsg += "造成非常嚴重的傷害.　\n";
	} else {
		c_dmsg += "造成極其嚴重的傷害.　\n";
	}
	c_msg_attacker	+= c_dmsg;
	c_msg_defender	+= c_dmsg;
	c_msg_others	+= c_dmsg;
}

// This is the 
varargs void report_combat(object attacker, object defender, int damage, object weapon)
{
	int i, defend;
	string msg, func,weap_type;
	object *obs;
	//add by ca
/*	string dd;
	damage=damage+random(100);
dd="damage="+ damage +"\n";
write(dd);*/
//end add 
	c_name = attacker->query("c_name");
	c_vname = defender->query("c_name");
	
	if( weapon ) c_weap_name = weapon->query("c_name");
	else c_weap_name = "";

	c_verb = (string)attacker->get_c_verb();

	if( !c_verb ) {
		if( !weapon || !(weap_type = weapon->query("type")) || undefinedp(c_dflt_verbs[weap_type]) )
			weap_type = "unarmed";

		if( !c_verb )
			c_verb = c_dflt_verbs[weap_type][ random(sizeof(c_dflt_verbs[weap_type]))];
	}

	c_limb = defender->get_c_limb();
	if( !c_limb ) c_limb = c_dflt_limbs[random(sizeof(c_dflt_limbs))];
	dam = damage;

	// Deceide how the hit looks like.
	generate_action_message();
	defend = 0;
	if( func = (string)defender->query("defense_skill") ) {
		msg = DEFENSE_SKILL(func)->query_defense_msg(defender, attacker);
		if( msg ) {
			c_msg_attacker	+= sprintf("，而"+msg+"，結果", c_vname);
			c_msg_defender	+= sprintf("，而"+msg+"，結果", "你");
			c_msg_others 	+= sprintf("，而"+msg+"，結果", c_vname);
			defend = 1;
		}
	}
	if( damage > 0 )
		generate_hit_message(defend);
	else if( damage==0 )
		generate_no_penetrate_message(defend);
	else if( damage==-1 )
		generate_miss_message(defend);
	else if( damage==-2 )
		generate_parry_message(defend);
	else if( damage==-3 )
		generate_block_message(defend);
	else if( damage==-4 )
		generate_dodge_message(defend);
	else if( damage==-5 )
		generate_unarmed_parry_message(defend);

	// Send message to attacker
	if( defender ) {
		attacker->quick_message(c_msg_attacker);
//		message( "combat", c_msg_attacker, attacker );
		if( damage > 0 ) 
			attacker->quick_message(sprintf( "( %s%s )\n",
				c_vname, STATS_D->status_string(defender) ) );
		
//			message( "combat", sprintf( "( %s%s )\n",
//				c_vname, STATS_D->status_string(defender) ), attacker );
	} 

	// Send message to defender
	if( defender ) {
		defender->quick_message(c_msg_defender);
//		message( "combat", c_msg_defender, defender );
		if( damage > 0 ) 
			defender->quick_message(sprintf( "( 你%s )\n",
				STATS_D->status_string(defender) ) );
//			message( "combat", sprintf( "( 你%s )\n",
//				STATS_D->status_string(defender) ), defender );
	} 

	// Send message to others
	obs = all_inventory(environment(attacker))- ({ attacker,defender });
	for ( i = sizeof(obs) -1 ; i >= 0 ; i -- ) 
		if ( living(obs[i]) )
			obs[i]->quick_message(c_msg_others);
/*
	tell_room( environment(attacker), 
		c_msg_others,
		({ attacker, defender }) );
*/
}

void report_death()
{
	int i;
	object me, *ob;
	string c_msg;

	me = previous_object();
	if( !stringp(c_msg = me->query("c_death_msg")) )
		switch( random(5) )	{
			case 0: 
				c_msg = "%s搖搖晃晃地退了幾步，倒在地上 ... 死了.　\n";
				break;
			case 1: 
				c_msg = "%s發出一聲淒厲的慘叫，跌在地上 ... 死了.　\n";
				break;
			case 2: 
				c_msg = "%s咳出幾口鮮血，軟倒在地 ... 眼看活不成了.　\n";
				break;
   /* bmp加了兩項。*/   case 3:
                                c_msg = "%s直倘倘地往後一倒 ... 死了。\n";
                                break;
                        case 4:
                                c_msg = "%s嘴角流出了一絲黑血，歪著身子一倒 ... 就這樣掛了。\n";
                                break;
 		}
	if ( !environment(me) ) return ;
	ob = all_inventory( environment(me) );
	i = sizeof(ob);
	while(i--) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		message( "combat", sprintf( c_msg, me->query("c_name") ), ob[i] );
	}
}
