#include "../almuhara.h"
 
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid(getuid());
        set_level(19);
        set_name( "The archmaster", "大國師" );
        add ("id", ({ "daemon", "master","archmaster" }) );
        set_short( "大國師  孝光");
        set("unit","位");
        set("exp_reward",40000) ;           
        set("alignment",3100);
        set("wealth/gold",500);
        set_long(
            "大國師  孝光是一位面目和善的人，看起來大約才四十多歲，可是你知道他\n"
            "絕對不只這個年紀。據說他是少數幾個從魔族大戰中倖存的人，因而來到東\n"
            "方大陸隱居。因為受皇帝的徵召，孝光成了東方王國的國師。他曾拜在龍虎\n"
            "山  張天師的門下，成為天師的得意弟子，因此他精研奇門遁甲、五行土木\n"
            "之學，再加上他本來的知識及能力，使他成為人人敬重的大國師。\n"
        );
        set_perm_stat("str", 25);        
        set_perm_stat("int", 30);
        set_perm_stat("dex", 30);
        set_perm_stat("kar",30);
        set_natural_weapon( 50, 20, 30 );
        set_natural_armor( 100, 50 );
        set_skill("dodge",100);
        
        set ("gender", "male");
        set ("race", "daemon");
        set("max_hp",1500);
        set("hit_points",1500);
        set("time_to_heal",2);
        set("max_sp",2000);
        set("spell_points",2000);
        set( "tactic_func", "my_tactic" ); 
        set("aim_difficulty",(["critical":60,"weakest":60,
                               "vascular":30,"ganglion":60 ])) ;
        set("stun_difficulty/ma",20) ;
        set("unbleeding",1);
        set("special_defense",(["all":70,"none":50,"monk":60,"scholar":60]));
//        set("moving",1);
//        set("speed",30);
//        set("patrol",({"south","sotuh","north","north"}) );
        set( "chat_chance", 10);
        set( "chat_output", ({
        	"大國師深深地看著你，彷佛要看進你的靈魂深處。\n",
        	"大國師緩緩地踱著方步。\n" }) );
	set( "att_chat_output", ({
		"大國師搖搖頭說道：為什麼就是有人不愛惜自己的生命呢？\n",
		}) );
        wield_weapon(WEAPONS"/ling");
        equip_armor(ARMORS"/master_hat"); 
        equip_armor(ARMORS"/master_boots");
        equip_armor(ARMORS"/master_robe");
        equip_armor(ARMORS"/master_amulet");
        equip_armor(ARMORS"/master_ring");        
        equip_armor(ARMORS"/shield1");
        set( "inquiry", ([
"almuhara" : ({"他是我最好的朋友。\n" }),
"wiwi" : ({"死包臭包大爛包。\n" }),
"blackjack" : ({"他不壞，他是一個好老頭。\n" }),
"monmonpig" : ({"聽說他跟阿福有一腿...... :~~~~    我要pk !!\n"}),
"kenwahl" : ({"一個笨巫師，不要理他...\n"}),
"阿福" : ({"問世間情是何物，直叫人生死相許........:~~~ \n" }),
"jade" : ({"玉佩？什麼樣的玉佩？可否給我看看？\n" }),
"seal" : "@@ask_seal",
"tomb" : ({"你問這幹嘛 ?\n" }) ]) );
}
 
