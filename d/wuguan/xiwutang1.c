// Room: /d/wuguan/xiwutang1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "习武堂");
        set("long", @LONG
这里是武馆内的一个习武堂，堂内一个教头在教着武功，几个新手正在向
教头学习功夫，堂子正上方挂着个匾，上面写着“吃得苦中苦，放为人上人”。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
               "south" : __DIR__"shibanlu2",
        ]));
        setup();
        replace_program(ROOM);
}
