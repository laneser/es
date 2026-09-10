inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name( "hawkman older", "鳥人族老人" );
        add("id",({"older","hawkman"}) );
        set_short( "鳥人族老者" );
        set_long(@LONG
老態龍鍾的鳥人族老人，正在遙想著以往英勇的往事。你若是想知道一些鳥人族的
過去(history) ，或許可以問問這為慈祥的老人。
LONG
        );
        set( "gender", "male" );
        set( "inquiry", ([
                "flesheater":"@@ask_flesh",
                   "history":"@@ask_history",
                       "war":"@@ask_war"
                        ]) );
        set( "race", "hawkman" );
        set( "alignment", 300 );
        set( "time_to_heal", 15 );
        set_natural_armor( 13, 2 );
        set_natural_weapon( 10 , 12 , 5 );
        set_perm_stat( "kar", 13 );
        set( "wealth/silver", 50 );
}

int ask_war()
{
        tell_object(this_player(),@LONG
老人用很害怕的語氣說：大概在幾個月前吧，塔姆姆酋長撒巴吐卡(Sa-ba'tuka)
帶了好幾百人的部隊攻打我們，在天空之城堅固的防禦工事下，我們抵擋住塔姆姆族
的攻擊。想不到原本以為沒事了的我們，卻在晚上被撒巴吐卡用邪魔法攻擊，完全摧
毀了我們的武力。所幸裘拉根呼喚出許多地獄中的魔物協助我們，尤其是太古魔獸--
肉食獸....
    老人似乎陷入了極度的恐慌，不說話了。
LONG
                );
        return 1;
}

int ask_flesh()
{
        tell_object(this_player(),@LONG
老人大喊：喔....不要再提起那可怕的怪物了。

你覺得這或許是所有鳥人族人心中最大的恐懼吧!!
LONG
                );
        return 1;
}

int ask_history()
{
        tell_object(this_player(),@LONG
老人說：鳥人族一向生活在高山中，與外界無所爭，傳說中的天空之城，是我們
鳥人族的聖地，也是我們聚居的地方。而每年所舉行的比武大會，推選出鳥人族的領
袖，帶領著我們抵抗意圖染指天空之城的異族。不過因為我們一向和外界沒啥來往，
所以也不常會有戰爭的發生。....
    不過自從阿道夫當上我們的領袖之後，就有點不一樣了，他的好朋友裘拉根和塔
姆姆族是世仇，這一年來為了追殺裘拉根，以經發動了數次戰爭(war) ，鳥人族的戰
士也是死傷慘重。為了一個素不相識的外族人....唉....真是不值得啊。
LONG
                );
        return 1;
}
