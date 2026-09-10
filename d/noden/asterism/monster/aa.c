#include "../asterism.h"

inherit MONSTER;

int false_attack() ;

void create()
{
        object obj ;
        ::create();
        set_level(19);
        set_name( "Gnome Elder","地精長老" );
        add ("id", ({ "gnome", "elder" }) );
        set_short( "地精長老");
        set("unit","位");
        set("alignment",500);
        set("wealth/gold",150);
        set_long(
            "地精是個精於法術的種族，而地精長老更是個可怕的施法者。\n"
        );
        set_perm_stat("int", 30);
        set_perm_stat("dex", 25);
        set_perm_stat("kar",30);
        set_natural_weapon( 42, 10, 22 );
        set_natural_armor( 27, 17 );
        set("stun_difficulty",33) ;
        set ("gender", "male");
        set ("race", "gnome");
        set("max_hp",625);
        set("hit_points",625);
        set("force_points",600);
        set("max_sp",600);
        set("spell_points",600);
        set("hime_to_heal",3);
        set("magic_delay",2 ) ;       
        set_temp("detect_hide",1) ;
        set_temp("detect_invi",1) ;        
        set_skill("concentrate",100);
        set_skill("target",100);
        set_skill("dodge",80);        
        set_skill("black-magic",100);
        set("guild_levels/black-magic",80) ;
        set("guild_levels/guild",80);
        set("spells/flare",2);
        set("magic_delay",2);
        set("chat_chance", 8 );
        set( "tactic_func", "cast_help" ); 
        set("aim_difficulty",(["critical":100,"weakest":40,
                               "vascular":35,"ganglion":60 ])) ;
                                                                                         
        set("special_defense",(["all":40,"none":35]));
        wield_weapon(WEAPONS"wand03");
        equip_armor(ARMORS"robe01") ;
        equip_armor(ARMORS"helmet03");
        equip_armor(ARMORS"cloak_g01");
        equip_armor(ARMORS"amulet_g02.c");
        equip_armor(ARMORS"gloves02");
        equip_armor(ARMORS"ring02");
        obj = new("/d/mage/spellbook.c") ;
        obj -> move(this_object()) ;
}

int cast_help()
{ 
    object victim;
    string name;
    int i,j,ran,vickar,vicint,refn;
    victim = query_attacker();
    vicint = victim->query_perm_stat("int") ;
    vickar = victim->query_perm_stat("kar") ;
    
    i =30-vicint ;
    j =30-vickar ;
    
    if(random(2)==0) false_attack() ;
    
    if( i+j < 1 )  refn = 1 ;
    else refn = random(i+j) ; 

    ran = random(50) ;
                            
    if ( (int)this_object()->query("spell_points")< 300 )   
         this_object()->set("spell_points",600);

    if ( ran < refn  )
       {
          name=victim->query("name");
          command("cast flare on "+name); 
          return 1;
        }
    return 0;
}

int accept_item(object me,object ob)
{
         tell_room( environment(),
                 "地精長老把"+ob->query("c_name")+"變成一個金幣,收進了口袋。\n"
                  , this_object() ) ;
         this_object()->add("wealth/gold",1) ;
         ob->remove() ;           
         return 1 ;
}

int filter_player(object obj)
{
    return userp(obj) ;
}

int false_attack()
{
    object *player ;
    int i,no ;
    string msg ;
    
    no = random(3) ;
    
    player = filter_array(all_inventory(environment(this_object())),
                          "filter_player",this_object()) ;   

    if(no == 0) 
       {
         msg = sprintf("地精長老的永恆之杖往你門面一揮，造成極其嚴重的傷害。\n"+set_color("( 你死了。)\t~~~^_^~~~\n","HIR",player[i])) ;
        }
    if(no == 1)
       { 
         msg = sprintf("地精長老的永恆之杖往你門面一揮，造成極其嚴重的傷害。\n( 你已經%s了。)\n",set_color("奄奄一息","HIR",player[i]))  ;
        }
    if(no == 2)  
       {
         msg = sprintf("地精長老的永恆之杖往你門面一揮，造成極其嚴重的傷害。\n( 你渾身是血，受傷極重，%s。)\n",set_color("有生命危險","HIM",player[i]))  ;
       }            
       
    say(msg) ;  

    return 1;
}
