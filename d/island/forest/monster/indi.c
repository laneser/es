#include "../tsunami.h"

inherit MONSTER;

void create()
{
    object obj;

    ::create();
    set_level(3);
    set_name("Adventurer Indiana Jones","瓊斯");
    add("id",({"anventurer","indiana","jones","indi"}) );
    set_short("偉大的冒險家 印地安那瓊斯");
    set_long(@LONG
印地安那瓊斯是一為非常活耀的冒險者，雖然是大學中考古系的教授，卻熱衷
於為博物館收集各種古代的文化遺蹟；這一次，他搜尋的是隱蔽在層層天險之
中的魔族秘境。
LONG);
    set("unit","位");
    set("race","human");
    set("gender","male");
    set("class","adventurer");
    set("weight",600);
    set("alignment",500);
    set_perm_stat("str",5);
    set_perm_stat("dex",3);
    set_skill("dodge",10);
    set("hit_points",100);
    set("max_hp",100);
    set("wealth/silver",100);
    set_natural_weapon(10,3,10);
    set_natural_armor(10,0);
    set("chat_chance",5);
    set("chat_output",({
 "瓊斯喃喃道：那個老頭到底是遭到什麼橫禍？怎麼會將研究一輩子的考古筆記寄給我?\n"
     }) );
    wield_weapon(TWEP"whip");
    set("inquiry", ([
        "note":"@@ask_note"
        ]) );
    obj = new(TOBJ"bag");
    obj->move(this_object());
//    note = new(TOBJ"note");
//    note->move(obj); 
}
void ask_note(object asker)
{
    
     if( this_object()->query("noted") ) 
     tell_object( asker,
     "\n瓊斯說道：你晚來一步，筆記本已經有人取走了。
\n"); 
   
     else {
     this_object()->set("noted",1);
     tell_object( asker,
     "\n瓊斯說道：好吧 !! 也算了卻我一樁心事。\n"); 
     call_out("rebo1",3,asker);    
     call_out("rebo2",2000,this_object());
     }
}     
void rebo1(object ob1)     
{    
     object note;
     note = new(TOBJ"note"); 
     note->move(this_object());
     command("give note to "+ob1->query("name"));
}
void rebo2(object ob)
{
     ob->delete("noted");
}  

    

