#include <mudlib.h>;
#include <config.h>;
 
inherit OBJECT;
inherit DAEMON ;

void create();
void init();
int read_me(string str);
 
void create() {
  seteuid(getuid());
  set("id",({"sutra"}));
  set_name("sutra","楞枷經");
  set_short("sutra","楞枷經");
  set_long("這本楞枷經看來已有相當的歷史, 紙張不但泛黃, 而且還有點黑黑的。\n"
           "你心想這本經書果然有歷史的價值, 難怪方丈這麼重視。\n");
  set("mass",1);
  set("bulk",1);
  set("unit","本");
  set("no_sale",1);
  set("prevent_drop",1) ;
  set("value",({10,"silver"}) );
}
