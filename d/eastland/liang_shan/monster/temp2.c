#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(15);
    set_name("Fat Tung","肥東");
    add("id",({"fat","tung","cooker"}) );
    set_short("肥東");
	set_long(@C_LONG
    你看到一個超級大胖子，胖的似乎連走出廚房門都有困難，他就是梁山泊的廚子
，名叫肥東，據山賊們的說法，肥東煮的菜又少又難以下□，所以當山賊們有錢時，
寧可去孫二孃的酒店中花錢吃飯，而免費的伙食都沒人要吃。肥東現在正在作今天的
飯。不要因他淳樸的外表而以為他好欺負，聽說他少年時曾在少林學藝。 
C_LONG
	);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "lizardman");
    set( "unit", "位" );
    set_perm_stat( "dex",20);
    set_perm_stat( "str",30);
    set_perm_stat( "int",15);
    set_perm_stat( "karma",25);
    set_skill("unarmed",70);
    set_skill("block",100);
    set_skill("dodge",100);	
    set ("max_fp",800);
    set ("max_hp",1000);
    set ("force_points",800);
    set ("hit_points",1000);
    set_natural_weapon(35,20,40);
	set_natural_armor(80,40);
	set ("aim_difficulty",([ "gangolion":60,"vascular":100]) );
	set("special_defense", (["all":50,"none":20]) );
    set("attack_skill","monk/fist/tb_fist");
    set("gonfus/ho_fist",80);
    set ("weight", 800);
    set("inquiry",([
        "trouble" : "@@ask_trouble",
        "diet" : "@@ask_diet",        
        "skill" : "@@ask_skill"
        ]));
    equip_armor(TARMOR"cook_hat");
    equip_armor(TARMOR"cook_cloth");
    equip_armor(TARMOR"pot");
}
int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name !="cook note" && name != "diet_tea" ) ) return 1;
	if (name == "cook note") {
     if ((int)this_player()->query_temp("fat_quest/skill")<1) {
     tell_object(me,
@ANSWER1
肥東接過這本筆記，看也不看，就把它當柴火燒掉了....
ANSWER1
);     
     item->remove();
     return 1;
}     
     if ((int)this_player()->query_temp("fat_quest/skill")==1) {
     tell_object(me,
@ANSWER2
肥東接過這本筆記，翻了一下，說道: 這些我都會了，你能不能再幫我問問別人??
ANSWER2
	);
        command("give "+name+" to "+(string)this_player()->query("name"));
        return 1;
}
     if ((int)this_player()->query_temp("fat_quest/skill")==2) {     
     tell_object(me,
@ANSWER3
肥東接過這本筆記，翻了一下，說道: 你是從那找到這麼多資料的? 有了這些，我一
定能做出更好吃的魚料理。真是太感謝你了!!
ANSWER3
	);
        this_player()->set_temp("fat_quest/skill",3);
        item->remove();
if ((int)this_player()->query_temp("fat_quest/diet")<4) {
write("肥東說道: 對了，你不是要幫我減肥嗎? 現在進度如何??\n");
        return 1;
}
else { 
        write("你完成了肥東任務，得到了7000點經驗值\n");                
        this_player()->gain_experience(7000);
        return 1;
}}}
     if (name == "diet_tea")
{     
if ((int)this_player()->query_temp("fat_quest/diet")<3) {
     tell_object(me,
@DIET1
肥東接過這杯茶，問道: 你幹嘛對我這麼好??說完把茶倒到流理臺
DIET
	);
        item->remove();	
	return 1;
}
else {
     tell_object(me,
@DIET2
肥東問道: 這就是減肥茶嗎? 而後將它一飲而盡     
DIET2
);
command("drink diet_tea");
    item->remove();
    this_player()->set_temp("fat_quest/diet",4);
    if ((int)this_player()->query_temp("fat_quest/skill")<3) {
    write("肥東問道: 對了，你有辦法使我做出更好的魚料理嗎??\n");
    return 1;
    }
    else { write("你完成了肥東任務，得到7000點經驗值\n");
    this_player()->gain_experience(7000);    
    return 1;
}}}}
void ask_skill()
{
if (!(this_player()->query_temp("fat_quest/fish")) || (int)this_player()->query_temp("fat_quest/fish")<3) {
write(
"肥東搖頭說道: 想要學煮飯嗎? 看你只配學泡麵......\n");
}
else {
write(
"我是跟一個流浪的半身人廚師學做菜的，他做的料理不但美味，還能撼動人心。\n"
"可惜當時時間有限，我只學到了肉類的料理法而已，真是可惜，後來他去諾達尼\n"
"亞大陸旅行，我就跟他失去聯絡了，一轉眼已經十多年啦....唉........\n");
return 1;
}}
void ask_diet()
{
if (!(this_player()->query_temp("fat_quest/fish")) || (int)this_player()->query_temp("fat_quest/fish")<3)
write(
"肥東說道: 我是想減肥呀，可是得先解決目前的問題吧?\n");
else {
write(
"你一五一十的把張順的話告訴了肥東，肥東聽完後默然無語，好像很難過的樣子。\n"
"你於心不忍，決定再幫他一個忙，設法幫助他恢復苗條的身材.......\n");
return 1;
}}
void ask_trouble()
{
if (!(this_player()->query_temp("fat_quest/ask")) || (int)this_player()->query_temp("fat_quest/ask")==0) 
write(
"肥東說道: 你是誰啊? 幹嘛來這裡問東問西的?\n");
else { 
write(
"肥東感激的說道: 好吧，讓我來告訴你我的困難。事情是這樣的: \n"
"十年前，梁山泊剛成立的時候，我加入了他們的行列。當時的大頭目宋江成立了一\n"
"個大眾的食堂，使大家能有免費的伙食，經費由山寨補助，由我當負責人。\n"
"這麼多年來，也經歷了不少事情，例如孫二孃的飯館開張，搶走我不少生意，但是\n"
"我的公營飯店仍然得繼續經營下去。\n\n");
call_out("ask_trouble2",10,this_player());
}
return 1;
} 
int ask_trouble2()
{
write(
"肥東又深深的嘆了一口氣，繼續說道: \n"
"但是長久以來，我都用後山獵得的野獸來作料理，用了快十年了，後山的野獸幾乎\n"
"快被獵光了，換句話就是我找不到肉類來作菜.......唉......\n"
"弟兄們早就習慣了大口喝酒，大口吃肉的日子，所以現在他們都到孫二孃的酒店去\n"
"花錢吃飯了。不過說也奇怪，為什麼他們還找的到肉(meat)呢?\n\n");
call_out("ask_trouble3",10,this_player());
return 1;
}
int ask_trouble3()
{
write(
"我現在的問題是，要如何恢復公營飯店的生意呢? 其實我也不是很在意這\n"
"裡的生意，只是看到大家都花錢去吃飯，感到對宋江老大有點過意不去，\n"
"肥東誠摯的握住你的手說道: 講了這麼多，心裡感到好多了。\n"
"你能幫我恢復飯店的生意，讓大家都能免費吃到好吃的食物嗎?\n");
this_player()->set_temp("fat_quest/meat",1);
return 1;
}
