// Room: /d/wuguan/zhangfang.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "帐房");
        set("long", @LONG
这里是武馆内的一个帐房，室内一个帐房先生在这里认真地做着帐。
几名新弟子正围着帐房先生，看来是想把积攒下来的钱物存在这里。墙
上挂有一个牌子(paizi)。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "north" : __DIR__"shibanlu",
        ]));
        set("objects", ([
                __DIR__"npc/zhangfang" : 1,
        ]));                
        setup();
        replace_program(ROOM);
}
