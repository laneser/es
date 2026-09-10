inherit "/d/noden/asterism/item/drink.c" ;

void create()
{
    ::create();
    seteuid(getuid());
    set("id", ({ "tea" , "herb tea","herbtea" }) ) ;
    set_name("herb tea","青草茶");
    set_short("青草茶");
    set_long(
    "這是由千草家密傳配方製成的青草茶。啥？......誰姓千草？\n"
    "嗯......為了身家性命著想，不知道的話就算了吧!!\n");
    set("container",0) ;
    set("tp",80);
    set("value",({ 50,"silver" }) ) ;
    set("amount",0) ;
    set("c_succ","你喝下一瓶青草茶,一股清涼的感覺流過你的喉頭。\n") ;
   set("c_osucc","$CN喝下了一瓶青草茶。看他閉上眼的神情,好像蠻清涼可口的樣子。\n") ;
}
