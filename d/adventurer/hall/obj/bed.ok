#include "mudlib.h"

inherit OBJECT;

string *c_illusion =({
"睡夢中你看到一隻羊、二隻羊、三隻羊、四隻羊...越來越多的羊跑來跑去！\n",
"睡夢中你看到自己站在一堆裡體小山上微笑，原來躺下的都是自己的傑作！\n",
"睡夢中你看到自己不斷的吶喊著：殺呀！殺呀！像個瘋子一樣.....\n",
"你看到一位全身金光閃閃的騎士，於千軍萬馬中衝刺，取敵人首級如入無人之地！\n",
"睡夢中你看到一位頭頂有光圈的高僧，正演練一套神奇武功，生龍活虎如達摩再世！\n",
"睡夢中你看到一位身材迷人，曲線姚佻的女魔法師，笑著對你說：「嗨！大帥哥！」\n",
"帶著情人吃完大餐要付賬時，你好像看到一個身影，然後發現錢不見了！真是好糗！\n",
"你看到一位高人在月下舞劍，身影翩翩，口中念著「我歌月徘徊，我舞影凌亂！」\n",
"睡夢中你看到一位全身髒兮兮的流浪漢，口中不斷念著「和平！奮鬥！玩泥巴！」\n",
"睡夢中你看到一隻可憐的小貓，叫著「喵喵！大爺別殺我...小的給你跪下磕頭！」\n",
"你看到一隻變態的青蛙唱著「你說你想要逃，偏偏註定要死掉，命沒了！錢沒了..」\n",
 }) ;

//int maxhp,maxsp,maxtp,hp_full,sp_full,tp_full ;

void create()
{
        set_name( "Bed", "行軍床" );
//        set( "id", ( { "bed" } ) );
        set_short( "行軍床" );
        set("unit", "個" );
        set_long( "這是一個行軍床, 你可以在上面睡覺\n" );
        set( "weight", 100000);
}

void init()
{
add_action("cmd_sleep","sleep");
// add_action("cmd_out","out");
// add_action("cmd_quit","quit");
add_action("cmd_wake","wake");
add_action("cmd_protect","protect");
add_action("cmd_unprotect","unprotect");
add_action("cmd_kill","kill");
}
void do_sleep(object player, int skill, int degree,int num )
{ 
   string text;
   string *colors = ({ "HIC", "HIY", "HIB" });
   int i, maxhp, maxsp, maxtp, hp_full, sp_full, tp_full;
   if ( degree < 10 && skill > random(degree*10) && (int)this_player()->query_temp("shaked") < 1) { 
           if (degree > 2) i = random(8)+2 ; else i = degree ;
           text = c_illusion[i];
           message("illusion", 
              set_color(text, colors[random(3)], player),player) ;
           if (degree % 2) {
             tell_room( environment(player), 
             sprintf("你看到 %s 躺在床上，一邊流著口水，一邊傳出嚇人的鼾聲。\n",
               player->query("c_name")), player );
           } 
           maxhp = (int)player->query("max_hp"); 
           maxsp = (int)player->query("max_sp"); 
           maxtp = (int)player->query("max_tp");     
           player->add("hit_points", num + 1);
           player->add("spell_points", (int)num/2 + 1 );
           player->add("talk_points", (int)num/2 + 1 );
           if ((int)player->query("hit_points") >= maxhp) {
              player->set("hit_points",maxhp) ;
              hp_full = 1 ;
           } 
           if ((int)player->query("spell_points") >= maxsp) {
              player->set("spell_points",maxsp) ;
              sp_full = 1 ;
           }
           if ((int)player->query("talk_points") >= maxtp) {
              player->set("talk_points",maxtp) ;
              tp_full = 1 ;
           } 
           call_out( "do_sleep", 8, player, skill, degree + 1,num );
   } else {
       player->delete_temp("block_command");
       tell_object( player, 
		"......突然間你聽到一陣鬧鈴聲，不甘願的醒了過來。\n" );
       tell_room( environment(player), 
       sprintf("你看到%s揉揉惺忪眼睛，伸伸懶腰，繼續活動。\n",
               player->query("c_name")), player );
       call_out("quit_camp", degree*20, player);
   }
}

void quit_camp( object player )
{
        if( !player ) return;
        tell_object( player,
                "你感覺有一點累了。\n");
        player->delete_temp("in_sleep");
}

int cmd_sleep()
{
    int skill, hp, num;
    object me,env;
	
    me = this_player();
    env = environment(me) ;
    skill = (int)me->query_temp("build_skill");
//    maxhp = (int)me->query("max_hp"); 
//    maxsp = (int)me->query("max_sp"); 
//    maxtp = (int)me->query("max_tp");     
//    sp_full=0; hp_full=0; tp_full = 0 ;
    num = me->query_temp("camp_size");
    if ( me->query("class") == "adventurer" )
    num = num +1;  
    if (me->query_temp("in_sleep")) {
    write("你是豬啊，才睡醒又想睡？\n");
    return 1;
    }
    if( (int)me->query_attacker()) {
      write("在戰鬥中睡覺，想要找老黑泡茶嗎？\n");
      return 1;
    }
    tell_object( me,
                    "你實在太累了，隨便找個空地倒頭就睡。\n" );
    tell_room( env, 
	me->query("c_name")+"似乎太累了，一進來就躺在床上補充睡眠。\n",
		me );
    if( !wizardp( me ) ) {
	me->set_temp("in_sleep",1);
	me->set_temp("block_command", 1 );
    }		
    me->set_temp("shaked",0);
    call_out( "do_sleep", 8, me, skill, 0, num );
    return 1;
}

