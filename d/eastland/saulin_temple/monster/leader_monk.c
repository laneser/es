#include "saulin_monk.c"

void create()
{
        ::create();
        set_level(19);
        set_name( "leader", "少林寺方丈 慧空大師" );
        add ("id", ({ "leader","monk" }) );
        set_short( "少林寺方丈 慧空大師");
        set("unit","位");
        set_long(@C_LONG
慧空大師是少林寺的方丈，雖然年紀已經很大，可是因為修練少林內功寶典
易筋經的關係，看起來還像壯年。仁慈寬厚的他堪稱是澤被天下。他長年誦
經唸佛，規勸世人向善，對於作惡多端的人也一定會加以開導。
C_LONG
        );
        set( "inquiry", ([
              "cave" : ({@HERB

   眾生院？那是本寺專門用來安置別派高手的地方，凡是本派有大事發生
   不能立時讓心存敵意的別派高手下山時，只好將他們暫時安置在那裡，
   說來慚愧。那原本是後山的一個天然地穴，現在由敝派的三位高僧把守
   ，負責把意圖劫人的高手驅離。
HERB
        }) ]) );
        set("alignment",2000);
        set("wealth/gold",250);
        set("gender", "male");
        set("race", "human");
        set("max_hp", 1000);
        set("max_fp", 600);
        set("hit_points", 1000);
        set("force_points", 600);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 30);
        set_natural_weapon( -5, 4, 10 );
	set_natural_armor( 50, 25 );
        set_temp("detect_hide",1);
        set("special_defense", ([ "all":70, "none":60, "monk":25 ]) );
        set("aim_difficulty", ([ "critical":65, "vascular":80, ]) );
        set_skill("bo",100);
        set_skill("parry", 90);
	set("defense_skill",CLASS"body_def");
	set("monk_gonfu/body-def",10);
        wield_weapon( SAULIN_OBJ"staff1" );
        equip_armor( SAULIN_OBJ"necklace01" );
        equip_armor( SAULIN_OBJ"cloth1" );
        equip_armor( SAULIN_OBJ"shield1" );
        equip_armor( SAULIN_OBJ"glove2" );
        equip_armor( SAULIN_OBJ"ring1" );
	set("tactic_func","my_tactic");
}

int my_tactic()
{
	object *ob;
	int  i;
	
        if( random(25) > 3 ) return 0;
        	if( random(5) > 1 ) { 
        		tell_room( environment(this_object()), @MSG1
慧空大師喃喃道：「施主 !! 您這又是何苦呢？」他垂首合十默唸心經真言 ..
突然一團團銀白色的光芒圍繞著他，他的傷口竟然復元了 !!

MSG1
			, this_object()
        		);
        		this_object()->receive_healing(80);
        		return 1; }
        	else {
        		tell_room( environment(this_object()), @MSG2
慧空大師突然聲如宏鍾大喊一聲道： 「 呔 ！！ 」....

你受到一陣強烈的衝擊，不由自主地倒退三步 !!

MSG2
			, this_object()
        		);
        		ob = this_object()->query_attackers();
        		i = sizeof(ob);
        		while(i--) {
        			ob[i]->block_attack(6);
        			ob[i]->set_temp("msg_stop_attack",
        				"( 你腦中一片混亂，無法攻擊 ！ )\n" );
        			}	
        		return 1; }
}


int check_partner(object obj)
{
   if( obj->query_attacker() ) return 0;
   if( (string)obj->query("name") == "bonze" ) return 1;
   return 0;
}

int special_attack()
{
    object victim,*guard;
    int i;
    
    victim = query_attacker();
    if(!victim) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "check_partner",this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room(environment(this_object()),
        "武僧大喊：師兄弟們，有人對師父不客氣，快來保護師父！\n"
      );
      guard[i]->kill_ob(victim);
    }
    return 1;
}

void init()
{
   ::init();
   add_action("report_master","report");
}

int report_master()
{
    if( (int)(this_player()->query_temp("book_quest/step"))==2 ) {
    	tell_object(this_player(),@REPORT
慧空大師合十道：阿彌陀佛!!竟然有這種事情？這真是敝寺用人不當了，多謝
施主!!老納立刻命人將那火工頭陀送交 ...他並非本寺弟子，不能送戒律院懲
處，那只好先送入眾生院(cave)。
此外，可否請施主代為詢問楞枷經的下落，唉～。
REPORT
        );
   	if (this_player()->query("class")!="monk") 
	    tell_object(this_player(),"多謝施主幫忙找出真相，不勝感激！");
        this_player()->set_temp("book_quest/step",3);
        return 1;
	}
    if( (int)(this_player()->query_temp("book_quest/step"))==4 ) {
	tell_object(this_player(),@REPORT
慧空大師合十說道：阿彌陀佛!!多謝施主替本寺尋回經書, 敝寺上下同感大恩....
                  對了!!可否勞煩施主轉告覺遠不必再繼續挑水了(release),
                  阿彌陀佛!!
REPORT
        );
         present("sutra",this_player())->remove();
         this_player()->set_temp("book_quest/step",5);
         return 1;
          }
	return 0;
}
