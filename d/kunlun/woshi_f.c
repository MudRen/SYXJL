 // Room: /d/kunlun/woshi_f.c 

 

inherit ROOM; 

 

void create() 

{ 

        set("short", "女弟子卧室");

        set("long", @LONG

这是昆仑女弟子的住处，室内亦有几盆花卉，门旁摆着一个香炉,一 

缕青烟缓缓地飘出来，令人恹恹欲睡。靠墙有三两张木床, 只听得骄喘细 

细, 几名女弟子正在休息。 

LONG

        ); 

        set("sleep_room",1);        set("no_fight", "0");

        set("no_clean_up", 0);

        set("exits", ([ /* sizeof() == 1 */

  "east" : __DIR__"dalgf_1",

]));



        setup();

        replace_program(ROOM);

}