void ask_seal(object who)
{
	if ( who->query("quest/sky_guilt") ) {
		tell_object( who, 
		"大國師說道：非常謝謝你的幫忙。\n" );
		return; }
	if ( who->query("sky_guilt") ) {
		tell_object( who,
		"大國師說道：加油!!\n" );
		return; }
        if ( (int)who->query_level() < 17 ) {
                tell_object( who,
                "大國師說道：請珍惜自己的生命，先提升你的能力再說吧。\n" );
                return; }
        if ( who->query("guilt_jade") ) {
                tell_object( who,
                "大國師嘆了一口氣，說道：『 那封印是用來囚禁人間兇獸 --「天罪」的。\n"
                "多年以前皇上將此劍收入劍冢，我就深深覺得不妥，只恨我當時沒有力諫不\n"
                "可，才讓它吸取靈氣、成了形。雖然我用陣勢將其困住，但亦耗了我三分之\n"
                "二的功力，已無力將其收服，希望你能替我除此兇獸，並將它帶來給我。\n"
                "這兒有一顆九轉金丹，應該對你有些幫助。』\n\n" );
                who->delete("sky_guilt");
                new(ITEM"/great_pill")->move(who);
                call_out("give_jade",6,who);
                return; }
        tell_object( who,
                "大國師嘆了一口氣，說道：『 那封印是用來囚禁人間兇獸 --「天罪」的。\n"
		"多年以前皇上將此劍收入劍冢，我就深深覺得不妥，只恨我當時沒有力諫不\n"
		"可，才讓它吸取靈氣、成了形。雖然我用陣勢將其困住，但亦耗了我三分之\n"
		"二的功力，已無力將其收服，希望你能替我除此兇獸，並將它帶來給我。這\n"
		"兒有一顆九轉金丹，應該對你有些幫助。』\n" );
                who->set("sky_guilt", 1);
                new(ITEM"/great_pill")->move(who);
                return;
}
 
void give_jade(object who)
{
        tell_object( who ,
                "大國師說道：對了...差點忘了...上回弄好的赦邪聖玉，正是象徵邪惡與原\n"
                "罪的天罪的天敵，等我為你幫赦邪聖玉開光，以助你誅除天罪兇獸...\n\n"
                "大國師念著一些咒語......\n\n"
                "大國師突然抓住你的手，手中的天師令驟然向你划來，把你嚇了一下！\n\n"
                "還好他拿捏得非常準確，僅僅颳去你小指的一小片皮膚，但是鮮血依然不斷\n"
                "地滲出....\n\n" );
        who->set_temp("block_command",1);
        tell_object( who,
                "大國師以最快的速度，幫你止血，並用你的鮮血在赦邪聖玉上劃下了些你看\n"
                "不懂的符號。\n\n" );
        call_out("tellmethod",12,who);
        return;
}
 
void tellmethod(object who)
{
        command("sweat");
        tell_object( who ,
                "大國師對你說：待與天罪對陣時，用赦邪聖玉丟(throw)向天罪，若能擊中\n"
                "那麼天罪的戾氣必然大減，你的勝算也會因此提高。祝你凱旋，記得把天罪\n"
                "帶來給我...\n\n" );
                new(ITEM"/holy_jade")->move(who);
                who->delete_temp("block_command");
                return;
}
 
