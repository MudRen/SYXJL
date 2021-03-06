inherit ROOM;

void create()
{
        set("short", "石门");
        set("long", @LONG
得到一道大石门前，只见两旁刻着两行大字，右首是“文成武德”，左
首是“仁义英明”，横额上刻着“一统江湖”四个大红字。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
"westup" : __DIR__"ryping",
"eastdown" : __DIR__"shijie2",
]));
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/jia" : 1,
            __DIR__"npc/shashou2" : 2,
  ]));

        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
        if(me->query_temp("hmy_enter") && dir == "westup")
        call_out("del_tmp",1000,me);
        else {

        if ((!myfam || myfam["family_name"] != "日月神教") && dir == "westup" &&
                objectp(present("jia bu", environment(me))))
           return notify_fail("贾布喝道：站住！你不是日月神教弟子，不得入内。\n");
             }
                
        return ::valid_leave(me, dir);
}
void del_tmp(object me)
{
        if ( objectp(me) ) me->delete_temp("hmy_enter");
}
