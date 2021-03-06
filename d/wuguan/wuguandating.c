// Room: /d/wuguan/wuguandating.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "武馆大厅");
        set("long", @LONG
这里是武馆大厅，正中靠北摆着一张八仙桌，桌上供着关公的神位，
旁边放着两个青瓷花瓶，插着几支孔雀翎，墙上写着大大的一个“武”字
武馆主人早些年在江湖上闯荡，现今洗手隐退，在扬州开起了这间武馆，
往北走是个长廊，一直通向馆主的卧室。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"wuguandayuan1",
                "north" : __DIR__"changlang4",                
                "east"  : __DIR__"shibanlu",                
                "west" : __DIR__"shibanlu2",
        ]));
        set("objects", ([
                __DIR__"npc/zhu" : 1,
        ]));        

        setup();
        replace_program(ROOM);
}