void relay_message(string class1, string msg)
{
     string who,aa,str ,str1,str2;
     object *ob,obj,*obj1;
     int i,j;
     
     ::relay_message(class1, msg);
     if( sscanf( msg, "%s(%s)走了過來。\n", aa , who )==2 ) 
       {
         who = lower_case(who);
         obj = find_player(who);
         ob = all_inventory(this_object());
                i = sizeof(ob);
         while(i--) {
                        if( ob[i]->query("equipped") || ob[i]->query("wielded") ) continue;
                      //  if( undefinedp(ob[i]->query("armor_class")) &&
                      //     undefinedp(ob[i]->query("defense_bonus")) )
                      //          continue;
                        ob[i]->remove();
                }
          obj1 = all_inventory(environment(this_object()));
          	j = sizeof(obj1);
          while(j--) {
     		if( present("sky guilt", obj1[j]) ) { 
		        obj = obj1[j];
        	   if( (int)obj->query_temp("GUILT") && 
		        (int)obj->query_quest_level("Sky_guilt") < 1 ) {
      	           obj->finish_quest( "Sky_guilt", 1 );
         		tell_object( obj, 
         		"大國師注視著你身上的『 天罪 』好一陣子。\n"
         		"\n\n"
         		"大國師說道：真是謝謝你的幫忙。我所料的果然不錯，在『 天罪 』上本來\n"
         		"鑲有一顆具有法力的紅寶石，現在卻不見了，難怪它能如此囂張。如果你想\n"
 	       		"駕馭它，必須先找回那顆寶石，將其放入那小洞中，不然恐怕它會傷敵亦傷\n"
 	       		"你喔。\n"
 	        	"\n"
 	        	"你完成了「天罪」任務，得到 20000 經驗值。\n");
 			obj->gain_experience(20000);
 			obj->delete_temp("GUILT");
 			return; 
	 		}
	 	}	
         } 
    }
}
int my_tactic()
{ 
    object victim,env;
    int i,j;
 
    env = environment(this_object());       
 
    if( !(victim = query_attacker()) ) return 0;
 
    if( (int)this_object()->query("spell_points") < 500 )
      this_object()->set("spell_points", 2000);
    
    if( ((int)this_object()->query("hit_points") < 200) && random(10) > 7 ) {
	tell_room(env,
		"\n"+"你看到大國師招出水之精靈幫他治療傷口。\n",this_object() );    	
      	this_object()->add("hit_points", 200); 
      	return 1; }
    
    i = 30 - (int)victim->query_perm_stat("int") ;
    j = 30 - (int)victim->query_perm_stat("kar") ;
    
    if ( random(50) < i+j  )
       { 
          if(random(5) < 2) {
          	if ( (int)this_object()->query("hit_points") < 200 ) { 
          	tell_room( env, 
          		"\n"+"大國師將自己所受到的攻擊轉到"+victim->query("c_name")+"身上。\n",
          		({victim,this_object()}) );	
		tell_object( victim, 
			"\n"+"大國師將自己所受到的攻擊轉到你身上。\n");          
		this_object()->receive_healing(60);
		victim->receive_damage(random(50));  
		return 1;
                	}
                else return 0;
                }
          else 
		tell_room( env, 
			"\n\n"+"大國師大喊：「 五雷天心正法 」!!\n"+"\n\n" 
			, this_object() );
		victim->receive_special_damage("electric",80);  
          return 1 ;
        }
    else 
          return 0 ;
 
}
void die()
{
  int i ;
  object scroll,killer,*player ;
 
  player = users() ;
  killer = query("last_attacker") ;
  scroll = new("/d/mage/tower/obj/ltn4_scroll") ;
  scroll->move(environment(this_object())) ;
 
  for(i=0;i<sizeof(player);i++)
    {
  tell_object(player[i],"\n震動的大地傳出大國師 孝光低沉的悲嘆 : \n
  天亡吾也，非戰之罪啊!!! \n");
     }
 
  ::die(1) ;
}
int accept_item(object who,object item )
{
    if( (item->query("sky_guilt_jade1")) )
      {
        who->set_temp("ask_jade",1);
        tell_object(who,@MSG
大國師仔細端詳這塊玉佩......
大國師將玉佩拿近七彩石，七彩石竟和玉佩同時發出強光，照得你目眩神搖。
 
大國師眼中閃著興奮的光芒。
大國師對你說道：這是我叫我弟子外出尋找的赦邪聖玉的一部份，上回他已經差人
　　　　　　　　把另一半送回來了，收在我老婆那兒，麻煩你去跟我老婆拿另一
　　　　　　　　塊好嗎？
MSG );
      }
    if( (item->query("sky_guilt_jade2")) )
      {
        if (who->query_temp("ask_jade")) {
        tell_object(who,@MSG
大國師仔細端詳這塊玉佩......
 
大國師將手中的兩塊玉佩依著斷口接合，一道銀白免的光茫由玉佩中泛出，使你感
到一陣暖意......
 
大國師面帶微笑地對你說：謝謝...這樣一來就算解除封印也無所謂了....
MSG );
who->set("guilt_jade",1);
} else {
        tell_object(who,@MSG
大國師仔細端詳這塊玉佩......
 
大國師對你說：你這塊玉佩是那裡偷來的？不要耍我......
MSG ); }
      }
item->remove();
tell_object(who,"謝謝你......\n");
return 0;
}