int cmd_wake(string arg)
{
     object target,me;
     me = this_player();
     if ( !arg || arg == "") {
                      tell_object( me,
                      "你已經起床了啊?\n" );
                      return 1;
                      }
    
     if ( !(target = present( arg,environment(this_player()))) ) {
                      tell_object( me,
                      "這裡沒有叫"+arg+"的東西。\n");
                      return 1;
                      }
    
     if ( !visible(target,this_player()) || target->query("invisible_player")) {
                      tell_object( me,
                      "好像沒有這個人喔?\n");
                      return 1;
                      }
     
     if ( !living(target) || !(int)target->query_temp("block_command")==1 ) {
                      tell_object( me,
                      "你用力的搖晃"+target->query("c_name")+"但是什麼事也沒發生。\n");
                      return 1;
                      }      
      tell_object( me, set_color(
           "你大力的搖晃" + target->query("c_name") + "的身體，企圖把他叫醒...\n\n", "HIY"
           ,me) );
                      
      tell_object(target, set_color(
           me->query("c_name")+"大力的搖晃你的身體.....\n\n", "HIM"
            ,target));
                                              
      tell_room( environment(me), "\n"+
           me->query("c_name")+"大力搖晃"+
           target->query("c_name")+"的身體，企圖把他叫醒\n\n" ,
           ({ me, target }) );
      
      target->set_temp("shaked",1); 
      target->delete_temp("block_command");
      target->receive_special_damage("none",20);
      return 1;
   }  
int cmd_protect(string str)
{
	object damsel,*prot,*prot2;
	string *foo;
	int	i;

        if ((string)this_player()->query("class") != "adventurer" ) 
              return notify_fail("只有冒險者有能力在帳蓬中守衛...\n");
        prot = (object *)this_player()->query_temp("protect_whom");

	if (!str) {
		if ( sizeof(prot) < 1 )
			return notify_fail("你現在沒有保護任何人。\n");
		prot2 = ({ }) ;
		for ( i=0 ; i < sizeof(prot) ; i++) 
			if ( !nullp(prot[i]) && prot[i]) prot2 += ({ prot[i] }) ;
		prot = prot2 ;
		this_player()->set_temp("protect_whom",prot);
		write(set_color("你現在保護著 :\n","HIY",this_player()));
		for ( i=0 ; i < sizeof(prot) ; i++)
			write(sprintf("%s(%s)\n",prot[i]->query("c_name"),prot[i]->query("name")));
		return 1;
	}

	damsel = present(str, environment(this_player())) ;
//	if ( damsel = this_player() )
//	        return notify_fail("保護自己嗎，你還真聰明\n");
	if (!damsel || !living(damsel))
		return notify_fail("你要保護誰？\n");

        if( prot && pointerp(prot) ) {
                if ( member_array( damsel,prot ) != -1 )
                return notify_fail("你已經保護著他了 !!\n");
		if (sizeof(prot) > 3 )
		return notify_fail("你不能分心保護那麼多人 !!\n");
	}

	write( sprintf("你提高了警覺，注意%s的安全。\n",damsel->query("short"),to_chinese(subjective(damsel))));
	tell_object( damsel, 
		sprintf("%s目不轉睛的注意著你的安全！\n",this_player()->query("c_name")));

	damsel->add_temp("who_protect", ({ this_player() }) ) ;
	this_player()->add_temp("protect_whom", ({ damsel }) ) ;
	return 1 ;
}
int cmd_unprotect(string str)
{
	object *foo, *tmp, me;
	int i, j, done;

	if( !str ) return 0;
	me = this_player();
	if ((string)this_player()->query("class") != "adventurer" )
	            return notify_fail("只有冒險者有能力在帳蓬中守衛...\n");
	foo = (object *)me->query_temp("protect_whom");
	if( sizeof(foo) < 1 )
		return notify_fail("你現在並沒有保護任何人。\n");
	done = 0;
	for( i=sizeof(foo)-1; i>=0; i-- ) {
		if ( !foo[i] ) continue ;
		if( !foo[i]->id(str) ) continue;
		write(sprintf("你停止保護%s(%s)。\n", foo[i]->query("c_name"),
				foo[i]->query("name")));
		tell_object( foo[i], 
			sprintf("%s(%s)停止保護你。\n", me->query("c_name"),
				me->query("name")));
		tmp = foo[i]->query_temp("who_protect");
		tmp -= ({ me });
		foo[i]->set_temp("who_protect", tmp);
		foo[i] = 0;
		done++;
	}
	if( done ) {
		if( sizeof(foo) > done ) {
			done = 0;
			tmp = allocate(sizeof(foo)-done);
			for( i=sizeof(foo)-1; i>=0; i-- ) {
				if( foo[i] == 0 ) continue;
				tmp[j] = foo[i];
				j++;
			}
			me->set_temp("proctect_whom", tmp);
		} else me->delete_temp("protect_whom");
	} else return notify_fail( 
		"你現在並沒有保護任何叫做 " + str + " 的人。\n");
	return 1;
}
int cmd_kill(string arg)
{ 
       object me, victim, *protector;
       int i,kar;
       me = this_player();
       kar = this_player()->query_perm_stat("karma");
       if( !arg ) return 0; 
       if ( !( victim = present( arg,environment(me))) ) return 0;
       if ( !living(victim)) return 0;                
       protector = (object *)victim->query_temp("who_protect");
       if( sizeof(protector) < 1 ) {
       if( victim->query_temp("block_command")) { 
       victim->set_temp("shaked",1);
//       victim->die();
       victim->receive_damage( 180 - kar*random(4)); 
       return 0; }
       else { 
       victim->set_temp("shaked",1);
       return 0;
       }
       }
       for( i=sizeof(protector)-1; i>=0; i-- ) {
       if ( !present(protector[i],environment(me)) ) continue ;
       me->kill_ob(protector[i]);
       }
       return 0;
 }        
