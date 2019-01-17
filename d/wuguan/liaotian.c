// Room: /d/wuguan/liaotian.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "聊天培训");
        set("long", @LONG
这一场景是专为新手而设的，在这里你可以看见一位名叫寻花的
ＮＰＣ（即非玩家），他会教你简单的交谈技巧。如果你熟悉操作之
后，可以往东走，东面可以教你一些如何冒险的指令。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"maoxian",
        ]));
        set("objects", ([
                __DIR__"npc/tiatian" : 1,
        ]));
        
        setup();
        replace_program(ROOM);
}
